/**
 * 在Java中支持对象的克隆操作,直接使用Object类中的clone()方法即可,方法定义如下:
 * protect Object clone() throws CloneNotSupportedException
 * 以上方法是受保护的类型,所以在子类中必须覆写此方法,而且在覆写之后应该扩大访问权限,这样才能
 * 被外部调用,但是具体的克隆方法的实现还是在Object中,所以在覆写的方法中只需要调用Object类中的
 * clone()方法即可完成操作,而且在对象所在的类中必须实现Cloneable接口才能完成对象的克隆操作
 * 但是如果直接查询JDK文档会发现Cloneable接口中并没有任何的方法定义,所以此接口在设计上称为是
 * 一种标识接口,标识对象可以被克隆.
 */
package dai.demo11.clonedemo;
class Person implements Cloneable{//必须时间Cloneable接口
    private String name = null;
    public Person(String name){
        this.name = name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getName() {
        return this.name;
    }
    // 需要子类覆写clone方法
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    public String toString(){
        return "姓名: " + this.getName();
    }
};

/**
 * CloneDemo01
 */
public class CloneDemo01 {

    public static void main(String[] args) throws Exception{
        Person p1 = new Person("张三");
        Person p2 = (Person) p1.clone();
        p2.setName("李四");
        System.out.println("原始对象: " + p1);
        System.out.println("克隆之后的对象: " + p2);
    }
}