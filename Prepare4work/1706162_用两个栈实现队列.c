//题目：用两个栈来实现一个队列。队列的声明如下，请实现它的两个函数appdenTaol和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
template <typename T>class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    void appendTail(const T &node);//在队列末尾添加一个结点
    T deleteHead();//删除队列头结点
private
    stack<T> stack1;
    stack<T> stack2;
};
template <typename T> CQueue<T>:CQueue(void)
{}

template <typename T> CQueue<T>:~CQueue(void)
{}

template <typename T>void CQueue<T>::append(const T&element)
{
    stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
        while(stack1.size()>0)
        {
            T& data =stack1.top();
            stack1.pop();
            stack2.push(data);
         }
     }
     if(stack2.size()==0)
         throw new exception("队列为空！");
     T head=stack2.top();
     stack2.pop();
     return head;
}
}
