#include <iostream>

using namespace std;

void PrintArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << "a[" << i << "] = " << array[i] << endl;
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

int main() {
    int a[5] = {12,3,15,7,10};
    for (int i = 0; i < 5; i++) 
        cin >> a[i];
    cout << "initial records\n";
    PrintArray(a, 5);

    HeapSort(a, 5);

    cout << "sorted record" << endl;
    PrintArray(a, 5);

    return 0;
}