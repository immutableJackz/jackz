#include"workmanager.h"
#include"worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"

int main(){
	/*worker* workertest = NULL;
	workertest = new employee(1001, "张三", 1);
	workertest->showinfo();
	delete workertest;
	
	workertest = new boss(1002, "李四", 2);
	workertest->showinfo();
	delete workertest;

	workertest = new manager(1003, "老王", 3);
	workertest->showinfo();
	delete workertest;*/

	workmanager wm;
	int choice = 0;
	while (1)
	{
		wm.show_menu();
		cout << "请输入你的选项！" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitmanagerment();
			break;
		case 1:
			wm.add_emp();
			break;
		case 2:
			wm.show_emp();
			break;
		case 3:
			wm.del_emp();
			break;
			
		case 4:
			wm.mod_emp();
			break;
		case 5:
			wm.find_emp();
			break;
		case 6:
			wm.bubble_sort();
			break;
		case 7:
			wm.cleam_file();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}