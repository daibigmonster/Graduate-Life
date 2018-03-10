import java.util.Iterator;
import java.util.Stack;

public class Solution {

    Stack<Integer> data = new Stack<Integer>();
    Stack<Integer> minnum = new Stack<Integer>();
    public void push(int node) {
        data.push(node);
        if(minnum.size() == 0 || node < minnum.peek()) minnum.push(node);
        else minnum.push(minnum.peek());
    }
    
    public void pop() {
        data.pop();
        minnum.pop();
    }
    
    public int top() {
        return data.peek();
    }
    
    public int min() {
        return minnum.peek();
    }
}