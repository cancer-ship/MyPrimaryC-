#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"workerManager.h"//
int main(){
	//Worker *worker = NULL;//��������һ��ָ�룬Ϊ������֤�Ƿ��ж�̬
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//
	//delete worker;//�ͷ�ָ������壬ָ�벻�����ͷ�Ҳ���Խ�����һ�εĸ�ֵ
	//worker = new Manager(2, "����",2);
	//worker->showInfo();
	//system("pause");
	//delete worker;

	WorkerManager wm;
	int choice=0;
	while (true)
	{
       wm.Show_Menu();
	   cout << "���������ѡ��" << endl;
	   cin >> choice;
	   switch (choice)
	   {
	   case 0://�˳�ϵͳ
		   wm.ExitSystem();
		   break;
	   case 1://���ְ��
		   wm.Add_Emp();
		   break;
	   case 2://��ʾְ��
		   wm.Show_Emp();
		   break;
	   case 3://ɾ��ְ��
		   wm.Del_Emp();
		   break;
	   case 4://�޸�ְ��
		   wm.Mod_Emp();
		   break;
	   case 5://����ְ��
		   wm.Find_Emp();
		   break;
	   case 6://����ְ��
		   wm.Sort_Emp();
		   break;
	   case 7://����ļ�
		   break;
	   default:
		     system("cls");
		   break;

	   }
	}
	system("pause");
	return 0;
}