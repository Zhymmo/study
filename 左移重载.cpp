#include<iostream>
using namespace std;
//重载<<运算符实现cout输出person类的两个成员 cout<<p
class person
{
	friend ostream &operator<<(ostream& cout, person& p);
public:
	person()
	{
		p_a = 10;
		p_b = 5;
	}
private:
	int p_a;
	int p_b;
};
ostream& operator<<(ostream& cout, person& p)//cout是全局唯一的类，要使用&引用
{
	cout << p.p_a << " " << p.p_b<<endl;
	return cout;
}
//int main()
//{
//	person p;
//	cout << p;
//	return 0;
//}
