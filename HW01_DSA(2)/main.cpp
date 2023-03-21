#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Random(int *arr, int m, int n) {
    srand(time(NULL));
    for (int i = m; i < n; i++) {
        arr[i] = rand()%50000;
    }
}

void PrintArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << "a[" << i << "] = " << array[i] << endl;
}

void InsertionSort(int *array, int n) {
    for (int i = 2, j = i; i <= n; i++, j = i) {
        array[0] = array[i];
        // Insert
        while (array[0] <= array[j-1]) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = array[0];
    }
}
// input[root:n](1-indexed), Adjust to max heap
void Adjust(int *array, int root, int n) {
    int buf = array[root-1], j;
    for (j = 2*root; j <= n; j*=2) {
        if (array[j-1] < array[j] && j < n) j++;
        if (buf > array[j-1]) break;
        array[j/2 - 1] = array[j-1];
    }
    array[j/2 - 1] = buf;
}
// sort array[1:n]
void HeapSort(int *array, int n) {
    // create heap
    for (int i = n/2; i > 0; i--)
        Adjust(array, i, n);
    // sorting
    for (int i = n-1; i > 0; i--) {
        swap(array[0], array[i]);
        Adjust(array, 1, i);
    }
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
    int n, SortType, m;
    cout << "Enter Sorting Type:\n0: Insertion\n1: Heap\n2:Quick\n";
    cin >> SortType;
    cout << "Enter how many random numbers to generate: ";
    cin >> n;

    // Initial Array
    m = SortType ? n+1 : n;
    int *arr = new int[m]();
    //init Random int array
    Random(arr, 1, n+1);
    PrintArray(arr, n+1);
    // Insertion sort
    InsertionSort(arr, n);
    PrintArray(arr, n+1);

    delete [] arr;

    return 0;
}