public class Solution {
    public void reOrderArray(int [] array) {
        for(int i = 0;i < array.length;i++){
            for(int j = 0; j < array.length - 1 - i;j++){
                if(array[j] % 2 == 0 && array[j + 1] % 2 == 1){
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}