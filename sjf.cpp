#include "Scheduler.h"

void Scheduler::sjf(bool prempt) {
	int time = 0;
	struct CompareArrivalBurst {
	    bool operator()(Process lhs, Process rhs) {
	    	if (lhs.getArrivalTime() < rhs.getArrivalTime())
	    		return true;
	    	else if (lhs.getArrivalTime() == rhs.getArrivalTime())
	    		return lhs.getBurstTime() <= rhs.getBurstTime();
	    	else
	    		return false;
	    };
	};

	_queue.sort(CompareArrivalBurst());

	while (true) {
		Process item = _queue.front();
		if (item.getRemainingTime() == 0) {
			item.stop(time);
			_queue.pop_front();
			if (_queue.size() == 0) break;
			_queue.front().start(time);
		}
		else {
			item.consumeTime(1);
		}
		time++;
	}
}