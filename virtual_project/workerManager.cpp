#include<cstring>
#include"workerManager.h"//.文件  与.cpp文件的相互的关系
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#define FILENAME "EmpFile.txt"
WorkerManager::WorkerManager()//类内的声明类外的实现
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//先判断文件是不是存在
	if (!ifs)
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArry = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;//将数据读入，这个时候可以判定数据是否为真
	if (ifs.eof())//不理解
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟新空间
	this->m_EmpArry = new Worker*[this->m_EmpNum];
	this->init_Emp();
	//this->m_EmpArry = new  Worker*[this->m_EmpNum];
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArry[i]->m_Id 
			<<"  姓名："<<this->m_EmpArry[i]->m_Name
			<<"  部门编号： "<<this->m_EmpArry[i]->m_DeptId<<endl;
    }
}
void WorkerManager::Add_Emp()
{
	cout << "请输入增加的职工数量" << endl;//经行的是批次添加
	int addNum = 0;
	cin >> addNum;
	if (addNum>0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker*[newSize];//开辟新的空间,双指针不理解
		if (this->m_EmpArry != NULL)//如果原来不为空，就进行数据的转移
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}
		for (int i = 0; i < addNum; i++)//输入新的编号
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工的编号"<<endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工的岗位i" << endl;
			//cin >> dSelect;
			cout << "请选择职工的岗位" << endl;
			cout << "1,普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3。老板" << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1 ://普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2 ://经理
				worker = new Manager(id, name, 2);
				break;
			case 3 ://老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		
		delete[] this->m_EmpArry;//释放原有的空间
		this->m_EmpArry = newSpace;//更改新空间的指向
		this->m_EmpNum = newSize;//更改新的个数
		this->m_FileIsEmpty = false;//更新员工不为空的标志
		cout << "成功添加" << addNum << "名新的员工" << endl;
		this->Save();
	}
	else//如果输入的数小于零
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Save()//用来保存文件
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//用输出的方式打开文件，写文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs <<to_string(this->m_EmpArry[i]->m_Id)  << " "
			<<this->m_EmpArry[i]->m_Name<< " "
			<<to_string(this->m_EmpArry[i]->m_DeptId) << endl;
	}
	ofs.close();
}
void WorkerManager::init_Emp()//
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArry[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManager::Show_Menu()
{
	cout << "*************************" << endl;
	cout << "***欢迎使用职工管理系统**" << endl;
	cout << "***0 退出管理程序********" << endl;
	cout << "***1.增加职工信息********" << endl;
	cout << "***2.显示职工信息********" << endl;
	cout << "***3.删除职工信息********" << endl;
	cout << "***4.修改职工信息********" << endl;
	cout << "***5.查找职工信息********" << endl;
	cout << "***6.排序职工信息********" << endl;
	cout << "***7.增加职工信息********" << endl;
	cout << "*************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用"<<endl;

	system("pause");
	exit(0);//不理解为什么用exit :弹幕解释(return会结束函数，不一样的函数结束就不能用return)
}
int WorkerManager::get_EmpNum()//获取文件中的人数个数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num=0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		num++;
	}
	ifs.close();
	return  num;//最后返回文件的人数
}
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Del_Emp()//删除员工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！"<<endl;
	}
	else
	{
		cout << "请输入想要删除的员工编号" << endl;
		int id = 0;
		cin >> id;
	 int index=this->IsExist(id);
	 if (index!=-1)//说明职工存在
	 {
		 for (int i = index; i < this->m_EmpNum - 1; i++)
		 {    //进行数据的前移，前移的时候的序号很重要
			 this->m_EmpArry[i] = this->m_EmpArry[i + 1];
		 }
		 this->m_EmpNum--;//更新记录的人数
		 this->Save();
		 cout << "删除成功！" << endl;
	 }
	 else
	 {
		 cout << "删除失败，未找到该员工" << endl;
	 }
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空";
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArry[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "请输入修改的职工的编号" << endl;
			cin >> newId;
			cout << "请输入姓名" << endl;
			cin >> newName;
			cout << "请输入岗位" << endl;
			cout << "1普通员工" << endl;
			cout << "2经理" << endl;
			cout << "3老板" << endl;
			cin >> dSelect;
			Worker*  worker = NULL;
			switch (dSelect)
			{
			case 1:
					worker = new Employee(newId, newName, dSelect);
			case 2:
				worker = new Manager(newId, newName, dSelect);
			case 3:
				worker = new Boss(newId, newName, dSelect);
			default:
				break;
			}
			this->m_EmpArry[ret] = worker;
			cout << "修改成功" << this->m_EmpArry[ret]->m_DeptId << endl;
			this->Save();
		}
		else
		{
			cout << "修改失败,查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)//查找员工是否存在
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArry[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void   WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空";
	}
	else
	{
		cout << "请输入要查找的方式" << endl;
		cout << "1按职工编号查找" << endl;
		cout << "2按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按编号查找
			int id;
			cout << "请输入查找的职工编号";
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功" << endl;
				this->m_EmpArry[ret]->showInfo();
			}
			else
			{
				cout << "查找失败" << endl;
			}
		}
			else if (select == 2)
			{

				//按姓名查找
				string name;
				cout << "请输入查找的姓名"<<endl;
				cin >> name;
				bool falg = false;//默认未找到员工
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (this->m_EmpArry[i]->m_Name==name)
					{
						cout << "查找成功，职工编号为" << this->m_EmpArry[i]->m_Id
							<< "号职工信息如下" << endl;
						falg = true;
						this->m_EmpArry[i]->showInfo();
					}
				}
				if (falg==false)
				{
					cout << "查找失败" << endl;
				}
			}
			else
			{
				cout << "输入项有误" << endl;
			}
		
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式";
		cout << "1,按职工进行升序";
		cout << "2.按职工进行降序";
		int select = 0;
		cin >> select;
		for (int i = 0; i <m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum;j++)
			{
				if (select==1)//升序
				{
					if (m_EmpArry[minOrMax]->m_Id>m_EmpArry[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (m_EmpArry[minOrMax]->m_Id<m_EmpArry[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i!=minOrMax)
			{
				Worker *temp = m_EmpArry[i];
				m_EmpArry[i] = m_EmpArry[minOrMax];
				m_EmpArry[minOrMax] = temp;
			}
		}
		cout << "排序成功";
		this->Save();
		this->Show_Emp();
	}
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArry != NULL)
	{
		delete[] this->m_EmpArry;
		this->m_EmpArry = NULL;
	}
}