/*题目：0,1,...,n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。求出这个圆圈李剩下的最后一个数字*/

int LastRemaining(unsigned int n,unsigned int m)
{
    if(n<1||m<1)return -1;
    unsigned int i=0;
    list<int> numbers;
    for(int i=0;i<n;++i)numbers.push_back(i);
    list<int>::iterator current=numbers.begin();
    while(number>1){
        for(int i=1;i<m;++i){
            current++;
            if(current==numbers.end())
               current=numbers.begin();
        }
        auto next=++current;
        if(next==numbers.end())
            next=numbers.begin();
        --current;
        numbers.erase(current);
        current=next;
    }
    return *current;
}
/*更高效的算法
数字n,循环数字m
在这n个数字中，第一个被删除的数字是(m-1)%n.为了简单期间，我们把(m-1)%n计为k,那么删除k之后剩下的n-1个数字为0,1,...，k-1,k+1,...,n-1，并且下一次删除从数字k+1开始计数。相当于在剩下的序列中，k+1排在最前面，从而形成k+1,...,n-1,0,1,...k-1.该序列最后剩下的数字也应该是关于n和m的函数。有序这个序列的规律和前面最初的序列不一样（最初的序列是从0开始的连续序列），因此该函数不同于前面的函数，计为f'(n-1,m)。最初的序列最后剩下的数字f(n,m)一定是删除一个数字之后的序列最后剩下的数字，即f(n,m)=f'(n-1,m)。
*/
int LastRemaining(unsigned int n,unsigned int m)
{
    if(n<1||m<1)return -1;
    int last=0;
    for(int i=2;i<=n;i++)
        last=(last+m)%i;
    return last;
}
