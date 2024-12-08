#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout<<"Enter the value: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"The unsorted array: "<< endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout<<endl;
    selectionSort(arr, n);
    cout<<"The sorted array: "<< endl;
    printArray(arr, n);
    return 0;
}

