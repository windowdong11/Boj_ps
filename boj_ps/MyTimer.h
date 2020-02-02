#pragma once
#include <iostream>
#include <chrono>

class MyTimer
{
private:
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;
	bool status = false;
public:

	MyTimer() {}
	MyTimer(bool status) : status(status){}
	~MyTimer() {}

	void start()
	{
		if(status)
			begin = std::chrono::steady_clock::now();
	}
	void stop()
	{
		if (status)
			end = std::chrono::steady_clock::now();
	}
	void printTime()
	{
		if (status)
			std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[ms]" << std::endl;
	}

	void enable()
	{
		status = true;
	}
	void disable()
	{
		status = false;
	}
};
