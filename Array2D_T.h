#ifndef ARRAY2D_T_H_INCLUDED
#define ARRAY2D_T_H_INCLUDED

#include <iostream>
using namespace std;

template <class T>
void arr2D_alloc(T** &a, int m, int n)
{
    T* buffer;
    a = new T*[m] {}; // cấp phát mảng gồm m con trỏ kiểuT
    // Cấp phát thất bại
    if(!a) return;

    buffer = new T[m * n];

    // Cấp phát thất bại
    if(!buffer)
    {
        delete [] a;
        a = nullptr;
        return;
    }

    // Ngược lại, tiến hành chia vùng nhớ cho từng con trỏ trong mảng a
    for(int i = 0; i < m; i++)
    {
        a[i] = buffer;
        buffer += n;
    }
}

template <class T>
void arr2D_free(T** a)
{
    if(a)
    {
        if(a[0])
        {
            delete [] a[0];
        }
        delete [] a;
    }
}

template <class T>
void arr2D_input(T** a, int m, int n)
{
    cout << "Nhap ma tran: ";
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}

template <class T>
void arr2D_out(T** a, int m, int n)
{
    cout << "Ma tran:";
    for(int i = 0; i < m; i++)
    {
        cout << "\n\t";
        for(int j = 0; j < n; j++)
        cout << a[i][j] << " ";
    }

    cout << endl;
}
#endif // ARRAY2D_T_H_INCLUDED
