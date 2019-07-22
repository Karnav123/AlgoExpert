#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
	// Write your code here.
	int maxSoFar = array[0];
	int maxGlobal = array[0];

	for (int i = 1; i < array.size(); ++i)
	{
		int temp = maxSoFar + array[i];
		maxSoFar = max(array[i], temp);
		maxGlobal = max(maxSoFar, maxGlobal);
	}

	return maxGlobal;
}
