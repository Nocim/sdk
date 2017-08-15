//============================================================================
// Name        : sudoku.cpp
// Author      : Nocim
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Cell {
public:
	void setFinal();
	bool isFinal();
	Cell(int);

	int getFinalNumber() const {
		return finalNumber;
	}

	void setFinalNumber(int finalNumber) {
		this->finalNumber = finalNumber;
	}

	const int* getNumbers() const {
		return numbers;
	}

private:
	int numbers[9];
	int finalNumber;
};

Cell::Cell(int i) {
	if (i != 0) {
		numbers = {0,0,0,0,0,0,0,0,0};
		finalNumber = i;
		return;
	}

	numbers = {1,2,3,4,5,6,7,8,9};
	finalNumber = i;
}

bool Cell::isFinal() {
	int count = 0;
	for (int i = 0; i < 9; i++) {
		if (numbers[i] != 0) {
			count++;
		}
	}
	if (count == 1) {
		return true;
	}
	return false;
}

void Cell::setFinal() {
	for (int i = 0; i < 9; i++) {
		if (numbers[i] != 0) {
			finalNumber = numbers[i];
		}
	}
}

class Sudoku {
public:
	bool isSolved();
	void simpleSolve();
	void printSudoku();
	Sudoku(char const *fileName);
private:
	Cell sudoku[9][9];
};

Sudoku::Sudoku(char const *fileName){
	fstream myFile;
	myFile.open(fileName, ios::in);
	string line;


	while (getline(myFile,line)) {

	}



	myFile.close();
}

bool Sudoku::isSolved() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (!sudoku[x][y].isFinal()) {
				return false;
			}
		}
	}
	return true;
}

void Sudoku::printSudoku(){
	for (int x = 0; x < 9; x++) {
			for (int y = 0; y < 10; y++) {
				if (y == 9) {
					std::cout<<"\n";
				} else {
					std::cout<<sudoku[x][y].getFinalNumber();
				}
			}
		}
}

int main() {

	Sudoku sudoku();

}
