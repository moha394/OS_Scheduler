class Process
{
public:
	Process::Process(double arrivalTime, double burstTime,  int priority = 0)
	{
		_waitingTime = 0;
		_stopTime = 0;
		_working = false;

		_arrivalTime = arrivalTime;
		_burstTime = burstTime;
		_remainingTime = burstTime;
		_priority = priority;
	};

	void start(double time) {
		if (_working)
		{
			throw("Process already running!");
			return;
		}

		_startTime = time;
		_waitingTime += time - _stopTime;
		_working = true;
	}

	void stop(double time) {
		if (!_working)
		{
			throw("Process not running!");
			return;
		}

		int latency = time - _startTime;
		if (latency > _burstTime)
		{
			throw("Process finishes before stopping!!");
			return;
		}

		_waitingTime = time;
		_remainingTime -= latency;
		_stopTime - time;
		_working = false;

		if (_remainingTime == 0)
		{
			_finishTime = time;
		}
	}

	double getArrivalTime() {
		return _arrivalTime;
	}

	double getBurstTime(){
		return _burstTime;
	}

	double getRemainingTime() {
		return _remainingTime;
	}

	double getWaitingTime() {
		return _waitingTime;
	}

	double getFinishTime() {
		return _finishTime;
	}

	int getPriority() {
		return _priority;
	}

	bool finished() {
		if (_remainingTime == 0)
			return true;
		return false;
	}

	bool working() {
		return working;
	}

private:
	double _startTime, _stopTime, _finishTime;
	double _waitingTime, _burstTime, _arrivalTime, _remainingTime;
	int _priority;
	bool _working;
};