/*统一的容器设计使得不同类型的容器之间具有明显关系。例如，可以使用copy()将常规数组中的值复制到vector对象中，将vector对象中的值复制到list对象中，将list对象中的值复制到set对象中.可以用==来比较不同类型的容器，如deque和vector。之所以能够这样做，是因为容器重载的==运算符使用迭代器来比较内容，因此如果deque和vector对象的内容相同，并且排列学列也相同，则它们是相等的。
STL将算法库分成4组：
非修改式序列操作
修改式序列操作
排序和相关操作
调用数字运算

非修改是序列操作对区间中的每个元素进行操作。这些操作不修该容器的内容。例如，find()和for_each()就术语这一类
修改式序列操作也对区间中的每个元素进行操作。然而，顾名思义，它们可以修改容器的内容。可以修改值，也可以修改值的排列顺序.tansform(),random_sheffle()和copy()属于这一类
排序和相关操作包括多个排序函数（包括sor(t)）和其他各种函数，包括集合操作。
数字操作包括将区间的内容累积、计算两个容器的内部成绩、计算小计、计算向另对象差的函数。通常，这些都是数组的操作特性，因此,vector是最有可能使用这些操作的容器

算法的通用特征
正如你多次看到的，STL函数使用迭代器和迭代器区间，从函数原型可知有关迭代器的假设。
copy()函数的原型如下：
template<class InputIterator,class OutputInterator>
OutputIterator copy(InputInterator first,InputIterator last,
                   OutputIterator result);
因为标识符InputIterator和OutputIterator都是模板参数，所以它们就像T和U一样。然而，STL文档使用模板参数名称来表示参数模型的概念。因此上述声明告诉我们，区间参数必须是输入迭代器或更高级的迭代器，而只是结果存储位置的迭代器必须是输出迭代器或更高级别的迭代器。
对算法进行分类的方式之一是按结果放置的位置进行分类。有些算法就地完成工作，有些则创建拷贝。例如，在sort()函数完成时，结果被存放在原始数据的位置上，因此,sort()是就地算法：而copy()函数将结果发送到另一个位置，所以它是复制算法。
有些算法由来嗯个版本：就地版本和复制版本。STL的约定是S，复制版本的名称将以_copy结尾。复制版本将接收一个额外的输出迭代器参数，该参数指定结果的放置位置。例如，函数replace()的原型如下：
template<class FoewardIterator,classT>
void replace(ForwardIterator first,ForwardIterator last,con T& old_value,const T& new_value);
它将所有的old_value替换为new_value,这就是就地发生的。由于这种算法同时读写容器元素，因此迭代器类型必须是ForwardIterator或者更高级别的。复制版本的原型如下
template<class InputIterator,clas OutputIterator,class T>
OutputIterator replace_copy(InputIterator first,InputIterator last,OutputIterator result,const T& old_calue,const T& new_value);
在这里，结果被复制到result指定的欣慰值，因此对于制定区间而言，只读输入迭代器足够了
replace_copy()的返回类型为OutputIterator.对于复制算法，统一的约定是：返回一个迭代器，该迭代器指向复制的最后一个值后面的一个位置。
另一个常见的变体是：有些函数右这样的版本，即根据将函数应用与容器元素得到的结果来执行操作，这些版本的名称通常以_if结尾。例如，如果将函数用于旧值时，返回的值为true，则replace_if()将把旧值替换为新的值，下面是该函数的原型
template<calss ForwardIterator,class Predicate class T>
void replace_if(ForwardIterator first,ForwardIterator last,Predicate pred,const T& new_value);
与InputIterator一样，Predicate也是模板参数名称，可以为T或U。然而，STL选择用Predicate来提醒用户，实参应模拟Predicate概念。注意，如果使用了错误的迭代器，则编译器试图实例化模板时，将显示大量的错误消息。

