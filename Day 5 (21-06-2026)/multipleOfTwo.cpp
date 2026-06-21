#include <iostream>
using namespace std;

void multipleOfTwo(int i, int n)
{
    if (i >10)
    {
        return;
    }
    cout << i * 2 << endl;
    multipleOfTwo(i + 1, n);
}

int main()
{
    int i = 1;
    int n = 10;
    multipleOfTwo(i, n);
}