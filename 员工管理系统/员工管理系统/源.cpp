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
		cout << "��ɾ������ĵ��£�" << endl;
	}
};
class manger : public person
{
	virtual void dowork()
	{
		cout << "����ϰ彻�����£����·ŵ�Ա�������У�" << endl;
	}
};
class boss : public person
{
	virtual void dowork()
	{
		cout << "�����ǵ����е��£�" << endl;
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
	cout << "��������Ҫ�����±�ţ�" << endl;
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