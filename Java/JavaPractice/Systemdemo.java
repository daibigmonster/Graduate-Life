package dai.demo11.systemdemo;
/**
 * Systemdemo
 */
public class Systemdemo {

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        long sum = 0;
        for(int i = 0;i < 30000000 ; i++){
            sum += i;
        }
        System.out.println(sum);
        long endTime = System.currentTimeMillis();
        System.out.println("计算所花费的时间: " + (endTime - startTime) + "毫秒");
    }
}