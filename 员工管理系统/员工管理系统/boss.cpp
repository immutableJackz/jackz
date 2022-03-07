#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showinfo()
{
	cout << "员工的编号为：" << this->m_id
		<< "\t员工的姓名为：" << this->m_name
		<< "\t员工的岗位为：" << this->getdeptname()
		<< "\t员工的岗位职责为： 管理公司所有的事！" << endl;
}

string boss::getdeptname()
{
	return string("老板");
}