#include"workmanager.h"


workmanager::workmanager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//文件存在，无数据
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_empnum();
	//cout << "当前职工的人数：" << num<<endl;
	this->m_empnum = num;
	this->m_emparray = new worker * [this->m_empnum];
	this->init_emp();
	//测试代码
	/*for (int i = 0; i < this->m_empnum; i++)
	{
		cout << "职工编号：" << this->m_emparray[i]->m_id << " "
			<< "职工姓名：" << this->m_emparray[i]->m_name << " "
			<< "部门编号：" << this->m_emparray[i]->m_deptid << endl;
	}*/
}
int workmanager::get_empnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}
void workmanager::show_menu()
{
	cout << "*******************************" << endl;
	cout << "*****" << "\t1、添加职工信息" << "   *****" << endl;
	cout << "*****" << "\t2、显示职工信息" << "   *****" << endl;
	cout << "*****" << "\t3、删除职工信息" << "   *****" << endl;
	cout << "*****" << "\t4、修改职工信息" << "   *****" << endl;
	cout << "*****" << "\t5、查找职工信息" << "   *****" << endl;
	cout << "*****" << "\t6、按照编号排序" << "   *****" << endl;
	cout << "*****" << "\t7、清空职工信息" << "   *****" << endl;
	cout << "*****" << "\t0、退出管理系统" << "   *****" << endl;
	cout << "*******************************" << endl;
}
void workmanager::exitmanagerment()//退出函数
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
void workmanager::add_emp()//添加函数
{
	cout << "请输入添加员工的数量:";
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_empnum + addnum;//计算新空间
		worker** newspace = new worker * [newsize];//开辟一个新空间
		if (this->m_emparray != NULL)//拷贝之前空间的数据
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int deptselect;
			cout << "请输入第" << i + 1 << "名员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "名员工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "名员工的部门编号" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> deptselect;

			worker* worker_ = NULL;
			switch (deptselect)
			{
			case 1:
				worker_ = new employee(id, name, 1);
				break;
			case 2:
				worker_ = new manager(id, name,2);
				break;
			case 3:
				worker_ = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[this->m_empnum + i] = worker_;
		}
		delete[]this->m_emparray;
		this->m_emparray = newspace;
		this->m_empnum = newsize;
		this->m_fileisempty = false;
		cout << "成功添加" << addnum << "名职工" << endl;

		this->save();//保持数据到文件中
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void workmanager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}
void workmanager::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index=0;

	while (ifs>>id,ifs>>name,ifs>>did)
	{
		worker* worker_ = NULL;
		if (did == 1)
		{
			worker_ = new employee(id, name, did);
		}
		else if (did == 2)
		{
			worker_ = new manager(id, name, did);
		}
		else
		{
			worker_ = new boss(id, name, did);
		}
		this->m_emparray[index] = worker_;

		index++;
	}
	ifs.close();
}
void workmanager::show_emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_empnum; i++)
		{
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");

}
void workmanager::del_emp()
{
	if(this->m_fileisempty) {
		cout << "文件不存在或数据不存在" << endl;
	}
	else {
		cout << "请输入您需要删除的的员工编号：";
		int id = 0;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_empnum - 1; i++)
			{
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败" << endl;
		}
	}
	system("pause");
	system("cls");
}
int workmanager::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++)
	{
		if (this->m_emparray[i]->m_id == id)
		{
			return i;
			break;
		}
	}
	return index;
}
void workmanager::mod_emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或数据不存在" << endl;
	}
	else {
		cout << "请输入修改的职工的编号：";
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int newselect = 0;

			cout << "查到" << id << "号职工，请输入新的职工号：";
			cin >> newid;
			cout << "请输入新人姓名：";
			cin >> newname;
			cout << "请输入新人岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newselect;
			worker* worker_ = NULL;
			switch (newselect)
			{
			case 1:
				worker_ = new employee(newid, newname, 1);
				break;
			case 2:
				worker_ = new manager(newid, newname, 2);
				break;
			case 3:
				worker_ = new boss(newid, newname, 3);
				break;
			default:
				break;
			}
			this->m_emparray[ret] = worker_;

			cout << "修改成功" << endl;
			this->save();
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workmanager::find_emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或数据不存在" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			int id;
			cout << "请输入职工编号：";
			cin >> id;

			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下：" << endl;
				this->m_emparray[ret]->showinfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (choice == 2)
		{
			string name;
			cout << "请输入查找的人名：";
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparray[i]->m_name == name)
				{
					cout << "查找成功，职工编号为："
						<< this->m_emparray[i]->m_id
						<< "号职工信息如下：" << endl;
					this->m_emparray[i]->showinfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workmanager::bubble_sort()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或数据不存在" << endl;
		cout << "请先输入员工信息！再进行排序操作！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请按照如下来进行排序：" << endl;
		cout << "1.按职工编号升序来进行排序！" << endl;
		cout << "2.按职工编号降序来进行排序！" << endl;
		int select=0;
		cin >> select;
		for (int i = 0; i < this->m_empnum-1; i++)
		{
			int minormax = i;
			for (int j = i + 1; j < this->m_empnum; j++)
			{
				if (select == 1)
				{
					/*cout << "你好" << endl;
					system("pause");*/
					if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id)//寻找最小值的下标
					{
						minormax = j;
					}
				}
				else
				{
					if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id)//寻找最大值的下标
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[minormax];
				this->m_emparray[minormax] = temp;
			}
			
		}
		
		cout << "排序完的员工信息如下：" << endl;
		this->save();
		this->show_emp();
	}
}
void workmanager::cleam_file()
{
	if (this->m_fileisempty)
	{
		cout << "文件中无要删除的数据！" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "您是否删除全部数据！" << endl;
		cout << "1.确定" << endl;
		cout << "2.返回" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			ofstream ofst(FILENAME, ios::trunc);
			ofst.close();

			if (this->m_emparray != NULL)
			{
				for (int i = 0; i < this->m_empnum; i++)
				{
					delete this->m_emparray[i];
				}
				delete[]this->m_emparray;
				this->m_emparray = NULL;
				this->m_empnum = 0;
				this->m_fileisempty = true;
			}
			cout << "清空完毕！" << endl;

		}
		system("pause");
		system("cls");
	}
}
workmanager::~workmanager()
{
	if (this->m_emparray != NULL)
	{
		for (int i = 0; i < this->m_empnum; i++)
		{
			if (this->m_emparray[i] != NULL)
			{
				delete this->m_emparray[i];
			}
		}
		delete[]this->m_emparray;
		this->m_emparray = NULL;
	}
}