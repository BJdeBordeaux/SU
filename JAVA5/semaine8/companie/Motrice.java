public class Motrice extends ElemTrain{

    protected double puissance;

    public Motrice(String marque) {
        super(marque);
        puissance = 10000;
    }

    @Override
    public String toString() {
        return "Motrice [marque=" + marque + ", numero_de_serie=" + numero_de_serie + "]";
    }


    
}
