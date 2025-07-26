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
    void deleteHeap(){
        if(size==0)
        return;
        arr[1]=arr[size];
        size--;
        int index=1;
        while(index<size){
            int left=(index*2);
            int right=(index*2)+1;
            if(left<size&&arr[left]>arr[index]&&arr[left]>arr[right]){
                swap(arr[left],arr[index]);
            }
           else if(right<size&&arr[right]>arr[index]&&arr[left]<arr[right]){
                swap(arr[right],arr[index]);
            }
            else {
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
   void heapify(int arr[],int n,int i){
        
        int left=2*i;
        int right=(2*i)+1;
        int large=i;
        if(left<n&&arr[left]>arr[large]){
large=left;
        }
        if(right<n&&arr[right]>arr[large]){
large=right;
        }
        if(large!=i){
            swap(arr[large],arr[i]);
            heapify(arr,n,large);
        }
        
    }
int main()
{
    heap h;
    h.insert(23);
    h.insert(2);
    h.insert(12);
    h.insert(112);
    h.insert(121);
    h.insert(91);
 
    h.deleteHeap();
    int a[]={-1,2,23,34,1,67,34,65};
    int n=7;
    for(int i=n/2;i>0;i--)
    heapify(a,n,i);
      for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    h.print();
    return 0;
}