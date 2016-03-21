#include <list>
#include "Process.h"

class Scheduler
{

private:
	list<Process> _queue;

public:
	Scheduler(list<Process> queue) {
		_queue = queue;
	}

	void sjf(bool prempt=false);
	void fcfs();
	void priority(bool prempt=false);
	void roundRobin();
};