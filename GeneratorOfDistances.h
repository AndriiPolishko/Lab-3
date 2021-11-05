#include <vector>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void distGen(int n)
{
	srand(time(NULL));
	
	std::ofstream fout;
	fout.open("Distances.txt");

	vector<vector<int>> distances(n, vector<int>(n));

	if (!fout.is_open()) { std::cout << "The error ocured"; exit(1); }

	int choise;
	std::cout << "PRESS 1 if you want to auto generate matrix of distances or PRESS 2 you want to enter it manually : ";
	std::cin >> choise;

	if (choise == 1) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					fout << -1;
					if (j != n - 1)
						fout << ' ';
					continue;
				}
					
				if(distances[j][i] == 0) {
					distances[i][j] = (rand() % 40) + 1;
					fout << distances[i][j];
					
				}
				else {
					
					distances[i][j] = distances[j][i];
					fout << distances[i][j];
				}

				

				if (j != n - 1)
					fout << ' ';	
			}
			fout << "\n";
		}
	}

	else {
		int temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					fout << -1;
					continue;
				}

				if (j != n - 1)
					fout << ' ';

				std::cout << "Enter value for transit from citie " << i << " to citie " << j << " : ";
				std::cin >> temp;
				fout << temp;
			}
			fout << "\n";
		}
	}
	
}



void printDistances(int n) {
	std::ifstream fin;
	fin.open("Distances.txt");
	if (!fin.is_open()) { std::cout << "Error ocured"; exit(1); }

	std::string tmp;

	std::cout << std::endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> tmp;
			std::cout << std::setw(5) << tmp << " ";

		}
		std::cout << std::endl;

	}

}


std::vector<std::vector<int>> getMatrix(int n) {
	std::vector<std::vector<int>> matrix(n,std::vector<int>(n));
	std::ifstream fin;
	fin.open("Distances.txt");
	if (!fin.is_open()) { std::cout << "Error ocured"; exit(1); }

	std::string tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> tmp;
			matrix[i][j] = stoi(tmp);
		}
	}
	return matrix;
}