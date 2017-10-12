class Demo{
	{
		System.out.println("1、构造块");
	}
//	运行的结果可以发信，静态代码块优先于主方法执行，而且在类中定义的静态代码块会先于构造块执行，而且
//	不管有多少个对象产生，静态代码块只执行一次
	static {
		System.out.println("Hello World!");
	}
	public Demo(){
		System.out.println("2、构造方法");
	}
}
public class CodeDemo {
	public static void main(String args[]) {
		new Demo();
		new Demo();
		new Demo();
	}
}
