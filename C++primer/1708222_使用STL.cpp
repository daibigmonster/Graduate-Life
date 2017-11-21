/*STL是一个库，其组成部分被设计成协同工作。STL组件是工具，但也是创建其他工具的基本不见。我们用一个例子来活命。假设要编写一个程序，让用户输入单词。希望最后得到一个按输入排序顺序排列的单词列表，一个按字母排序的单词列表,一个按字母顺序排序的单词列表（忽略大小写），并记录每个单词被输入的次数。处于简化的目的，假设输入中不包含数字和标点符号。
输入和保存单词列表很简单
如何得到按字母顺序排列的单词列表呢？可以使用sort(),然后使用unique,但这种方法将覆盖遇上你是数据，因为sort()是就地算法。有一种更简单的方法：创建一个set<string>对象，然后将矢量中的单词复制（使用插入迭代器）到集合中。集合自动对其内容进行排序，因此无序调用sort():集合值允许使用同一键出现一次，因此无序调用unique().这里要求忽略大小写，处理这种方法之一是使用tansform()而不是copy(),将矢量中的数据复制到集合中。使用一个转换函数将字符串转换成小写形式
set<string> wordset;
transform(word.begin(),words.end(),insert_iterator<set<string> >(wordset,,wordset.begin()),ToLower);//transform将函数对象用于区间的每一个元素（或区间对中的每对元素），并将返回值复制到另一个区间的相应位置
ToLower()函数很容易编写，只需使用transform()将tolower()函数应用于字符串中的哥哥应用于字符串中的各个元素，并将字符串用作源和目标。记住，string对象也可以使用STL函数。将字符串引用传递和返回意味着算法不必复制字符串，而可以直接操作原始字符串。下面是函数ToLower()代码：
string & ToLower(string &st)
{
    transform(st.begin().st.end(),st.begin(),tolower);
    return st;
}
一个可能出现的问题是：tolower()函数被定义为int tolower(int),而一些编译器希望函数与元素类型(char)匹配。一种解决方法是，使用toLower代替tolower,并启动下面的定义：
	char toLower(char ch){return tolower(ch);}
