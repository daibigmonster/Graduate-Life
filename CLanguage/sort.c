#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 用来给qsort调用，比较整型值
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int compare_integers(void const *a,void const *b){
    register int const *pa = a;
    register int const *pb = b;
    return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int main(){
    int *array;
    int n_values;
    int i;

    // 观察有多少个值
    printf("How many values are there? ");
    if(scanf("%d",&n_values) != 1 || n_values <= 0){
        printf("错误的数字！\n");
        exit(EXIT_FAILURE);
    }

    // 分配内存
    array = malloc(n_values * sizeof(int));
    if(array == NULL){
        printf("不能分配这么多的内存！\n");
        exit(EXIT_FAILURE);
    }

    // input the values
    for(int i = 0;i < n_values;i++){
        printf("? ");
        if(scanf("%d",&array[i]) != 1){
            printf("Error reading value #%d\n", i);
            free(array);
            exit(EXIT_FAILURE);
        }
    }

    // sort
    qsort(array,n_values,sizeof(int),compare_integers);

    // output the values
    for(int i = 0;i < n_values;i++) printf("%d\t",array[i]);
    printf("\n");

    // free the memory
    free(array);
    return EXIT_SUCCESS;
}