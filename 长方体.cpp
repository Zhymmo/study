#include<iostream>
#include<string>
using namespace std;

class cube
{
public:
	int l;
	int w;
	int h;

	int Getarea()
	{
		return 2 * (l * w + l * h + w * h);
	}

	int GetVolume()
	{
		return l * w* h;
	}

	bool IsSameCube(cube b)
	{
		if (h == b.h && l == b.l && w == b.w)
			return true;
		else
			return false;
	}
};

int main()
{
	cube c1;
	cube c2;
	c1.h = 10;
	c1.l = 5;
	c1.w = 10;
	c2.h = 10;
	c2.l = 5;
	c2.w = 10;
	
	cout << "c1的面积: " << c1.Getarea() << endl;
	cout << "c2的体积:" << c2.GetVolume() << endl;
	cout << "c1 c2 是否相同 :" << c1.IsSameCube(c2) << endl;
}
