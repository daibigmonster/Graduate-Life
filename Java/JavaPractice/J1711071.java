/*
 * 宠物商店
 * 设计一个宠物商店，在宠物商店中可以有多种（由用户决定数量）
 * 宠物，试表示出此种关系，并要求可以根据宠物的关键字查找到相应
 * 的宠物信息。所需要的宠物信息自行设计
 * 具体分析如下
 * 1本要求中提示宠物的信息可以自行设计，所以此时简单设计出名字
 * 、颜色、年龄3个属性
 * 2宠物的类别很多，如猫、狗等都属于宠物，所以宠物应该是一个标准
 * 3在宠物商店中，只要是符合了此宠物标准的就应该可以放进宠物商店
 * 中
 * 4宠物商店中要保存多种宠物，则肯定应该是一个宠物的对象数组，
 * 如果宠物的个数由用户决定，则应该在穿件宠物商店时，就已经分配好
 * 宠物的个数
 */

//宠物接口——pet.java
interface Pet{
	public String getName();
	public String getColor();
	public int getAge();
}

class Cat implements Pet{
	private String name;
	private String color;
	private int age;
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public int getAge() {
		return this.age;
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
	public Cat(String name,String color,int age) {
		this.setName(name);
		this.setColor(color);
		this.setAge(age);
	}
}

class Dog implements Pet{
	private String name;
	private String color;
	private int age;
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public int getAge() {
		return this.age;
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
	public Dog(String name,String color,int age) {
		this.setName(name);
		this.setColor(color);
		this.setAge(age);
	}
}

class PetShop{
	private Pet[] pets;
	private int foot;
	public PetShop(int len) {
		if(len > 0) {
			this.pets = new Pet[len];
		}
		else {
			this.pets = new Pet[1];
		}
	}
	
	public boolean add(Pet pet) {
		if(this.foot < this.pets.length) {
			this.pets[this.foot] = pet;
			this.foot++;
			return true;
		}
		else {
			return false;
		}
	}
	
	public Pet[] search(String keyWord) {
		Pet p[] = null;
		int count = 0;
		for(int i = 0;i < this.pets.length;i++) {
			if(this.pets[i] != null) {
				if(this.pets[i].getName().indexOf(keyWord) != -1
				  ||this.pets[i].getColor().indexOf(keyWord) != -1)
					count++;
			}
		}
		p = new Pet[count];
		int f = 0;
		for(int i = 0;i < this.pets.length;i++) {
			if(this.pets[i] != null) {
				if(this.pets[i].getName().indexOf(keyWord) != -1
					||this.pets[i].getName().indexOf(keyWord) != -1) {
					p[f] = this.pets[i];
					f++;
					}
			}
		}
		return p;
	}
};

public class J1711071{
	public static void main(String args[]) {
		PetShop ps = new PetShop(5);
		ps.add(new Cat("白猫","白色的",2));
		ps.add(new Cat("黑猫","黑色的",3));
		ps.add(new Cat("花猫","花色的",3));
		ps.add(new Cat("拉布拉多","黄色的",3));
		ps.add(new Cat("金毛","金色的",3));
		ps.add(new Cat("黄狗","黑色的",2));
		print(ps.search("黑"));
	}
	public static void print(Pet p[]) {
		for(int i = 0;i < p.length;i++) {
			if(p[i] != null) {
				System.out.println(p[i].getName() +
						"," + p[i].getColor() + ","
						+ p[i].getAge());
			}
		}
	}
}