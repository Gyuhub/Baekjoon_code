#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <time.h>
#include <string>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

Eigen::VectorXi _hanoi_0;
Eigen::VectorXi _hanoi_1;
Eigen::VectorXi _hanoi_2;
Eigen::MatrixXi _hanoi;

int m;
int itr = 0;

void hanoiTower(int num_rings, int from, int tmp, int to)
{
    if (num_rings == 1)
    {
        // cout << "Move ring 1 from " << from << " to " << to << endl;
        int sz_0 = _hanoi_0.count();
        int sz_1 = _hanoi_1.count();
        int sz_2 = _hanoi_2.count();
        switch (from)
        {
        case 0:
            if (to == 1)
            {
                _hanoi_1(m -1 - sz_1) = _hanoi_0(m - sz_0);
                _hanoi_0(m - sz_0) = 0;
            }
            else
            {
                _hanoi_2(m -1 - sz_2) = _hanoi_0(m - sz_0);
                _hanoi_0(m - sz_0) = 0;
            }
            break;
        case 1:
            if (to == 0)
            {
                _hanoi_0(m -1 - sz_0) = _hanoi_1(m - sz_1);
                _hanoi_1(m - sz_1) = 0;
            }
            else
            {
                _hanoi_2(m -1 - sz_2) = _hanoi_1(m - sz_1);
                _hanoi_1(m - sz_1) = 0;
            }
            break;
        case 2:
            if (to == 1)
            {
                _hanoi_1(m -1 - sz_1) = _hanoi_2(m - sz_2);
                _hanoi_2(m - sz_2) = 0;
            }
            else
            {
                _hanoi_0(m -1 - sz_0) = _hanoi_2(m - sz_2);
                _hanoi_2(m - sz_2) = 0;
            }
            break;
        default:
            break;
        }
        _hanoi.col(0) = _hanoi_0;
        _hanoi.col(1) = _hanoi_1;
        _hanoi.col(2) = _hanoi_2;
        cout << _hanoi << endl;
        cout << "Iteration : "<< ++itr <<" --------------------" << endl;
    }
    else
    {
        hanoiTower(num_rings - 1, from, to , tmp);
        // cout << "Move ring " << num_rings << " from " << from << " to " << to << endl;
        int sz_0 = _hanoi_0.count();
        int sz_1 = _hanoi_1.count();
        int sz_2 = _hanoi_2.count();
        switch (from)
        {
        case 0:
            if (to == 1)
            {
                _hanoi_1(m -1 - sz_1) = _hanoi_0(m - sz_0);
                _hanoi_0(m - sz_0) = 0;
            }
            else
            {
                _hanoi_2(m -1 - sz_2) = _hanoi_0(m - sz_0);
                _hanoi_0(m - sz_0) = 0;
            }
            break;
        case 1:
            if (to == 0)
            {
                _hanoi_0(m -1 - sz_0) = _hanoi_1(m - sz_1);
                _hanoi_1(m - sz_1) = 0;
            }
            else
            {
                _hanoi_2(m -1 - sz_2) = _hanoi_1(m - sz_1);
                _hanoi_1(m - sz_1) = 0;
            }
            break;
        case 2:
            if (to == 1)
            {
                _hanoi_1(m -1 - sz_1) = _hanoi_2(m - sz_2);
                _hanoi_2(m - sz_2) = 0;
            }
            else
            {
                _hanoi_0(m -1 - sz_0) = _hanoi_2(m - sz_2);
                _hanoi_2(m - sz_2) = 0;
            }
            break;
        default:
            break;
        }
        _hanoi.col(0) = _hanoi_0;
        _hanoi.col(1) = _hanoi_1;
        _hanoi.col(2) = _hanoi_2;
        cout << _hanoi << endl;
        cout << "Iteration : "<< ++itr <<" --------------------" << endl;
        hanoiTower(num_rings - 1, tmp, from , to);
    }
}

int main()
{
    timespec ts_s,ts_e;
    clock_gettime(CLOCK_MONOTONIC, & ts_s);
    chrono::system_clock::time_point start = chrono::system_clock::now();
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n = 0;
    bool flag = false;
    while (!flag)
    {
        cout << "Enter the initial position of rings of hanoi tower!! You can choose from 0 to 2...\nInitial Position : ";
        cin >> n;
        cin.ignore();
        if (n >= 0 && n <=2)
        {
            flag = true;
        }
        else
        {
            cout << "You type a wrong number!!! Please type a correct number...";
        }
    }

    cout << "\nEnter the number of rings of hanoi tower!! : ";
    cin >> m;
    cin.ignore();
    _hanoi_0.setZero(m);
    _hanoi_1.setZero(m);
    _hanoi_2.setZero(m);
    _hanoi.setZero(m, 3);
    int k;
    bool bl = false;
    while (!bl)
    {
        cout << "\nEnter the number of goal which you want to move the rods. Initial number of goal is " << n << ".\nThe number of goal is varing from 0 to 2\nGOAL : ";
        cin >> k;
        cin.ignore();
        if (k != n)
        {
            bl = true;
        }
        else
        {
            cout << "You type a same number with start position!!! Please type a correct number...";
        }
    }
    int l;
    int idx = m;
    if (n == 0)
    {
        if (k == 2) l = 1; 
        else if (k == 1) l = 2;
        for (int i = m; i > 0; i--)
        {
            _hanoi_0(--idx) = i;
        }
        
    }
    else if (n == 1)
    {
        if (k == 2) l = 0;
        else if (k == 0) l = 2;
        for (int i = m; i > 0; i--)
        {
            _hanoi_1(--idx) = i;
        }
    }
    else
    {
        if (k == 0) l = 1;
        else if (k == 1) l = 0;
        for (int i = m; i > 0; i--)
        {
            _hanoi_2(--idx) = i;
        }
    }
    _hanoi.col(0) = _hanoi_0;
    _hanoi.col(1) = _hanoi_1;
    _hanoi.col(2) = _hanoi_2;
    cout << "Start!!!" << endl;
    cout << _hanoi << endl;
    cout << "Iteration : "<< itr <<" --------------------" << endl;
    hanoiTower(m, n, l, k);
    cout << "End..." << endl;
    cout << "Total iterations : " << itr << endl;
    clock_gettime(CLOCK_MONOTONIC, &ts_e);
    chrono::system_clock::time_point end = chrono::system_clock::now();
    chrono :: nanoseconds nano = end - start;
    double time = (ts_s.tv_sec - ts_e.tv_sec) - (ts_s.tv_nsec - ts_e.tv_nsec);
    printf("time cost with chrono : [%lf]us\n", nano/1000.0);
    printf("time cost with time.h : [%lf]us\n", time/1000.0);
    return 0;
}