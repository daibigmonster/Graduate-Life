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
    public boolean equals(Object obj) {//覆写Object类中的equals()方法
        if(this == obj)
        {
            return true;
        }
        if(!(obj instanceof Person))//判断传经来的对象是否是Person的实例
        {
            return false;        
        }
        Person per = (Person)obj;//将传进来的对象向下转型
        if(per.name.equals(this.name) && per.age == this.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public String toString() { //此处覆写toString()方法
        return "姓名: " + this.name + ": 年龄:" + this.age;
    }
}
/**
 * J2602183
 */
public class J2602183 {
    public static void main(String[] args) {
        Person per1 = new Person("daijian", 29);
        Person per2 = new Person("daijian", 29);
        System.out.println(per1.equals(per2) ? "是同一个人!" : "不是同一个人!");
        System.out.println(per1.equals("Hello") ? "是同一个人!" : "不是同一个人!");
    }
}