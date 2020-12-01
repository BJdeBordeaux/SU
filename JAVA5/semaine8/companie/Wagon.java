public abstract class Wagon extends ElemTrain{

    protected int nb_portes;
    
    protected Wagon(String marque) {
        super(marque);
    }

    @Override
    public String toString() {
        return "Wagon [marque=" + marque + ", numero_de_serie=" + numero_de_serie + "]";
    }
    
    
}
