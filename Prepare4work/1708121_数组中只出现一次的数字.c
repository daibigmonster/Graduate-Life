/*题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次，请写程序找出这两个只出现一次的数字。要求时间复杂度是o(n),看哦昂键复杂度是O(1)
我们想到了异或运算的一个性质：任何一个数字异或它自己都等于0.也就是说，如果我们从头到为一次异或数组中的每一个数字，那么最终的结果刚好是只出现一次的数字，因为那些成对出现两次的数字全部在异或中抵消了。
我们试着把原数组分成两个子数组。使得每个子数组包含一个只出现一次的数字，而其他数字都成对出现两次。如果能够这样拆分成两个数组，我们就可以按照前面的办法分别找出两个只出现一次的数字了。
我们还是从头到尾一次异或数组中的每一个数字，那么最终得到的记过就是两个出处先一次的数字的异或结果。我们在结果数字中找到第一个为1的位的位置，记为第n位。现在我们以第n位是不是1为标准把原数组中的数字分成两个子数组，第一个子数组中每个数字的第n位都是1,而第二个子数组中每个数字的第n位都是0.由于我们分组的标准是数字中的某一位是1还是0,那么出现了两次的数字肯定被分配到同一个数字。因为两个相同的数字任意一位都是相同的。
举个例子，假设输入数组{2,4,3,6,3,2,5,5}。当我们一次对数组中的每一个数字做异或运算之后，得到的结果用二进制表示是0010.异或得到的结果中倒数第二位是1,于是我们根据数字的倒数第二位是不是1分为两个数组。第一个子数组{2,3,6,3,2}中所有数字的倒数第二位都是1,而第二个子数组{4,5,5}中所有数字的倒数第二位都是0.接下来第二个子数组{4,5,5}中所有数字的倒数第二位都是0.接下来只要分别对这两个子数组求异或，就能找出第一个子数组中值出现一次的数字是6,而第二个子树组中只出现一次的数字是4*/
void FindNumsAppearOnce(int data[],int length,int* num1,int* num2){
    if(data==NULL||length<2)return;
    int resultEXCLUsiveOR=0;
    for(int i=0;i<length;++i)
    resultExclusiveOR^=data[i];
    unsigned int indexOf1=FindFirstBitIS1(resultExclusiveOR);
    *num1=*num2=0;
    for(int j=0;j<lengtth;++j)
    {
        if(IsBit1(data[j],indexOf1))*num1^=data[j];
        else *num2^=data[j];
    }}
unsigned int FIndFirstBitIs1(int num)//给出第几位是1
{
    int indexBit=0;
    while(((num&1)==0)&&(indexBit<8*sizeof(int))){
        num=num>>1;
        ++indexBit;
    }
    return indexBit;
}
bool IsBit1(int num,unsigned int indexBit)//判断这一位是不是1
{
    num=num>>indexBit;
    return (num&1);
}
