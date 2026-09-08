import java.util.logging.Level;
import java.util.logging.Logger;

class Contenedor {
    private int cantidadObjetos;
    private String ID;

    public Contenedor(int capacidad,String ID) {
        this.cantidadObjetos = capacidad;
        this.ID = ID;
    }
    
    public int getCantidadObjetos() {
    	return cantidadObjetos;
    }
    
    public String getID() {
    	return ID;
    }

    public synchronized boolean estaVacio() {
        return cantidadObjetos == 0;
    }

    public synchronized int descarga(String idBrazo, String tipo) {
        if (!estaVacio()) {
            cantidadObjetos--;
            return cantidadObjetos + 1;
        }

        System.out.println("Brazo " + idBrazo + ": Contenedor " + tipo + " vacio, esperando...");
        
        // EXCLUSION MUTUA!!!, pone el hilo en el que se está ejecutando en un
        // estado de espera (suspendido) si el contenedor está vacío y un
        // brazo intenta descargar una pieza.
        try {
            wait();
        } catch (InterruptedException ex) {
            Logger.getLogger(Contenedor.class.getName()).log(Level.SEVERE, null, ex);
        }

        return -1;
    }

    public synchronized void notificar() {
        notifyAll();
    }
}