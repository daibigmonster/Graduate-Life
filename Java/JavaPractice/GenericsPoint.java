/**
 * 泛型可以解决数据类型的安全性问题,其主要原理是在类声明时通过一个标识表示类中某个属性的类型或者是
 * 某个方法的返回值及参数类型.这样在类声明或实例化时只要指定好需要的类型即可.
 */
//声明泛型
package dai.demo10.genericspoint;
class Point<T>{
    // private T x;
    // private T y;
    // public void setX(T x) {
    //     this.x = x;
    // }
    // public void setY(T y) {
    //     this.y = y;
    // }
    // public T getX() {
    //     return this.x;
    // }
    // public T getY() {
    //     return this.y;
    // }
    private T var;
    public Point(T var) {
        this.var = var;        
    }
    public T getVar() {
        return var;
    }
}
/**
 * 上面的代码中的Point类在声明时使用了<T>刑事,T表示此类型是由外部调用本类时决定的,这里使用
 * 任意的字母都可以
 */
/**
 * GenericsPoint
 */
public class GenericsPoint {

    public static void main(String[] args) {
        // Point<Integer> p = new Point<Integer>();
        // p.setX(10);
        // p.setY(20);
        // int x = p.getX();
        // int y = p.getY();
        // System.out.println("整数表示,X坐标为" + x);
        // System.out.println("整数表示,Y坐标为" + y);
        // p.setX(10);
        // p.setY("北纬210度");
        Point<String> p = null;
        p = new Point<String>("戴涧");
        System.out.println("内容: " + p.getVar());
    }
}