#include"workmanager.h"


workmanager::workmanager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	int num = this->get_empnum();
	//cout << "��ǰְ����������" << num<<endl;
	this->m_empnum = num;
	this->m_emparray = new worker * [this->m_empnum];
	this->init_emp();
	//���Դ���
	/*for (int i = 0; i < this->m_empnum; i++)
	{
		cout << "ְ����ţ�" << this->m_emparray[i]->m_id << " "
			<< "ְ��������" << this->m_emparray[i]->m_name << " "
			<< "���ű�ţ�" << this->m_emparray[i]->m_deptid << endl;
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
	cout << "*****" << "\t1�����ְ����Ϣ" << "   *****" << endl;
	cout << "*****" << "\t2����ʾְ����Ϣ" << "   *****" << endl;
	cout << "*****" << "\t3��ɾ��ְ����Ϣ" << "   *****" << endl;
	cout << "*****" << "\t4���޸�ְ����Ϣ" << "   *****" << endl;
	cout << "*****" << "\t5������ְ����Ϣ" << "   *****" << endl;
	cout << "*****" << "\t6�����ձ������" << "   *****" << endl;
	cout << "*****" << "\t7�����ְ����Ϣ" << "   *****" << endl;
	cout << "*****" << "\t0���˳�����ϵͳ" << "   *****" << endl;
	cout << "*******************************" << endl;
}
void workmanager::exitmanagerment()//�˳�����
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
void workmanager::add_emp()//��Ӻ���
{
	cout << "���������Ա��������:";
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_empnum + addnum;//�����¿ռ�
		worker** newspace = new worker * [newsize];//����һ���¿ռ�
		if (this->m_emparray != NULL)//����֮ǰ�ռ������
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
			cout << "�������" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "��Ա���Ĳ��ű��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		cout << "�ɹ����" << addnum << "��ְ��" << endl;

		this->save();//�������ݵ��ļ���
	}
	else {
		cout << "��������" << endl;
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
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
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
		cout << "�ļ������ڻ����ݲ�����" << endl;
	}
	else {
		cout << "����������Ҫɾ���ĵ�Ա����ţ�";
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
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ��" << endl;
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
		cout << "�ļ������ڻ����ݲ�����" << endl;
	}
	else {
		cout << "�������޸ĵ�ְ���ı�ţ�";
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int newselect = 0;

			cout << "�鵽" << id << "��ְ�����������µ�ְ���ţ�";
			cin >> newid;
			cout << "����������������";
			cin >> newname;
			cout << "���������˸�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workmanager::find_emp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ����ݲ�����" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			int id;
			cout << "������ְ����ţ�";
			cin >> id;

			int ret = isexist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_emparray[ret]->showinfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (choice == 2)
		{
			string name;
			cout << "��������ҵ�������";
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparray[i]->m_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_emparray[i]->m_id
						<< "��ְ����Ϣ���£�" << endl;
					this->m_emparray[i]->showinfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workmanager::bubble_sort()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ����ݲ�����" << endl;
		cout << "��������Ա����Ϣ���ٽ������������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�밴����������������" << endl;
		cout << "1.��ְ�������������������" << endl;
		cout << "2.��ְ����Ž�������������" << endl;
		int select=0;
		cin >> select;
		for (int i = 0; i < this->m_empnum-1; i++)
		{
			int minormax = i;
			for (int j = i + 1; j < this->m_empnum; j++)
			{
				if (select == 1)
				{
					/*cout << "���" << endl;
					system("pause");*/
					if (this->m_emparray[minormax]->m_id > this->m_emparray[j]->m_id)//Ѱ����Сֵ���±�
					{
						minormax = j;
					}
				}
				else
				{
					if (this->m_emparray[minormax]->m_id < this->m_emparray[j]->m_id)//Ѱ�����ֵ���±�
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
		
		cout << "�������Ա����Ϣ���£�" << endl;
		this->save();
		this->show_emp();
	}
}
void workmanager::cleam_file()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ�����Ҫɾ�������ݣ�" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "���Ƿ�ɾ��ȫ�����ݣ�" << endl;
		cout << "1.ȷ��" << endl;
		cout << "2.����" << endl;
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
			cout << "�����ϣ�" << endl;

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