import pygame
import time
import os
import win32gui
import win32con
import random

def hide_console():
    import win32gui, win32con
    the_program_to_hide = win32gui.GetForegroundWindow()
    win32gui.ShowWindow(the_program_to_hide , win32con.SW_HIDE)

def main():
    # Ocultar la consola de la ventana
    hide_console()

    # Resto del código sigue igual...
    # Inicializar pygame
    pygame.init()

    # Obtener el tamaño de la pantalla
    screen = pygame.display.set_mode((0, 0), pygame.NOFRAME)

    # Cargar la imagen
    jumpscare_img = pygame.image.load(os.path.join('recursos', 'jumpscare two.jpg'))

    # Obtener el tamaño de la imagen y de la pantalla
    img_width, img_height = jumpscare_img.get_rect().size
    screen_width, screen_height = screen.get_size()

    # Escalar la imagen al tamaño de la pantalla
    scaled_img = pygame.transform.scale(jumpscare_img, (screen_width, screen_height))

    # Cargar el sonido
    jumpscare_sound = pygame.mixer.Sound(os.path.join('recursos', 'jumpscare corto 1.mp3'))

    # Configurar la ventana para que siempre esté en la parte superior
    hwnd = pygame.display.get_wm_info()['window']
    win32gui.SetWindowPos(hwnd, win32con.HWND_TOPMOST, 0, 0, 0, 0,
                          win32con.SWP_NOMOVE | win32con.SWP_NOSIZE | win32con.SWP_NOACTIVATE)

    # Mostrar la imagen en pantalla completa
    screen.blit(scaled_img, (0, 0))
    pygame.display.flip()

    # Reproducir el sonido
    jumpscare_channel = jumpscare_sound.play()

    # Esperar un tiempo antes de cerrar la ventana
    if jumpscare_channel:
        duration = jumpscare_sound.get_length() * 1000  # Duración en milisegundos
        pygame.time.delay(int(duration))

    # Cerrar pygame
    pygame.quit()

if __name__ == "__main__":
    # Esperar 5 segundos antes de ejecutar el jumpscare
    while 1:
        seconds = random.randint(5, 15)
        time.sleep(seconds)
        main()
