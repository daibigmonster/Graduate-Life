class Singleton{
	static Singleton instance = new Singleton();
	private Singleton() {}//此处将构造方法进行封装
	public void print() {
		System.out.println("Hello World!");
	}
}
public class SingleDemo {
	public static void main(String args[]) {
		Singleton s1 = Singleton.instance;
		s1.print();
		Singleton s2 = Singleton.instance;
		s2.print();
		Singleton s3 = Singleton.instance;
		s3.print();
	}
}
//由运行结果可以发现，程序成功地取得可Singleton的实例化对象并调用了其中的print()方法。但这样做本身也存在着问题，因为类中的属性必须封装
//所以此处应该将instance属性进行封装，而封装之后必须通过方法取得，但因为instance属性属于静态属性，所以此处必须申明一个静态方法，这样就可以被类
//名称直接调用
