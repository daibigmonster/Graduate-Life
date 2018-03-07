/**
 * Timer类是一种线程设施,可以用来实现在某一个时间或某一段时间后安排某一个任务执行一次或定期重复执行.
 * 该功能要与TimeTask配饰使用.TimeTask类用来实现由Time类安排的一次或重复执行的某一个任务
 * 每一个Timer对象对应的是一个线程,因此计时器所执行的任务应该迅速完成,否则可能会延迟后续任务的执行,
 * 而这些后续的任务就有可能堆在一起,等到该任务完成后才能快速连续执行
 */
package dai.demo11.task;
import java.util.Timer;

import dai.demo11.task.MyTask;

/**
 * TimeTask
 */
public class TimeTask {

    public static void main(String[] args) {
        Timer t = new Timer();
        MyTask mytask = new MyTask();
        t.schedule(mytask, 1000, 2000);
    }
}