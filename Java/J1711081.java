/* Object类
 * 在Java中所有的类都有一个公共的父类，一个类只要没有明显地继承
 * 一个类，则肯定是Object类的子类
 */
class Person{
}
public class J1711081{
	public static void main(String args[]) {
		Demo d = new Demo();
		System.out.println("不加toString输出: " + d);
		System.out.println("加上toString输出: " + d.toString());
	}
}