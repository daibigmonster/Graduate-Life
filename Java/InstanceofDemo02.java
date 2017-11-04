import org.omg.CORBA.PUBLIC_MEMBER;

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

class C extends A{
	public void fun1() {
		System.out.println("C --> public void fun1");
	}
	public void fun5() {
		System.out.println("C --> public void fun3");
	}
}

public class InstanceofDemo02{
	public static void main(String[] args) {
		fun(new B());
		fun(new C());
	}
	public static void fun(A a) {
		a.fun1();
		if(a instanceof B) {
			B b = (B)a;
			b.fun3();
		}
		if(a instanceof C) {
			C c = (C)a;
			c.fun5();
		}
	}
}
/*
 * 在上面fun()方法中因为要调用各个子类的方法，所以必须进行对象
 * 的向下转型，但是为了保证程序在运行时不出现转化异常，所以在发生向
 * 下转型前要使用instance关键字判断是那个子类的实例，以保证程序
 * 运行正确 
 */
 */