#include<iostream>
using std::cout;
#include "1709134_stonewt.h"
Stonewt::Stonewt(double lbs){
	stone=int(lbs)/Lbs_per_stn;
	pds_left=int(lbs)%Lbs_per_stn+lbs-int(lbs);
	pounds=lbs;
}
Stonewt::Stonewt(int stn,double lbs){
	stone=stn;
	pds_left=lbs;
	pounds=stn*Lbs_per_stn+lbs;
}
Stonewt::Stonewt()
{
	stone=pounds=pds_left=0;
}
Stonewt::~Stonewt(){
}
//show weight in stones
void Stonewt::show_stn()const
{
	cout<<stone<<" stone, "<<pds_left<<" pounds\n";
}
//show weifht in pounds
void Stonewt::show_lbs()const
{
	cout<<pounds<<" pounds\n";
}
/*函数接受这样的隐式转换
 * Stone myCat;
 * myCat=19.6
 *
 * 但是有的时候可以关闭这种自动特性
 * explicit Stone(double lbs);
 * 这将关闭隐式转换，但是仍然允许显式转换
 * Stonewt myCat;
 * myCat=19.6;//wrong
 * myCat=Stonewt(19.6);
 * myCat=(Stonewt)19.6;
 * 下面下希介绍最后一点。函数原型话提供的参数匹配过程中，允许使用Stonewt(double)构造函数来转换其他数值类型。也就是说，下面两条语句都将首先将int转换为double，然后使用Stonewt(double)构造函数。
 * Stonewt Jumbo(7000);
 * Jumbo=7300;
 * 但是只有转换不存在二义性时，才会进行这种二步转换，也就是说如果这个类还定义了构造函数Stone(long),则编译器将拒绝这些语句。*/
