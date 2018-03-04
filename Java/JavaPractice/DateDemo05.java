package dai.demo11.datedemo;
import java.text.*;
import java.util.Date;

/**
 * DateDemo05
 * 获得完整的日期
 */
class DateTime{
    // 声明日期格式化操作对象,直接对new Date()进行实例化
    private SimpleDateFormat  sdf = null;
    // 得到完整的日期,格式为: yyyy-MM-dd HH:dd:ss.SSS
    public String getDate() {
        this.sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
        return this.sdf.format(new Date());
    }
    // 得到完整的日期,格式为: yyyy年MM月dd日 HH时mm分ss秒SSS毫秒
    public String getDateComplete() {
        this.sdf = new SimpleDateFormat("yyyy年MM月dd日 HH时mm分ss秒SSS毫秒");
        return this.sdf.format(new Date());
    }
    // 得到时间戳
    public String getTimeStamp() {
        this.sdf = new SimpleDateFormat("yyyyMMddHHmmssSSS");
        return this.sdf.format(new Date());
        
    }


}
public class DateDemo05 {
    public static void main(String[] args) {
        DateTime dt = new DateTime();
        System.out.println("系统日期: " + dt.getDate());
        System.out.println("中文日期: " + dt.getDateComplete());
        System.out.println("时间戳: " + dt.getTimeStamp());
    }
    
}