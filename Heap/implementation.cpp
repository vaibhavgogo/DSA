#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int i)
    {
        size++;
        int index = size;
        arr[index] = i;
        while (index > 1)
        {
            int p = index / 2;
            if (arr[p] < arr[index])
            {
                swap(arr[p], arr[index]);
                index = p;
            }
            else
            {
               return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(23);
    h.insert(2);
    h.insert(12);
    h.insert(112);
    h.insert(121);
    h.insert(91);
    h.print();
    return 0;
}