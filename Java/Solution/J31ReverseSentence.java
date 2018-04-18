public class Solution {
    public String ReverseSentence(String str) {
        if(str == null) return null;
        if(str.trim().equals(""))return str;
        String res = "";
        String  [] strs = str.split(" ");
        for(int i = strs.length - 1;i >= 0;i--){
            res += strs[i] + " ";
        }
        return res.trim();
    }
}