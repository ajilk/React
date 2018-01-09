#include "Timer.h"

void Timer::start(){
	begin = steady_clock::now();	
}

void Timer::stop(){
	end  = steady_clock::now();
}

duration<double> Timer::elapsed(){
	return end-begin; 
}
