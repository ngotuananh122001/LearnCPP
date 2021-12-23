#include <iostream>
#include <cstring>
using namespace std;

// Sử dụng đệ quy nhị phân
// Cách làm tệ nhất khi có 2 lần gọi đệ quy
long Fibo1(int n)
{
    long result, Fn_1, Fn_2;
    if(n <= 1)  result = 1;
    else
    {
        // 2 lân gọi đệ quy
        Fn_1 = Fibo1(n - 1);
        Fn_2 = Fibo1(n -2);
        result = Fn_1 + Fn_2;
    }

    return result;
}

// Khử đệ quy
long Fibo(int n)
{
    long Fn_1, Fn;
    if(n <= 1)
        Fn = 1;
    else
    {
        int i = 2;
        Fn = Fn_1 = 1;
        while(i++ <= n)
        {
            Fn = Fn + Fn_1;
            Fn_1 = Fn - Fn_1;
        }
    }

    return Fn;
}
int main()
{
    cout << "Recursion: Fibo(10) = " << Fibo1(10) << endl;
    cout << "Loop: Fibo(10) =  " << Fibo(10) << endl;
    return 0;
}

