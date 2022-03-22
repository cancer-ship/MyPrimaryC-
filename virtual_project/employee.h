#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class Employee :public Worker//类的名称是大写，但是头文件名是小写
{//员工类
public:
	Employee(int id, string name, int dId);//构造函数
	virtual void showInfo();//显示个人信息
	virtual string getDeptName();
};