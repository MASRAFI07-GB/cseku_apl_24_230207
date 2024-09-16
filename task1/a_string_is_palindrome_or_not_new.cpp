
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
// cheak whether the string is palindrome or not
int isPalidrome(char s1[])
{
    int length = strlen(s1);
    char s2[100];
    int z = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        s2[z++] = s1[i];
    }
    s2[z] = '\0';
    int flag = strcmp(s1, s2);
    if (flag == 0)
        return 1;
    else
        return 0;
}
int main()
{
    int numofString;
    cin >> numofString;
    char name[numofString][100];
    for (int i = 0; i < numofString; i++)
    {
        scanf("%s", name[i]);
    }

    for (int i = 0; i < numofString; i++)
    {
        if (isPalidrome(name[i]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
