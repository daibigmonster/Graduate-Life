import java.security.Principal;
import java.util.ArrayList;
class Solution {
    public ArrayList<Integer> printMatrix(int [][] matrix) {
       ArrayList<Integer> res = new ArrayList<Integer>();
       if(matrix == null || matrix.length == 0 || matrix[0].length == 0) return res;
       int row = matrix.length;
       int col = matrix[0].length;
       int circle = ((row < col ? row : col) - 1) / 2 + 1;
       return printMatrixInCircle(matrix,row,col,circle);
    }
    private ArrayList<Integer> printMatrixInCircle(int [][] matrix,int row,int col,int circle){
        ArrayList<Integer> res = new ArrayList<Integer>();
        for(int i = 0;i < circle;i++){
            for(int j = i; j < col - i;j++)res.add(matrix[i][j]);
            for(int k = i + 1;k < row - i;k++)res.add(matrix[k][col - 1 - i]);
            for(int m = col - i -2 ;(m >= i) && (row - i - 1 != i);m--)res.add(matrix[row - i - 1][m]);
            for(int n = row - i - 2;(n > i) && (col - i - 1 != i);n--)res.add(matrix[n][i]);
        }
        return res;
    }
}
/**
 * J19PrintMatrixInCircle
 */
public class J19PrintMatrixInCircle {

    public static void main(String[] args) {
        int [][] matrix = new int[][]{{1,2,3,4,5}};
        int col = matrix[0].length;
        int row = matrix.length;
        System.out.println(col + " " + row);
        // Solution ans = new Solution();
        // ArrayList<Integer> res = ans.printMatrix(matrix);
        // System.out.println(res);
    }
}