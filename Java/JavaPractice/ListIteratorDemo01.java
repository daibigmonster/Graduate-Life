package dai.demo13.iteratordemo;


import java.util.*;

import com.sun.crypto.provider.AESKeyGenerator;
/**
 * ListIteratorDemo01
 */
public class ListIteratorDemo01 {

    public static void main(String[] args) {
        List<String> all = new ArrayList<String>();
        all.add("hello");
        all.add("_");
        all.add("world");
        ListIterator<String> iter = all.listIterator();
        System.out.print("由前向后输出: ");
        while(iter.hasNext()){
            String str = iter.next();
            System.out.print(str + ", ");
        }
        System.out.print("\n由后向前输出: ");
        while (iter.hasPrevious()) {
            String str = iter.previous();
            System.out.print(str + ", ");
        }
    }
}