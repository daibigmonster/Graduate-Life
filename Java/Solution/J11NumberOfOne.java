import java.util.Scanner;

class Solution {
    public int NumberOf1(int n) {
        int num = 0;
        while(n != 0){
            n &= (n - 1);
            num++;
        }
        return num;
    }
}
/**
 * J10NumberOfOne
 */
public class J11NumberOfOne {
    public static void main(String[] args) {
        
        Scanner var = new Scanner(System.in);
        int num = var.nextInt();
        Solution res = new Solution();
        int result = res.NumberOf1(num);
        System.out.println(result);
    }
}