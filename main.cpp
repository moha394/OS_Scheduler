#include "Scheduler.h"

using namespace std;

int main()
{
	list<Process*> q;
	q.push_back(new Process(0, 0, 8));
	q.push_back(new Process(1, 1, 4));
	q.push_back(new Process(2, 2, 9));
	q.push_back(new Process(3, 3, 5));
	Scheduler s = Scheduler(q);
	s.sjf(true);
	return 0;
}
