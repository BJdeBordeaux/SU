package submarine;

import java.util.ArrayList;

public class Mer {
    private ArrayList<Submarine> membres = new ArrayList<Submarine>();

    public void ajouter(Submarine s) {
        membres.add(s);
    }

    public void seDeplacerTous() {
        for (Submarine submarine : membres) {
            if(submarine == null){continue;}
            submarine.seDeplacer();
        }
    }


}
