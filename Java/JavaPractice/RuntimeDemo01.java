package dai.demo11.runtimedemo;
/**
 * RuntimeDemo01
 * 在java中Runtime类表示运行时操作类,是一个封装了JVM进程的类,每一个JVM都对应着一个Runtime类
 * 的实例,此实例由JVM运行时为其实例化.所以在JDK文档中读者不会发现任何有关Runtime类中构造方法
 * 的定义.这是因为Runtime类本身的构造方法是私有化的,如果想取得
 */
public class RuntimeDemo01 {

    public static void main(String[] args) {
        Runtime run = Runtime.getRuntime();
        System.out.println("JVM最大内存量: " + run.maxMemory() );
        System.out.println("JVM空闲内存量: " + run.maxMemory() );
        String str = "Hello World!!!\t Welcome To daimonster's home";
        System.out.println(str);
        for(int x = 0;x < 1000;x++)
        {
            str += x;
        }
        System.out.println("操作String后,JVM空闲内存量: " + run.freeMemory());
        run.gc();
        System.out.println("垃圾回收后,JVM空闲内存量: " + run.freeMemory());
        
    }
}