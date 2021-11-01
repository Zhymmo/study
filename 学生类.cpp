#include<iostream>
#include<string>
using namespace std;

class student
{
	//访问权限（公共权限）
public:	
	//属性
	string name;
	int id;
	//行为
	void ShowStu()
	{
		cout << "姓名: " << name << " 学号: " << id << endl;
	}
};

