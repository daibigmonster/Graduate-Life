package dai.demo11.comparable;
/**
 * ComparableDemo02
 */
class BinaryTree{
    //声明一个节点类
    class Node{
        private Comparable data;//保存具体内容
        private Node left;
        private Node right;
        public void addNode(Node newNode) {
            if(newNode.data.compareTo(this.data) < 0){//判断左子树还是右子树
                if(this.left == null){
                    this.left = newNode;
                }
                else{
                    this.left.addNode(newNode);
                }
            }
            if(newNode.data.compareTo(this.data) >= 0){
                if(this.right == null){
                    this.right = newNode;
                }
                else{
                    this.right.addNode(newNode);
                }
            }
        }
        public void printNode() {//输出的时候采用中序遍历
            if(this.left != null){//先输出左子树
                this.left.printNode();
            }
            System.out.print(this.data + "\t");
            if(this.right != null){
                this.right.printNode();
            }
        }
    };
    private Node root;
    public void add(Comparable data) {
        Node newNode = new Node(); //每传入一个新的内容就声明一个根节点
        newNode.data = data;
        if(root == null){
            root = newNode;//如果是第一个元素,设置成根元素
        }
        else
        {
            root.addNode(newNode);
        }
    }
    public void print() {
        this.root.printNode();
    }
}
public class ComparableDemo02 {

    public static void main(String[] args) {
        BinaryTree br = new BinaryTree();
        br.add(8);
        br.add(3);
        br.add(3);
        br.add(10);
        br.add(9);
        br.add(1);
        br.add(5);
        br.add(5);
        System.out.println("排序之后的结果: ");
        br.print();
    }
/**
 * 从上面的代码可以清楚地发现,Comparable接口通过对Integer对象实例化,然后直接输出Comparable接口对象时实际上调用的是Integer类中的toString()方法
 * ,此方法已经被Integer覆写了.下面的代码就将直接使用Comparable接口完成,输出时为了方便,也直接将Comparable接口打印.
 */
}