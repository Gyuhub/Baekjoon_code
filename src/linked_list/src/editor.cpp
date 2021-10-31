#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <time.h>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

vector<char> _editor;

int _num;
string _str, _num_str;

int _cursor, _init_length;
bool flag;

inline bool isCursorLeft();
inline bool isCursorRight();
inline void moveCursorLeft();
inline void moveCursorRight();
inline void removeDataAtCursorLeft();
inline void addDataToCursorLeft(char ch);
void solve(int num);

inline bool isCursorLeft()
{
    if (_cursor == 0)
        return true;
    else
        return false;
}

inline bool isCursorRight()
{
    if (_cursor == _editor.size() + 1)
        return true;
    else
        return false;
}
 
inline void moveCursorLeft()
{
    if (!isCursorLeft())
        _cursor -= 1;
}

inline void moveCursorRight()
{
    if (!isCursorRight())
        _cursor += 1;    
}

inline void removeDataAtCursorLeft()
{
    vector<char>::iterator it = _editor.begin();
    if(!isCursorLeft())
        _editor.erase(it + (_cursor--) - 2);
}

inline void addDataToCursorLeft(char ch)
{
    vector<char>::iterator it = _editor.begin();
    if (!isCursorLeft())
        _editor.insert(it + (_cursor++) - 2, ch);
    else
        _editor.insert(_editor.begin(), ch);
}

void solve(int num)
{
    int n=_str.size();
    for (int i = 0; i < n; i++)
    {
        _editor.push_back(_str[i]);
        //cout << _editor.at(i);
    }

    _cursor = _str.size()+1;

    for (int i = 0; i < num; i++)
    { 
        string op;
        getline(cin, op);
        if (op[0] == 'L')
        {
            moveCursorLeft();
        }
        else if (op[0] == 'D')
        {
            moveCursorRight();
        }
        else if (op[0] == 'B')
        {
            removeDataAtCursorLeft();
        }
        else if(op[0] == 'P')
        {
            addDataToCursorLeft(op[2]);
        }
        // cout << "cursor is :" << _cursor << endl;
        // for (auto iter = _editor.begin(); iter < _editor.end(); iter++)
        // {
        //     cout << *iter;
        // }
        //cout << endl;
    }
}

int main()
{
    timespec ts_s,ts_e;
    clock_gettime(CLOCK_MONOTONIC, & ts_s);
    chrono::system_clock::time_point start = chrono::system_clock::now();
  
    getline(cin, _str);
    getline(cin, _num_str);

    _num = stoi(_num_str);

    solve(_num);

    for (auto iter = _editor.begin(); iter < _editor.end(); iter++)
    {
        cout << *iter;
    }
    cout << endl;
    clock_gettime(CLOCK_MONOTONIC, &ts_e);
    chrono::system_clock::time_point end = chrono::system_clock::now();
    chrono :: nanoseconds nano = end - start;
    double time = (ts_s.tv_sec - ts_e.tv_sec) - (ts_s.tv_nsec - ts_e.tv_nsec);
    // printf("time cost with chrono : [%lf]us\n", nano/1000.0);
    // printf("time cost with time.h : [%lf]us\n", time/1000.0);
    return 0;
}