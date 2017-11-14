import org.omg.CORBA.PUBLIC_MEMBER;

/* 
 * 匿名内部类
 * 在Java中除了内部类之外，还有一种匿名内部类。匿名内部类就是指
 * 没有一个具体名称的类，切实在接口和抽象类的应用上发展起来的，
 * 那么匿名内部类有那些作用呢
 */
interface A{
	public void printInfo();
}
/*class B implements A{
	public void printInfo() {
	}
}*/

class X{
	public void fun1() {
		this.fun2(new A(){
			public void PrintInfo() {
				System.out.println("Hello World");
			}
		});
	}
	public void fun2(A a) {
		a.printInfo();
	}
}

public class J1711094{
	public static void main(String args[]) {
		new X().fun1();
	}
}