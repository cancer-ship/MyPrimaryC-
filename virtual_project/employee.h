#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class Employee :public Worker//��������Ǵ�д������ͷ�ļ�����Сд
{//Ա����
public:
	Employee(int id, string name, int dId);//���캯��
	virtual void showInfo();//��ʾ������Ϣ
	virtual string getDeptName();
};