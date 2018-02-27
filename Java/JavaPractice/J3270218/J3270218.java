/*
 * 异常类的继承结构
 * 在整个Java的异常结构中，实际上有连个最常用的类，分别是Exception和Error,这两个类全都是Throwable的子类.
 * Exception: 一般表示的是程序中出现的问题,可以直接使用try...catch处理
 * Error: 一般指的是JVM错误,程序中无法处理
 * 
 * Java的异常处理机制
 * 在整个Java的异常处理中，实际上也是按照面向对象的方式进行处理，
 * 处理的步骤如下：
 * 1 一旦产生异常，则首先会产生一个异常类的实例化对象.
 * 2 在try语句中对此异常对象进行捕捉.
 * 3 产生的异常对象与catch语句中的各种异常类型进行匹配,如果匹配成功,则执行catch语句中的
 * 中的代码
 */
/**
 * J3270218
 */
public class J3270218{
	public static void main(String args[]) {
		System.out.println("*******计算开始********");
		int i = 0,j = 0;
		try {
			String str1 = args[0];
			String str2 = args[1];
			i = Integer.parseInt(str1);
			j = Integer.parseInt(str2);
			int temp = i / j;
			System.out.println("两个数字相除的结果:" + temp);
			System.out.println("-----------------------");
		}
		// catch(ArithmeticException e) {
		// 	System.out.println("算术异常: " + e);
		// }
		// catch(NumberFormatException e) {
		// 	System.out.println("数字转换异常: " + e);
		// }
		// catch(ArrayIndexOutOfBoundsException e) {
		// 	System.out.println("数组越界异常: " + e);
		// }
		// finally {
			// System.out.println("不管是否出现异常，都执行此代码");
		// }
		catch(Exception e)
		{
			System.out.println("异常:" + e);
		}
		System.out.println("*******计算结束********");
	}
}