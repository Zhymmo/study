#include<iostream>
using namespace std;
//用operator+ 重载一个可以把两个类相加的加法运算
class person
{
public:
	int a;
	int b;
	//成员函数重载运算符
	//person operator+(person one)
	//{
	//	person tmp;
	//	tmp.a = this->a + one.a;
	//	tmp.b = this->b + one.b;
	//	return tmp;
	//}
};
//全局函数重载运算符
person operator+(person one, person two)
{
	person tmp;
	tmp.a = one.a + two.a;
	tmp.b = one.b + two.b;
	return tmp;
}
//int main()
//{
//	person z;
//	z.a = 10;
//	z.b = 20;
//	person l;
//	l.a = 5;
//	l.b = 10;
//	person w=z + l;
//	cout << w.a  << w.b << endl;
//	return 0;
//}
