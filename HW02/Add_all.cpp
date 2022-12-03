#include <iostream>
#include <time.h>

using namespace std;

void Add(int **a, int **b, int **c, int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}

int main() {
    clock_t start_t, end_t;
    float total_t = 0;
    int m, n;
    int **a, **b, **c;
    cout.precision(6);

    // cout << "enter size of m, n " << endl;
    // cout << "(m, n) = ";
    // cin >> m >> n;
    for (int times = 1; times < 31; times++) {
        m = times * 100;
        n = m;
        cout << "n = " << n << endl;
        
        a = new int* [n]();
        b = new int* [n]();
        c = new int* [n]();
        
        for (int i = 0; i < m; i++) {
            a[i] = new int [n]();
            b[i] = new int [n]();
            c[i] = new int [n]();
        }
    
        for (int i = 0; i < m; i++) {
            for (int  j = 0; j < n; j++) {
                a[i][j] = 2;
                b[i][j] = 4;
            }
        }
    
        start_t = clock();
        Add(a, b, c, m, n);
        end_t = clock();
        total_t = (float)(difftime(end_t, start_t) / CLOCKS_PER_SEC);
    
        cout << "start time: " << start_t << endl;
        cout << "end time: " << end_t << endl;
        cout << fixed << "total time: " << total_t << " sec\n" << endl;
    
        for (int i = 0; i < m; i++) {
            delete[] a[i];
            delete[] b[i];
            delete[] c[i];
        }
        delete[] a;
        delete[] b;
        delete[] c;
    }
    
    return 0;
}