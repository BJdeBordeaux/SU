public class TestMonTableau {
    public static void main(String[] args) {
        MonTableau tab = new MonTableau(3);
        for (int i = 0; i < 10; i++) {
            try {
                tab.ajouter(i);
            } catch (TabPleinException e) {
                System.out.println(e.getMessage() + e);
                break;
            }
        }
    }
}
