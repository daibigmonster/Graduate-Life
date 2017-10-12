
class Person{
	private String name;
	private int age;
	public Person() {};
	public Person(String name) {
		this.setName(name);
	};
	public Person(String name,int age) {
		this.setName(name);
		this.setAge(age);
	}
	
//	显示类中的内容
	public void tell() {
		System.out.println("姓名: " + getName() + ",年龄：" + getAge());
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String n) {
		name = n;
	}
	
	public int getAge() {
		return age;
	}
	
	public void setAge(int a) {
		if(a >= 0 && a < 150)age = a;
	}
}

public class ConsDemo1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person per1 = new Person("张三",30);
		per1.tell();
		
		Person per2 = new Person("李四");
		per2.tell();
		
		new Person("王五",100).tell();
	}
}
