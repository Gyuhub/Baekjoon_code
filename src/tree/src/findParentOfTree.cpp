#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

#define MAX_SIZE 100001

queue<int> Q;
vector<vector<int>> TREE;
//vector<bool> MARKED;
vector<int> PARENT;
bool MARKED[MAX_SIZE];

void search(int root)
{
  MARKED[root] = true;
  Q.push(root);

  while(!Q.empty())
  {
    int node = Q.front(); Q.pop();
    MARKED[node] = true;
    
    for(auto child : TREE[node]){
      if(!MARKED[child]){
        MARKED[child] = true;
        PARENT[child] = node;
        Q.push(child);
      }
    }    
    // for (int i = 0; i < TREE[node].size(); i++)
    // {
    //   if (MARKED[TREE[node][i]] != true)
    //   {
    //     MARKED[TREE[node][i]] = true;
    //     PARENT[TREE[node][i]] = node;
    //     Q.push(TREE[node][i]);
    //   }
    // }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  TREE.resize(n + 1);
  PARENT.resize(n + 1);
  TREE[0].push_back(0);
  for (int i = 1; i < n; i++)
  {
    int node1, node2;
    cin >> node1 >> node2;
    TREE[node1].push_back(node2);
    TREE[node2].push_back(node1);
  }
  // for(int i=0; i<=n; i++){
  //     cout<<i<<" : ";
  //     for(auto v:TREE[i])
  //         cout<<v<<' ';
  //     cout<<'\n';
  // }
  search(1);
  for (int i = 2; i <= n; i++)
  {
    cout << PARENT[i] << '\n';
  }
}