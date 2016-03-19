#include <list>
#include "Process.h"

class scheduler
{

private:
	int _time;
	string _algorithm;
	list<Process> _queue;

public:
	scheduler(string algorithm, list<Process> queue);
	void start();

	void sjf(bool prempt);
	void fcfs();
	void priority(bool prempt);
	void roundRobin();
};