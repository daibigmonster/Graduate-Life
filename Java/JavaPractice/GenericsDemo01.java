package dai.demo10.genericsdemo;
class Point{
    private Object x;
    private Object y;
    public void setX(Object x) {
        this.x = x;
    }
    public void setY(Object y) {
        this.y = y;
    }
    public Object getX() {
        return this.x;
    }
    public Object getY() {
        return this.y;
    }
    //以上程序在定义Point属性使用了Object类型,则输入的数据可以输任意的类型
}
/**
 * GenericsDemo01
 */
public class GenericsDemo01 {

    public static void main(String[] args) {
        Point p = new Point();
        p.setX(10);
        p.setY(20);
        int x = (Integer)p.getX();
        int y = (Integer)p.getY();
        System.out.println("整数表示,X坐标为" + x);
        System.out.println("整数表示,Y坐标为" + y);
        p.setX(10.5f);
        p.setY(20.29f);
        float v = (Float)p.getX();
        float w = (Float)p.getY();
        System.out.println("小数表示,X坐标为" + v);
        System.out.println("小数表示,Y坐标为" + w);
    }
}