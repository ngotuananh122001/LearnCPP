#include <iostream>
#include <cstring>
using namespace std;

// Đệ quy phi tuyên
// Lời gọi đệ quy nằm trong một vòng lặp
// => rất khó để khử đệ quy
long A(int n)
{
    long result = 0;

    if(n == 0) result = 1;
    else
    {
        for(int i = 1; i <= n; i++)
            result +=  i * i * A(n - i);
    }

    return result;
}

int main()
{
    cout << A(10);
    return 0;
}
