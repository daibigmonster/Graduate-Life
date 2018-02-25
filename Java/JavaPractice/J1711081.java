/* Object类
 * 在Java中所有的类都有一个公共的父类，一个类只要没有明显地继承
 * 一个类，则肯定是Object类的子类
 * 对于一个良好设计的类来说，最好覆写Object类中的equals,hasCode,toString
 * 三个方法。
 */
class Person{
	private String name;
	private int age;
	public Person(String name,int age){
		this.name = name;
		this.age = age;
	}
	public boolean equals(Object obj){
		if(this == obj)return true;
		if(!(obj instanceof Person))return false;
		Person per = (Person)obj;
		if(per.name.equals(this.name) && per.age == this.age){
			return true;
		}
		else {
			return false;
		}
	}
	public String toString() {
		return "姓名： " + this.name + " 年龄： " + this.age;
	}
}
public class J1711081{
	public static void main(String args[]) {
		Person per1 = new Person("Daijian",28);
		Person per2 = new Person("Daijian",28);
		System.out.println(per1.equals(per2) ? "是同一个人" :
			"不是同一个人");
		System.out.println(per1.equals("hello") ? "是同一个人" :
				"不是同一个人");
	}
}