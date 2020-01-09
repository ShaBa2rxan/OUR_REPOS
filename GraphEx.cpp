#include <iostream>
#include <cstdlib>

using namespace std;

/*
		This is demonstration of work of the graph

*/


const int n = 9;

int a[n][n] = {
	{0, 1, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 1, 0}
};

bool path_search(int a[][n], int source, int destination, int i) {
	static int counter = 10;
	static bool flag = false;

	//for (int index = 0; index < n; index++) {
	//	if (a[i][index] == 1) {
	//		if (index == destination) { 
	//			flag = true;
	//			break;
	//		}
	//		a[i][index] = counter++;
	//		//a[i][index] = 2;
	//		path_search(a, source, destination, index);
	//	}
	//}

	//for (int index = destination; index > 0; index--) {
	//	if (a[i][index] == 1) {
	//		if (index == destination) {
	//			flag = true;
	//			break;
	//		}
	//		a[i][index] = counter++;
	//		//a[i][index] = 2;
	//		path_search(a, source, destination, index);
	//	}
	//}

	return flag;
}

int main() {


	int source;
	int destination;
	cout << "Source: ";
	cin >> source;
	cout << "Destination: ";
	cin >> destination;
	cout << "Result: " << path_search(a, source, destination, source) << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}



	system("pause");
}