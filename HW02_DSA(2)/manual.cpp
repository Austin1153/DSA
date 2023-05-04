#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

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
        void reset_e() {e = edges.size();}
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
            // print column index
            for (int i = 1; i <= n; i++)
                cout << i << ' ';
            cout << endl;
            for (int i = 1, k = 0; i <= n; i++, k = 0) {
                // print row index
                (i < 10) ? cout << ' ' << i << ' ': cout << i << ' ';
                for (int j = 1; j <= n; j++) {
                    // align
                    if (j > 9) 
                        cout << ' ';
                    
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
                    } else 
                        cout << 0 << ' ';
                }
                cout << endl;
            }
        }
        void print_adj_list() {
            for (int i = 1; i <= n; i++) {
                cout << i << " :";
                for (int j = 0; j < edges[i].size(); j++) {
                    cout << " <-- ";
                    ((edges[i][j] < 10) ? cout << ' ': cout) << edges[i][j];
                }
                cout << endl;
            } 
            cout << endl;
        }
        void print_graph(ofstream &out) {
            out << "Head,Tail" << endl;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < edges[i].size(); j++) {
                    if (edges[i][j] == 0) 
                        break;
                    if (edges[i][j] < i)
                        continue;
                    out << i << ',' << edges[i][j] << endl;
                }
            }
        }
        void DFS_visit(int *color, Graph &G, int node_u) {
            color[node_u-1] = 1;
            for (int i = 0; i < edges[node_u].size(); i++) {
                // if island skip
                if (edges[node_u][i] == 0) break;
                
                if (color[edges[node_u][i]-1] == 0) {
                    cout << edges[node_u][i] << ' ';
                    G.insert_edge(node_u, edges[node_u][i]);
                    DFS_visit(color, G, edges[node_u][i]);
                }
            }
            color[node_u-1] = 2;
        }
        void DFS(Graph &Tree) {
            int *color = new int[n]();
            for (int i = 0; i < n; i++)
                color[i] = 0;
            cout << endl << "DFS Begin" << endl << "discover order : ";
            for (int i = 0; i < n; i++) {
                if (color[i] == 0)  {
                    cout << i+1 << ' ';
                    DFS_visit(color, Tree, i+1);
                }
            }
            cout << endl;
            delete [] color;
            Tree.reset_e();
        }
        void BFS(Graph &Tree) {
            int *color = new int[n]();
            vector<int> queue;
            for (int i = 0; i < n; i++)
                color[i] = 0;
            // Begin BFS
            cout << endl << "BFS Begin" << endl << "discover time : 1 ";
            color[0] = 1;
            queue.push_back(1);

            while(!queue.empty()) {
                int node_u = queue[0];
                queue.erase(queue.begin());

                for (int i = 0; i < edges[node_u].size(); i++) {
                    // if island skip
                    if (edges[node_u][i] == 0) break;

                    if (color[edges[node_u][i] - 1] == 0) {
                        cout << edges[node_u][i] << ' ';
                        Tree.insert_edge(node_u, edges[node_u][i]);
                        color[edges[node_u][i] - 1] = 1;
                        queue.push_back(edges[node_u][i]);
                    }
                }
                color[node_u - 1] = 2;
            }
            cout << endl;
            delete [] color;
            Tree.reset_e();
        }
        void out_adj_list(ofstream &out);
        void out_adj_matrix(ofstream &out);
        void out_tree_md(ofstream &out);
};

