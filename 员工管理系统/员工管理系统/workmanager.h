#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include<fstream>
constexpr auto FILENAME = "empfile.txt";
class workmanager
{
public:
	workmanager();

	void show_menu();
	void exitmanagerment();
	int m_empnum;
	worker** m_emparray;
	void add_emp();
	void save();//保存函数
	bool m_fileisempty;
	int get_empnum();
	void init_emp();
	void show_emp();//显示函数
	void del_emp();
	int isexist(int id);
	void mod_emp();
	void find_emp();
	void bubble_sort();
	void cleam_file();
	~workmanager();
};