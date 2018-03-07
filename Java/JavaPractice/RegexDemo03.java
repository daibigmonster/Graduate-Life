package dai.demo11.regexdemo;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

// import com.sun.org.apache.xalan.internal.xsltc.compiler.Pattern;
/**
 * RegexDemo03
 */
public class RegexDemo03 {

    public static void main(String[] args) {
        String str = "A1B22C333D4444E55555F".replace("\\d+", "_");
        boolean temp = "1983-07-27".matches("\\d{4}-\\d{2}-\\d{2}");
        String s1[] = "A1B22C333D4444E55555F".split("\\d+");
        String info = "LXH:98|MLDN:90|LI:100";
        String s2[] = info.split("\\|");
        System.out.println(str);
        System.out.println(temp);
        for(int x = 0;x < s1.length;x++)
        {
            System.out.print(s1[x] + "\t");
        }
        System.out.println();
        System.out.println("字符串拆分: ");
        for(int x = 0;x < s2.length;x++)
        {
            String s3[] = s2[x].split(":");
            System.out.println(s3[0] + s3[1]);
        }
        // String pat = "\\d+";
        // Pattern p = Pattern.compile(pat);
        // String s[] = p.split(str);
        // if(m.matches())
        // {
        //     System.out.println("合规!");
        // }
        // else
        // {
        //     System.out.println("不合规!");
        // }
    }
}