public class TabPleinException extends Exception{

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public TabPleinException(String message) {
        super(message);
    }

    public TabPleinException() {
    }

    @Override
    public String toString() {
        return "TabPleinException\n";
    }
    
    
}
