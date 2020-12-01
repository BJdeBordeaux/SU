package submarine;

public class ChatSub extends Chat implements Submarine {
    @Override
    public void seDeplacer() {
        System.out.println("Le chat nage.");
    }
}
