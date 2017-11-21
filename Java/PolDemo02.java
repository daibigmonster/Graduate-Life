class A{
	public void fun1(){
		System.out.println("A --> public void fun1() {}");
	}
	public void fun2() {
		this.fun1();
	}
};

class B extends A{
	public void fun1() {
		System.out.println("B --> public void fun1() {}");
	}
	public void fun3() {
		System.out.println("B --> public void fun3() {}");
	}
};

public class PolDemo02{
	public static void main(String[] args){
		A a = new B();
		B b = (B)a; //此时发生了向下转型关系
		b.fun1();
		b.fun2();
		b.fun3();
	}
}
/* 
 * 从以上程序中可以发现，如果想要调用子类自己的方法，则一定只能用子类声明，另外，在子类中调用了
 * 父类中的fun2()方法，fun2()方法要调用fun1()方法，但此时fun1()方法已经被子类覆写，所以，
 * 此时调用的方法是被子类覆写过的方法。
 * 
 */