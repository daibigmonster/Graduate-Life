/*
 * 前面对类的继承进行了初步的讲解，通过继承可以从原有的类派生出新的类。
 * 除了上述的机制之外，在Java中也可以创建一种类专门用来当做父类，这种累称为“抽象类”。抽象类的作用类似“模板”，其目的是
 * 要设计者根据它的格式来修改并穿件新的类。但是并不错直接有抽象类创建对象，只能通过抽象类派生出新的类，在由它来创建对象。
 * 但是在抽象类的使用中童颜存在单继承的局限，一个子类只能继承一个抽象类
 * 
 * 抽象类的定义及使用规则如下
 * 包含一个抽象方法的类必须是抽象类
 * 抽象类和抽象方法都要使用abstract关键字申明
 * 抽象方法只需声明而不需要实现
 * 抽象类必须被子继承，子类（如果不是抽象类）必须覆写抽象类中的全部抽象方法
 * 
 */
abstract class A{
	public static final String FLAG = "CHINA";
	private String name = "戴涧";
	
	public String getnName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public abstract void print();
}

class B extends A{
	public void print() {
		System.out.println("FLAG = " + FLAG);
		System.out.println("姓名 = " + super.getnName());
	}
}

public class AbstractDemo02{
	public static void main(String args[]) {
		B b = new B();
		b.print();
	}
}
