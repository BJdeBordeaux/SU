package submarine;

public class TestMer {
    public static void main(String[] args) {
        Mer mer = new Mer();
        mer.ajouter(new Merlu());
        mer.ajouter(new SousMarin());
        mer.ajouter(new Dauphin());
        mer.ajouter(new ChatSub());
        mer.seDeplacerTous();
    }
}
