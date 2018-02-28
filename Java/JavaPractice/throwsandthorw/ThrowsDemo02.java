/**
 * 
 * 与thorws不同的是,可以直接使用thorw抛出一个异常,抛出时直接抛出异常类的实例化对象
 * 即可
 * 学习了异常的处理格式、throw、throws关键字之后，读者可能会有这样的疑问，这些技术到底应该如何应用呢
*/

class Math
{
    public int div(int i,int j) throws Exception {
        System.out.println("******计算开始******");
        int temp = 0;
        try
        {
            temp = i / j;
        }
        catch(Exception e)
        {
            throw e;
        }
        finally
        {
            System.out.println("******计算结束******");
        }
        return temp;
    }
}
public class ThrowsDemo02 {
    public static void main(String[] args) {
        Math m = new Math();
        try
        {
            System.out.println("除法操作" + m.div(10,2));
        }
        catch(Exception e)
        {
            System.out.println("异常产生" + e);
        }
        // System.out.println("除法操作: " + m.div(10,2));
            
    }
}