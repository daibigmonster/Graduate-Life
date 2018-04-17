import java.util.*;
public class Solution {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k)
    {
        ArrayList<Integer> res = new ArrayList<Integer>();
        if(input.length <= 0 || k > input.length)return res;
        int length = input.length;
        int start = 0;
        int end = length - 1;
        int index = this.Partition(input,start,end);
        while (index != k-1){
            if(index > k - 1){
                end = index - 1;
                index = this.Partition(input,start,end);
            }
            else
            {
                start = index + 1;
                index = this.Partition(input,start,end);
            }
        }
        for(int i = 0;i < k;i++){
            res.add(input[i]);
        }
        return res;
    }

    private void swap(int [] input,int a,int b){
        int temp = input[a];
        input[a] = input[b];
        input[b] = temp;
    }

    private int Partition(int [] input,int start,int end){
        int key = input[start];
        while(start < end){
            while(key < input[end]) end--;
            this.swap(input,start,end);
            while (key >= input[start])start++;
            this.swap(input,start,end);
        }
        return start;
    }
}