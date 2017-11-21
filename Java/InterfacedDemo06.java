/*
 * 接口是Java中最重要的概念之一，他可以被理解为一种特殊的类，是由全局变量和公共的抽象方法组成
 * 接口的定义格式
 * interface 接口名称{
 *     全局变量；
 *     抽象方法；
 * }
 * 需要注意的是，在接口的抽象方法必须定义为public访问权限，这是绝对不可以改变的
 * 
 * 范例
 * interface A{
 *     public static final String AUTHOR = "daijian";
 *     public abstract void print();
 *     public abstract String getInfo();
 * }
 * 以上程序定义了一个接口，这里要提醒读者的是，在接口的基本概念中已经明确声明了接口是由全部变量和抽象方法组成的，所以
 * 此处的接口的定义可以简化成如下的形式：
 * interaface A{
 *     String AUTHOR = "daijian";
 *     void print();
 *     String getInfo();
 * }
 * 与抽象类一样，接口若要使用也必须通过子类，子类通过implements关键字来实现接口。
 * 格式 实现接口：
 * class 子类 implements 接口，接口，...{
 * }
 * 从格式6-4中可以清楚第发现，一个子类可以同时实现多个接口，那么这实际上就摆脱了Java的单继承局限   
 * 
 * 如果在开发中一个子类既要实现接口又要继承抽象类，则可以按照以下进行定义。
 * class 子类 extends 抽象类 implements 接口A，接口B，...{}
 * 
 * 在Java中一个接口是不允许继承抽象类的，但是允许一个接口继承多个接口
 */
interface A{
	public String AUTHOR = "daijian";
	public void printA();
}

interface B{
	public void printB();
}

interface C extends A,B{
	public void printC();
}

class X implements C{
	public void printA() {
		System.out.println("A、Hello World!!!");
	}
	public void printB() {
		System.out.println("B、Hello XXXX");
	}
	public void printC() {
		System.out.println("C、Hello XXXX");
	}
}

public class InterfacedDemo06{
	public static void main(String args[]) {
		X x = new X();
		x.printA();
		x.printB();
		x.printC();
	}
}
/*
 * 在以上程序中因为抽象类和接口本身都有抽象方法，所以实现类中必须覆写3个抽象方法。另外，在Java中是允许一个抽象类实现多个接口的
 */