import os
import ctypes
import random
import shutil

def cambiar_fondo_bloqueo(carpeta_imagenes):
    # [1] Obtener la lista de archivos de la carpeta de imágenes
    #     (primera f: valor que será añadido a la nueva lista, segunda f: variable iteradora, que toma cada elemento de os.listdir(carpeta_imagenes))
    #     (Esta linea hace append automáticamente a lo que hay después del if, si este se cumple)
    lista_imagenes = [f for f in os.listdir(carpeta_imagenes) if f.lower().endswith(('.png', '.jpg', '.jpeg', '.gif', '.bmp'))]

    # [1.1] Verificar si hay imágenes en la carpeta
    if not lista_imagenes:
        print("No se encontraron imágenes en la carpeta especificada.")
        return

    # [2] Seleccionar una imagen aleatoria con random
    imagen_seleccionada = random.choice(lista_imagenes)
    ruta_imagen = os.path.join(carpeta_imagenes, imagen_seleccionada) # Join para asegurar que los separadores de rutas '/' o '\' sean corectos, y garantizar una ruta útil

    # [3] Obtener la ruta completa del fondo de pantalla
    #     (el parámetro es gigante, pero simplemente es una ruta) ( C:\Users\amado\AppData\Local\Packages\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\LocalState\Assets )
    ruta_fondo_bloqueo = os.path.join(os.environ['USERPROFILE'], 'AppData', 'Local', 'Packages', 'Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy', 'LocalState', 'Assets')

    # [3.1] Obtener la ruta del archivo en la carpeta
    nuevo_nombre = os.path.join(ruta_fondo_bloqueo, f'{imagen_seleccionada.split(".")[0]}.jpg')

    # [3.2] Verificar si el archivo ya existe y, en ese caso, generar un nuevo nombre único (para  no sobreescribir imágenes que ya existen en la carpeta de destino)
    contador = 1
    while os.path.exists(nuevo_nombre):
        nuevo_nombre = os.path.join(ruta_fondo_bloqueo, f'{imagen_seleccionada.split(".")[0]}_{contador}.jpg')
        contador += 1

    # [3.3] Copiar la imagen seleccionada como fondo de pantalla
    #       (Windows gestiona los fondos de pantalla a través de imágenes almacenadas en una carpeta específica)
    #       (las imágenes que deseas usar como fondo de pantalla deben estar en esa carpeta específica antes de que el sistema pueda usarlas.)
    try:
        shutil.copy2(ruta_imagen, nuevo_nombre)
    except Exception as e:
        print(f"Error al copiar la imagen: {e}")
        return

    # [4] Llamar a la función de la API de Windows para cambiar el fondo de pantalla
    ctypes.windll.user32.SystemParametersInfoW(20, 0, nuevo_nombre, 3)

# [0] Especifica la carpeta de imágenes...
carpeta_imagenes = r'C:\Wallpapers'

# [0] Llama a la función para cambiar el fondo de pantalla de bloqueo
cambiar_fondo_bloqueo(carpeta_imagenes)
