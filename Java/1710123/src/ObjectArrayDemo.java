/*
 * 对象数组的概念本身并不复杂，所谓对象数组，就是指包含了一组相关的对象的数组，但是在对象数组的
 * 使用中读者必须要清楚一点：数组一定要先开辟空间，但是因为其实引用数据类型，所以数组中的每个
 * 对象都输null值，则在使用时数组中的每一个对象都必须进行实例化操作
 */
class Person{
	private String name;
	public Person(String name) {
		this.name = name;
	}
	public String getNmae() {
		return this.name;
	}
}
public class ObjectArrayDemo {
	public static void main(String args[]) {
		Person per[] = new Person[3];
//		对象数组初始化之前，每一个元素都是默认值
		System.out.println("===============数组声明==============");
		for(Person x : per) {
			System.out.print(x + "、");//输出实例化之前的元素
		}
		per[0] = new Person("张三");
		per[1] = new Person("李四");
		per[2] = new Person("王五");
		System.out.println();
		System.out.println("===============实例化对象==============");
		for(Person x : per) {
			System.out.print(x.getNmae() + "、");//输出实例化之后的元素
		}
		
	}
}
