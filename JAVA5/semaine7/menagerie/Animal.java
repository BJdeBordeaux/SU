public abstract class Animal {
    protected String nom;
    protected int age;

    public Animal(String nom, int age) {
        this.nom = nom;
        this.age = age;
    }

    public Animal(String nom) {
        this.nom = nom;
        age = 1;
    }

    @Override
    public String toString() {
        return "Animal [age=" + age + ", nom=" + nom + "]";
    }

    public void vieillir(){
        age += 1;
    }

    public abstract void crier();
}
