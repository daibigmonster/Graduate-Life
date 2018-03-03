package dai.demo11.stringbufferdemo;
/**
 * StringBufferDemo01
 */
public class StringBufferDemo02 {

    public static void main(String[] args) {
        StringBuffer buf = new StringBuffer();
        buf.append("Hello ");
        fun(buf);
        System.out.println(buf);
    }
    public static void fun(StringBuffer s) {
        s.append("MLDN ").append("LiXingHua");
    }
}
/**
 * 从程序运行的记过可以发现,将StringBuffer对象的内容传递到了fun()方法之后
 * 对StringBuffer的内容进行修改,而且操作完毕后修改的内容将被保存下来,所以与String比较StringBuffer的内容是可以修改的
 */