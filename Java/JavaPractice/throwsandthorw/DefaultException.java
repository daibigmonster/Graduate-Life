/**
 * MyException
 */
class MyException extends Exception { //自定义异常类,继承exception类
    public MyException(String msg) {
        super(msg);
    }
}

/**
 * DefaultException
 */
public class DefaultException {

    public static void main(String[] args) {
        try {
            throw new MyException("自定义异常.");//抛出异常
        } catch (Exception e) {
            //TODO: handle exception
            System.out.println(e);
        }
    }
}