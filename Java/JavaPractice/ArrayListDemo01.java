package dai.demo13.listdemo;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
/**
 * ArrayListDemo01
 */
public class ArrayListDemo01 {

    public static void main(String[] args) {
        List<String> allList = null;
        // Collection<String> allCollection = null;
        allList = new ArrayList<String>();
        System.out.println("集合操作前是否为空? " + allList.isEmpty());
        allList.add("Hello");
        allList.add(0,"World");
        System.out.println(allList);
        // allCollection.add("Daijian");
        // allCollection.add("www.MD.com");
        // allList.addAll(allCollection);
        // allList.addAll(0,allCollection);
        allList.add("demo");
        allList.add("www");
        // allList.remove(0);
        allList.add("Daijian");
        String str[] = allList.toArray(new String[] {});
        System.out.print("指定数组类型: ");
        for(int i = 0;i < str.length;i++)
        {
            System.out.print(str[i] + ",");
        }
        System.out.print("\n回对象数组: ");
        Object obj[] = allList.toArray();
        for(int i = 0; i < obj.length;i++)
        {
            String temp = (String)obj[i];
            System.out.print(temp + ",");
        }
        System.out.println();
        System.out.println(allList);
        // System.out.println(allList.get(3));
    }
}
/**
 * 在Collection中定义了toArray()方法,此方法可以将集合变为对象
 * 数组,但是由于在类集声明时已经通过泛型指定了集合的元素类型,所以在接收时要使用泛型指定的类型
 */