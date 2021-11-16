#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_WEIGHT 100000
#define MAX_VALUE 1000
#define MAX_SIZE 100

int _value[MAX_WEIGHT + 1];
int _total_value[MAX_WEIGHT + 1];
int _weight, _cnt;

bool isBackpackFull(int weight, int maximum_weight){
    if (_weight + weight > maximum_weight) return true;
    else if (_weight + weight == maximum_weight) {_weight += weight; _total_value[_cnt] += _value[weight]; return true;}
    else {_weight += weight; return false;}
}

void findMaxValue(int weight, int maximum_weight){
    if (weight < 0){
        return;
    }

    for (int i = weight; i >= 0; i--){
        if (_value[i] != -1) {
            if (!isBackpackFull(i, maximum_weight))
                _total_value[_cnt] += _value[i];
            else{
                continue;
            } 
        }
    }
    _cnt++;
    _weight = 0;
    findMaxValue(weight - 1,maximum_weight);
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    int max_weight = 0;
    fill(&_value[0], &_value[MAX_WEIGHT + 1], -1);
    for (int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;
        if (max_weight < w) max_weight = w;
        _value[w] = v;
    }
    fill(&_value[max_weight+1], &_value[MAX_WEIGHT + 1], 0);
    findMaxValue(max_weight, k);

    int max_value = 0;
    for (int i = 0; i <= max_weight; i++){
        if (max_value < _total_value[i]) max_value = _total_value[i];
        // cout << i << ": " << _total_value[i];
        // cout << '\n';
    }
    cout << max_value << '\n';
}