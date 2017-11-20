//题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//分析：我们可以找到一个判断序列是不是栈的弹出序列的规律：如果下一个弹出的数字刚好是栈顶数字，那么直接弹出。如果下一个弹出的数字不再栈顶，我们把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶位置。如果所有的数字都压入栈了仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列。
#include<iostream>
bool IsPopOrder(const int* pPush,const int* pPop,int nLength)
{
    bool bPossible=false;
    if(pPush!=NULL&&pPop!=NULL&&nLength>0)
    {
        const int* pNextpush=pPush;
        const int* pNextPop=pPop;
        std::stack<int> stackData;
        while(pNextPop-pPop<nLength)
        {
            while(stackData.empty()||stackData.top()!=*pNextPop)//如果下一个弹出的数字不再栈顶
            {
               if(pNextPush-pPush==nLength)
                   break;
               stackData.push(*pNextPush);
               pNextPush++;
            }
            if(stackData.top()!=*pNextPop)
                break;
            stackData.pop();
            pNextPop++;
        }
        if(stackData.empty()&&pNextPop-pPop==nLength)
            bPossible=true;
    }
    return bPossible;
}

//另外一种写法
bool IsPopOrder(vector<int> pushV,vector<int> popV)
{
    if(pushV.empty())return false;
    vector<int> stack;
    int i=0,j=0;
    while(i<pushV.size())
    {
        stack.push_back(pushV[i++]);
        while(j<popV.size()&&stack.back()==popV[j])
        {
            stack.pop_back();
            j++;
         }
     }
     return stack.empty();
}
