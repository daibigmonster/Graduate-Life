/*不同的算法对迭代器的要求也不同，例如，查找算法需要定义++运算符，以便迭代器能够遍历整个容器;它要求能够读取数据但不要求能写数据（它只是查看数据，而并不修改数据）。而排序算法要求能够随机访问，以便迭代器能够遍历整个容器。如果iter是一个迭代器，则可以通过+运算符来实现随即访问，这样就可以使用像iter+10这样的表达式了。另外，排序算法要求能够读写数据。
STL定义了5中迭代器，并根据所需的迭代器类型对算法进行了描述。这5中迭代器分别是输入迭代器、输出迭代器、正向迭代器、双向迭代器和随机访问迭代器。
输入迭代器
术语输入是从程序的角度来说的，即来自容器的信息被视为输入。因此，输入迭代器可被程序用来读取容器中的信息。输入迭代器的算法将不会修改容器中的值。
基于输入迭代器的任何算法都应当是单通行的，不依赖与前一次遍历时迭代器的值，也不依赖于本次遍历中前面的迭代器的值。
注意输入迭代器是单向迭代器，可以递增，但不能倒退。
输出迭代器
简而言之，对于单通行、只读算法，可以使用输入迭代器;而对于单通行、只写算法，则可以使用输出迭代器
正向迭代器
与输入迭代器和输出迭代器相似，正向迭代器只使用++运算符来遍历容器，所以它每次沿容器向前移动一个元素;然而，与输入和输出迭代器不同的是，它总是按相同的顺序遍历一系列值。另外，将正向迭代器递增之后，仍然可以对前面的迭代器值接触引用（如果保存了它），并可以得到相同的值
STL sort()函数接收指向容器第一个元素的迭代器和指向超尾的迭代器作为参数。&Receipts[0](或Receipts)是第一个元素的地址，&Receipts[SIZE]（或Receipts+SIZE）是数组最后一个元素后面的元素的地址。因此，下面的函数调用对数组进行排序：
sort(Receipts,Receipts_SIZE);
C++确保了表达式Receipts+n是被定义的，只要该表达式的结果位于数组中。因此，C++支持将超尾改用用于数组，使得可以将STL算法用于常规数组。
int cast[10]={6,7,2,3,1,2,3,1,2,3}
vector<int> dice[10];
copy(cast,cast+10,dice.begin())
copy()的前两个迭代器参数表示要复制的范围，最后一个迭代器参数表示要将第一个元素复制到什么位置。前两个参数必须是（或最好是）输入迭代器，最后一个参数最好是输出迭代器。copy()函数将覆盖目标容器中已有的数据，同时目标容器必须足够大，以便能够容纳被复制的元素。因此，不能将使用copy()将数据放到空矢量中。
现在假设要将信息复制到显示器上。如果由一个表示输出流的迭代器。则可以使用copy().STL为这种迭代器提供了ostream_iterator模板。用STL的话说，该模板是输出迭代器概念的一个模型。可以通过包含头文件iterator并做以下声明来创建这种迭代器
#include<itrator>
ostream_iterator<int,char>out_iter(cout," ");
copy(dice.begin(),dice.end(),out_iter);
这意味着将dice容器的整个区间复制到输出流中，即显示容器的内容。
也可以不创建命名的迭代器，而直接构建一个匿名迭代器。即这样使用适配器：
copy(dice.begin(),dice.end(),ostream_iterator<int,char>(cout," "));
iterator头文件还定义了istream_iterator,是istream输入可用作迭代器接口，它是一个输入迭代器，可以使用两个istream_iterator对象来定义copy()的输入范围：
copy(istream_iterator<int,char>(cin),istream<int,char>(),dice.begin());
与ostream_iterator相似，istream_iterator也使用来嗯个模板参数，第一个参数指出要读取的数据类型，第二个参数指出输入流使用的字符类型。使用构造函数参数cin移位这使用cin管理的输入流，省略构造函数表述输入失败，因此上述代码从输入流中读取，直到文件结尾、类型不匹配或出现其他输入故障为止。
其他有用的迭代器
现在假设要反向打印容器的内容。vector类由一个名为rebing()的成员函数和一个名为rend(),前者返回一个指向超尾的反向迭代器，后者返回一个指向第一个元素的反向迭代器。因为对迭代器执行递增操作将导致它被递减，可以使用下面的语句来返回显示内容：
copy(dice.rbegin(),dice.end(),out_iter);
甚至不必声明反向迭代器。
必须对反向指针做一种特殊补偿。假设rp是一个辈出实话为dice.rbegin()的反转指针。那么*rp是什么呢？因为rbegin（）返回超尾，因此不能对该地址进行解除引用。同样，如果rend()是第一个元素的位置,则copy()必须提早一个位置停止，因为因为区间的结尾处不包括在区间中。
反向指针通过递减，在接触引用解决了这两个问题。即*rp将在*RP的当前值之前对迭代器执行接触引用。也就是说，如果rp指向位置6,则*rp将是位置5的值*/
#include <iostream>
#include<iterator>
#include<vector>
int main()
{
    using namespace std;
    int casts[10]={6,7,2,9,4,11,8,7,10,5};
    vector<int> dice(10);
    copy(casts,casts+10,dice.begin());
    cout<<"Let the dice be cast!\n";
    ostream_iterator<int,char> out_iter(cout," ");
    copy(dice.begin(),dice.end(),out_iter);
    cout<<endl;
    
    cout<<"Implicit use of reverse iterator.\n";
    copy(dice.rbegin(),dice.rend(),out_iter);
    cout<<endl;
    
    cout<<"Exp;icit use of reverse iterator.\n";
    vector<int>::reverse_iterator ri;
    for(ri=dice.rbegin();ri!=dice.rend();++ri)
        cout<<*ri<<' ';
    cout<<endl;
    return 0;}
