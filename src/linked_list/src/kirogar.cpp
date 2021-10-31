#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <list>
#include <chrono>
#include <time.h>

using namespace std;

int main()
{
    timespec ts_s,ts_e;
    clock_gettime(CLOCK_MONOTONIC, & ts_s);
    chrono::system_clock::time_point start = chrono::system_clock::now();

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while (n--)
    { 
        string L;
        cin >> L;
        list<char> arr;
        list<char>::iterator iter = arr.begin();
        
        int L_len = L.size(), L_idx = 0;
        
        while (L_idx < L_len)
        { 
            switch (L[L_idx])
            {
                case '<':
                    if (iter != arr.begin()) iter--;
                    break;
                case '>':
                    if (iter != arr.end()) iter++;
                    break;
                case '-':
                    if (iter != arr.begin()) arr.erase((--iter)++);
                    break;
                default:
                    arr.insert(iter, L[L_idx]);
                    break;
            }
            L_idx++;
        }
        
        for (auto x : arr) printf("%c", x);
        printf("\n");
    }
    return 0;

    clock_gettime(CLOCK_MONOTONIC, &ts_e);
    chrono::system_clock::time_point end = chrono::system_clock::now();
    chrono :: nanoseconds nano = end - start;
    double time = (ts_s.tv_sec - ts_e.tv_sec) - (ts_s.tv_nsec - ts_e.tv_nsec);
    // printf("time cost with chrono : [%lf]us\n", nano/1000.0);
    // printf("time cost with time.h : [%lf]us\n", time/1000.0);
    return 0;
}