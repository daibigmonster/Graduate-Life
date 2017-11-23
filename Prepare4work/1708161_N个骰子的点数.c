/*题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
我们可以考虑用来嗯个数组来存储骰子点数的每一个总数出现的次数。在一次循环中，第一个数组中的第n个数字表示骰子和为n出现的次数。在下一循环中，我们加上一个新的骰子，此时和为n的骰子出现的次数应该等于上一次循环骰子点数和为n-1、n-2、n-3、n-4、n-5、n-6的次数的总和，所以我们把另一个数组的第n个数字设为前一个数组对应的第n-1、n-2、n-3、n-4、n-5、n-6的次数之和，基于这个思路，我们可以写出如下代码：*/
void PrintProbability(int number){
    if(number<1)return;
    int * pProbabilities[2];
    pProbabilities[0]=new int[g_maxValue*number+1];
    pProbabilities[1]=new int[g_maxValue*number+1];
    for(int i=0;i<g_maxValue*number+1;++i)
    {
        pProbabilities[0][i]=0;
        pProbabilities[1][i]=0;
    }
    int flag=0;
    for(int i=1;i<=g_maxValue;++i)
        pProbabilities[flag][i]=1;
    for(int k=2;k<number;++k){
        for(int i=0;i<k;++i)
            pProbabilities[1-flag][i]=0;
        for(int i=k;i<=g_maxValue*k;++i){
            pProbabilities[1-flag][i]=0;
            for(int j=1;j<=i&&j<=g_maxValue;++j)
                probabilities[1-flag][i]+=pProbabilities[flag][i-j];}
            flag=1-flag;
        }
    double totoal=pow((double)g_maxValue,number);
    for(itn i=number;i<=g_maxValue*number;++i){
        double ratio=(double)pProbabilities[flag][i]/total;
        printf("%d:%e\n",i,ratio);
    }
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}
