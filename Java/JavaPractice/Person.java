package dai.demo15;
interface China{
    public static final String NATIONAL = "China";
    public static final String AUTHOR = "Daijian";
    private void sayChina();
    public String sayHello(String name,int age);
}
public class Person implements China{
    private String name;
    private int age;
    public Person(){
    }

    public Person(String name){
        this.name = name;
    }

    public Person(String name,int age){
        this(name);
        this.setAge(age);
    }

    public int getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void sayChina(){
        System.out.println("作者: " + AUTHOR + ", 国籍" + NATIONAL);
    }

    @Override
    public String sayHello(String name, int age) {
        return name + ","
    }
}