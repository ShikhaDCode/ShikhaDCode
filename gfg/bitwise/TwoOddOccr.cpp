#include <iostream>
using namespace std;

void oddAppearing(int arr[], int n)
{
    int xors = 0, res1 = 0, res2 = 0; 
    
    xors = arr[0];
    for (int i = 1; i < n; i++) 
        xors = xors ^ arr[i]; 

    int sn = xors & (~(xors - 1));  // get first set bit
    //cout << sn << endl;

    for (int i = 0; i < n; i++) 
    { 
        if ((arr[i] & sn) != 0) 
            res1 = res1 ^ arr[i]; 
        else
            res2 = res2 ^ arr[i]; 
    }
    
    cout <<  res1 << " " << res2 << endl;
}
    
int main() {
	
	int arr[]= {3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, n = 10;
	
    oddAppearing(arr, n);
    
    return 0;
}