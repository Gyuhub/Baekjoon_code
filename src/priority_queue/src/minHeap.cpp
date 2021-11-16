#include <iostream>

using namespace std;

int array[100001];

// print the smallest value in array and remove it
void remove(int x){
    cout << array[1] << '\n';
    array[1] = 0;
}
// insert the integer in array
void insert(int x){

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 0) remove(x);
        else insert(x);
    }
}