#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showinfo()
{
	cout << "Ա���ı��Ϊ��" << this->m_id
		<< "\tԱ��������Ϊ��" << this->m_name
		<< "\tԱ���ĸ�λΪ��" << this->getdeptname()
		<< "\tԱ���ĸ�λְ��Ϊ�� ����˾���е��£�" << endl;
}

string boss::getdeptname()
{
	return string("�ϰ�");
}