int main() {
    int n, e;
    cout << "Enter number of nodes :" << endl;
    cin >> n;
    cout << "Enter number of edges :" << endl;
    cin >> e;

    ofstream out, dfs_out, bfs_out;
    ofstream csv, dfs_csv, bfs_csv;
    out.open("graph.md");
    csv.open("graph.csv");
    dfs_out.open("DFS.md");
    dfs_csv.open("DFS.csv");
    bfs_out.open("BFS.md");
    bfs_csv.open("BFS.csv");

    Graph G(n, e);
    int h, t;
    for (int i = 0; i < e; i++) {
        cout << "enter edge " << i << " head :";
        cin >> h;
        if (h > n || h < 1) {
            cout << "invalid head" << endl;
            i--;
            continue;
        }
        cout << "enter edge " << i << " tail :";
        cin >> t;
        if (t > n || t < 1) {
            cout << "invalid tail" << endl;
            i--;
            continue;
        }

        G.insert_edge(h, t);
    }

    G.out_tree_md(out);
    
    G.sort_edge();

    G.print_adj_list();
    G.print_adj_matrix();
    G.print_graph(csv); 
    
    G.out_adj_list(out);
    G.out_adj_matrix(out);

    // DFS
    Graph DFS_Tree(n ,e); 
    G.DFS(DFS_Tree);

    DFS_Tree.out_tree_md(dfs_out);
    DFS_Tree.sort_edge();

    cout << "DFS Adj List" << endl;
    DFS_Tree.print_adj_list();
    cout << "DFS Adj Matrix" << endl;
    DFS_Tree.print_adj_matrix();
    DFS_Tree.print_graph(dfs_csv);

    DFS_Tree.out_adj_list(dfs_out);
    DFS_Tree.out_adj_matrix(dfs_out);

    // BFS
    Graph BFS_Tree(n, e);
    G.BFS(BFS_Tree);

    BFS_Tree.out_tree_md(bfs_out);
    BFS_Tree.sort_edge();

    cout << "BFS Adj List" << endl;
    BFS_Tree.print_adj_list();
    cout << "BFS Adj Matrix" << endl;
    BFS_Tree.print_adj_matrix();
    BFS_Tree.print_graph(bfs_csv);

    BFS_Tree.out_adj_list(bfs_out);
    BFS_Tree.out_adj_matrix(bfs_out);

    out.close();
    csv.close();
    dfs_out.close();
    dfs_csv.close();
    bfs_out.close();
    bfs_csv.close();

    return 0;
}

void Graph::out_adj_list(ofstream &out) {
    out << "### Adjacent List\n" << endl;
    out << "<table style=\"border-collapse: collapse;\">" << endl;
    for (int i = 1; i <= n; i++) {
        out << '\t' << "<tr>" << endl;
        out << "<th style=\"width: 25px\">[" << i << "]</th>";
        out << "\t\t" << "<th style=\"border: 2px solid #ffffff; width: 25px\"></th>" << endl;
        for (int j = 0; j < edges[i].size(); j++) {
            if (edges[i][j]) {
                out << "\t\t" << "<th>→</th>" << endl;
                out << "\t\t" << "<th style=\"border: 2px solid #ffffff; width: 25px\">" << edges[i][j] << "</th>" << endl;
                out << "\t\t<th style=\"border: 2px solid #ffffff; width: 25px\"></th>" << endl;
            }
        }
        out << "</tr>" << endl;
    }
    out << "</table>\n" << endl;
}

void Graph::out_adj_matrix(ofstream &out) {
    out << "### Adjacent Matrix\n" << endl;
    out << "$$\\begin {array} {cc}\n\\begin {matrix}" << endl;
    for (int i = 0; i < n; i++) 
        out << '&' << ' ' << i+1;
    out << endl;
    out << "\\end {matrix} \\\\" << endl << "\\begin {matrix}" << endl;
    for (int i = 1; i <= n; i++) 
        out << i << ' ' << '\\' << '\\';
    out << endl;
    out << "\\end {matrix}\n\\begin {bmatrix}" << endl;
    for (int i = 1, k = 0; i <= n; i++, k = 0) {
        for (int j = 1; j <= n; j++) {
            if (j - 1)
                out << "& ";
            if (!edges[i][0]) {
                out << 0 << ' ';
                continue;
            }
            if (k >= edges[i].size()) {
                out << 0 << ' ';
                continue;
            }
            if (edges[i][k] == j) {
                out << 1 << ' ';
                k++;
            } else {
                out << 0 << ' ';
            }
        }
        out << "\\\\" << endl;
    } 
    out << "\\end {bmatrix}\n\\end{array}$$\n" << endl;
}

void Graph::out_tree_md(ofstream &out) {
    for (int i = 0; i < e; i++) {
        out << '<' << edges[i][0] << ',' << edges[i][1] << '>' << ' ';
    }

    out << endl << "```mermaid\n graph TD" << endl;
    for (int i = 0; i < n; i++)
        out << '\t' << 'A' << i+1 << '(' << i+1 << ')' << endl;
    for (int i = 0; i < e; i++) {
        out << '\t' << 'A' << edges[i][0] << " --- " << 'A' << edges[i][1] << endl;
    }
    out << "```" << endl;
}
