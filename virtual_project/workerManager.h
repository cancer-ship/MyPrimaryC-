#pragma once//防止头文件重复包含
#include<iostream>
#include<fstream>
using namespace std;//标准的命名空间
#include"worker.h"
#define FILENAME "EmpFile.txt"
class WorkerManager
{
public:
	void init_Emp();//初始化
	int get_EmpNum();//得到员工的数量
	bool m_FileIsEmpty;//判断是否为空
	int m_EmpNum;//员工的数量
	Worker ** m_EmpArry;//职工数组指针
	WorkerManager();//构造函数
	void Add_Emp();//添加员工
	void Del_Emp();//删除员工
	void Save();//保存
	int IsExist(int id);//按编号查找员工是否存在
	void Mod_Emp();//按编号修改员工的信息
	void  Show_Menu();//展示菜单
	void ExitSystem();//退出系统
	void Show_Emp();//展示员工
	void Find_Emp();
	void Sort_Emp();
	~WorkerManager();//xig
};