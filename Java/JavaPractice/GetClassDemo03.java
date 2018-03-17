package dai.demo15.getclassdemo;
class X{}
/**
 * GetClassDemo03
 */
public class GetClassDemo03 {

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
        c2 = new X().getClass();
        c3 = X.class;
        System.out.println("类名称: " + c1.getName());
        System.out.println("类名称: " + c2.getName());
        System.out.println("类名称: " + c3.getName();
    }
}
