#include <iostream>
using namespace std;


int power(int a,int b,int n)
{
    int y;
    if (a == 0)
        return 0;

    if (b == 0)
        return 1;

    if (b % 2 == 0) {
        y = power(a, b / 2, n);
        y = (y * y) % n;
    }

    else {
        y = a % n;
        y = (y * power(a, b - 1, n) % n) % n;
    }
    return (int)((y + n) % n);
}

int iterative(int a,int b,int n)
{
    int y = a;
    int counter=1;
    while (b > 0) {

        if (b % 2 == 1)

            y = (y * a);

        else

            y=(y*y)%n;



        b = b >> 1;

    cout<<"Counter:"<<counter++<<"\n";

    }
    return y;
}
// Driver code
int main()
{
    int a = 2;
    int b = 37;
    int n = 12;
    //cout << "Recursive Solution is " << power(a, b, n);
    cout << "\nIterative Solution is " << iterative(a, b, n);
    return 0;
}
