public class StringReversible implements Reversible {

    private String string;

    public StringReversible(String string) {
        this.string = string;
    }

    public int length() {
        return string.length();
    }

    public char charAt(int i){
        return string.charAt(i);
    }

    @Override
    public void reverse() {
        String s = "";
        for (int i = 0; i < length(); i++) {
                s += charAt(length()-1 - i);
        }
        string = s;
    }

    @Override
    public String toString() {
        return string;
    }
    
    
}
