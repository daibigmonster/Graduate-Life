#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int N;
    while(cin >> N)
    {
        double sum = 0.0;
        for(int i = 1;i <= N;i++)
        {
            sum += 1.0/i;
        }
        printf("%0.4f",sum);
    }
    return 0;
}