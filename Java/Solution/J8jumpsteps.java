class Solution {
    public int JumpFloor(int n) {
        if(n <= 1) return n;
        int[] dp = new int[n + 10];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++ )
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
/**
 * J8jumpsteps
 */
public class J8jumpsteps {

    public static void main(String[] args) {
        Solution test = new Solution();
        System.out.println(test.JumpFloor(5));
    }
}