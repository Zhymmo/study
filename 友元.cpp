#include<iostream>
#include<string>
using namespace std;
//1.类做友元2.成员函数做友元3.全局函数做友元
class room	
{
	friend void test1();
	friend class person;
public:
	room()
	{
		settingroom = "客厅";
		bedroom = "卧室";
	}
	string settingroom;
private:
	string bedroom;
};
class person
{

public:
	person()
	{
		name = "张三";
		building = new room;
	}
	string name;
	room* building;
	void visit()
	{
		cout << name << "访问" << building->settingroom << endl;
		cout << name << "访问" << building->bedroom<< endl;
	}

};
void test1()
{
	room building;
	cout << building.settingroom << endl;
	cout << building.bedroom << endl;
}
void test2()
{
	person zs;
	zs.visit();

}
int main()
{
	test2();
}
