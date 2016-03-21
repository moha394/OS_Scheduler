#include "Scheduler.h"

using namespace std;

int main()
{
	list<Process*> q;
	q.push_back(new Process(1, 0,24,0));
	q.push_back(new Process(2, 0, 3,0));
	q.push_back(new Process(3, 0, 3,0));
	Scheduler s = Scheduler(q);
	s.fcfs();
	system("pause");
	return 0;
}
