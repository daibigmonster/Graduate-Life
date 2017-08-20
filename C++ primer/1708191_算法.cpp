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
因为标识符InputIterator和OutputIterator都是模板参数，所以它们就像T和U一样。然而，STL文档
