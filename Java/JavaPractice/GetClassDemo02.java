package dai.demo15.getclassdemo;
class X{}
/**
 * GetClassDemo02
 */
public class GetClassDemo02 {

    public static void main(String[] args) {
        Class<?> c1 = null;
        Class<?> c2 = null;
        Class<?> c3 = null;
        try {
            c1 = Class.forName("dai.demo15.getclassdemo.X");
        } catch (ClassNotFoundException e) {
            //TODO: handle exception
            e.printStackTrace();
        }
    }
}