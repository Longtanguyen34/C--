#include <iostream>
using namespace std;
void swap(int &a,int &b )
{
      int temp = a;
      a = b;
      b = temp;
}

void Sapxep(int a[], int n)
{
    int i, j;
    for (int i = 0; i<n -1 ; i++){
        for (int j = n - 1; j>i; j--){
            if (a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int A[12]={240,73,101,21,13,25,11,37,89,30,15,51};
    cout << "Bubble sort:" << endl;
    Sapxep(A, 12);

}