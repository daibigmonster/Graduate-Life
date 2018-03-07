package dai.demo11.regexdemo;

import java.util.regex.Pattern;
/**
 * RegexDemo01
 */
public class RegexDemo01 {

    public static void main(String[] args) {
        String str = "1234567890";
        if(Pattern.compile("[0-9]+").matcher(str).matches()){
            System.out.println("是由数字组成! ");
        }
        else{
            System.out.println("不是由数字组成!");
        }
    }
}
// boolean flag = true;
// char c[] = str.toCharArray();
// for(int i = 0;i < c.length;i++)
// {
//     if(c[i] < '0' || c[i] > '9'){
//         flag = false;
//         break;
//     }
// }
// if(flag){
//     System.out.println("是由数字组成! ");
// }else{
//     System.out.println("不是由数字组成!");
// }