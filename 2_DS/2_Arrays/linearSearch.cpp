#include <iostream>
#include <array>

using namespace std;

bool LinearSearch(int arr[], int size, int num)
{
	for(int i = 0; i < size; i++) {
		if (arr[i] == num){
			return 1;
		}
	}

	return 0;
}

int main()
{
	int arr[10] = {2, 64, 22, 76, 43, 234, 344, 67, 23, 1};
	bool ret;

	ret = LinearSearch(arr, 10, 3);

	if(!ret){
		cout<<"Element not found!"<<endl;
	} else {
		cout<<"Element is found"<<endl;
	}

	return 0;
}
