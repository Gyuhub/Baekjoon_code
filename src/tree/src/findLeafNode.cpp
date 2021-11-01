#include <iostream>
#include <vector>

#define MAX_SIZE 51
using namespace std;

vector<vector<int>> _node(MAX_SIZE);
bool _is_visited[MAX_SIZE];
bool _has_parent[MAX_SIZE];

int _size;

void DFS(int node, int target){
    if (node == -1) return;

    _is_visited[node] = true;
    cout << node << " ";
    for (int i = node; i < _size; i++)
        if (_is_visited[i] == false)
            for (auto &n : _node[i]) {
                if (n == node) {
                    n = -2;
                    DFS(i, i);
                }
            }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    int n; cin >> n;
    _size = n;
    _node.resize(n + 1);
    for (int i = 0; i < n; i++) { int m; cin >> m; _node[i].push_back(m); }

    int k; cin >> k;
    DFS(0, k);
    cout << '\n';

    for (int i = 0; i < n; i++){
        cout << i << ": ";
        for (auto v : _node[i]) cout << v << " ";
        cout << '\n';
    }

    // for (int i = 0; i < n; i++){
    //     cout << i << " has parent? : " << _has_parent[i] << '\n';
    // }
}