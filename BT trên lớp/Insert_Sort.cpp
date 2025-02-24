#include <iostream>
using namespace std;

void InsertionSort(int A[], int n)
{   
     for (int i = 1; i < n; i++){
           int x = A[i];
           int j = i;
           while (j > 0 && A[j - 1] > x){
            A[j] = A[j - 1];
             j--;
            }
            A[j] = x;
      for (int i=0; i < n; i++)
        cout << A[i] << " ";
        cout << endl;
      }
      
}
int main()
{
    int A[12]={240,73,101,21,13,25,11,37,89,30,15,51};
    cout << "Insertion sort:"  << endl;
    InsertionSort(A, 12);

}