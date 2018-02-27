/**
 * PetShop
 */
public class PetShop {
    private Pet[] pets;
    private int foot;
    public PetShop(int len) {
        if(len > 0)
        {
            this.pets = new Pet[len];
        }
        else
        {
            this.pets = new Pet[1];
        }
    }
    public boolean add(Pet pet) {
        if(this.foot < this.pets.length) //判断宠物商店里面的宠物是否已经满了
        {
            this.pets[this.foot] = pet;
            this.foot++;
            return true;
        }
        else
        {
            return false;
        }
    }
    public Pet[] search(String keyWord) { //关键字查找
        Pet p[] = null;
        int count = 0;
        for(int i = 0;i < this.pets.length;i++)
        {
            if(this.pets[i] != null)
            {
                if(this.pets[i].getName().indexOf(keyWord) != -1 || this.pets[i].getColor().indexOf(keyWord) !=  -1)
                {
                    count++;//统计符合条件的宠物个数
                }
            }
        }
        p = new Pet[count];
        int f = 0;//设置增加的位置标记
        for(int i = 0; i < this.pets.length;i++)
        {
            if(this.pets[i] != null)
            {
                if(this.pets[i].getName().indexOf(keyWord) != -1 || this.pets[i].getColor().indexOf(keyWord) !=  -1)
                {
                    p[f] = this.pets[i];
                    f++;
                }
            }
        }
        return p;
    }
}