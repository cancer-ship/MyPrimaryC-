#pragma once
#include<iostream>
#include<string>
using namespace std;
class  Worker
{
public:
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;
	int  m_Id;//职工号
	string m_Name;//职工姓名
	int m_DeptId;//职工所在部门名称
};