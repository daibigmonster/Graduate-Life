package dai.demo11.stringbufferdemo;
/**
 * StringBufferDemo03
 */
public class StringBufferDemo03 {

    public static void main(String[] args) {
        StringBuffer buf = new StringBuffer();
        buf.append("World!!!");
        buf.insert(0, "Hello ");
        System.out.println(buf);
        buf.insert(buf.length(), " to Diamonster ");
        System.out.println(buf);
    }
}