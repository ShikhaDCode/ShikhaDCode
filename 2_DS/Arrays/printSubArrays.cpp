#include <iostream>

using namespace std;

void printSubArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			for(int k = i; k < j; k++)
			{
				cout<<arr[k] << " ";
			}

			cout<<endl;
		}
	}
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 0, 8};

	printSubArray(arr, 7);
	return 0;
}
