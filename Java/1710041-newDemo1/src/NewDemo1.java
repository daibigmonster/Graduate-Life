/**
 * 
 */

/**
 * @author daijian
 *
 */
public class NewDemo1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("不传递参数(fun()) : ");
		fun();
		System.out.print("\n传递一个参数(fun(1)) : ");
		fun(1);
		System.out.print("\n传递5个参数(fun(1,2,3,4,5)) : ");
		fun(1,2,3,4,5);
	}
	public static void fun(int... arg) {
		for(int i : arg)
			System.out.print(i + "、");
		
	}

}
