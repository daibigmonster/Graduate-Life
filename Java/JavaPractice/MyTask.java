package dai.demo11.task;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimerTask;
/**
 * MyTask
 */
public class MyTask extends TimerTask{
    public void run() {
        SimpleDateFormat sdf = null;
        sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS");
        System.out.println("当前系统时间为: " + sdf.format(new Date()));
    }
    
}