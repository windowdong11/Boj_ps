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
	// ���� �ð��� �޼��� ���
	// ex) 123ms : hello
	cout << chrono::duration_cast<chrono::milliseconds>((lastTime - startTime)).count() << "ms : "<< msg << '\n';
}


void stupidProgram()
{
	// �ٺ�����
	/*
		x�� ������ ����,
		�ƹ� Ű�� �Է½� ���� on, ���� �ð�(200 ~ 3000 ms) �� off���·� �ǵ��ư�
	*/
	// �Ʒ� 3�� ��ó : cppreference.com
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

		// type 1 : �ð� ������ �̿��� ������
		/*
		auto lastTime = clocknow();
		while (delay > chrono::duration_cast<chrono::milliseconds>(clocknow() - lastTime));
		*/

		// type 2 : ���� �����带 ������
		this_thread::sleep_for(delay);

		printTimeMsg(clocknow(), startTime, " : off");
	}
	cout << '\n';
}