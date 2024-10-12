#include <iostream>
using namespace std;
void hd(int &a, int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
       
}
int main()
{
    int x, y;
    int c;
    cin >> x >> y;
    hd (x, y);
    cout << x << y;

}