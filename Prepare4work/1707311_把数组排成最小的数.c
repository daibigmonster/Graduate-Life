/*题目：输入一个正整数数组，把数组里所有的数字拼接起来排成一个树，打印能拼接出的所有的数字中最小的一个。例如输入数组{3,32,321}，则打印出这3个数字能排成的最小数组321323
这个题目最直接的做法应该是先求出这个数组中所有数字的全排列，然后把每个排列拼接起来，然后求出拼起来的数字的最大值。
这道题其实是希望我们能找到一个排序规则，数组根据这个规则排序之后能拍成一个最小的数字。要确定排序规则，就要比较两个数字，也就是给出两个数字m和n，我们需要确定一个规则判断m和n哪个因该排在前面，而不是仅仅比较这两个数字的值那个更大
更具题目要求，两个数字m和n能拼接成数字mn和nm。如果mn<nm，那么我们应该打印出mn，也就是m应该排在n的前面*/
const int g_MaxNumberLength=10;
char* g_StrCombine1=new char[g_MaxNumberLength*2+1];
char* g_StrCombine2=new char[g_MaxNumberLength*2+1];
void PringtMinNumber(int* numbers,int length)
{
    if(numbers==NULL||length<=0)
        return;
    char** srNumbers=(char**)(new int[length]);
    for(int i=0;i<length;++i)
    {
        StrNumbers[i]==new char[g_MaxNumberLength+1];
        sprintf(strNumbres[i],"%d",numbers[i]);
    }
    qsort(strNumbers,length,sizeof(char*),compare);
    for(int i=0;i<length;++i)
        printf("%s",strNumbers[i]);
    printf("\n");
    for(int i=0;i<length;++i)
        delete[] strNumber[i];
    delete[] strNumber[i];
 }
 int comparre(const voide* strNumber1,const void* strNumber
 //这个代码的风格已经很老的了，不想继续敲下去了还是写个自己的代码
 string PrintMinNumber(vector<int> numbers) {
        int length=numbers.size();
        string str;
        vector<string> temp;
        if(length==0) return "";
        if(length==1) return to_string(numbers[0]);
        for(int i=0;i<length;++i)
            temp.push_back(to_string(numbers[i]));
        sort(temp.begin(),temp.end(),compare);
        for(int i=0;i<length;i++)
            str+=temp[i];
        return str;
    }
    static bool compare(string str1,string str2)
    {
        return (str1+str2)<(str2+str1);
    }
