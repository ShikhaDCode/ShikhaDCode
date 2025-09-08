#include <iostream>

using namespace std;

//with prefix sum
void printLargestSumKadane(int arr[], int size)
{
	int csum = 0;
	int largestSum = 0;

	for(int i = 0; i < size; i++) {
		csum = csum + arr[i];
		if(csum < 0){
			csum = 0;
		}

		largestSum = max(csum, largestSum);
	}

	cout << "Largest Sum = "<< largestSum;
}

int main()
{
	int arr[] = {1, 34, 5, -70, 9, 0, 80};

	printLargestSumKadane(arr, 7);
	return 0;
}
