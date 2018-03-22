package dai.demo16.systemannotation;

/**
 *  @oerride 主要是在方法覆写时使用，用于保证方法覆写的正确性。
 */
class Person{
    public String getInfo(){
        return "这是一个student类.";
    }
}

class  Studnet extends Person{
    @Override
    public String getInfo() {
        return "这是一个Student类";
    }
}

public class OverrideAnnotationDemo01{
    public static void main(String[] args) {
        Person per = new Studnet();
        System.out.println(per.getInfo());
    }
}