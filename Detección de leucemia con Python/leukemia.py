import os
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import cv2
import shutil
from sklearn.model_selection import train_test_split
import keras
from sklearn.metrics import f1_score, precision_score, recall_score
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay


def detect_roi(image):
    # Convertir la imagen a escala de grises si tiene 3 canales (RGB)
    if len(image.shape) == 3 and image.shape[2] == 3:
        image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    
    # Asegurarse de que la imagen esté en formato de 8 bits (CV_8U)
    image = np.uint8(image)
    
    # Aplicar desenfoque para reducir ruido
    blurred = cv2.GaussianBlur(image, (5, 5), 0)
    
    # Detectar bordes usando el algoritmo Canny
    edges = cv2.Canny(blurred, threshold1=30, threshold2=100)
    
    # Encontrar los contornos de las regiones de interés
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    # Dibujar los contornos sobre la imagen original
    image_with_contours = cv2.cvtColor(image, cv2.COLOR_GRAY2RGB)  # Convertir de nuevo a RGB si era en gris
    cv2.drawContours(image_with_contours, contours, -1, (0, 255, 0), 2)  # Dibujar contornos en verde
    
    # Extraer y mostrar la primera ROI encontrada (puedes ajustar esto)
    if contours:
        # Extraer el contorno más grande (puedes ajustar esto para ROIs específicas)
        largest_contour = max(contours, key=cv2.contourArea)
        x, y, w, h = cv2.boundingRect(largest_contour)  # Obtener el rectángulo delimitador
        roi = image[y:y+h, x:x+w]
        # Mostrar la ROI extraída
        cv2.imshow("ROI", roi)

    return image_with_contours


def load_and_preprocess_image(image_path):
    # Cargar la imagen
    image = Image.open(image_path).convert('RGB')  # Asegurar que está en modo RGB
    # Redimensionar la imagen a 224x224 píxeles
    image = image.resize((224, 224))
    # Convertir la imagen a un array NumPy
    image = np.array(image)
    # Convertir a escala de grises
    image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    # Normalizar los píxeles a un rango entre 0 y 1
    image = image / 255.0

    # Realce de contraste
    blurred = cv2.GaussianBlur(image, (5, 5), 0)
    sharpened = cv2.addWeighted(image, 1.5, blurred, -0.2, 0) #entre -0.4 y -0.2 está chido, 0 también se ve prometedor
    image = np.clip(sharpened, 0, 1)  # Asegurar que los valores estén en [0, 1]

    # Expandir las dimensiones para agregar un canal (de (224, 224) a (224, 224, 1))
    image = np.expand_dims(image, axis=-1)

    image_with_roi = detect_roi(image)

    return image_with_roi



dataset_dir = 'C:/Users/amado/Desktop/Leukemia/Dataset'
class_names = ['Benign', 'Early', 'Pre', 'Pro']
images = []
labels = []

# Recorrer cada clase y cargar las imágenes correspondientes
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
                labels.append(class_id)  # Guardar el ID de la clase (Benign=0, Early=1, Pre=2, Pro=3)


# Convertir las listas de imágenes y etiquetas a arrays NumPy
images = np.array(images)
labels = np.array(labels)

# Verificar las dimensiones de las imágenes y etiquetas
print(f"\n\nDimensiones de las imágenes: {images.shape}")  # (n_imágenes, 224, 224, 3)
print(f"Dimensiones de las etiquetas: {labels.shape}")  # (n_imágenes, )


# Crear el directorio de salida para imágenes procesadas
output_dir = "ProcessedDataSet"
if os.path.exists(output_dir):
    shutil.rmtree(output_dir)  # Eliminar el directorio si ya existe
os.makedirs(output_dir)


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
X_train, X_temp, y_train, y_temp = train_test_split(images, labels, test_size=0.2, random_state=42)

# Luego dividir el conjunto temporal en validación y prueba (50% cada uno, que representa 10% del total)
X_test, X_val, y_test, y_val = train_test_split(X_temp, y_temp, test_size=0.5, random_state=42)

# Convertir imágenes a escala de grises
X_train = np.array([cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) for img in X_train])
X_val = np.array([cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) for img in X_val])
X_test = np.array([cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) for img in X_test])

X_train = X_train.reshape((-1, 224, 224, 1))
X_val = X_val.reshape((-1, 224, 224, 1))
X_test = X_test.reshape((-1, 224, 224, 1))

print(f"\nDimensiones del conjunto de entrenamiento: {X_train.shape}")
print(f"Dimensiones del conjunto de validación: {X_val.shape}")
print(f"Dimensiones del conjunto de prueba: {X_test.shape} \n\n")



# Crear el modelo
model = keras.models.Sequential()

# Capas convolucionales + capa de max pooling
model.add(keras.layers.Conv2D(32, (3, 3), activation='relu', input_shape=(224, 224, 1)))  # Para imágenes de 224x224 con 1 canal (gris)
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Conv2D(64, (3, 3), activation='relu'))
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Conv2D(64, (3, 3), activation='relu')) # NUEVAS
model.add(keras.layers.MaxPooling2D((2, 2)))                  #
model.add(keras.layers.Conv2D(128, (3, 3), activation='relu'))
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Conv2D(128, (3, 3), activation='relu'))
model.add(keras.layers.MaxPooling2D((2, 2)))
model.add(keras.layers.Flatten()) # Aplanar la imagen para pasar a la capa densa
model.add(keras.layers.Dense(128, activation='relu',kernel_regularizer=keras.regularizers.l2(0.01))) # Capa densa con 128 neuronas y Dropout
model.add(keras.layers.Dropout(0.5))  # Dropout para evitar sobreajuste
model.add(keras.layers.Dense(4, activation='softmax'))  # Capa de salida (4 clases en total) # Usamos softmax porque tenemos múltiples clases

# Compilar el modelo
model.compile(optimizer=keras.optimizers.Adam(learning_rate=0.0001), loss='sparse_categorical_crossentropy', metrics=['accuracy'])
model.summary()

# Entrenar al modelo
history = model.fit(X_train, y_train, epochs=40, batch_size=32, validation_data=(X_val, y_val))
model.save('leukemia_detection_v8_40_epochs.h5')

# Gráfica de la precisión y pérdida durante el entrenamiento
plt.plot(history.history['accuracy'], label='Precisión de entrenamiento')
plt.plot(history.history['val_accuracy'], label='Precisión de validación')
plt.xlabel('Epochs')
plt.ylabel('Precisión')
plt.legend()
plt.show()

# Evaluar el modelo en el conjunto de prueba
test_loss, test_acc = model.evaluate(X_test, y_test)

print(f"Pérdida en el conjunto de prueba: {test_loss}")
print(f"Precisión en el conjunto de prueba: {test_acc}")

# Calcular la matriz de confusión
y_pred = model.predict(X_test)
y_pred_classes = np.argmax(y_pred, axis=1)
cm = confusion_matrix(y_test, y_pred_classes)

# Mostrar la matriz de confusión de manera gráfica
disp = ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=class_names)
disp.plot(cmap=plt.cm.Blues)
plt.title('Matriz de Confusión')
plt.show()

print("End")