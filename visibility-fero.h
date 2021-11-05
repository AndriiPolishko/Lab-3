#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void smellGen(int n) {
	srand(time(NULL));
	ofstream fout;
	fout.open("Smell.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if(i==j) {
				if (j < n - 1)
					fout << -1.0 << " ";
				else
					fout << -1.0;
				continue;
			}
			if (j < n - 1)
				fout << 1.0 << " ";//<< (float)((rand() % 3) + 1) / 10 << " ";
			else
				fout << 1.0 ;//<< (float)((rand() % 3) + 1) / 10;
		}
		if(i<n-1)
			fout << endl;
	}
}

void visibilityGen(int n, vector<vector<int>> distances) {
	srand(time(NULL));
	ofstream fout;
	fout.open("Visibility.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (i == j) {
				fout << -1;
				if (j < n - 1)
					fout << " ";
				continue;
			}
			if (j < n - 1)
				fout << setprecision(2) << (float)1/distances[i][j] << " ";//(float)((rand() % 10) + 1) / 10 << " ";
			else
				fout << setprecision(2) << (float)1 / distances[i][j]; //(float)((rand() % 10) + 1) / 10;
		}
		if (i < n - 1)
			fout << endl;
	}
}

std::vector<std::vector<float>> getSmell(int n) {
	std::vector<std::vector<float>> matrix(n, std::vector<float>(n));
	std::ifstream fin;
	fin.open("Smell.txt");
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

std::vector<std::vector<float>> getVisibility(int n) {
	std::vector<std::vector<float>> matrix(n, std::vector<float>(n));
	std::ifstream fin;
	fin.open("Visibility.txt");
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