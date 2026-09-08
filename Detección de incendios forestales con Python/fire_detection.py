import os
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import cv2
import shutil
from sklearn.model_selection import train_test_split
import keras
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay


def detect_roi(image):
    # Asegurarse de que la imagen esté en formato BGR para OpenCV
    if len(image.shape) == 2:  # Es una imagen en escala de grises
        image_bgr = cv2.cvtColor(image, cv2.COLOR_GRAY2BGR)
    else:
        image_bgr = image.copy()
    

    # Si la imagen está normalizada a [0,1], convertirla a [0,255]
    if image_bgr.max() <= 1.0:
        image_bgr = np.uint8(image_bgr * 255)
    else:
        image_bgr = np.uint8(image_bgr)
    
    # Detección de color
    # Convertir a múltiples espacios de color para una detección más robusta
    hsv = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2HSV)
    lab = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2LAB)
    
    # Definir rangos de color para el fuego con umbrales más ajustados en HSV
    # Rojo bajo (cerca de 0 en HSV) - más restrictivo para rojos puros
    lower_red1 = np.array([0, 100, 100]) # originales: 0, 150, 150
    upper_red1 = np.array([10, 255, 255])
    
    # Rojo alto (cerca de 180 en HSV) - más restrictivo
    lower_red2 = np.array([170, 100, 100]) # originales: 170, 150, 150
    upper_red2 = np.array([180, 255, 255])
    
    # Naranja (fuego típico)
    lower_orange = np.array([11, 100, 100]) # originales: 11, 150, 150
    upper_orange = np.array([20, 255, 255])
    
    # Amarillo (partes más calientes del fuego)
    lower_yellow = np.array([21, 100, 100]) # originales: 21, 150, 150
    upper_yellow = np.array([35, 255, 255])
    
    # Crear máscaras para cada rango de color
    mask_red1 = cv2.inRange(hsv, lower_red1, upper_red1)
    mask_red2 = cv2.inRange(hsv, lower_red2, upper_red2)
    mask_orange = cv2.inRange(hsv, lower_orange, upper_orange)
    mask_yellow = cv2.inRange(hsv, lower_yellow, upper_yellow)
    
    # Combinar las máscaras para obtener todos los colores de fuego
    fire_mask_hsv = cv2.bitwise_or(cv2.bitwise_or(cv2.bitwise_or(mask_red1, mask_red2), mask_orange), mask_yellow)
    
    # Análisis adicional en el espacio LAB para capturar más características del fuego
    # El fuego tiene valores altos en el canal a (rojo-verde) y b (amarillo-azul)
    l, a, b = cv2.split(lab)
    
    # Establecer umbrales en los canales a y b para capturar colores de fuego
    _, a_thresh = cv2.threshold(a, 128, 255, cv2.THRESH_BINARY)
    _, b_thresh = cv2.threshold(b, 128, 255, cv2.THRESH_BINARY)
    
    # Combinar los canales para identificar áreas con altos valores tanto en a como en b
    lab_mask = cv2.bitwise_and(a_thresh, b_thresh)
    
    # Brillo y saturación (el fuego es brillante y saturado)
    _, s, v = cv2.split(hsv)
    
    _, bright_mask = cv2.threshold(v, 190, 255, cv2.THRESH_BINARY) # Obtener píxeles muy brillantes (potencial fuego)
    _, sat_mask = cv2.threshold(s, 130, 255, cv2.THRESH_BINARY) # Obtener píxeles muy saturados (colores vivos)

    # Combinar brillo y saturación
    bright_sat_mask = cv2.bitwise_and(bright_mask, sat_mask)
    
    # Combinación de todas las máscaras para identificación de fuego
    # Combinar todos los criterios de detección
    combined_mask = cv2.bitwise_and(fire_mask_hsv, lab_mask)
    combined_mask = cv2.bitwise_and(combined_mask, bright_sat_mask)
    
    # Filtrado y refinamiento
    # Aplicar operaciones morfológicas para mejorar la máscara
    kernel_open = np.ones((3, 3), np.uint8)
    kernel_close = np.ones((7, 7), np.uint8)
    
    # Eliminar pequeños puntos de ruido
    fire_mask = cv2.morphologyEx(combined_mask, cv2.MORPH_OPEN, kernel_open)
    
    # Cerrar huecos en la región de fuego
    fire_mask = cv2.morphologyEx(fire_mask, cv2.MORPH_CLOSE, kernel_close)
    
    # Forma y tamaño
    # Encontrar contornos para quedarnos solo con las áreas significativas
    contours, _ = cv2.findContours(fire_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Crear una máscara en blanco para el resultado final
    final_mask = np.zeros_like(fire_mask)
    
    # Analizar y dibujar solo contornos que sean prometedores como fuego
    if contours:
        for cnt in contours:
            area = cv2.contourArea(cnt)
            
            # Filtrar por tamaño (mínimo)
            if area < 100:  # Ignorar áreas muy pequeñas
                continue
                
            # Obtener el rectángulo delimitador
            x, y, w, h = cv2.boundingRect(cnt)
            aspect_ratio = float(w) / h if h > 0 else 0
            
            # Filtrar por forma (el fuego tiende a ser más alto que ancho)
            if aspect_ratio > 2.0:  # Rechazar áreas muy anchas y cortas
                continue
                
            # Calcular la compacidad (el fuego tiende a ser irregular)
            perimeter = cv2.arcLength(cnt, True)
            circularity = 4 * np.pi * area / (perimeter * perimeter) if perimeter > 0 else 0
            
            # El fuego tiende a tener una forma irregular (menos circular)
            if circularity > 0.8:  # Rechazar áreas muy circulares
                continue
                
            # Dibujar el contorno si pasa todos los filtros
            cv2.fillPoly(final_mask, [cnt], 255)
    
    # Normalizar a rango [0, 1] para el modelo
    return final_mask / 255.0

def load_and_preprocess_image(image_path):
    image = Image.open(image_path).convert('RGB') # Cargar la imagen
    
    image = image.resize((224, 224))    # Redimensionar la imagen a 224x224 píxeles
    image_np = np.array(image)          # Convertir la imagen a un array NumPy
    enhanced_img = image_np.copy()      # Crear una copia para manipular
    hsv = cv2.cvtColor(image_np, cv2.COLOR_RGB2HSV) # Convertir a HSV para mejor manipulación de colores
    
    # Definir rangos de color para fuego
    # Rojo bajo (0-10)
    lower_red1 = np.array([0, 70, 70])
    upper_red1 = np.array([10, 255, 255])
    
    # Rojo alto (160-180)
    lower_red2 = np.array([160, 70, 70])
    upper_red2 = np.array([180, 255, 255])
    
    # Naranja-amarillo (11-35)
    lower_yellow = np.array([11, 70, 70]) # originales: 11, 70, 70
    upper_yellow = np.array([35, 255, 255]) # originales: 35, 255, 255
    

    # Crear máscaras para fuego
    mask_red1 = cv2.inRange(hsv, lower_red1, upper_red1)
    mask_red2 = cv2.inRange(hsv, lower_red2, upper_red2)
    mask_yellow = cv2.inRange(hsv, lower_yellow, upper_yellow)
    
    # Combinar máscaras de fuego
    fire_mask = cv2.bitwise_or(cv2.bitwise_or(mask_red1, mask_red2), mask_yellow)
    
    # Crear máscara para no-fuego
    non_fire_mask = cv2.bitwise_not(fire_mask)
    
    # Extraer áreas de fuego y no fuego
    fire_area = cv2.bitwise_and(image_np, image_np, mask=fire_mask)
    non_fire_area = cv2.bitwise_and(image_np, image_np, mask=non_fire_mask)
    
    # Aumentar saturación en áreas de fuego
    fire_area_hsv = cv2.cvtColor(fire_area, cv2.COLOR_RGB2HSV)
    fire_area_hsv[:,:,1] = np.clip(fire_area_hsv[:,:,1] * 1.5, 0, 255)  # Aumentar saturación
    fire_area_enhanced = cv2.cvtColor(fire_area_hsv, cv2.COLOR_HSV2RGB)
    
    # Disminuir saturación en áreas que no son fuego
    non_fire_area_hsv = cv2.cvtColor(non_fire_area, cv2.COLOR_RGB2HSV)
    
    # Desaturar tonos verdes y azules (haciéndolos grises)
    non_fire_area_hsv[:, :, 1][np.logical_and(hsv[:, :, 0] >= 10, hsv[:, :, 0] <= 150)] = 0  # Tonos verdes y azules
    
    non_fire_area_enhanced = cv2.cvtColor(non_fire_area_hsv, cv2.COLOR_HSV2RGB)
    
    # Combinar las áreas procesadas
    enhanced_img = cv2.add(fire_area_enhanced, non_fire_area_enhanced)
    
    # Normalizar a [0, 1]
    enhanced_img = enhanced_img / 255.0

    # Blur
    processed = cv2.GaussianBlur(enhanced_img, (3, 3), 0)

    if not isinstance(image, np.ndarray):
        image = np.array(image)

    processed = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

    roi = detect_roi(processed)
    return roi


print("\n[+] Estableciendo ruta del dataset y etiquietas...")
#dataset_dir = 'C:/Users/amado/Desktop/firedetection/imgs_aug_copy' # dataset chico, para pruebas rápidas de procesamiento de datos
dataset_dir = 'C:/Users/amado/Desktop/firedetection/imgs_mix' # dataset completo (original + copias artificiales de "data_augmentation.py")

class_names = ['fire', 'nofire']
images = []
labels = []

# Recorrer cada clase y cargar las imágenes correspondientes
print("[+] Cargando dataset...")
for class_id, class_name in enumerate(class_names):
    class_path = os.path.join(dataset_dir, class_name)
    
    # Asegurarnos de que la carpeta existe
    if os.path.isdir(class_path):
        # Recorrer todas las imágenes en la carpeta de la clase
        for image_name in os.listdir(class_path):
            image_path = os.path.join(class_path, image_name)
            
            # Verificar que sea un archivo de imagen
            if image_path.lower().endswith(('png', 'jpg', 'jpeg')):
                # Cargar y preprocesar la imagen
                image = load_and_preprocess_image(image_path)
                # Añadir la imagen y la etiqueta a las listas
                images.append(image)
                labels.append(class_id)  # Guardar el ID de la clase (fire=0, nofire=1)


# Convertir las listas de imágenes y etiquetas a arrays NumPy
images = np.array(images)
labels = np.array(labels)

# Verificar las dimensiones de las imágenes y etiquetas
print(f"    Dimensiones de las imágenes: {images.shape}")  # (n_imágenes, 224 px en x, 224 px en y, 3 canales {RGB})
print(f"    Dimensiones de las etiquetas: {labels.shape}\n")  # (n_imágenes, )


# Crear el directorio de salida para imágenes procesadas
output_dir = "ProcessedDataSet"
if os.path.exists(output_dir):
    shutil.rmtree(output_dir)  # Eliminar el directorio si ya existe
os.makedirs(output_dir)


print("[+] Creando copia del data set procesado...")
for class_index, class_name in enumerate(class_names):
    # Crear una carpeta para la clase en el directorio de salida
    class_dir = os.path.join(output_dir, class_name)
    os.makedirs(class_dir)

    # Obtener todos los índices de las imágenes de la clase
    image_indices = np.where(labels == class_index)[0]

    # Guardar todas las imágenes procesadas de la clase
    for idx, img_idx in enumerate(image_indices):
        # Convertir la imagen de numpy a PIL
        processed_img = Image.fromarray((images[img_idx].squeeze() * 255).astype(np.uint8))
        # Guardar la imagen
        img_path = os.path.join(class_dir, f"{class_name}_{idx+1}.png")
        processed_img.save(img_path)


# Primero dividir en entrenamiento (80%) y temporal (20%)
print("[+] Separando en conjunto de entrenamiento, test y validación (80%,10%,10%)...")
X_train, X_temp, y_train, y_temp = train_test_split(images, labels, test_size=0.2, random_state=42)

# Luego dividir el conjunto temporal en validación y prueba (50% cada uno, que representa 10% del total)
X_test, X_val, y_test, y_val = train_test_split(X_temp, y_temp, test_size=0.5, random_state=42)

# Convertir imágenes a escala de grises
X_train = np.array([cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) if img.ndim == 3 else img for img in X_train])
X_val = np.array([cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) if img.ndim == 3 else img for img in X_val])
X_test = np.array([cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) if img.ndim == 3 else img for img in X_test])

