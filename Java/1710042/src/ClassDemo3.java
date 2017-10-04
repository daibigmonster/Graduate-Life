class Person {
	private String name;
	private int age;
	public void tell() {
		System.out.println("姓名： " + name + ", 年龄： " + age);
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
		if(a >= 0 && a<150)
			age = a;
	}
	
}

public class ClassDemo3 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person per1 = new Person();
		Person per2 = new Person();

		per1.setName("张三");
		per1.setAge(-1);
//		System.out.print("per1对象中的内容 --> ");
		per1.tell();
		
		per2.setName("李四");
		per2.setAge(33);
//		System.out.print("per2对象中的内容 --> ");
		per2.tell();
		
	}

}
