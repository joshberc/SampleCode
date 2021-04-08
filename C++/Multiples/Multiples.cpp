#include <iostream>
#include <algorithm>
#include <stdlib.h>

//Josh Berc - 2021

using namespace std;

/// <summary>
/// Efficiently calculates the Value at position. O(N).
/// </summary>
/// <param name="pos">position to be evaluated</param>
void EfficientCalculate(int pos) {
	//Declares new array the size of pos.
	int * data = new int[pos];
	
	//Keeps track of number of times each multiple is used.
	int twoNum = 0;
	int threeNum = 0;
	int fiveNum = 0;
	//Current multiple value for each.
	int twoMult = 2;
	int threeMult = 3;
	int fiveMult = 5;


	//Knowing 1 is included, manual add.
	data[0] = 1;

	//Loops pos times, O(Pos) == O(N)
	for (int i = 1; i < pos; i++) {
		//stores lowest current multiple in the current array position.
		int temp = min(threeMult, fiveMult);
		data[i] = min(twoMult,temp);

		//Increases to the next multiple relative to last position multiple was used at.
		if (data[i] == fiveMult) {
			fiveNum++;
			fiveMult = 5 * data[fiveNum];
		}
		if (data[i] == threeMult) {
			threeNum++;
			threeMult = 3 * data[threeNum];
		}
		if (data[i] == twoMult) {
			twoNum++;
			twoMult = 2*data[twoNum];
		}	
	}

	//Output
	cout << "Actual: " << data[pos - 1] << endl;

	//Clears array data
	delete[] data;

}

int main() {

	cout << "The value at position 10: " << endl;
	cout << "Expected: 12" << endl;
	//Calculate(10);
	EfficientCalculate(10);

	cout << "The value at position 18: " << endl;
	cout << "Expected: 30" << endl;
	EfficientCalculate(18);

	cout << "The value at position 1500: " << endl;
	cout << "Expected: 859963392" << endl;
	EfficientCalculate(1500);

	return 1;
}