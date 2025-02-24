#include <iostream>
using namespace std;

void Merge(int A[], int B[], int m, int n)
{
    int i=0, j=0, k=0;
    int C[m+n];
    while (i<m && j<n)
    {
        if (A[i]<=B[j])
        {
            C[k]=A[i];
            i++;
        }
        else
        {
            C[k]=B[j];
            j++;
        }
    }
    while (i>=m)
    {
        C[k]=B[j];
        k++; 
        j++;
    }
    while (j>=n)
    {
        C[k]=A[i];
        k++; 
        i++;
    }
    for (int k=0; k<m+n; k++)
    cout << C[k] << " ";
   
}

int main()
{
    int A[4]={15, 30, 201, 303};
    int B[8]={5, 7, 10, 27, 98, 121, 204, 308};
    Merge(A, B, 4, 8);
}