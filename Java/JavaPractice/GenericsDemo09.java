/**
 * 如果一个类有多个属性需要使用不同的泛型声明,则可以在声明类时指定多个泛型类型
 */
package dai.demo10.genericsdemo;
class Notepad<K,V> {
    private K key;
    private V value;
    public K getKey() {
        return key;
    }
    public void setKey(K key) {
        this.key = key;
    }
    public V getValue() {
        return value;
    }
    public void setValue(V value) {
        this.value = value;
    }
};
/**
 * GenericsDemo09
 */
public class GenericsDemo09 {

    public static void main(String[] args) {
        Notepad<String,Integer> t = new Notepad<String,Integer>();
        t.setKey("戴涧");
        t.setValue(30);
        System.out.print("姓名: " + t.getKey());
        System.out.println(",年龄: " + t.getValue());
    }
}