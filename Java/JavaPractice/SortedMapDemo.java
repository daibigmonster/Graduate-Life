package dai.demo13.mapdemo;
import java.util.*;
/**
 * SortedMapDemo
 */
public class SortedMapDemo {

    public static void main(String[] args) {
        SortedMap<String,String> map = new TreeMap<String,String>();
        map.put("D,mldn","www.mldn.cn");
        map.put("A,qq","www.qq.com");
        map.put("C,baidu","www.baidu.com");
        map.put("B,ali","www.ali.com");
        System.out.print("第一个元素的内容的key: " + map.firstKey());
        System.out.println("; 对应的值: " + map.get(map.firstKey()));
        System.out.print("最后一个元素的内容的key: " + map.lastKey());
        System.out.println("; 对应的值: " + map.get(map.lastKey()));
        System.out.println("返回小于指定范围的集合");
        for(Map.Entry<String,String> me : map.headMap("D,mldn").entrySet()){
            System.out.println("\t|- " + me.getKey() + " --> " + me.getValue());
        }
        System.out.println("返回大于指定范围的集合");
        for(Map.Entry<String,String> me : map.tailMap("B,ali").entrySet()){
            System.out.println("\t|- " + me.getKey() + " --> " + me.getValue());
        }
    }
}