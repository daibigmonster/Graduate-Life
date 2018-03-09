package dai.demo13.iteratordemo;
/**
 * 集合的输出
 * 迭代输出:Iterator
 * Iterator是专门的迭代输出接口,所谓的迭代输出就是讲元素一个个进行判断,判断其是否有内容
 * 如果有则吧内容取出
 * Iterator是一个接口,可以直接使用Collection接口中定义的Iterator()方法为其实例化.既然
 * Collection接口存在了此方法,则List和Set接口中也一定存在此方法,所以也同样可以使用Iterator
 * 接口输出.
 */
import java.util.ArrayList;
import java.util.*;
/**
 * IteratorDemo01
 */
public class IteratorDemo01 {

    public static void main(String[] args) {
        List<String> all = new ArrayList<String>();
        all.add("hello");
        all.add("_");
        all.add("world");
        Iterator<String> iter = all.iterator();

        while(iter.hasNext()){
            String str = iter.next();
            if("_".equals(str)){
                iter.remove();
            }
            else{
                System.out.print(str + " ");
            }
        }
        System.out.println("\n删除之后的集合: " + all);
    }
}
/**
 * 以上的输出代码是Iterator的标准操作形式,将集合中的内容一个个地循环输出.此种输出也是必须掌握的形式
 */