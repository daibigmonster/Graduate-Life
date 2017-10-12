
class Demo {
	private int temp = 30;
	public void fun(Demo d2) {
		d2.temp = 50;
	}
	public int getTemp() {
		return temp;
	}
	public void setTemp(int t) {
		temp = t;
	}
}

public class TestJava0538 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Demo d1 = new Demo();
		System.out.println(d1.getTemp());
		d1.setTemp (50);
//		String str1 = "world";
//		String str2 = str1;
		System.out.println("fun()方法调用之前 " + d1.getTemp());
		d1.fun(d1);
		System.out.println("fun()方法调用之后 " + d1.getTemp());
	}
}


