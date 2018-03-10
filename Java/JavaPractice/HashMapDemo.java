/**
 * HashMap: 无需存放
 * TreeMap: 有序存放
 */
// 向集合增加和取出内容,在Map接口中使用put(Object key,Object value)
// 可以向集合中增加内筒,之后可以通过get(E key) 方法根据key找出其对应的value

package dai.demo13.mapdemo;
import java.security.Principal;
import java.util.*;

import javax.swing.plaf.basic.BasicTreeUI.TreeModelHandler;
/**
 * HashMapDemo
 */
class ListValues{
    private Set<String> keys;
    private Collection<String> values;
    public ListValues(Map<String,String> map) {
        Set<String> keys = map.keySet();
        Collection<String> values = map.values();
        this.keys = keys;
        this.values = values;
    }
    public void showValues(){
        Iterator<String> iterkey = this.keys.iterator();
        Iterator<String> itervalue = this.values.iterator();
        System.out.print("全部的key: ");
        while(iterkey.hasNext()){
            String str = iterkey.next();
            System.out.print(str + " ");
        }
        System.out.println();
        System.out.print("全部的value: ");
        while(itervalue.hasNext()){
            String str = itervalue.next();
            System.out.print(str + " ");
        }
        System.out.println();
    }
}
public class HashMapDemo {

    public static void main(String[] args) {
        Map<String,String> map = new HashMap<String,String>();
        map.put("daijian","tiancai");
        map.put("QQ","www.qq.com");
        map.put("baidu", "www.baidu.com");
        ListValues test = new ListValues(map);
        test.showValues();
        Map<String,String> treemap = new TreeMap<String,String>();
        treemap.put("1 daijian","tiancai");
        treemap.put("3 qq","www.qq.com");
        treemap.put("2 baidu","www.baidu.com");
        ListValues treetest = new ListValues(treemap);
        treetest.showValues();
    }
}
/**
 * 在Map中提供了一个叫做keySet()的方法,可以将一个Map中的全部key变为一个
 * set集合.但是在进行操作时一定要注意的是,接受的Set集合中指定的泛型要和Map
 * 中key的泛型类型保持一致
 */
