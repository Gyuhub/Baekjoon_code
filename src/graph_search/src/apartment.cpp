#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>

#define MAX_ARRAY_SIZE 25

using namespace std;

string _apartment[MAX_ARRAY_SIZE + 2][MAX_ARRAY_SIZE + 2];
bool _visited[MAX_ARRAY_SIZE + 2][MAX_ARRAY_SIZE + 2];
vector<int> _apt;
int _cnt;

void solve(int y, int x)
{
    //TODO: find terminate condition

    _visited[y][x] = true;
    
    for (int i = 0; i < 2; i++)
    {
        if (_visited[y+i][x+i-1] == false) {
            _visited[y+i][x+i-1] = true;
            if (_apartment[y+i][x+i-1] == "1"){
                _cnt++; solve(y+i, x+i-1);
            }
            else if (_apartment[y+i][x+i-1] == "0"){
                
            }
        }
        if (_visited[y-i][x-i+1] == false) {
            _visited[y-i][x-i+1] = true;
            if (_apartment[y-i][x-i+1] == "1"){
                _cnt++; solve(y-i, x-i+1);
            }
            else if (_apartment[y-i][x-i+1] == "0"){
                
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    for (int i =0; i<n+2; i++) {fill(&_apartment[i][0], &_apartment[i][n+2], "*"); fill(&_visited[i][0], &_visited[i][n+2], false);}
    fill(&_visited[0][0], &_visited[0][n+2], 1);
    fill(&_visited[n+1][0], &_visited[n+1][n+2], 1);
    for (int i = 0; i < n+2; i++) {_visited[i][0] = true; _visited[i][n+1] = true;}
    
    // for (int i = 0; i < n+2; i++) {memset(_apartment[i], 9, sizeof(string)*(n+2)); memset(_visited[i], 0, sizeof(bool)*(n+2));}
    // for (int i = 0; i < n+2; i++){
    //     for (int j = 0; j < n+2; j++){
    //         cout << _apartment[i][j];
    //     }
    //     cout << '\n';
    // }
    // for (int i = 0; i < n+2; i++){
    //     for (int j = 0; j < n+2; j++){
    //         cout << _visited[i][j];
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i < n+1; i++){
        string str;
        getline(cin, str);
        for (int j = 1; j < n+1; j++){
            _apartment[i][j] = str[j-1];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (_visited[i][j] == false && _apartment[i][j] == "1"){
                solve(i, j); cnt++; _apt.push_back(_cnt+1); _cnt=0;
            }
        }
    }
    // for (int i = 0; i < n+2; i++){
    //     for (int j = 0; j < n+2; j++){
    //         cout << _apartment[i][j];
    //     }
    //     cout << '\n';
    // }
    cout << cnt << '\n';
    sort(_apt.begin(), _apt.end());
    for (auto v : _apt) {
        cout << v << '\n';
    }
    // cout << '\n';
    // for (int i = 0; i < n+2; i++){
    //     for (int j = 0; j < n+2; j++){
    //         cout << _visited[i][j];
    //     }
    //     cout << '\n';
    // }
}