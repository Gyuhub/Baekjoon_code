#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

#define MAX_SIZE 101

using namespace std;

vector<vector<int>> _computer;
bool _visited[MAX_SIZE];
int cnt;

void solve(int root) // DFS
{
    if (root == 0) return;
    _visited[root] = true;
    for (auto next : _computer[root])
        if (_visited[next] == false) {_visited[next] = true; solve(next); cnt++;}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);

    int n, m;
    cin >> n;
    cin.ignore();
    cin >> m;

    _computer.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int node1 = 0, node2 = 0;
        cin >> node1 >> node2;
        _computer[node1].push_back(node2);
        _computer[node2].push_back(node1);
    }
    
    solve(1);
    cout << cnt;
    // for (int i = 1; i <= n; i++){
    //     cout << i << " : ";
    //     for (auto c : _computer[i]) cout << c << " ";
    //     cout << '\n';
    // }
}