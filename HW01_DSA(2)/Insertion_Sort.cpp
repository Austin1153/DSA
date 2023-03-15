#include <iostream>

using namespace std;

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

int main() {
    int a[6] = {0,12,3,15,7,10};
    for (int i = 1; i < 6; i++) 
        cin >> a[i];
    cout << "initial records\n";
    PrintArray(a, 6);

    InsertionSort(a, 5);

    cout << "sorted record" << endl;
    PrintArray(a, 6);

    return 0;
}