#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 100001

using namespace std;

vector<int> _preorder(MAX_SIZE);
vector<int> _inorder(MAX_SIZE);
vector<int> _postorder(MAX_SIZE);
vector<vector<int>> _index_inorder(MAX_SIZE);

void findPreOrder(int inorder_start, int inorder_end, int postorder_start, int postorder_end){
    // Terminate condition
    if (inorder_start > inorder_end || postorder_start > postorder_end) return;

    int root = _postorder[postorder_end]; // find root
    cout << root << " ";
   // find left side
   findPreOrder(inorder_start, _index_inorder[root][0]-2, postorder_start, postorder_start +  _index_inorder[root][0] - inorder_start - 2);
   // find right side
   findPreOrder(_index_inorder[root][0], inorder_end, postorder_start + _index_inorder[root][0] - inorder_start - 1, postorder_end - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    _preorder.resize(n);
    _inorder.resize(n);
    _postorder.resize(n);
    _inorder.resize(n);
    _preorder.clear();
    _inorder.clear();
    _postorder.clear();

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        _inorder.push_back(m);
    }

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        _postorder.push_back(m);
    }
    // record the index of inorder value 
    // ex) _inorder : 1 4 2 3 5
    //     _index_inorder : 1 3 5 2 5
    for (int i = 1; i <= n; i++)
    {
        _index_inorder[_inorder[i-1]].push_back(i);
    }

    findPreOrder(0, n-1, 0, n-1);
}