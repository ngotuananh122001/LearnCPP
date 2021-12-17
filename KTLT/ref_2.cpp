#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool arr_alloc(int* &a, int n)
{
    a = new int[n];
    if(a == nullptr)    return false;
    else    return true;
}

void arr_free(int *a)
{
    delete [] a;
}

void arr_input(int *a, int n)
{
    cout << "Nhap cac phan tu: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void arr_out(int *a, int n)
{
    cout << "Array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Giai bai tap
int average(const int *a, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return sum * 1.0 / n;
}

int& min_of_arr(int *a, int n)
{
    int min_i = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[min_i] > a[i])
            min_i = i;
    }

    return a[min_i];
}
int main()
{
    int *B;
    int nB;
    cout << "So phan tu cua mang: ";
    cin >> nB;

    if(nB > 0 && arr_alloc(B, nB))
    {
        arr_input(B, nB);
        arr_out(B, nB);
    }

    int &arr_min = min_of_arr(B, nB);
    cout << "Gia tri nho nhat: " << arr_min << endl;
    cout << "Tang gia tri nho nhat len 100 lan" << endl;
    arr_min *= 100;
    arr_out(B, nB);


    arr_free(B);
    return 0;
}
