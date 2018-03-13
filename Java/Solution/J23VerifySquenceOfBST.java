public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if(sequence.length == 0) return false;
        return Judge(sequence,0,sequence.length - 1);
    }
    private boolean Judge(int [] num,int start,int end){
        if(end <= start) return true;
        int midnum = start;
        for(;midnum < end;midnum++){
            if(num[midnum] > num[end]) break;
        }
        for(int i = midnum;i < end;i++){
            if(num[i] < num[end]) return false;
        }
        return Judge(num, start, midnum - 1) && Judge(num, midnum + 1,  end - 1);
    }
}