X_train = X_train.reshape((-1, 224, 224, 1))
X_val = X_val.reshape((-1, 224, 224, 1))
X_test = X_test.reshape((-1, 224, 224, 1))

print(f"    Dimensiones del conjunto de entrenamiento: {X_train.shape}")
print(f"    Dimensiones del conjunto de validación: {X_val.shape}")
print(f"    Dimensiones del conjunto de prueba: {X_test.shape} \n")

# Crear el modelo
print("[+] Creando modelo...")
model = keras.models.Sequential()

# Capas convolucionales + capa de max pooling
model.add(keras.layers.Conv2D(32, (3, 3), activation='relu', input_shape=(224, 224, 1)))  # Para imágenes de 224x224 con 1 canal (gris)
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Conv2D(64, (3, 3), activation='relu'))
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Conv2D(64, (3, 3), activation='relu'))
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Conv2D(128, (3, 3), activation='relu'))
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Conv2D(128, (3, 3), activation='relu'))
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Flatten()) # Aplanar la imagen para pasar a la capa densa
model.add(keras.layers.Dense(128, activation='relu',kernel_regularizer=keras.regularizers.l2(0.01))) # Capa densa con 128 neuronas y Dropout
model.add(keras.layers.Dropout(0.5))  # Dropout para evitar sobreajuste
model.add(keras.layers.Dense(2, activation='softmax'))  # Capa de salida (2 clases en total)

