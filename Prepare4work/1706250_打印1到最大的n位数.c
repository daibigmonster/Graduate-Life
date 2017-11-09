//题目：输入数字n，按顺序打印出从1到最大的n位十进制数。比哦如输入3,则打印出1、2、3一直到最大的3位数即999.
bool Increment(char * number)
{
    bool isOverflow=false;
    int nTakeOver=0;
    int nLength=strlen(number);
    for(int i=nLength-1;i>=0;--i)
    {
        int nSum=number[i]-'0'+nTakeOver;
        if(i==nLength-1)
            nSum++;
        if(nSum>=10)
        {
            if(i==0)
                isOverflow=true;
            else
            {
                nSum-=10;
                nTakeOver=1;
                number[i]='0'+nSum;
            }
        }
        else{
            number[i]='0'+nSum;
            break;
        }      
    }
    return isOverflow;
}
void Print1tomaxofndigits(int n)
{
    if(n<=0)
        return;
    char *number=new char[n+1];
    memset(number,'0',n);
    number[n]='\0';
    while(!Increment(number))
    {
        PrintNumber(number);
    }
    delete[] number; 
}

//递归思路，如果我们在数字前面补0的话，就会发现n位所有的十进制数其实就是n个从0到9的全排列。也就是说，我们把数字的每一位都从0到9排列一遍，节能得到所有的十进制数。
void Print1ToMaxOfNdigits(int n)
{
    if(n<=0)return;
    char *number=new char(n+1);
    number[n]='\0';
    for(int i=0;i<10;++i)
    {
        number[0]=i+'0';
        Print1ToMaxofNDigitsRecursively(number,n,0);
     }
     delete[] number;
 }
void Print1ToNDigitsRecursively(char* number,int length,int index);
{
    if(index==length-1)
    {
        PrintNumber(number);
        return;
    }
    for(int i=0;i<10;++i)
    {
        number[index+1]=i+'0';
        Print1ToMaxofNDigitsRecursively(number,length,index+1);
    }
}
