#include <iostream>
#include <math.h>

using namespace std;

int A[11];

int solve(int A[], int N, int K)
{
    int min_num = 0;
    int money = K;

    while (N >= 0)
    {
        if((money / A[N]) == 0) {N--; continue;}
        else{
            min_num += money / A[N];
            money -= (money / A[N]) * A[N--];
        }
    }

    return min_num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int num = 0;
    num = solve(A, n-1, k);
    cout << num;

    return 0;
}