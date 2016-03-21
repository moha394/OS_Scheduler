#include  <iostream>
#include "scheduler.h"
using namespace std;
void Scheduler::roundRobin ()
{
		list<Process*>::iterator pointer;
		pointer =_queue.begin();
	double x;
	double total_waiting_time =0;
	double avg_waiting_time;
	cout<< "Enter Quantum Time" << endl ;
		cin >> x ; 
		double z=_queue.size();
		double Time =0 ;
		while (!_queue.empty())
		{
		if(pointer == _queue.end)
		{
		pointer=_queue.begin();	
		}
		else
		{
			if((*pointer)->getArrivalTime() <=Time)
			{
			(*pointer)->start(Time);
			Time += x;
			(*pointer) ->stop(Time);
			if((*pointer)->finished())
				{
					total_waiting_time+= (*pointer)->getWaitingTime();
					_queue.erase(pointer);
				}
			++pointer ;

			}
			
			else	
			{
			pointer = _queue.begin() ;
			(*pointer)->start(Time);
		    Time += x;
			(*pointer) ->stop(Time);
			if((*pointer)->finished())
				{
					_queue.erase(pointer);
				}			
			++pointer ;
			}
			}
	}
		if (_queue.size()==0){
		avg_waiting_time= total_waiting_time/z;
		 cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;
		}
}

