#include "Ant.h"

void Ant::pCalculation() {
	this->p = 0;
}

void Ant::pathOfOneAnt(int current_citie ,vector<vector<int>> distanes, vector<vector<float>> visibility, vector<vector<float>> feromon, int n) {
	float probability;
	vector<int> remaining_cities(n-1);

	for(int i = 0; i < n; i++) {
		if (i != current_citie)
			remaining_cities[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				probability = -1;
				continue;
			}
				
			
		}
	}
}