#include"manager.h"
manager::manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void manager::showinfo()
{
	cout << "Ա���ı��Ϊ��" << this->m_id
		<< "\tԱ��������Ϊ��" << this->m_name
		<< "\tԱ���ĸ�λΪ��" << this->getdeptname()
		<< "\tԱ���ĸ�λְ��Ϊ�� ����·��ϰ������" << endl;
}

string manager::getdeptname()
{
	return string("����");
}