package dai.demo11.arraydemo;


import java.util.*;

/**
 * ArraysDemo
 */
public class ArraysDemo {

    public static void main(String[] args) {
        int temp[] = {3,5,7,9,1,2,6,8};
        Arrays.sort(temp);
        System.out.println("排序后数组");
        System.out.println(Arrays.toString(temp));
        int point = Arrays.binarySearch(temp, 3);
        System.out.println("元素'3'的位置在: " + point );
        Arrays.fill(temp,3);
        System.out.print("数组填充: ");
        System.out.println(Arrays.toString(temp));

    }
}