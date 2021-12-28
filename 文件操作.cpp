#include<iostream>
#include<string.h>
using namespace std;
#include<fstream>
int main()
{
	/*ofstream ofs;
	ofs.open("person.txt", ios::binary | ios::out);
	class person
	{
	public:
		char name[64];
		int age;
	};
	person p = { "张山",18 };
	ofs.write((const char*)& p, sizeof(p));
	ofs.close();*/
	ifstream ifs;
	ifs.open("person.txt", ios::binary | ios::in);
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
	}
	person a;
	ifs.read((char*)& a, sizeof(a));
	cout << a.age << endl;
	cout << a.name << endl;
	ifs.close();
}

