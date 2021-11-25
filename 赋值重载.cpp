#include<iostream>
using namespace std;
class person
{
public:
	person(int age)
	{
		p_a =new int(age);
	}
	~person()
	{
		if (p_a != NULL)
		{
			delete p_a;
			p_a = NULL;
		}
	}
	person& operator=(person& p)
	{
		*this->p_a = *p.p_a;
		return *this;
	}
	int* p_a;
};
void test1()
{
	person p1(18);
	person p2(20);
	person p3(30);
	p1 = p1;
	cout << *p1.p_a << endl;
	cout << *p2.p_a << endl;
	cout << *p3.p_a << endl;
}
int main()
{
	test1();
	return 0;
}
