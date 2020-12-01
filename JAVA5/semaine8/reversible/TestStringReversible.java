import java.util.ArrayList;

public class TestStringReversible {
    public static void main(String[] args) {
        Reversible rev = new StringReversible("Hello World");
        StringReversible rev2 = new StringReversible("Happy");
        System.out.println(rev+ " " + rev2);
        rev.reverse();
        rev2.reverse();
        System.out.println(rev.toString() + " " + rev2.toString());
        ArrayListReversible listRev = new ArrayListReversible();
        listRev.add(rev);
        listRev.add(rev2);
        System.out.println(listRev);
        listRev.reverse();
        System.out.println(listRev);
    }
}
