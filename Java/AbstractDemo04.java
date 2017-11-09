/* 一个抽象类可以定义构造方法吗
 * 一个抽象类中是允许存在构造方法的，因为抽象类依然使用的是类的继承关系，而且抽象类也存在各个属性，所以
 * 子类在实例化之前必须先要对父类进行实例化
 */
abstract class Person{
	private String name;
	private int age;
	public Person(String name,int age) {
		this.setName(name);
		this.setAge(age);
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public int getAge() {
		return age;
	} 
	
	public void setAge(int age) {
		this.age = age;
	}
	
	public abstract String getInfo() ;
}

class Student extends Person
{
	private String school;
	public Student(String name,int age,String school) {
		super(name,age);
		this.setSchool(school);
	}
	
	public void setSchool(String school) {
		this.school = school;
	}
	
	public String getSchool() {
		return school;
	}
	
	public String getInfo() {
		return "姓名： " + super.getName() + " 年龄： " + super.getAge() + " 学校： " + this.getSchool();
	}
}

public class 1710191AbstractDemo04{
	public static void main(String args[]) {
		Student stu = new Student("张三", 30, "清华大学");
		System.out.println(stu.getInfo());
	}
}