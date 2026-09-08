import os
import random
from PIL import Image, ImageOps
import shutil

# Función para hacer zoom en la imagen
def zoom(image, zoom_factor):
    width, height = image.size
    new_width, new_height = int(width * (1 + zoom_factor)), int(height * (1 + zoom_factor))
    zoomed_image = image.resize((new_width, new_height), Image.LANCZOS)  # Cambié a LANCZOS
    left = (new_width - width) / 2
    top = (new_height - height) / 2
    right = (new_width + width) / 2
    bottom = (new_height + height) / 2
    zoomed_image = zoomed_image.crop((left, top, right, bottom))
    return zoomed_image

# Función principal para generar copias modificadas
def generate_image_copies(input_folder, output_folder, num_copies):
    # Crear el directorio de salida si no existe
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # Obtener las imágenes en la carpeta de entrada
    images = [f for f in os.listdir(input_folder) if f.lower().endswith(('png', 'jpg', 'jpeg', 'gif'))]
    
    # Seleccionar imágenes aleatorias
    selected_images = random.sample(images, min(num_copies, len(images)))

    for img_name in selected_images:
        img_path = os.path.join(input_folder, img_name)
        img = Image.open(img_path)

        # Operaciones aleatorias
        operation = random.choice(['mirrorx', 'mirrory', 'rotate', 'zoom'])

        if operation == 'mirrorx':
            img = ImageOps.mirror(img)  # Espejo horizontal
        elif operation == 'mirrory':
            img = ImageOps.flip(img)  # Espejo vertical
        elif operation == 'rotate':
            degrees = random.choice([90, 180, 270])  # Rotaciones aleatorias
            img = img.rotate(degrees)
        elif operation == 'zoom':
            zoom_factor = random.uniform(0.1, 0.3)  # Zoom aleatorio entre 10% y 30%
            img = zoom(img, zoom_factor)

        # Guardar la imagen modificada en el directorio de salida
        output_path = os.path.join(output_folder, f"modified_{operation}_{img_name}")
        img.save(output_path)

        #print(f"Imagen guardada como: {output_path}")


path_base = 'C:/Users/amado/Desktop/firedetection/imgs'
parametros = []
parametros.append(('fire',18))
parametros.append(('nofire',95))


for idx in parametros:

    # Uso
    input_folder = f'{path_base}/{idx[0]}' # path de la clase original
    output_folder = f'{path_base}_aug_copy/{idx[0]}' # path de la copia de la aumentación
    final_folder = f'{path_base}_mix/{idx[0]}' # path de la copia de original + aumentación
    num_copies = idx[1]  # Número de copias por clase

    generate_image_copies(input_folder, output_folder, num_copies) # función generadora de copias

    os.makedirs(final_folder, exist_ok=True)

    # Paso 2: Crear carpeta final
    os.makedirs(final_folder, exist_ok=True)

    # Copiar originales
    for file in os.listdir(input_folder):
        src_path = os.path.join(input_folder, file)
        dst_path = os.path.join(final_folder, file)
        if os.path.isfile(src_path):
            shutil.copy(src_path, dst_path)

    # Copiar aumentadas (evitar duplicados)
    for file in os.listdir(output_folder):
        src_path = os.path.join(output_folder, file)
        dst_path = os.path.join(final_folder, file)
        
        base, ext = os.path.splitext(file)
        counter = 1
        while os.path.exists(dst_path):
            dst_path = os.path.join(final_folder, f"{base}_{counter}{ext}")
            counter += 1
        
        if os.path.isfile(src_path):
            shutil.copy(src_path, dst_path)

print("Todo listo: originales + aumentadas combinadas en imgs_final.")


