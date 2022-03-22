#include<cstring>
#include"workerManager.h"//.�ļ�  ��.cpp�ļ����໥�Ĺ�ϵ
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#define FILENAME "EmpFile.txt"
WorkerManager::WorkerManager()//���ڵ����������ʵ��
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ж��ļ��ǲ��Ǵ���
	if (!ifs)
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArry = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;//�����ݶ��룬���ʱ������ж������Ƿ�Ϊ��
	if (ifs.eof())//�����
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//�����¿ռ�
	this->m_EmpArry = new Worker*[this->m_EmpNum];
	this->init_Emp();
	//this->m_EmpArry = new  Worker*[this->m_EmpNum];
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArry[i]->m_Id 
			<<"  ������"<<this->m_EmpArry[i]->m_Name
			<<"  ���ű�ţ� "<<this->m_EmpArry[i]->m_DeptId<<endl;
    }
}
void WorkerManager::Add_Emp()
{
	cout << "���������ӵ�ְ������" << endl;//���е����������
	int addNum = 0;
	cin >> addNum;
	if (addNum>0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker*[newSize];//�����µĿռ�,˫ָ�벻���
		if (this->m_EmpArry != NULL)//���ԭ����Ϊ�գ��ͽ������ݵ�ת��
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}
		for (int i = 0; i < addNum; i++)//�����µı��
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ���ı��"<<endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ���ĸ�λi" << endl;
			//cin >> dSelect;
			cout << "��ѡ��ְ���ĸ�λ" << endl;
			cout << "1,��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1 ://��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2 ://����
				worker = new Manager(id, name, 2);
				break;
			case 3 ://�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		
		delete[] this->m_EmpArry;//�ͷ�ԭ�еĿռ�
		this->m_EmpArry = newSpace;//�����¿ռ��ָ��
		this->m_EmpNum = newSize;//�����µĸ���
		this->m_FileIsEmpty = false;//����Ա����Ϊ�յı�־
		cout << "�ɹ����" << addNum << "���µ�Ա��" << endl;
		this->Save();
	}
	else//����������С����
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Save()//���������ļ�
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//������ķ�ʽ���ļ���д�ļ�
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
	cout << "***��ӭʹ��ְ������ϵͳ**" << endl;
	cout << "***0 �˳��������********" << endl;
	cout << "***1.����ְ����Ϣ********" << endl;
	cout << "***2.��ʾְ����Ϣ********" << endl;
	cout << "***3.ɾ��ְ����Ϣ********" << endl;
	cout << "***4.�޸�ְ����Ϣ********" << endl;
	cout << "***5.����ְ����Ϣ********" << endl;
	cout << "***6.����ְ����Ϣ********" << endl;
	cout << "***7.����ְ����Ϣ********" << endl;
	cout << "*************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��"<<endl;

	system("pause");
	exit(0);//�����Ϊʲô��exit :��Ļ����(return�������������һ���ĺ��������Ͳ�����return)
}
int WorkerManager::get_EmpNum()//��ȡ�ļ��е���������
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
	return  num;//��󷵻��ļ�������
}
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
void WorkerManager::Del_Emp()//ɾ��Ա��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�"<<endl;
	}
	else
	{
		cout << "��������Ҫɾ����Ա�����" << endl;
		int id = 0;
		cin >> id;
	 int index=this->IsExist(id);
	 if (index!=-1)//˵��ְ������
	 {
		 for (int i = index; i < this->m_EmpNum - 1; i++)
		 {    //�������ݵ�ǰ�ƣ�ǰ�Ƶ�ʱ�����ź���Ҫ
			 this->m_EmpArry[i] = this->m_EmpArry[i + 1];
		 }
		 this->m_EmpNum--;//���¼�¼������
		 this->Save();
		 cout << "ɾ���ɹ���" << endl;
	 }
	 else
	 {
		 cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
	 }
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��";
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArry[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�������޸ĵ�ְ���ı��" << endl;
			cin >> newId;
			cout << "����������" << endl;
			cin >> newName;
			cout << "�������λ" << endl;
			cout << "1��ͨԱ��" << endl;
			cout << "2����" << endl;
			cout << "3�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << this->m_EmpArry[ret]->m_DeptId << endl;
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ��,���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)//����Ա���Ƿ����
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
		cout << "�ļ������ڻ��¼Ϊ��";
	}
	else
	{
		cout << "������Ҫ���ҵķ�ʽ" << endl;
		cout << "1��ְ����Ų���" << endl;
		cout << "2��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//����Ų���
			int id;
			cout << "��������ҵ�ְ�����";
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�" << endl;
				this->m_EmpArry[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
			else if (select == 2)
			{

				//����������
				string name;
				cout << "��������ҵ�����"<<endl;
				cin >> name;
				bool falg = false;//Ĭ��δ�ҵ�Ա��
				for (int i = 0; i < m_EmpNum; i++)
				{
					if (this->m_EmpArry[i]->m_Name==name)
					{
						cout << "���ҳɹ���ְ�����Ϊ" << this->m_EmpArry[i]->m_Id
							<< "��ְ����Ϣ����" << endl;
						falg = true;
						this->m_EmpArry[i]->showInfo();
					}
				}
				if (falg==false)
				{
					cout << "����ʧ��" << endl;
				}
			}
			else
			{
				cout << "����������" << endl;
			}
		
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ";
		cout << "1,��ְ����������";
		cout << "2.��ְ�����н���";
		int select = 0;
		cin >> select;
		for (int i = 0; i <m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum;j++)
			{
				if (select==1)//����
				{
					if (m_EmpArry[minOrMax]->m_Id>m_EmpArry[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
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
		cout << "����ɹ�";
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