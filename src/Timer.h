#ifndef TIMER_H
#define TIMER_H

#include <chrono>
using namespace std::chrono;

class Timer{
private:
	time_point<steady_clock> begin;
	time_point<steady_clock> end;
public:
	void start();
	void stop();
	duration<double> elapsed();		
};

#endif
