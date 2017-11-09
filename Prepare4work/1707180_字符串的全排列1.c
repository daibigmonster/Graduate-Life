/*问题
输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，则输出由字符a，b，c所能排列出来的所有字符串abc，acb，bac，bca，cab和cba
对于字符串的排列问题
如果能生成n-1个元素的全排列，就能生成n个元素的全排列，对于只有一个元素的集合，可以直接生成全排列。所以全排列的递归终止条件很明确，只有一个元素时。我们可以分析以下全排列的过程：
1.首先，我们固定第一个字符a，求后面两个字符bc的排列
2.当两个字符bc排列求好之后，我们把第一个字符和后面的b交换，得到bac，接着我们固定第一个字符b,求后面两个字符ac的排列
3.现在是把c放在第一个位置的时候了，但是记住前面我们已经把原先的第一个字符a和后面的b做了交换，为了保证这次c仍是和原先处在第一个位置的a交换，我们在拿c和第一个字符交换之前，要先把b和a交换回来。在交换b和a之后，再拿c和处于第一个位置的a进行交换，得到cba。我们再次固定第一个字符c，求后面两个字符b、a的排列
4既然我们已经直到怎么求三个字符的排列，那么固定第一个字符之后求后面两个字符的排列，就是典型的递归思路了。*/
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
struct seq
{
    char str[7];
}
struct seq seqs[721];
int count;
void swap(char *str,int a,int b)
{
    char temp;
    temp=str[a];
    str[a]=str[b];
    str[b]=temp;
}
void permutation_process(char *name,int begin,int end)
{
    int k;
    if(begin==end-1)
    {
       strcpy(seqs[count].str,name);
       count++;
    }
    else
    {
       for(k=begin;k<end;k++)
       {    swap(name,k,begin)
           permutatuin_process(name,begin+1,end)
           swap(name,k,begin);
       }
    }
}
int main()
{
    char name[7];
    int i,len;
    while(scanf())}
