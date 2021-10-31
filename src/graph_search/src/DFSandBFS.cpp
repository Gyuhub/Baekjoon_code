#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_SIZE 1001

queue<int> _TODO;
vector<vector<int>> _node;
bool _visited[MAX_SIZE];

void DFS(int start)
{
    if (start == 0) return;

    _visited[start] = true;
    cout << start << " ";
    for (auto n : _node[start])
        if (_visited[n] == false) DFS(n);
}

void BFS(int start)
{
    _visited[start] = true;
    _TODO.push(start);
    cout << start << " ";

    while (!_TODO.empty())
    {
        int node = _TODO.front(); _TODO.pop();
        _visited[node] = true;
        for (auto next : _node[node]){
            if(!_visited[next]){
                _visited[next] = true;
                cout << next << " ";
                _TODO.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    _node.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int node1 = 0, node2 = 0;
        cin >> node1 >> node2;

        _node[node1].push_back(node2);
        _node[node2].push_back(node1);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(_node[i].begin(), _node[i].end());
    }
    
    DFS(v);
    memset(_visited,0,sizeof(bool)*(n+1));
    cout << '\n';
    BFS(v);
    
    // for (int i = 1; i <= n; i++){
    //     cout << i << ":";
    //     for (auto v : _node[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << '\n';
    // }
}