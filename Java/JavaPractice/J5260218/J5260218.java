/**
 * J5260218
 * 通过以上代码可以发现,虽然接口不能继承一个类,但是依然是Object类的子类,因为接口本身是引用数据
 * 类型,所以可以进行向上转型工作.
 * 同理,也可以使Object接收一个数组,因为数组本身也是引用数据类型.
 */
public class J5260218 {

    public static void main(String[] args) {
        int temp[] = {1,3,5,7,9};
        Object obj = temp;
        print(obj);
    }
    public static void print(Object o) {
        if(o instanceof int[])
        {
            if(o instanceof int[])
            {
                int x[] = (int[])o;// 向下转型
                for(int i = 0;i < x.length;i++)
                {
                    System.out.println(x[i] + "\t");
                }
            }
        }
    }
}