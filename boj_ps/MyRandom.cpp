#include <random>
#include <iostream>
using namespace std;


int randomInt(int start, int end)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(start, end);
	return dis(gen);
}