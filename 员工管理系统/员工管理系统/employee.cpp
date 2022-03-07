#include"employee.h"
employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void employee::showinfo()
{
	cout << "员工的编号为：" << this->m_id
		<< "\t员工的姓名为：" << this->m_name
		<< "\t员工的岗位为：" << this->getdeptname()
		<< "\t员工的岗位职责为： 完成经理下发的任务！" << endl;
}

string employee::getdeptname()
{
	return string("员工");
}