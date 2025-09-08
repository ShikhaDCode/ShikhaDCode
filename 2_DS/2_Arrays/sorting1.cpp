#include<iostream>
#include<vector>

using namespace std;

//{1, 2, 6, 0, 8, 3, 22, 45}

void PrintData(vector<int>& v);

// =================== Bubble Sort ======================== //
void BubbleSort(vector<int>& v)
{
    int n = v.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j+1]);
            }
        }

        // PrintData(v);
    }
}

// =================== Selection Sort ======================== //
//{1, 2, 6, 0, 8, 3, 22, 45} //8
void SelectionSort(vector<int>& v)
{
    int minidx;

    for(int j = 0; j < v.size(); j++){
        minidx = j;
        for(int i = 1 + j; i < v.size(); i++){
            if(v[i] < v[minidx]){
                minidx = i;
            }
        }

        if(minidx != j) {
            swap(v[j], v[minidx]);
        }

        // PrintData(v);
    }

}

// =================== Insertion Sort ======================== //
void InsertionSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

// Partition function (Lomuto, pivot = first element)
int partitionFirtPivot(vector<int>& arr, int low, int high) {
    int pivot = arr[low];   // choose first element as pivot
    int i = low;            // place for smaller elements

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]); // move pivot to its correct place
    return i;               // pivot index
}

// Partition function (Lomuto, pivot = last element)
int Partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high]; //Note: pivot can be first or last element, 
    //if you want to do partition on some other element then you need to swap that element with first or last
    int i = low -1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(vector<int>& arr, int low, int high)
{
    if(low < high){
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void Merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int i = 0; i < n2; i++) {
        R[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void MergeSort(vector<int>& arr, int left, int right)
{
    if(left < right){
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void Heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(vector<int>& arr)
{
    int n = arr.size();

    for(int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }

    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

void PrintData(vector<int>& v)
{
    for(int i : v){
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 6, 0, 8, 3, 22, 45};
    // vector<int> arr = {10, 7, 8, 9, 1, 5};
    vector<int> arr = {12, 0, 0,11, 13, 5, 6, 7, 1, 1};
    int n = arr.size();

    // BubbleSort(v);
    // SelectionSort(v);
    // InsertionSort(v);

    // QuickSort(arr, 0, n - 1);
    // MergeSort(arr, 0, n - 1);

    HeapSort(arr);

    PrintData(arr);
    return 0;
}