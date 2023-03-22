#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#define EX_FILE_NAME "Heap.csv"
using namespace std;

void Random(int *arr, int mode, int n) {
    srand(time(NULL));
    mode = (!mode) ? 1 : 0;
    for (int i = mode; i < n; i++) {
        arr[i] = (rand())%50000;
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
        while (array[0] < array[j-1]) {
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
    clock_t start_t, end_t;
    float total_t;
    ofstream out;
    string type[3] = {"Insertion", "Heap", "Quick"};

    cout << "Enter Sorting Type:\n0: Insertion\n1: Heap\n2: Quick\n";
    cin >> SortType;
    // cout << "Enter how many random numbers to generate: ";
    // cin >> n;

    out.open(EX_FILE_NAME);
    out << type[SortType] << endl;
    for (int i = 10; i <= 100000; i*=10) (i == 100000) ? out << i << endl : out << i << ',';

    for (int ii = 0; ii < 10; ii++) {
        for (n = 10; n <= 100000; n *= 10) {
            // Initial Array
            m = SortType ? n : n+1;
            int *arr = new int[m]();

            // Randomize int array
            Random(arr, SortType, m);
            // cout << "The Random Number Generate as below\n";
            // PrintArray(arr, m);
            // cout << "--------------------" << endl;
            
            // Sorting Selection
            switch (SortType) {
            case 0: //Insertion Sort
                start_t = clock();
                InsertionSort(arr, n);
                end_t = clock();
                break;
            case 1: //Heap Sort
                start_t = clock();
                HeapSort(arr, n);
                end_t = clock();
                break;
            case 2: //Quick Sort
                start_t = clock();
                QuickSort(arr, 0, n-1);
                end_t = clock();
                break;
            }

            cout << type[SortType] << " Sort Result" << endl;
            // PrintArray(arr, m);
            total_t = (float)(difftime(end_t, start_t) / CLOCKS_PER_SEC);

            cout << "n = " << n << "; " << ii << "th times" << endl;
            cout << "start time: " << start_t << endl;
            cout << "end time: " << end_t << endl;
            cout << fixed << "total time: " << total_t << "sec\n" << endl;
            out << fixed << total_t;
            (n == 100000) ? out << endl : out << ',';

            delete [] arr;
        }
    }

    out.close();

    return 0;
}