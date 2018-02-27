/**
 * throws 关键字
 * 在定义一个方法是可以使用throws关键字声明,使用throws声明的昂发表示此方法不处理异常,
 * 而交给方法的调用处理进行处理
 */

class Math
{
    public int div(int i,int j) throws Exception {
        int temp = i / j;
        return temp;
    }
}
public class ThrowsDemo01 {
    public static void main(String[] args) throws Exception{
        Math m = new Math();
        // try
        // {
        //     System.out.println("除法操作: " + m.div(10,2));
        // }
        // catch(Exception e)
        // {
            //     e.printStackTrace();
            // }
        System.out.println("除法操作: " + m.div(10,2));
            
    }
}