package dai.demo13.iteratordemo;
import java.util.*;
/**
 * IteratorDemo04
 */
public class IteratorDemo04 {

    public static void main(String[] args) {
        Map<String,String> map = new HashMap<String,String>();
        map.put("mldn","www.mldn.cn");
        map.put("qq","www.qq.com");
        map.put("baidu","www.baidu.com");
        // Set<Map.Entry<String,String>> allset = map.entrySet();
        // Iterator<Map.Entry<String,String>> iter = null;
        // iter = allset.iterator();
        // while(iter.hasNext()){
        //     Map.Entry<String,String> me = iter.next();
        //     System.out.println(me.getKey() + "-->" + me.getValue());
        for(Map.Entry<String,String> me : map.entrySet()){
            System.out.println(me.getKey() + "--->" + me.getValue());
        }
        // }
    }
}