#include <iostream>

using namespace std;

int array[100001];
int heap_size;

// print the smallest value in array and remove it
void remove(int x){
    int smallest = array[1];
    array[1] = array[heap_size--];
    // cout << smallest << '\n';
    int i = 1;
    while (i <= heap_size) {
        int smaller = 0;
        int smaller_index = 0;
        if (i < heap_size && (array[i*2] < array[i*2+1])) {smaller = array[i*2]; smaller_index = i*2;}
        else {smaller = array[i*2+1]; smaller_index = i*2+1;}
        if (array[smaller_index/2] < array[smaller_index]) break;
        int temp = array[i];
        array[i] = smaller;
        array[smaller_index] = temp;
        i = smaller_index;
    }
    for (int i = 1; i <= heap_size; i++) cout << array[i] << ' ';
    cout << '\n';
    // if (heap_size == 1) cout << array[1] << '\n';
    // else {
    //     cout << array[1] << '\n';
    //     for (int i = 2; i <= heap_size; i++)
    //         array[i - 1] = array[i];
    //     heap_size--;
    // }
    // return;
}
// insert the integer in array
void insert(int x){
    int i = heap_size++;
    array[i] = x;
    while (i != 1 && array[i] < array[i / 2])
    {
        int temp = array[i];
        array[i] = array[i / 2];
        array[i / 2] = temp;
        i = i / 2;
    }
    // int max = array[1];
    // int idx = 1;
    // for (int i = idx; i <= heap_size; i++) {
    //     if (max <= x) {
    //         max = array[i];
    //         idx = i;
    //     }
    //     else continue;
    // }
    // for (int j = heap_size; j >= idx; j--)
    //     array[j + 1] = array[j];
    // array[idx] = x;
    // heap_size++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; heap_size = 1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 0) remove(x);
        else insert(x);
    }
}