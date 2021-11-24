#include<iostream>
using namespace std;
//使用operator++实现自建数据类型的自减。
class integret
{
	friend ostream& operator<<(ostream& cout, integret& inte);
public:
	integret()
	{
		i_a = 0;
	}
	integret& operator--()
	{
		--i_a;
		return *this;
	}
	integret operator--(int)
	{
		integret tmp;

	}
private:
	int i_a;
};
ostream& operator<<(ostream& cout, integret& inte)
{
	cout << inte.i_a;
	return cout;
}
void test1()
{
	integret inte;
	cout << ----------inte << endl;
}
int main()
{
	test1();
	return 0;
}
