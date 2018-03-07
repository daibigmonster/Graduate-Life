class Info<T extends Number>{
    private T var;
    public T getVar() {
        return var;
    }
    public void SetVar(T var) {
        this.var = var;
    }
    public String toString() {
        return this.var.toString();
    }
};
/**
 * GenericsDemo27
 */
public class GenericsDemo27 {

    public static void main(String[] args) {
        Info<Integer> i = fun(30);
        System.out.println(i.getVar());
    }
    public static <T extends Number> Info<T> fun(T param) {
        Info<T> temp = new Info<T> ();
        temp.SetVar(param);
        return temp;
    }
}