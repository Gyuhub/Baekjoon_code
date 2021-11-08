#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
// (i+1)H(n-2*i) = (n-i)C(n-2*i)

int factorial( int num )
{
	if( num == 1 )
	{
		return 1;
	}

	return num * factorial( num-1 );
}


int square(int n){
    if (n <= 4){
        switch (n)
        {
        case 4:
            result = 5;
            break;
        case 3:
            result = 3;
            break;
        case 2:
            result = 2;
            break;
        case 1:
            result = 1;
            break;
        
        default:
            break;
        }
        return result;
    }
    int result = 0;
    for (int i = 0; i <= n / 2; i++){
        // cout << i << ": ";
        if (i == 0) result += 1;
        else result += factorial(n-i)/(factorial(i)*factorial(n-2*i));
        // cout << "res:" << result << '\n';
    }
    return result;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout << square(n) % 10007 << '\n';
}