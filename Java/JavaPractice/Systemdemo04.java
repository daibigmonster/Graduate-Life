/**
 * 此处讲解的是如何对一个对象进行回收,一个对象如果不在被任何栈内所引用,那么此对象就可以称为
 * 垃圾对象,等待被回收.实际上等待的时间是不确定的,所以可以直接调用System.gc()方法进行垃圾
 * 的回收.
 * 如果在一个对象被回收之前要进行某些操作该怎么办呢?实际上在Object类中有一个finalize()方法
 * protected void finalize() throws Throwable
 * 一个子类只需要覆写此方法即可在师范对象前进行某些操作.
 */

package dai.demo11.systemdemo;


class Person{
    private String name;
    private int age;
    public Person(String name,int age) {
        this.name = name;
        this.age = age;
    }
    public String toString() {
        return "姓名: " + this.name + ", 年龄: " + this.age;
    }
    protected void finalize() throws Throwable {
        System.out.println("对象被释放 --> " + this.toString());
    }
}

/**
 * Systemdemo04
 */
public class Systemdemo04 {

    public static void main(String[] args) {
        Person per = new Person("张三",30);
        per = null;
        System.gc();
    }
}