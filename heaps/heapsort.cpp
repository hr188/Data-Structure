#include <iostream>
using namespace std;
class heap{
public:
    int arr[100];
    int size  ;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){

        size = size+1;
        int index = size;
        arr[index]= val;

        while(index>1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void remove(){
        if(size==0){
            cout<<"kuch dal to do "<<endl;
        }
        arr[1]=arr[size];
        size--;
        int i =1;
        while(i<size){
            int leftindex = 2*1;
            int rightindex= 2 *(i+1);

            if(leftindex < size && arr[i] < arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex<size && arr[i] < arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i = rightindex;
            }
            else{
                break;
            }
        }

    }
    
};
void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int l = 2 * i;
        int r = 2 * i + 1;

        if (l <=  n && arr[largest] < arr[l])
        {
            largest = l;
        }
        if (r <=  n && arr[largest] < arr[r])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
void heap_sort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);

        size--;
        heapify(arr, size, 1);
    }
}
int main()
{
    int arr[6] ={-1 ,54,53,55,52,50 };
    int n = 5;
    //heap creation (o(N))
    for (int  i = n/2; i >0; i--)
    {
        heapify(arr , n , i);
    }
    cout<<"printing after heapify"<<endl;
    for (int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    heap_sort(arr,n);
    cout<<"after heap sort"<<endl;
    for (int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }

}