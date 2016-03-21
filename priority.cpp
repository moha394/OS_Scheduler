#include "Scheduler.h"

// struct compareArrivalPriority
// {
// 	bool operator (Process lhs, Process rhs) {
// 		if(lhs.getArrivalTime() < rhs.getArrivalTime())
// 			return true;
// 		if (lhs.getArrivalTime() == rhs.getArrivalTime())
// 		{
// 			if (lhs.getPriority() > rhs.getPriority())
// 				return true;
// 			return false;
// 		}
// 		return false;
// 	}
// };

struct compareArrivalPriority {
	bool operator()(Process* lhs, Process* rhs) {
		double t1 = lhs->getArrivalTime();
		double t2 = rhs->getArrivalTime();
		if (_time >= t1 && _time >= t2)
			return lhs->getPriority() <= rhs->getPriority();
		if (t1 < t2)
			return true;
		else if (t1 == t2)
			return lhs->getPriority() <= rhs->getPriority();
		else
			return false;
	}
};

void Scheduler::priority(bool prempt=false) {
	int totalWaiting = 0;

	_queue.sort(compareArrivalPriority);
	Process* top = _queue.front();
	if (prempt)
	{

		while(_queue.size() != 0) {
			_queue.sort(compareArrivalPriority);
			if (_queue.front != top)
			{
				top->stop();
				top = _queue.front();
			}

			if (!top->isWorking()) {
				top->start();
			}
			else {
				if (top->isFinished())
				{
					top->stop();
					totalWaiting += top->getWaitingTime();
					delete top;
					_queue.pop();
				}

			}
			_time++;
		}
	}
	else {
		while(_queue.size > 0) {
			int latency = top->getBurstTime();
			top->start(_time);
			_time += latency;
			top->stop(_time);
			totalWaiting += top->getWaitingTime();
			delete top;
			_queue.sort(compareArrivalPriority);
			top = _queue.pop();
		}
	}

	cout << "Total time: " << _time;
	cout << "Average waiting time: " << totalWaiting/_queue.size();
}

