#include <random>
#include <iostream>
#include <typeinfo>
#include <string>
#include <chrono>
#include <thread>

#include "ToyCode.h"

using namespace std;

void printTimeMsg(chrono::steady_clock::time_point lastTime, chrono::steady_clock::time_point startTime, const string& msg)
{
	// 지난 시간과 메세지 출력
	// ex) 123ms : hello
	cout << chrono::duration_cast<chrono::milliseconds>((lastTime - startTime)).count() << "ms : "<< msg << '\n';
}


void stupidProgram()
{
	// 바보상자
	/*
		x를 누르면 종료,
		아무 키나 입력시 상태 on, 랜덤 시간(200 ~ 3000 ms) 후 off상태로 되돌아감
	*/
	// 아래 3줄 출처 : cppreference.com
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(200, 3000);
	auto& clocknow = chrono::steady_clock::now;
	const auto startTime = clocknow();

	string inp;
	bool status = false;
	while (true)
	{
		cin >> inp;
		if (inp == "x")
			break;
		int rval = dis(gen);
		chrono::milliseconds delay(rval);
		printTimeMsg(clocknow(), startTime, " : on " + to_string(rval));

		// type 1 : 시간 측정을 이용한 딜레이
		/*
		auto lastTime = clocknow();
		while (delay > chrono::duration_cast<chrono::milliseconds>(clocknow() - lastTime));
		*/

		// type 2 : 현재 스레드를 딜레이
		this_thread::sleep_for(delay);

		printTimeMsg(clocknow(), startTime, " : off");
	}
	cout << '\n';
}