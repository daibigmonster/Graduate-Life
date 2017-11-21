/*abstract class A{
	public abstract void print();
};*/
interface A{
	public abstract void print() ;
}

class B implements A{
	public void print() {
		System.out.println("Hello World!!!");
	}
};

public class AbstractCaseDemo01{
	public static void main(String[] args) {
		A a = new B();
		a.print();
	}
}