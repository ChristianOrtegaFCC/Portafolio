import tensorflow as tf
import cv2
import numpy as np
import os
import keras_facenet


DIR_KNOWNS = 'C:/Users/amado/Desktop/RF/_RF/knowns'
DIR_UNKNOWNS = 'C:/Users/amado/Desktop/RF/_RF/unknowns'
DIR_RESULTS = 'C:/Users/amado/Desktop/RF/_RF/results'


with tf.io.gfile.GFile('C:/Users/amado/Desktop/IA4/RF/_RF/mobilenet_graph.pb','rb') as f:
    graph_def = tf.compat.v1.GraphDef()
    graph_def.ParseFromString(f.read())


with tf.Graph().as_default() as mobilenet:
    tf.import_graph_def(graph_def,name='')


# Cargar imagen
def load_image(DIR, NAME):
    return cv2.cvtColor(cv2.imread(f'{DIR}/{name}'), cv2.COLOR_BGR2RGB)


def detect_faces(image, score_threshold=0.7): # S C O R E   T H R E S H O L D !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    global boxes, scores
    (imh, imw) = image.shape[:-1]
    img = np.expand_dims(image,axis=0)
    
    # Inicializar mobilenet
    sess = tf.compat.v1.Session(graph=mobilenet)
    image_tensor = mobilenet.get_tensor_by_name('image_tensor:0')
    boxes = mobilenet.get_tensor_by_name('detection_boxes:0')
    scores = mobilenet.get_tensor_by_name('detection_scores:0')
    
    # Predicción (detección)
    (boxes, scores) = sess.run([boxes, scores], feed_dict={image_tensor:img})
    
    # Reajustar tamaños boxes, scores
    boxes = np.squeeze(boxes,axis=0)
    scores = np.squeeze(scores,axis=0)
    
    # Depurar bounding boxes
    idx = np.where(scores>=score_threshold)[0]
    
    # Crear bounding boxes
    bboxes = []
    for index in idx:
        ymin, xmin, ymax, xmax = boxes[index,:]
        (left, right, top, bottom) = (xmin*imw, xmax*imw, ymin*imh, ymax*imh)
        left, right, top, bottom = int(left), int(right), int(top), int(bottom)
        bboxes.append([left,right,top,bottom])        
    return bboxes


def draw_box(image,box,color,line_width=6):
    if box==[]:
        return image
    else:
        cv2.rectangle(image,(box[0],box[2]),(box[1],box[3]),color,line_width)
    return image

# Extraer rostros
def extract_faces(image,bboxes,new_size=(160,160)):
    cropped_faces = []
    for box in bboxes:
        left, right, top, bottom = box
        face = image[top:bottom,left:right]
        cropped_faces.append(cv2.resize(face,dsize=new_size))
    return cropped_faces


def compute_embedding(model,face):
    face = face.astype('float32')
    mean, std = face.mean(), face.std()
    face = (face-mean) / std
    face = np.expand_dims(face,axis=0)
    embedding = model.predict(face)
    return embedding


def compare_faces(embs_ref, emb_desc, umbral=0.9): # U M B R A L !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    distancias = []
    for emb_ref in embs_ref:
        distancias.append(np.linalg.norm(emb_ref-emb_desc))
    distancias = np.array(distancias)
    return distancias, list(distancias<=umbral)



facenet = keras_facenet.FaceNet()

print('Procesando rostros conocidos...')
known_embeddings = []
for name in os.listdir(DIR_KNOWNS):
    if name.endswith('.jpg'):
        print(f'   {name}')
        image = load_image(DIR_KNOWNS,name)
        bboxes = detect_faces(image)
        face = extract_faces(image,bboxes)
        known_embeddings.append(compute_embedding(facenet.model,face[0])) 


print('Procesando imágenes desconocidas...')
for name in os.listdir(DIR_UNKNOWNS):
    if name.endswith('jpg'):
        print(f'   {name}')
        image = load_image(DIR_UNKNOWNS, name)
        bboxes = detect_faces(image)
        faces = extract_faces(image, bboxes)

        # por cada rostro calcular el embedding
        img_with_boxes = image.copy()
        for face, box in zip(faces, bboxes):
            emb = compute_embedding(facenet.model, face)
            distancias, reconocimiento = compare_faces(known_embeddings, emb)
            match_found = any(reconocimiento)
            if match_found:
                print(f'    match found for {name}!')
                img_with_boxes = draw_box(img_with_boxes, box, (0,255,0))
        cv2.imwrite(f'{DIR_RESULTS}/{name}', cv2.cvtColor(img_with_boxes, cv2.COLOR_RGB2BGR))

print('¡Fin!')
