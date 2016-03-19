#include <list>
#include "Process.h"

class Scheduler
{

private:
	list<Process> _queue;

public:
	Scheduler(string algorithm, list<Process> queue);

	void sjf(bool prempt);
	void fcfs();
	void priority(bool prempt);
	void roundRobin();
};