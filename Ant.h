#pragma once
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class Ant {
	float p;//posibility of ant k to go from citie i to citie j
	int place;

	void pathOfOneAnt(int , vector<vector<int>> , vector<vector<float>> , vector<vector<float>> ,int );

	void pCalculation();

public:
	Ant() {
		srand(time(NULL));
		this->place = rand() % 200 + 1;
	}
};