#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<fstream>
using namespace std;//��׼�������ռ�
#include"worker.h"
#define FILENAME "EmpFile.txt"
class WorkerManager
{
public:
	void init_Emp();//��ʼ��
	int get_EmpNum();//�õ�Ա��������
	bool m_FileIsEmpty;//�ж��Ƿ�Ϊ��
	int m_EmpNum;//Ա��������
	Worker ** m_EmpArry;//ְ������ָ��
	WorkerManager();//���캯��
	void Add_Emp();//���Ա��
	void Del_Emp();//ɾ��Ա��
	void Save();//����
	int IsExist(int id);//����Ų���Ա���Ƿ����
	void Mod_Emp();//������޸�Ա������Ϣ
	void  Show_Menu();//չʾ�˵�
	void ExitSystem();//�˳�ϵͳ
	void Show_Emp();//չʾԱ��
	void Find_Emp();
	void Sort_Emp();
	~WorkerManager();//xig
};