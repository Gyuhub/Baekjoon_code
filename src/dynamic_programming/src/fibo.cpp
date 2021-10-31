#include <iostream>

using namespace std;

int _z, _o;

void fibo_cal(int num)
{
    //if (num == 0) {cout << num << '\n'; return;}
    //else if (num == 1) {cout << num-1 << " " << num << '\n'; return;}
    int arr[num+1] = {0,};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    //cout << arr[0] << " " << arr[1] << " " << arr[2] << " ";
    for (int i = 3; i <= num+1; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
        //cout << arr[i] << " ";
    }
    if (num == 0) {cout << "1 0" << '\n'; return;}
    else if (num == 1) {cout << "0 1" << '\n'; return;}
    else cout << arr[num-1] << " " << arr[num];
    cout << '\n';
    return;
    // if (num == 0) {_z++; return;}
    // else if (num == 1) {_o++; return;}
    // else {
    //     fibo_cal(num-1); fibo_cal(num-2);
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        fibo_cal(N);
        //cout << _z << " " << _o << '\n';
        _z = 0;
        _o = 0;
    }
    

    return 0;
}