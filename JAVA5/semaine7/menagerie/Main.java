public class Main {
    public static void main(String[] args) {
        Canard canard = new Canard("canard");
        Vache vache = new Vache("vache");
        MillePattes millePattes = new MillePattes("millePattes");
        Saumon saumon = new Saumon("saumon");
        Boa boa = new Boa("boa", 3);
        Menagerie menagerie = new Menagerie();
        menagerie.ajouter(canard);
        menagerie.ajouter(vache);
        menagerie.ajouter(millePattes);
        menagerie.ajouter(saumon);
        menagerie.ajouter(boa);
        System.out.println(menagerie.toString());
        menagerie.midi();
        menagerie.vieillirTous();
        System.out.println(menagerie.toString());
    }
}
