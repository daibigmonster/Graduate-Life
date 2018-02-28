import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {
        if(array.length == 0) return 0;
        int left = 0;
        int right = array.length - 1;
        int mid = 0;
        while(array[left] >= array[right]){
            if((right - left) == 1){
                mid = right;
                break;
            }
            mid = (left + right) / 2;
            if(array[left] == array[right] && array[mid] == array[left]){
                return this.min(array,left,right);
            }
            if(array[mid] >= array[right]) {
                left = mid;
            }
            if(array[mid] <= array[right]) {
                right = mid;
            }
        }
        return array[mid];
    }
    private int min(int[] array,int left,int right) {
        int res = array[left];
        for(int i = left + 1;i <= right;i++){
            if(res > array[i]) res = array[i];
        }
        return res;
    }
}