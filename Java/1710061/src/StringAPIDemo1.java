
public class StringAPIDemo1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str1 = "hello D";
		char c[] = str1.toCharArray();//字符串变成字符数组
		for (char i : c)System.out.print(i + "\t");
		System.out.println();
		String str2 = new String(c);//将字符数组变为String
		String str3 = new String (c,0,3);
		System.out.println(str2);
		System.out.println(str3);
		System.out.println(str1.charAt(3));
		
		byte b[] = str1.getBytes();//将字符串变为byte数组
		System.out.println(new String(b));//将全部byte数组变为字符串
		System.out.println(str1.length());
		
		System.out.println(str1.indexOf("D"));
		
		String str4 = "       Hello world!     ";
		System.out.println(str4.trim());
		
		String str5 = "Welcome Daijian";
		System.out.println(str5.substring(4));
		System.out.println(str5.substring(1, 5).toUpperCase());
	}

}