# (Usamos softmax con 2 neuronas en la ultima capa porque aparentemente reacciona mejor que con sigmoid y 1 neurona)

# Compilar el modelo
# (Usamos sparse_categorical_crossentropy porque usamos softmax en la ultima capa)
print("[+] Compilando modelo...")
model.compile(optimizer=keras.optimizers.Adam(learning_rate=0.0001), loss='sparse_categorical_crossentropy', metrics=['accuracy'])
model.summary()

# !!! Entrenar al modelo !!!
print("[+] Entrenando modelo...")
history = model.fit(X_train, y_train, epochs=35, batch_size=32, validation_data=(X_val, y_val))
nombre = 'fire_detection_v2_35_epochs.h5'
print(f"[+] Guardando modelo como: {nombre}...")
model.save(nombre)

# Gráfica de la precisión y pérdida durante el entrenamiento
plt.plot(history.history['accuracy'], label='Precisión de entrenamiento')
plt.plot(history.history['val_accuracy'], label='Precisión de validación')
plt.xlabel('Epochs')
plt.ylabel('Precisión')
plt.legend()
plt.show()

# Evaluar el modelo en el conjunto de prueba
print("[+] Evaluando modelo...")

test_loss, test_acc = model.evaluate(X_test, y_test)
print(f"    Pérdida en el conjunto de prueba: {test_loss}")
print(f"    Precisión en el conjunto de prueba: {test_acc}")

# Calcular la matriz de confusión
y_pred = model.predict(X_test)
y_pred_classes = np.argmax(y_pred, axis=1)
cm = confusion_matrix(y_test, y_pred_classes)

# Mostrar la matriz de confusión de manera gráfica
disp = ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=class_names)
disp.plot(cmap=plt.cm.Blues)
plt.title('Matriz de Confusión')
plt.show()

print("[+] End...")