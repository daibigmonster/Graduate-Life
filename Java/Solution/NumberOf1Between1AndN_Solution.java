public class NumberOf1Between1AndN_Solution {
    public int NumberOf1Between1AndN_Solution(int n) {
        if(n == 0) return 0;
        if(n <= 9) return 1;
        int length = LengthOfNum(n);
        int first = (int)(n / pow(n,length - 1));
        int firstcount = 0;
        if(first == 1){
            
        }
    }
    private int LengthOfNum(int n){
        int length = 1;
        while(n / 10 > 0){
            length++;
        }
        return length;
    }
}