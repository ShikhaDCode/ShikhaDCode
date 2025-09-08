#include <iostream>

using namespace std;

void printLargestSubArraySum(int arr[], int size)
{
	int sum = 0;
	int largestSum = arr[0];
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
			if(sum > largestSum){
				largestSum = sum;
			}

			sum = 0;
		}
	}

	cout << "Largest Sum = "<< largestSum;
}

//with prefix sum
void printLargestSubArraySum2(int arr[], int size)
{
	int prefix[100] = {0};
	int sum = 0;
	int largestSum = arr[0];

	prefix[0] = arr[0];
	for(int i = 1; i < size; i++)
	{
		prefix[i] = arr[i] + prefix[i - 1];
	}

	for(int i = 0; i < size; i++)
	{
		for(int j = i; j < size; j++)
		{
			sum = i > 0 ? (prefix[j] - prefix[i - 1]) : prefix[j];
			cout << " : sum = " << sum << endl;
			if(sum > largestSum){
				largestSum = sum;
			}

			sum = 0;
		}
	}

	cout << "Largest Sum = "<< largestSum;
}

int main()
{
	int arr[] = {1, 34, 5, 70, 9, 0, 80};

	printLargestSubArraySum(arr, 7);
	printLargestSubArraySum2(arr, 7);
	return 0;
}
