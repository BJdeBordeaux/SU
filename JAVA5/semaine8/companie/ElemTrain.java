public abstract class ElemTrain {

    protected static int compteur = 10000;
    protected int numero_de_serie;
    protected String marque;

    protected ElemTrain(String marque) {
        this.marque = marque;
        compteur += 1;
        this.numero_de_serie = compteur;
    }

	@Override
	public String toString() {
		return "ElemTrain [marque=" + marque + ", numero_de_serie=" + numero_de_serie + "]";
	}

    
}
