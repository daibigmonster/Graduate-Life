class Person{
	private String name;
	private int age;
	public Person(String name,int age) {
		this.setName(name);
		this.setAge(age);
	}
	
	public boolean compare(Person per) {
//		调用此方法时里面存在两个对象：当前对象、传入的对象
		Person p1 = this;
		Person p2 = per;
		if(p1 == p2) {
			return true;
		}
//		分别判断每一个属性是否相等
		if(p1.name.equals(p2.name)&&p1.age == p2.age) {
			return true;
		}
		else return false;
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
		age = a;
	}
	
}
public class ThisDemo06 {
	public static void main(String[] args) {
		Person per1 = new Person("张三",30);
		Person per2 = new Person("张三",30);
		if(per1.compare(per2)) {
			System.out.println("两个对象相等！ ");
		}
		else System.out.println("两个对象不相等！ ");
	}
}
