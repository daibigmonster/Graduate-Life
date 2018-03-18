package dai.demo15.getclassdemo;
/**
 * 什么是反射机子呢？举个简单的例子来说，正常情况下如果已经有如果已经有一个类，
 * 则肯定可以通过类创建对象：那么如果现在要求通过一个对象找到一个类的名称，此时就需要
 * 用到反射机制。如果要完成反射操作，则首先应该认识的就是class类
 * @brief 通过一个对象得到一个完成的“包，类”名称
 */
class X{

}
/**
 * GetClassDemo01
 */
public class GetClassDemo01 {

    public static void main(String[] args) {
        X x = new X();
        System.out.println(x.getClass().getName());
    }
}


