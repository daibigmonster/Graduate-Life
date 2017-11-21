/*
 * 接口的实际应用
 * 接口是Java解决多继承局限的一种手段，而且从前面的内容读者也已经
 * 可以清楚可以通过对象的多态性为借口进行实例化，但是接口在实际中更多
 * 作用是用来制定标准，例如，U盘和丹印记都可以插在计算机上使用，
 * 这是因为他们都实现了USB的接口，对于计算机来说，只要是符合了USB
 * 接口标准的设备就都可以插进来
 * 下面的范例是USB标准
 */
interface USB{
	public void start();
    public void stop();		
}

class Computer{
	public static void plugin(USB usb) {
		usb.start();
		System.out.println("=======USB设备工作=======");
		usb.stop();
	}
};

class Flash implements USB {
	public void start() {
		System.out.println("U盘开始工作。");
	}
	public void stop() {
		System.out.println("U盘停止工作。");
	}
};

class Print implements USB {
	public void start() {
		System.out.println("打印机开始工作。");
	}
	public void stop() {
		System.out.println("打印机停止工作。");
	}
}

public class J1711051{
	public static void main(String[] args) {
		Computer.plugin(new Flash());
		Computer.plugin(new Print());
	}
}