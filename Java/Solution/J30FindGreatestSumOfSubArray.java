public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if(array == null) return 0;
        int cursum = 0;
        int res = array[0];
        int length = array.length;
        for(int i = 0;i < length;i++){
            if(cursum <= 0) cursum = array[i];
            else cursum +=array[i];
            if(cursum > res) res = cursum; 
        }
        return res;
    }
}