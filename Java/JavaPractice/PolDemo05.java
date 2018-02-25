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

class C extends A{
	public void fun1() {
		System.out.println("C --> public void fun1() {}");
	}
	public void fun5() {
		System.out.println("C --> public void fun5() {}");
	}
};

public class PolDemo05{
	public static void main(String[] args){
		fun(new B());
		fun(new C());
	}
	public static void fun(A a) {
		a.fun1();
	}
}
/* 
 * 从以上程序可以发现，此时由于在fun方法中使用了对象的多态性，所以可以接收
 * 任何的子类对象，这样无论子类如何增加，fun()方法都不用做任何的改变，因为
 * 一旦发生对象的向上转型关系后，调用的方法一定是被子类覆写过的方法。
 * 
 */