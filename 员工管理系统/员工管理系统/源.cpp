#include <iostream>
using namespace std;
#include <string>
class person
{
public:
	virtual void dowork() = 0;
	int m_num;
	string m_offer;

};
class normalwork: public person
{
	virtual void dowork()
	{
		cout << "完成经理交代的的事！" << endl;
	}
};
class manger : public person
{
	virtual void dowork()
	{
		cout << "完成老板交代的事，并下放到员工的手中！" << endl;
	}
};
class boss : public person
{
	virtual void dowork()
	{
		cout << "管你们的所有的事！" << endl;
	}
};
void addofficer()
{

}
int main()
{
	
	cout << "*************************" << endl;
	
	
	cout << "*************************" << endl;
	int a;
	cout << "请输入您要做的事编号！" << endl;
	cin >> a;
	switch (a)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		break;
	}
}