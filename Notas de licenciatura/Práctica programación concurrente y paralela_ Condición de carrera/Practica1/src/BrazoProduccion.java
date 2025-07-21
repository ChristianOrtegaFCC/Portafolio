public class BrazoProduccion extends Thread {
    private String idBrazo;
    private Contenedor contenedor1;
    private Contenedor contenedor2;
    private int piezasExtrae;
    private int contPiezas;

    public BrazoProduccion(String nombre, int piezas, Contenedor contenedor1, Contenedor contenedor2) {
        this.idBrazo = nombre;
        this.contenedor1 = contenedor1;
        this.contenedor2 = contenedor2;
        this.piezasExtrae = piezas;
        this.contPiezas = 0;
    }

    public boolean verifica() {
        return contPiezas < piezasExtrae;
    }

    @Override
    public void run() {
        while (verifica()) {
            int objeto1, objeto2;

            synchronized (contenedor1) {
                if (idBrazo.equals("2")) {
                    objeto1 = contenedor2.descarga(idBrazo, contenedor2.getID());
                } else {
                    objeto1 = contenedor1.descarga(idBrazo, contenedor1.getID());
                }
            }

            synchronized (contenedor2) {
                if (idBrazo.equals("2")) {
                    objeto2 = contenedor1.descarga(idBrazo, contenedor1.getID());
                } else {
                    objeto2 = contenedor2.descarga(idBrazo, contenedor2.getID());
                }
            }

            contPiezas++;
            System.out.println("Brazo " + idBrazo + ": Ha tomado la pieza "+objeto1+" del contenedor " + contenedor1.getID());
            System.out.println("Brazo " + idBrazo + ": Ha tomado la pieza "+objeto2+" del contenedor " + contenedor2.getID());
            System.out.println("Brazo " + idBrazo + ": Ha montado su producto " + contPiezas + " de " + piezasExtrae+"\n");

            contenedor1.notificar();
            contenedor2.notificar();
        }

        System.out.println("Brazo " + idBrazo + ": Ha alcanzado su limite, ha ensamblado " + contPiezas + " productos.");
        System.out.println("Quedan "+contenedor1.getCantidadObjetos()+" piezas en el contenedor '"+contenedor1.getID()+"', y "+contenedor2.getCantidadObjetos()+" en el contenedor '"+contenedor2.getID()+"'.");
        
    }
}