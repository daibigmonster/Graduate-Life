package dai.demo11.stringbufferdemo;
/**
 * StringBufferDemo04
 */
public class StringBufferDemo04 {

    public static void main(String[] args) {
        StringBuffer buf = new StringBuffer();
        buf.append("World!!!");
        buf.insert(0, "Hello ");
        StringBuffer buf2 = new StringBuffer(buf);
        StringBuffer buf3 = new StringBuffer(buf);
        String str = buf.reverse().toString();
        String str2 = buf2.replace(6, 11, "Daimonster").toString();
        String str3 = buf2.substring(6,16);
        System.out.println(str);
        System.out.println(str2);
        System.out.println(str3);
        if(buf3.indexOf("Hello ") == -1)
        {
            System.out.println("没有查找到指定的内容");
        }
        else
        {
            System.out.println("可以查找到指定的内容");
        }
    }
}