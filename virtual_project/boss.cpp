#include"boss.h"
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "ְ�����" << this->m_Id << "\tְ������" << this->m_Name << "\t��λ"
		<< this->getDeptName() << "\t��λ��ְ�������˾����ʵ��" << endl;
}
string Boss::getDeptName()
{
	return string("�ܲ�");
}