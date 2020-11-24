import java.util.ArrayList;
public class Menagerie {
    ArrayList<Animal> animaux;

    public Menagerie() {
        animaux = new ArrayList<Animal>();
    }

    public void ajouter(Animal a) {
        animaux.add(a);
    }

    public void midi() {
        for (Animal animal : animaux) {
            animal.crier();
        }
    }

    public void vieillirTous() {
        for (Animal animal : animaux) {
            animal.vieillir();
        }
    }

    public String toString() {
        String listAnimaux = "";
        for (Animal animal : animaux) {
            listAnimaux += animal.toString() + "\n";
        }
        return listAnimaux;
    }
}
