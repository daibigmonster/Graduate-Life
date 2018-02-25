/*
 * 既然Object类是所有对象的父类，则所有的对象都可以向
 * Object进行转换，在这其中也包含了数组和接口类型，即一切的引用
 * 数据都已使用Object进行接收
 */
interface A{
	public String getInfo();
}

class B implements A{
	public String getInfo() {
		return "Hello World!!!!";
	}
}

public class J1711092{
	public static void main(String args[]) {
		A a = new B();
		Object obj = a;
		System.out.println(a.getInfo());
		A x = (A)obj;
		System.out.println(x.getInfo());
		int temp[] = {1,3,5,7,9};
		Object O = temp;
		print(O);
	}
	public static void print(Object o) {
		if(o instanceof int[]) {
			int x[] = (int [])o;
			for(int i : x) {
				System.out.print(i + "\t");
			}
		}
	}
}
/*
 * 通过上面的代码就可以发现，虽然接口不能集成一个类，但依然是Ob
 * ject类的子类，因为接口本身是引用数据类型，所以可以进行向上
 * 转型工作
 * 同理，也可以使用Object接收一个数组，因为数组本身也是引用数据
 * 类型
 * 
 * Object类可以接收任意的引用数据类型，所以在很多的类库设计上
 * 都采用Object方法的参数，这样操作起来会比较方便。
 */