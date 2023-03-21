#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Random(int *arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%50000;
    }
}

int main() {
    int n;
    cout << "Enter how many random numbers to generate: ";
    cin >> n;
    int *arr = new int[n]();
    Random(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}