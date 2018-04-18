import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Solution {
    public String PrintMinNumber(int [] numbers) {
        if(numbers == null || numbers.length == 0) return "";
        int len = numbers.length;
        ArrayList<String > list=new ArrayList<String >();
        StringBuilder sb = new StringBuilder();

        // 将numbers中的数字转化为数组
        for (int i = 0; i < len; i++) {
            list.add(String.valueOf(numbers[i]));
        }

        // 实现Compare接口的compare方法,将集合按照compare方法的规则进行派苏
        Collections.sort(list,new Comparator<String>(){
            @Override
            public int compare(String s1,String s2){
                String c1 = s1 + s2;
                String c2 = s2 + s1;
                return c1.compareTo(c2);
            }
        });
        for (int i = 0; i < len; i++) {
            sb.append(list.get(i));
        }
        return sb.toString();
    }
}