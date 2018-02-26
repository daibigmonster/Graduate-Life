/**
 * J2602182
 */
/**
 * Person
 */
class Person {
    private String name;
    private int age;
    public Person(String name,int age) {
        this.name = name;
        this.age = age;
    }
    public String toString() { //此处覆写toString()方法
        return "姓名: " + this.name + ": 年龄:" + this.age;
    }
}
public class J2602182 {
    public static void main(String[] args) {
        Demo d = new Demo();
        Person per = new Person("李兴华",30);
        System.out.println("对象信息: " + per.toString());
    }
}