package dai.Demo01;//加入包只是让类的管理更方便
/**
 * Demo
 */
public class Demo {
    public String getInfo() {
        return "Hello World!!!";
    }
}

/**
 * PackageDemo01
 */
public class PackageDemo01 {

    public static void main(String[] args) {
        System.out.println(new Demo().getInfo());
    }
}