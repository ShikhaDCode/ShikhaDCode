#include <iostream>

using namespace std;

void printPairs(int arr[], int size)
{
	for(int i = 0; i < size; i++) {
		for(int j = i + 1; j < size; j++){
			cout<< arr[i] << " " << arr[j] << endl;
		}
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};

	printPairs(arr, 5);
	return 0;
}
