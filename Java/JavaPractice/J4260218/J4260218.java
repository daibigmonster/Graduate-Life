/**
 * A
 */
interface A {
    public String getInfo();
}
class B implements A{
    public String getInfo(){
        return "Hello World!!!";
    }
}
/**
 * J4260218
 */
public class J4260218 {
    public static void main(String[] args) {
        A a = new B();
        Object obj = a;       
        A x = (A)obj;
        System.out.println(x.getInfo());
    }
}