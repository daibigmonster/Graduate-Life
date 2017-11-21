/*
 * 在Java中可以使用instanceof关键字判断一个对象到底是那个类的实例
 * ，格式如下所示
 * 对象instance类-> 返回boolean类型
 */
class A{
	public void fun1() {
		System.out.println("A --> public void fun1");
	}
	public void fun2() {
		this.fun1();
	}
};

class B extends A{
	public void fun1() {
		System.out.println("B --> public void fun1");
	}
	public void fun3() {
		System.out.println("B --> public void fun3");
	}
}

public class InstanceofDemo01{
	public static void main(String[] args) {
		A a1 = new B();
		System.out.println("A a1 = new B():" + (a1 instanceof A));
		System.out.println("A a1 = new B():" + (a1 instanceof B));
		A a2 = new A();
		System.out.println("A a2 = new B():" + (a2 instanceof A));
		System.out.println("A a2 = new B():" + (a2 instanceof B));
	}
}
/* 
 * 从以上的程序中可以发现，由于通过子类实例化的对象同时是子类和父类
 * 的实例，所以可以直接进行向上或向下转型，但如果使用了父类实例化
 * 本类对象，则一定就不再是子类示例了，所以是不能转换的。
 */