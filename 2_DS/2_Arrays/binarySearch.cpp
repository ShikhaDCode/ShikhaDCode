#include <iostream>
#include <array>

using namespace std;

bool BinarySearch(int arr[], int size, int num)
{
	int mid, low, high;

	low = 0;
	high = size;
	while(low <= high){
		mid = (low + high)/2;

		if(arr[mid] == num){
			return 1;
		} else if(num < arr[mid]){
			high = mid - 1;
		} else if(num > arr[mid]){
			low = mid + 1;
		}
	}

	return 0;
}

int main()
{
	int arr[10] = {1, 2, 22, 23, 43, 64, 67, 76, 234, 344};
	bool ret;

	ret = BinarySearch(arr, 10, 344);

	if(!ret){
		cout<<"Element not found!"<<endl;
	} else {
		cout<<"Element is found"<<endl;
	}

	return 0;
}
