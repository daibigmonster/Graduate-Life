/* 
 * 工厂设计是Java开发中使用的最多的一种设计模式，那么什么叫工厂
 * 设计，工厂设计的作用都有那些？
 */
interface Fruit{
	public void eat();
}

class Apple implements Fruit{
	public void eat() {
		System.out.println("** 吃苹果");
	}
};

class Orange implements Fruit{
	public void eat() {
		System.out.println("** 吃橘子");
	}
};

public class J1711052 {
	public static void main(String[] args) {
		Fruit f = new Apple();
		f.eat();
	}
}