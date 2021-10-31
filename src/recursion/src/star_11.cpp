#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <time.h>
#include <string>
#include <math.h>

using namespace std;

//char STAR[3*(2^10)][6*(2^10)];
char STAR[10000][10000];
/**
 * @brief Recursive star function that print stars with respect to the rule 
 * @param h height of entire star
 * @param x x position of entire star
 * @param y y position of entire star. (0,0) is a left-up side point
 */
void star(int h, int x, int y)
{
    if (h == 3)
    {
        STAR[y][x] = '*';
        STAR[y + 1][x - 1] = '*';
        STAR[y + 1][x + 1] = '*';
        STAR[y + 2][x - 2] = '*';
        STAR[y + 2][x - 1] = '*';
        STAR[y + 2][x] = '*';
        STAR[y + 2][x + 1] = '*';
        STAR[y + 2][x + 2] = '*';
        return;
    }
    else
    {
        star(h / 2, x, y);
        star(h / 2, x - (h / 2), y + (h / 2));
        star(h / 2, x + (h / 2), y + (h / 2));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; // Enter the number of input
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            if (j == 2 * n - 1) STAR[i][j] = '\0';
            else STAR[i][j] = ' ';
        }
    }
    star(n, n-1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n-1; j++)
        {
            cout << STAR[i][j];
        }
        cout << endl;
    }
    return 0;
}