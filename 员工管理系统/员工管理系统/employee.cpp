#include"employee.h"
employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void employee::showinfo()
{
	cout << "Ա���ı��Ϊ��" << this->m_id
		<< "\tԱ��������Ϊ��" << this->m_name
		<< "\tԱ���ĸ�λΪ��" << this->getdeptname()
		<< "\tԱ���ĸ�λְ��Ϊ�� ��ɾ����·�������" << endl;
}

string employee::getdeptname()
{
	return string("Ա��");
}