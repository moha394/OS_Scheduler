class Process
{
public:
	Process::Process(double arrivalTime, double burstTime,  int priority = 0)
	{
		_waitingTime = -1;
		_arrivalTime = arrivalTime;
		_burstTime = burstTime;
		_remainingTime = burstTime;
		_priority = priority;
	};
	Process::~Process()
	{
	};
    void setWaitingTime(double t)
	{
		_waitingTime = t;
	};
	void consumeTime(double t)
	{
		_remainingTime -= t;
	};
	double getFinishTime() const
	{
		if (_remainingTime == 0) return _arrivalTime + _waitingTime + _burstTime;
		else return -1;
	};
private:
	double _waitingTime, _burstTime, _arrivalTime, _remainingTime;
	int _priority;
};