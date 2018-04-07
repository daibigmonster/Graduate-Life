import java.util.Arrays;
import java.util.Random;

class Solution{
    Random random = new Random();

    //产生随机数组
    int[] generateList(){
        int N = random.nextInt(100) + 5;
        System.out.printf("数组长度为%d\n",N);
        int[] a = new int[N];
        for(int i = 0;i < a.length;i++){
            a[i] = random.nextInt(1000);
        }
        return a;
    }

    // 判断数组是否升序
    boolean checkRight(int[] a){
        for(int i = 1; i < a.length ; i++){
            if(a[i] < a[i - 1]) return false;
        }
        return false;
    }

    // 交换函数
    private void swap(int [] num,int a,int b){
        int temp = num[a];
        num[a] = num[b];
        num[b] = temp;
    }

    //随机快排
    void quickSort(int [] numbers,int k){
        if(numbers.length <= 0) return;
        int start = 0;
        int end = numbers.length - 1;
        int index = Partition(numbers,start,end);
        //int x = random.nextInt(end - begin);
        int key = numbers[start];
        while(index != k - 1){
            if(index > k - 1){
                end = index - 1;
                index = Partition(numbers,start,end);
            }
            else{
                start = index + 1;
                index = Partition(numbers,start,end);
            }
        }
    }


    // 分块函数
    private int Partition(int [] numbers,int start,int end){
        int key = numbers[start];
        while(start < end){
            while(start < end && key < numbers[end]){
                end--;
            }
            swap(numbers,start,end);
            while(start < end && key >= numbers[start]){
                start++;
            }
            swap(numbers,start,end);
        }
        return start;
    }

    // 构造函数
    public void showACase(){
        int[] a = generateList();
        System.out.println("排序前的数组: ");
        System.out.println(Arrays.toString(a));
        quickSort(a,2);
        System.out.println("排序后的数组: ");
        System.out.println(Arrays.toString(a));
        for(int i = 0;i < a.length - 1;i++){
            if(checkRight(a)) break;
            quickSort(a,i + 1);
        }
        System.out.println("完全排序后的数组: ");
        System.out.println(Arrays.toString(a));
    }

}

public class QuickSort{
    public static void main(String[] args) {
        Solution test = new Solution();
        test.showACase();

    }

}