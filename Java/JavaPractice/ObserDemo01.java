/**
 * 在java中可以直接依靠Observable类和Observer接口轻松实现以上功能
 * 每一个观察者类都需要实现Observer接口,Observer接口定义如下:
 * public interface Observer{
 *     void update(Observable o,Object arg)
 * }
 */
package dai.demo11.obserdemo;
import java.util.*;

import com.sun.media.jfxmediaimpl.HostUtils;
class House extends Observable{
    private float price;
    public House(float price) {
        this.price = price;
    }
    public float getPrive() {
        return price;
    }
    public void setPrice(float price) {
        super.setChanged();
        super.notifyObservers(price);
        this.price = price;
    }
    public String toString() {
        return "房子的价格为: " + this.price;
    }
}
class HousePriceObserver implements Observer{
    private String name;
    public HousePriceObserver(String name){
        this.name = name;
    }
    public void update(Observable obj,Object arg) {
        if(arg instanceof Float){
            System.out.println(this.name + "观察到的价格更改为: ");
            System.out.println(((Float)arg).floatValue());
        }
    }
}
/**
 * ObserDemo01
 */
public class ObserDemo01 {

    public static void main(String[] args) {
        House h = new House(10000000);
        HousePriceObserver hpo1 = new HousePriceObserver("购房者A");
        HousePriceObserver hpo2 = new HousePriceObserver("购房者B");
        HousePriceObserver hpo3 = new HousePriceObserver("购房者C");
        h.addObserver(hpo1);
        h.addObserver(hpo2);
        h.addObserver(hpo3);
        System.out.println(h);
        h.setPrice(666666);
        System.out.println(h);
    }
}