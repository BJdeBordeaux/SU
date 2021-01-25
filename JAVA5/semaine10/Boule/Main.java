import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList<Boule> gdeUrne = new ArrayList<Boule>();
        for (int i = 0; i < 1000; i++) {
            gdeUrne.add(BouleFactory.build());
        }

        // declaration
        int[] couleurCompteur = new int[BouleFactory.couleurs.length];
        Boule[] bouleStandard = new Boule[BouleFactory.couleurs.length];
        
        // boules de chaque couleur
        for (int i = 0; i < BouleFactory.couleurs.length; i++) {
            bouleStandard[i] = new Boule(BouleFactory.couleurs[i]);
        }

        // comparaison
        for (Boule boule : gdeUrne) {
            for (int i = 0; i < BouleFactory.couleurs.length; i++) {
                if (boule.equals(bouleStandard[i])) {
                    couleurCompteur[i] += 1;
                }
            }
        }

        // affichage
        for (int i = 0; i < bouleStandard.length; i++) {
            System.out.println("Il y a " + couleurCompteur[i] + " boules de couleur " + BouleFactory.couleurs[i] + ".");
        }

        // BouleV2[] bv2 = {BouleV2.ROUGE, BouleV2.JAUNE, BouleV2.BLEUE, BouleV2.VERTE, BouleV2.ORANGE, BouleV2.VIOLETTE};
        // ArrayList<BouleV2> gdeBouleV2s = new ArrayList<gdeBouleV2s>(); 
        // for (int i = 0; i < 1000; i++) {
        //     gdeBouleV2s.add(bv2[(int) (Math.random() * bv2.length)]);
        // }
    }
}