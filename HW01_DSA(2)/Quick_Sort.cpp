#include <iostream>

using namespace std;

void PrintArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << "a[" << i << "] = " << array[i] << endl;
}

void QuickSort(int *array, int left, int right) {
    if (left < right) {
        int i = left, j = right+1, pivot = array[left];
        do {
            do i++; while (array[i] < pivot);
            do j--; while (array[j] > pivot);
            if (i < j) swap(array[i], array[j]);
        } while (i < j);
        swap(array[left], array[j]);
        QuickSort(array, left, j-1);
        QuickSort(array, j+1, right);
    }
}

int main() {
    int a[5] = {12,3,15,7,10};
    for (int i = 0; i < 5; i++) 
        cin >> a[i];
    cout << "initial records\n";
    PrintArray(a, 5);

    QuickSort(a, 0, 4);

    cout << "sorted record" << endl;
    PrintArray(a, 5);

    return 0;
}