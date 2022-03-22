#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
void test()
{
	Worker *worker = NULL;//父函数的一个指针，为的是验证是否有多态
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五",3);
	worker->showInfo();
	delete worker;
}