class Solution {
    public int MoreThanHalfNum_Solution(int [] numbers) {
        if(numbers.length <= 0) return 0;
        int length = numbers.length;
        int middle = length / 2;
        int start = 0;
        int end = length - 1;
        int index = Partition(numbers,start,end);
        while(index != middle){
            if(index < middle){
                start = index + 1;
                index = Partition(numbers,start,end);
            }
            else{
                end = index - 1;
                index = Partition(numbers,start,end);
            }
        }
        int result = numbers[middle];
        if(check(numbers,length,result) == false)result = 0;
        return result;
    }

    private  int Partition(int [] numbers,int start,int end){
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

    private void swap(int [] num,int a,int b){
        int temp = num[a];
        num[a] = num[b];
        num[b] = temp;
    }

    private boolean check(int [] numbers,int length,int result){
        int times = 0;
        for(int i = 0;i < length;i++){
            if(numbers[i] == result){
                    times++;
            }
        }
        boolean MoreThanHalf = true;
        if(times*2 <= length)MoreThanHalf = false;
        return  MoreThanHalf;
    }
}

public class J28MoreThanHalfNum_Solution{
    public static void main(String[] args) {
        Solution test = new Solution();
        int [] array = {1,2,3,2,2,2,5,4,2};
        int res = test.MoreThanHalfNum_Solution(array);
        System.out.println(res);
    }
}