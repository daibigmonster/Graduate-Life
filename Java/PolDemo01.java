/*
 * 对象的多态性
 * 多态性在面向对象中是一个重要的概念，在java中面向对象主要有以下两种主要体现
 * 1方法的重载和覆写
 * 2对象的多态性
 * 对于方法的重载和覆写已经介绍过，下面介绍对象的多态性
 * 方法的多态性主要分为以下两种类型。
 * 1向上转型：子类对象->父类对象
 * 2向下转型：父类对象->子类对象
 * 对于向上转型，程序会自动完成，而对于向下转型，必须明确地指明要转型的子类类型
 */

//对象向上转型
class A{
	public void fun1() {
		System.out.println("A --> public void fun1() {}");
	}
	public void fun2() {
		this.fun1();
	}
}

class B extends A{
	public void fun1() { //覆写父类中的fun1方法
		System.out.println("B --> public void fun1() {}");
	}
	public void fun3() {
		System.out.println("B --> public void fun3() {}");
	}
}

public class PolDemo01{
	public static void main(String[] args) {
		B b = new B();
		A a = b;
		a.fun1(); // 此类方法被子类覆写过
	}
