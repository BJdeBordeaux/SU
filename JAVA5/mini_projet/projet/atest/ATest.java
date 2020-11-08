package projet.atest;
/**
 * ATest
 */

import projet.A;
public class ATest {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        A a = new A(1, 2);
        System.out.println("i in class A is " + A.i);
        System.out.println("a in class A is " + a.a);
        System.out.println("b in class A is " + a.getB());
    }
}