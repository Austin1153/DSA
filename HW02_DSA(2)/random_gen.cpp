#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Graph {
    private:
        int n;
        int e;
    public:

};

void random_edge(int n, int e) {
    int arr[(n*(n-1))/2];
    for (int i = 0; i < (n*(n-1))/2; i++)
        arr[i] = 0;
    int count = 0;
    while(count < e) {
        int ran = rand() % ((n*(n-1))/2);
        if (arr[ran] == 1) {
            continue;
        } else {
            arr[ran] = 1;
            count++;
        }
    }

    // testing: list arr
    for (int i = 0; i < (n*(n-1))/2; i++)
        cout << i << ' ';
    cout << endl;
    for (int i = 0; i < (n*(n-1))/2; i++)
        cout << arr[i] << ' ';
    cout << endl;

    // list edges
    for (int i = 0; i < (n*(n-1))/2; i++) {
        if (arr[i] == 1) {
            int j = n-1;
            int head = 1;
            while (i > j-1) {
                j += n-head-1;
                head++;
            }

            // print head
            cout << '<' << head << ',';
            cout << head+1 + (i+1 - (j-n+head+1)) << '>' << endl;
        }
    }

}

int main() {
    int n, e;
    cout << "Enter number of nodes :" << endl;
    cin >> n;
    cout << "Enter number of edges :" << endl;
    cin >> e;


    srand(time(NULL));
    random_edge(n, e);

    return 0;
}