package a.test;
/**
 * This is the test class
*/
import a.A;
import bc.B;
import bc.C;
public class Test {
    /***
     * Our test starts there
     * @param args
    */
    public static void main(String[] args) {
        A a = new A();
        B b = new B();
        C c = new C();
        a.afficher();
        c.afficher();
    }
}
