// take some marks of some students and sort their marks in ascending order
#include <bits/stdc++.h>
using namespace std;

// sorting them in ascending order
void sort_theMarks(vector<int> &v, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (v[i] > v[j])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// printing the vector of marks
void printMarks(vector<int> v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int num_of_ele;
    cin >> num_of_ele;
    vector<int> students_mark;

    // taking the students marks in the vector
    for (int i = 0; i < num_of_ele; i++)
    {
        int x;
        cin >> x;
        students_mark.push_back(x);
    }

    // printing the marks before sorting
    cout << "before sort:" << endl;
    printMarks(students_mark, num_of_ele);

    sort_theMarks(students_mark, num_of_ele);

    // printing the marks after sorting
    cout << "after sort:" << endl;
    printMarks(students_mark, num_of_ele);
}
