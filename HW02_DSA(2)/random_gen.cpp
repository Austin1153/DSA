#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Graph {
    private:
        int n;
        int e;
        vector<vector<int> > edges;
    public:
        Graph(int ns, int es) {
            n = ns, e = es;
        }
        void insert_edge(int head, int tail) {
            vector<int> edge;
            edge.push_back(head);
            edge.push_back(tail);
            edges.push_back(edge);
        }
        void sort_edge() {
            vector<vector<int> > elist;
            
            // init with <0>
            vector<int> tmp;
            tmp.push_back(0);
            for (int i = 0; i <= n; i++)
                elist.push_back(tmp);
            
            // sort, vertax for 1 to n
            for (int i = 0; i < e; i++) {
                // link for first vertax
                if (elist[edges[i][0]][0] == 0) {
                    elist[edges[i][0]][0] = edges[i][1];
                } else
                    elist[edges[i][0]].push_back(edges[i][1]);
                // link for 2nd vertax
                if (elist[edges[i][1]][0] == 0) {
                    elist[edges[i][1]][0] = edges[i][0];
                } else
                    elist[edges[i][1]].push_back(edges[i][0]);
            }
            edges = elist;
        }
        void print_adj_matrix() {
            cout <<"   ";
            for (int i = 1; i <= n; i++)
                cout << i << ' ';
            cout << endl;
            for (int i = 1, k = 0; i <= n; i++, k = 0) {
                (i < 10) ? cout << ' ' << i << ' ': cout << i << ' ';
                for (int j = 1; j <= n; j++) {
                    if (!edges[i][0]) {
                        cout << 0 << ' ';
                        continue;
                    }
                    if (k >= edges[i].size()) {
                        cout << 0 << ' ';
                        continue;
                    }
                    if (edges[i][k] == j) {
                        cout << 1 << ' ';
                        k++;
                    } else {
                        cout << 0 << ' ';
                    }
                }
                cout << endl;
            }
        }
        void print_adj_list() {
            for (int i = 1; i <= n; i++) {
                cout << i << " :";
                for (int j = 0; j < edges[i].size(); j++) {
                    cout << " <-- " << edges[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }

};

void random_edge(Graph &G, int n, int e) {
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

    // list edges & store edges
    for (int i = 0, e = 0; i < (n*(n-1))/2; i++) {
        if (arr[i] == 1) {
            int j = n-1;
            int head = 1;
            while (i > j-1) {
                j += n-head-1;
                head++;
            }

            G.insert_edge(head, head+1 + (i+1 - (j-n+head+1)));

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

    Graph G(n, e);


    srand(time(NULL));
    random_edge(G, n, e);
    G.sort_edge();
    cout << "G-print" << endl;
    G.print_adj_list();
    G.print_adj_matrix();

    return 0;
}