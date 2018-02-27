/**
 * A
 */
interface A {
    public void printInfo() ;
}

/**
 * x
 */
class x {
    public void fun1() {
        this.fun2(new A(){ // 匿名内部类
            public void printInfo() {
                System.out.println("Hello World!!!");                
            }
        });
    }
    public void fun2(A a) {
        a.printInfo();        
    }
}

/**
 * J1270218
 */
public class J1270218 {
    public static void main(String[] args) {
        new x().fun1();
    }
}