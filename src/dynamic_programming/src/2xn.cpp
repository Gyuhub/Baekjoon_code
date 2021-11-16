#include <iostream>
#include <math.h>
#include <memory.h>

using namespace std;
// (i+1)H(n-2*i) = (n-i)C(n-2*i)

#define MAX_SIZE 1001

unsigned int dp[MAX_SIZE];

unsigned int square(unsigned int n){
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (dp[n] != -1) return dp[n];
    else{
        return dp[n] = (square(n - 2) + square(n - 1)) % 10007;
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp, -1 ,sizeof(dp));
    int n; cin >> n;
    cout << square(n) % 10007 << '\n';
}