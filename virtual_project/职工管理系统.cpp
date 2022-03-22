#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"workerManager.h"//
int main(){
	//Worker *worker = NULL;//父函数的一个指针，为的是验证是否有多态
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//
	//delete worker;//释放指针的意义，指针不进行释放也可以进行下一次的赋值
	//worker = new Manager(2, "李四",2);
	//worker->showInfo();
	//system("pause");
	//delete worker;

	WorkerManager wm;
	int choice=0;
	while (true)
	{
       wm.Show_Menu();
	   cout << "请输入你的选择" << endl;
	   cin >> choice;
	   switch (choice)
	   {
	   case 0://退出系统
		   wm.ExitSystem();
		   break;
	   case 1://添加职工
		   wm.Add_Emp();
		   break;
	   case 2://显示职工
		   wm.Show_Emp();
		   break;
	   case 3://删除职工
		   wm.Del_Emp();
		   break;
	   case 4://修改职工
		   wm.Mod_Emp();
		   break;
	   case 5://查找职工
		   wm.Find_Emp();
		   break;
	   case 6://排序职工
		   wm.Sort_Emp();
		   break;
	   case 7://清空文件
		   break;
	   default:
		     system("cls");
		   break;

	   }
	}
	system("pause");
	return 0;
}