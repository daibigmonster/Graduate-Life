//题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O(1).
//在代码中，m_data是数据栈，而m_min是辅助栈 
#include<iostream>
template<typename T>
void StackWithMin<T>::push(const T&value)
{
    m_data.push(value);
    if(m_min.size()==0||value<m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}
template<typename T>void StackWithMin<T>::pop()
{
    assert(m_data.size()>0)&&m_min.size()>0);
    m_data.pop();
    m_min.pop();
}
template<typename T>const T& StackWithMin<T>::min() const
{
    assert(m_data.size()>0&&m_min.size()>0);
    return m_min.top();
 }

