#include"boss.h"
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "职工编号" << this->m_Id << "\t职工姓名" << this->m_Name << "\t岗位"
		<< this->getDeptName() << "\t岗位的职责管理公司所有实物" << endl;
}
string Boss::getDeptName()
{
	return string("总裁");
}