public class Solution {
    public String replaceSpace(StringBuffer str) {
        int spacenum = 0;
        for(int i = 0;i < str.length();i++)
        {
            if(str.charAt(i) == ' ')
            {
                spacenum++;
            }
        }
        int oldlength = str.length();
        int newlength = oldlength + spacenum * 2;
        int oldindex = oldlength - 1;
        int newindex = newlength - 1;
        str.setLength(newlength);
        for(;oldindex >= 0;oldindex--)
        {
            if(str.charAt(oldindex) == ' ')
            {
                str.setCharAt(newindex--,'0');
                str.setCharAt(newindex--,'2');
                str.setCharAt(newindex--,'%');
            }
            else
            {
                str.setCharAt(newindex--, str.charAt(oldindex));
            }
        }
        return str.toString();
    }
    
}