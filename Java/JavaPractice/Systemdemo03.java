package dai.demo11.systemdemo;
/**
 * Systemdemo03
 */
public class Systemdemo03 {

    public static void main(String[] args) {
        System.out.println("系统版本为: " + System.getProperty("os.name")
            + System.getProperty("os.version")
            + System.getProperty("os.arch"));
        System.out.println("系统用户为: " + System.getProperty("user.name"));
        System.out.println("当前用户目录: " + System.getProperty("user.home"));
        System.out.println("当前用户工作目录: " + System.getProperty("user.dir"));
    }
}