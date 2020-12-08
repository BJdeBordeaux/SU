public class AucunNoteException extends Exception{
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public AucunNoteException(String string) {
        super(string);
	}

	@Override
    public String toString() {
        return "Aucun note est valide.\n";
    }

    public AucunNoteException() {
    }
}
