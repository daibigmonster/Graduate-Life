import java.util.Scanner;
import java.nio.file.Paths;

/**
 * J260218
 */ 
public class J260218 {
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner in = new Scanner(Paths.get("test.txt"));
        String str1 = in.nextLine();
        String str2 = in.nextLine();
        String str3 = in.next();
        System.out.println(str1);
        System.out.println(str2);
        System.out.println(str3);
    }
}