class Person {
	private String name;
	private int age;
	private Book book;
	private Person child;
	public Person(String name,int age) {
		this.setName(name);
		this.setAge(age);
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
	public Book getBook() {
		return book;
	}
	public void setBook(Book b) {
		book = b;
	}
	public Person getChild() {
		return child;
	}
	public void setChild(Person child) {
		this.child = child;
	}
}
class Book{
	private String title;
	private float price;
	private Person person;
	public Book(String title,float price) {
		this.setTitle(title);
		this.setTitle(price);
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String t) {
		title = t;
	}
	public float getPrice() {
		return price;
	}
	public void setTitle(float p) {
		price = p;
	}
	public Person getPerson() {
		return person;
	}
	public void setPerson(Person p) {
		this.person = p;
	}
	
}
public class RefDemo05 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//实例化Person对象
		Person per = new Person("张三",30);
		//定义一个孩子
		Person cld = new Person("张草",10);
		Book bk = new Book("JAVA SE核心开发",90.0f);
		Book b = new Book("一千零一夜",30.3f);//定义孩子的书
		per.setBook(bk);//设置对象间的关系，一人有一本书
		bk.setPerson(per);//设置对象间的关系，一本书属于一个人
//		设置对象间的关系，一个孩子有一本书
		cld.setBook(b);
//		设置对象间的关系，一本书属于一个孩子
		b.setPerson(cld);
//		设置对象间的关系，一个人有一个孩子
		per.setChild(cld);
		System.out.println("从人找到书 --> 姓名： " + per.getName() + " 年龄： "
	+ per.getAge() + " 书名： " + per.getBook().getTitle() + " 价格: " + 
	 per.getBook().getPrice());
		System.out.println("从书找到人 --> 书名： " + per.getBook().getTitle() + " 价格："
+ per.getBook().getPrice() + " 姓名: " + per.getName() + " 年龄 ：" + per.getAge());		
//		通过人找到孩子，并找到孩子所拥有的书
		System.out.println(per.getName() + "的孩子 --> 姓名: "
				+ per.getChild().getName() + " 年龄: " + per.getChild().getAge()
				+ " 书名: " + per.getChild().getBook().getTitle() + " 价格: "
				+ per.getChild().getBook().getPrice());
	}

}
