#include <iostream>
using namespace std;

void MergeArrays(int a[],int m, int n, int p){
	int i= m,j= n+1;
	while (i< j && j<= p){
		if (a[i] <= a[j]) i++;
		else {
			int x= a[j];
			for (int k= j-1;k>= i;k--) 
				a[k+1]= a[k];
			a[i]= x;
			i++; j++;
		}
	}
    
}

void SplitMerg(int a[], int trc, int sau){
	if (trc>=sau) return;
	int m=(trc+sau)/2;
	SplitMerg(a, trc, m); 
	SplitMerg(a, m+1, sau); 
	MergeArrays(a, trc, m, sau); 
}

void MergeSort(int a[], int n){
	if (n < 2) return;
	SplitMerg(a, 0, n-1);
}

int main()
{
    int a[]={240, 51, 73, 101, 21, 13, 25, 11, 37, 89, 30, 15};
    MergeSort(a, sizeof(a)/sizeof(a[0]));
    for (int i=0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        cout << a[i] << " "; 
    }
}