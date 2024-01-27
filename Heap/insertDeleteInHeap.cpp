#include "iostream"
using namespace std;

class Heap{
public:
    int arr[1000];
    int size= 0;
    Heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size+=1;
        int idx=size;
        arr[idx]=val;

        while (idx>1){
            int parent=idx/2;
            if(arr[parent]<arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for (int i = 1; i <=size ; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


//Heapify
void heapify(int arr[],int size,int idx)
    {
        int largest= idx;
        int left=2*idx;
        int right=2*idx+1;
        if(left <size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<size && arr[largest]< arr[right]){
            largest=left;
        }

        if(largest !=idx)
        {
            swap(arr[largest],arr[idx]);
            heapify(arr,size,largest);
        }
    }




//Deletion HEAP
   void deletefromHeap()
   {
        if(size==0){
            cout<<"NOTHING";
            return;
        }

        //shifted last element to 1st index.
        arr[1]=arr[size];
        //remove last element.
        size--;
        //replace it with it correct position
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]< arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size &&arr[i]< arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
   }


};



int  main()
{
     Heap h;
     h.insert(50);
    h.insert(55 );
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
    int n=5;
    int arr[6]= {-1,54,53,55,52,50};
    for (int i = n/2; i >0; --i) {
        h.heapify(arr,n,i);
    }
    for (int i = 1; i <= n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}