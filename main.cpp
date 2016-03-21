#include "Scheduler.h"

using namespace std;

int main()
{
	list<Process*> q;
<<<<<<< HEAD
	q.push_back(new Process(1, 0,24,0));
	q.push_back(new Process(2, 0, 3,0));
	q.push_back(new Process(3, 0, 3,0));
	Scheduler s = Scheduler(q);
	s.fcfs();
	system("pause");
=======
	q.push_back(new Process(1, 2, 5, 5));
	q.push_back(new Process(2, 4, 5, 1));
	// q.push_back(new Process(3, 0, 2, 4));
	// q.push_back(new Process(4, 0, 1, 5));
	// q.push_back(new Process(5, 0, 5, 2));
	Scheduler s = Scheduler(q);
	s.priority();
>>>>>>> 14e121fc2f39a3f140ed443f9bb65601488dc93a
	return 0;
}
