/*
 * 异常的基本概念
 * 异常是导致程序终端运行的一种指令流，如果不对异常进行正确的
 * 处理，则可能导致程序的终端执行，造成不必要的损失，所以在程序
 * 的设计中必须要考虑各种异常的发生，并正确地做好相应的处理，这样
 * 才能保证程序正常地执行。在Javazh0ong一切的异常都秉着面向对象的
 * 设计思想，所有的异常都以类和对象的形式存在，除了Java中已经提供的
 * 各种类之外，用户也可以根据需要定义自己的异常类
 * 
 *  为什么要异常处理
 *  在没有异常处理的语言中就必须使用判断语句，配合所想到的错误状况来
 *  捕捉程序中可能发生的错误。但为了捕捉这些错误，编写出来的代码经常
 *  有大量的判断语句，有事这样也未必能捕捉到所有的错误，而且这样做势必导致
 *  程序运行效率的降低
 *  Java的异常处理机制恰好改进了这一点。它具有易于使用、可自行定义异常类、处理
 *  抛出的异常同时又不会降低程序运行是的速度等有点。因而在Java程序设计时，应
 *  充分地利用Java的异常处理机制，以增进程序的稳定性及效率 
 */
public class J1711131{
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
		}catch(ArithmeticException e) {
			System.out.println("算术异常: " + e);
		}
		catch(NumberFormatException e) {
			System.out.println("数字转换异常: " + e);
		}
		catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("数组越界异常: " + e);
		}
/*		finally {
			System.out.println("不管是否出现异常，都执行此代码");
		}
*/		System.out.println("*******计算结束********");
	}
}