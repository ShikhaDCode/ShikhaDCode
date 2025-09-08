#include <iostream>

using namespace std;

void printSubArraySum(int arr[], int size)
{
	int sum = 0;
	for(int i = 0; i < size; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			for(int k = i; k < j; k++)
			{
				cout<<arr[k] << " ";
				sum += arr[k];
			}

			cout << " : sum = " << sum << endl;
			sum = 0;
		}
	}
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 0, 8};

	printSubArraySum(arr, 7);
	return 0;
}
