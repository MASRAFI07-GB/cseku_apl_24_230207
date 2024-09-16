
#include <bits/stdc++.h>
using namespace std;

// cheak prime or not
int isPrime(int ele)
{
    int flag = 0;
    for (int i = 2; i <= sqrt(ele); i++)
    {
        if (ele % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

// sum the digits of the num
int sumofDigits(int ele)
{
    int sum = 0;
    while (ele > 0)
    {
        sum += (ele % 10);
        ele /= 10;
    }

    return sum;
}

int main()
{
    int numofElement;
    cin >> numofElement;
    vector<int> v(numofElement);
    for (auto &it : v)
        cin >> it;
    for (int i = 0; i < numofElement; i++)
    {
        int element = v[i];
        if (isPrime(element))
        {
            v[i] = sumofDigits(element);
        }
    }
    
    for (int i = 0; i < numofElement; i++)
        cout << v[i] << " ";
}
