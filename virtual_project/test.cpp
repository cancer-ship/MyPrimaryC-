#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
void test()
{
	Worker *worker = NULL;//��������һ��ָ�룬Ϊ������֤�Ƿ��ж�̬
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����",3);
	worker->showInfo();
	delete worker;
}