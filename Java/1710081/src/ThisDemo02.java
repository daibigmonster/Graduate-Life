class Person{
	private String name;
	private int age;
//	无参构造
	public Person() {
		System.out.println("一个新的Person对象被实例化。");
	}
	public Person(String name,int age) {
//		在此处调用Person类中的无参构造方法
		this();
		this.name = name;
		this.age = age;
	}
	public String getInfo() {
		return "姓名: " + name + ", 年龄" + age;
	}
}
public class ThisDemo02 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		调用构造实例化对象
		Person per1 = new Person("张三",33);
//		取得信息
		System.out.println(per1.getInfo());
	}
}
