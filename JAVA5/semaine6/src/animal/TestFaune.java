public class TestFaune {
    public static void main(String[] args) {
        Faune f = new Faune();
        System.out.println(f.terrain());
        Animal[] tab = f.getTab();
        for(Animal a: tab){
            Animal plusProche = tab[f.getIndiceAnimalLePlusProche(a)];
            System.out.println(a + " a pour voisin le plus proche : " + plusProche);
        }
        for (int i = 0; i < 50; i++) {
            f.update();
            System.out.println(f.terrain());
        }
    }
}
