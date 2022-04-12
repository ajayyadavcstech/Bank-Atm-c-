#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;
    void Insert(int val)
    {
        arr[++size] = val;
        int curInd = size;
        while (curInd > 1 && arr[curInd / 2] < arr[curInd])
        {
            swap(arr[curInd], arr[curInd / 2]);
            curInd = curInd / 2;
        }
    }
    void Print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deleteElement()
    {
        if (size == 0)
        {
            cout << "Nothing to delete " << endl;
        }
        arr[1] = arr[size--];
        int i = 1;
        while (i < size)
        {
            int left = i * 2;
            int right = i * 2 + 1;
            if (left <= size && arr[left] > arr[i])
            {
                if (left < size && arr[left] > arr[right])
                {
                    swap(arr[i], arr[left]);
                    i = left;
                }
                else
                {
                    swap(arr[i], arr[left]);
                    i = left;
                }
            }
            else if (right <= size && arr[right] > arr[left] && arr[right] > arr[i])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
                return;
        }
    }
    // void deleteElement() //love babbar code gives wrong output
    // {
    //     if (size == 0)
    //     {
    //         cout << "Nothing to delete " << endl;
    //     }
    //     arr[1] = arr[size--];
    //     int i = 1;
    //     while (i < size)
    //     {
    //         int left = i * 2;
    //         int right = i * 2 + 1;
    //         if (left < size && arr[left] > arr[i] )
    //         {
    //             swap(arr[i], arr[left]);
    //             i = left;
    //         }
    //         else if (right <size && arr[right] > arr[left] )
    //         {
    //             swap(arr[i], arr[right]);
    //             i = right;
    //         }
    //         else
    //             return;
    //     }
    // }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    while (i < size)
    {
        int left = largest * 2;
        int right = largest * 2 + 1;
        if (left <= size && arr[left] > arr[largest])
        {
            if (left < size && arr[left] > arr[right])
            {
                swap(arr[largest], arr[left]);
                largest == left;
            }
            else
            {
                swap(arr[largest], arr[right]);
                largest = left;
            }
        }
        else if (right <= size && arr[right] > arr[largest] && arr[right] > arr[left])
        {
            swap(arr[largest], arr[right]);
            largest = right;
        }
        else
            return;
    }
}
int main()
{
    // heap *h = new heap;
    // h->Insert(60);
    // h->Insert(50);
    // h->Insert(53);
    // h->Insert(30);
    // h->Insert(40);
    // h->Insert(45);
    // h->Insert(35);
    // h->Print();
    // h->deleteElement();
    // h->Print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}