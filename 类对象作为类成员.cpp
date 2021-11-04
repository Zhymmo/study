#include<iostream>
using namespace std;
#include<string>

class weapen
{
public:
	weapen(string WeapenName,int bullet=60)
	{
		w_name = WeapenName;
		w_bullet = bullet;
		cout << w_name << " 剩余子弹 "<<w_bullet<<endl;
	}
	string w_name;
	int w_bullet;
};
class solder
{
public:
	solder(string sname, string wname):s_name(sname),s_weapen(wname)
	{
	/*	s_name = sname;
		s_weapen = wname;*/
		cout << s_name << " 拿起 "<<wname<<  endl;
	}
	string s_name;
	weapen s_weapen;
};
int main()
{
	solder p1("张三", "AK47");
}
