public class Solution {
    public int JumpFloorII(int target) {
        if(target <= 1) return target;
        int res = (new Double(Math.pow(2.0, target - 1)).intValue());
        return res;
    }
}