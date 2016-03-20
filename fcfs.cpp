#include "scheduler.h"
#include <iostream>


void Scheduler::fcfs ()
{
	int time = 0;
	double total_waiting_time =0 ,avg_waiting_time , temp=0 ; 
	pointer = _queue.begin();
	       
	    while(pointer != _queue.end()) ////// put the next arrival time in temp 
	    {
		    ++pointer ;
			temp = pointer->getArrivalTime() ;
		}

		while(pointer != _queue.end()) ///calculate the total Waiting time
	       {
		       pointer->setWaitingTime(0);pointer->setRemainingTime(0);
			   if((pointer->get_BurstTime() + pointer-> getArrivalTime()) < temp )
			   {
				   time = (pointer->get_BurstTime() + pointer->getArrivalTime()) - temp ;
				   pointer-> setWaitingTime(time);
				   
			   }
			   else {pointer->setWaitingTime(0);}
			   total_waiting_time += pointer->get_WaitingTime();
		   }

		if(pointer == _queue.end())///calculate the Avg Time 
		{
				avg_waiting_time= total_waiting_time/_queue.size();			
			    cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;

		}		

		



  /*     while(pointer != _queue.end())
    {
       pointer->setWaitingTime(time);
	   total_waiting_time += time;

	   pointer->set_remainingTime(0);
	   time=time + pointer->get_BurstTime() ;
	   ++pointer;
	}

	pointer=_queue.begin();

    total_waiting_time=0;

    for(int i=1;i<max;i++)

    {

        pointer ++;

        total_waiting_time=total_waiting_time+(pointer->wait_time);

    }

    avg_waiting_time=total_waiting_time/max;

    cout<<"AVERAGE WAITING TIME IS ==> "<<avg_waiting_time << endl ;*/


}