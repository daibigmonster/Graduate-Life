/*#抽象数据类型*/
#ifndef STACK_H_
#define STACK_H_
typedef unsigned long Item;
class Stack
{
	enum{MAX=10};
	Item items[MAX];
	int top;
public:
	Stack();
	bool isfull() const;
	bool isempty() const;
	bool push(const Item &item);
	bool pop(Item &item);
};
#endif

