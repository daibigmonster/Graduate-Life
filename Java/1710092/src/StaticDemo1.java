class Person{
	private String name;
	private int age;
	private static String country = "A城";
	public Person(String name,int age) {
		this.name = name;
		this.age = age;
	}
	public void info() {
		System.out.println("姓名" + this.name + "，年龄： " + this.age 
				+"，城市： "  + country);
	}
	public static String getCountry() {
		return country;
	}
	public static void setCountry(String c) {
		country = c;
	}
}
public class StaticDemo1 {
	public static void main(String args[]) {
		Person p1 = new Person("张三",30);
		Person p2 = new Person("李四",30);
		Person p3 = new Person("王五",30);
		System.out.println("-----------修改前------------");
		p1.info();
		p2.info();
		p3.info();
		System.out.println("-----------修改后------------");
		p1.setCountry("B城");
		p1.info();
		p2.info();
		p3.info();
	}
}
