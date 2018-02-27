/**
 * Dog
 */
class Dog implements Pet {
    private String name;
    private String color;
    private int age;
    public Dog(String name,String color,int age) {
        this.setName(name);
        this.setColor(color);
        this.setAge(age);
    }
    public String getName(){
        return this.name;
    }
    public int getAge() {
        return this.age;
    }
    public String getColor() {
        return this.color;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setColor(String color) {
        this.color = color;
    }
    public void setAge(int age) {
        this.age = age;
    }
}