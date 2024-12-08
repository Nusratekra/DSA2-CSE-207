#include <iostream>
using namespace std;

void swap(int* e1, int* e2) {
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start + 1;

    for (int j = start + 1; j <= end; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[start], &arr[i - 1]);

    return i - 1;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int main() {
    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the value of k: ";
    cin >> k;

    if (k > 0 && k <= n) {
        cout << "\nThe " << k << "-th smallest element is: " << arr[k - 1] << endl;
    } else {
        cout << "\nInvalid value of k." << endl;
    }


    return 0;
}
