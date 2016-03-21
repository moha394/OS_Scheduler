#include "Scheduler.h"

using namespace std;

int main()
{
	list<Process*> q;
	q.push_back(new Process(1, 2, 5, 5));
	q.push_back(new Process(2, 4, 5, 1));
	// q.push_back(new Process(3, 0, 2, 4));
	// q.push_back(new Process(4, 0, 1, 5));
	// q.push_back(new Process(5, 0, 5, 2));
	Scheduler s = Scheduler(q);
	s.priority();
	return 0;
}
