package dai.demo15.instancedemo;
class Person{
    private String name;
    private int age;

    public String getName() {
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

    public String toString(){
        return "姓名：" + this.name + ", 年龄" + this.age;
    }
}
public class InstanceDemo01{
    public static void main(String[] args) {
        Class<?> c = null;
        try {
            c = Class.forName("dai.demo15.instancedemo.Person");
        }catch (ClassNotFoundException e){
            e.printStackTrace();
        }
        Person per = null;
        try{
            per = (Person) c.newInstance();
        }catch (Exception e){
            e.printStackTrace();
        }
        per.setName("李兴华");
        per.setAge(30);
        System.out.println(per);
    }
}