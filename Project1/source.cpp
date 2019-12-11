#include <iostream>
#include "stack.h"
#include <string>
#include "Q.h"
#include <ctime>
#include <fstream>
#include "Car.h"
#include <vector>
#include <Windows.h>
#include "Box.h"
using namespace std;

int getMinServTime(const vector<Box> &boxes) {
	int min_ind = 0;
	for (int i = 1; i < boxes.size(); i++) {
		if (boxes[i].getTotalServingTime() < boxes[min_ind].getTotalServingTime()) {
			min_ind = i;
		}
	}
	return min_ind;
}

int main() {
	ifstream in("inpt2.txt");
	int n;
	cout << "enter number for the boxes:";
	cin >> n;
	vector<Box> boxes(n);
	struct tm s_t;
	Queue<Car> cs;
	time_t cur_time;
	int k = 0, j = 0;
	while (true) {
		Sleep(500);
		time(&cur_time);
		while (!in.eof()) {
			Sleep(800);
			time(&cur_time);
			Car obj;
			in >> obj;
			int ind = getMinServTime(boxes);
			boxes[ind].push(obj);
			cout << obj << " added to " << ind + 1 << "-th box" << endl;
			j++;
			for (int i = 0; i < boxes.size(); i++) {
				if (!boxes[i].empty() && boxes[i].front().getArrivalTime() + boxes[i].front().getDuration() + boxes[i].getTotalWatingTime() <= cur_time) {
						cout << boxes[i].pop() << " is leaved " << endl;
						k++;
						cout << endl;
				}
			}
		}
		for (int i = 0; i < boxes.size(); i++) {
			if (!boxes[i].empty() && boxes[i].front().getArrivalTime() + boxes[i].front().getDuration() + boxes[i].getTotalWatingTime() <= cur_time) {
				cout << boxes[i].pop() << " is leaved " << endl;
				k++;
			}
		}
		if (k == j) {
			break;
		}
	}

	system("pause");
	return 0;
}