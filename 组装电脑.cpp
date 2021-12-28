#include<iostream>
#include<string.h>
using namespace std;
class Equepment
{
public:
	virtual void Work() = 0;
	~Equepment()
	{
		;
	}
};
class CPU :public Equepment
{
public:
	CPU(string name)
	{
		factor = name;
	}
	string factor;
	virtual void Work()
	{
		cout << factor << "CPU正在计算数据中···" << endl;
	}
	~CPU()
	{
		cout << "CPU关闭" << endl;
	}
};
class GPU :public Equepment
{
public:
	GPU(string name)
	{
		factor = name;
	}
	string factor;
	virtual void Work()
	{
		cout << factor<<"GPU正在处理图像中···" << endl;
	}
	~GPU()
	{
		cout << "GPU关闭" << endl;
	}
};
class AMR :public Equepment
{
public:
	AMR(string name)
	{
		factor = name;
	}
	string factor;
	virtual void Work()
	{
		cout << factor << "AMR正在储存数据中···" << endl;
	}
	~AMR()
	{
		cout << "AMR关闭" << endl;
	}
};

class Computer
{
public:
	Equepment* C;
	Equepment* G;
	Equepment* A;
	Computer(string Cpu,string Gpu,string Amr)
	{
		C=new CPU(Cpu);
		G=new GPU(Gpu);
		A=new AMR(Amr);
	}
	void Run()
	{
		C->Work();
		G->Work();
		A->Work();
	}
	void Close()
	{
		delete C;
		delete G;
		delete A;
		C = NULL;
		G = NULL;
		A = NULL;
	}

};
int main()
{
	
	Computer A("inter", "nvidia", "kinston");
	A.Run();
	A.Close();
}
