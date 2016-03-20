#include "Scheduler.h"
size_t current_time = 0;

struct CompareArrivalBurst {
	bool operator()(Process* lhs, Process* rhs) {
		double t1 = lhs->getArrivalTime();
		double t2 = rhs->getArrivalTime();
		if (current_time >= t1 && current_time >= t2)
			return lhs->getRemainingTime() <= rhs->getRemainingTime();
		if (t1 < t2)
			return true;
		else if (t1 == t2)
			return lhs->getRemainingTime() <= rhs->getRemainingTime();
		else
			return false;
	}
};

void Scheduler::sjf(bool prempt) {
	int counter = 0;

	_queue.sort(CompareArrivalBurst());

	while (true) {
		Process* item = _queue.front();
		if (item->finished()) {
			_queue.pop_front();
			if (_queue.size() == 0) break;
		}
		else {
			 _queue.sort(CompareArrivalBurst());
			item = _queue.front();
			item->start(current_time);

			if (!prempt || _queue.size() == 1)
				current_time += item->getRemainingTime();
			else
				current_time += 1;

			item->stop(current_time);
		}
		counter++;
		if (counter > 100)  {
			cout << "Infinite Loop Ya 7mar";
			break;
		}
	}
}
