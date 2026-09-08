public class SistemaProduccion {
    public static void main(String[] args) {
        Contenedor contenedorA = new Contenedor(35,"A");
        Contenedor contenedorB = new Contenedor(35,"B");

        BrazoProduccion brazo1 = new BrazoProduccion("1", 25,contenedorA, contenedorB);
        BrazoProduccion brazo2 = new BrazoProduccion("2", 25,contenedorB, contenedorA);
        
        brazo1.start();
        brazo2.start();
    }
}


