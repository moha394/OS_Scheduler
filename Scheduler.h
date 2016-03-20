#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <list>
#include "Process.h"

class Scheduler
{

private:
	list<Process*> _queue;

public:
	Scheduler(list<Process*> queue) {
		_queue = queue;
	}

	void sjf(bool prempt);
	void fcfs();
	void priority(bool prempt);
	void roundRobin();
};

#endif
