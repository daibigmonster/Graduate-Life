/**
 * 此类可以对Object数组进行排序,但是要使用此方法排序也是有要求的,即对象所在的类必须实现Comparable接口,此接口就是用于指定对象排序队则的.
 * Comparable接口定义如下
 * public interface Comparetable<T>
 * {
 *     public int compareTo(T o);
 * }
 * 从上面定义中可以发现,在Comparable接口中也使用了java的泛型技术.其中只有一个compareTo方法,此方法返回一个int类型的数据,但是此int的值只能是一下三种
 * 1:表示大于
 * -1:表示小于
 * 0:表示相等
 * 
 * 现在要求设计一个学生类,此类包含姓名,年龄,成绩,并产生一个对象数组,要求成绩从高到低排序,如果成绩相等,则按年龄由低到高排序.
 */
package dai.demo11.comparable;
class Student implements Comparable<Student>{
    private String name;
    private int age;
    private float score;
    public Student(String name,int age,float score){
        this.name = name;
        this.age = age;
        this.score = score;
    }
    public String toString(){
        return name + "\t\t" + age + "\t\t" + score;
    }
    public int compareTo(Student stu){
        if(this.score > stu.score){
            return -1;
        } 
        else if(this.score < stu.score){
            return 1;
        }
        else {
            if(this.age > stu.age){
                return 1;
            }
            else if(this.age < stu.age){
                return -1;
            }
            else{
                return 0;
            }
        }
    }
};
/**
 * ComparableDemo01
 */
public class ComparableDemo01 {

    public static void main(String[] args) {
        Student stu[] = {new Student("张三", 20, 90.0f),new Student("李四", 22, 90.0f),new Student("王五", 20, 99.0f),new Student("赵六", 20, 70.0f),new Student("孙七", 22, 100.0f)};
        java.util.Arrays.sort(stu);
        for(int i = 0;i < stu.length;i++)
        {
            System.out.println(stu[i]);
        }
    }
}