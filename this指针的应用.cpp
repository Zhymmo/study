#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	Person& AgeAdd(Person p)
	{
		this->age += p.age;
		return *this;
	}
	string name;
	int age;
};
int main()
{
	Person p1("张三", 18);
	Person p2("李四", 20);
	p1.AgeAdd(p2).AgeAdd(p2).AgeAdd(p1);
	cout << p1.age << endl;
	return 0;
}
