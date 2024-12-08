#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
  int n;
    cout<<"Enter the value: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"The unsorted array: "<< endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout<<endl;
    bubbleSort(arr, n);
    cout<<"The sorted array: "<< endl;
    printArray(arr, n);
    return 0;
}

