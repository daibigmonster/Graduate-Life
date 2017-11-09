/* 
 * 工厂设计是Java开发中使用的最多的一种设计模式，那么什么叫工厂
 * 设计，工厂设计的作用都有那些？
 */
interface Fruit{
	public void eat();
}

class Apple implements Fruit{
	public void eat() {
		System.out.println("** 吃苹果");
	}
};

class Orange implements Fruit{
	public void eat() {
		System.out.println("** 吃橘子");
	}
};

class Factory{
	public static Fruit getInstance(String className){
		Fruit f = null;
		if("apple".equals(className)){
			f = new Apple();
		}
		if("orange".equals(className)){
			f = new Orange();
		}
		return f;
	}
}

public class J1711052 {
	public static void main(String[] args) {
		Fruit f = Factory.getInstance("apple");
		f.eat();
	}
}
/* 以上的程序相信读者都可以看明白，子类为借口实例化以后，调用被子类覆写过的方法，但是以上的
 * 操作中是否存在问题呢？前面曾静为读者将结果这样的一个注意事项：主方法实际上就是相当于一个
 * 客户端，如果此时需要更换一个子类，则必须要修改主方法，那么这实际上就存在了问题
 * 但对于这样的问题应该如何解决呢？在接口与具体子类之间可以加入一个过渡端，通过此过渡端
 * 来取得接口实例。
 */