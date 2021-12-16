#include <iostream>
using namespace std;

#define NROW 3

/*
* param1: mảng con trỏ (đại diện cho mảng động 2 chiều)
* param2: kích thước mảng con trỏ (số dòng)
* param3: kích thước mảng nguyên mà mỗi con trỏ a[i] quản lý (số cột)

* Tiền điều kiện: mảng con trỏ, tất cả đều mang giá trị null
* Hàm trả về 1 nếu cấp phát thành công, ngược lại trả về 0 nếu thất bại
*/
int arr2D_alloc(int* a[], int m, int n)
{
    int *buffer = new int[m*n] {};
    // int *buffer = (int *) calloc(m * n, size(int);
    if(buffer == nullptr)
    {
        // Có lỗi, không cấp phát được vùng nhớ
        return 0;
    }
    // Phân phối vùng nhớ cấp phát buffer để mỗi con trỏ quản lý n ô nhớ nguyên
    int i = 0;
    while(i < m)
    {
        a[i] = buffer;
        buffer += n;
        i++;
    }
    return 1;
}

void arr2D_free(int * a[])
{
    if(a[0] != nullptr)
    {
        free(a[0]);
        a[0] = nullptr;
    }
}

void arr2D_input(int* a[], int m, int n)
{
    cout << "Nhap lien tuc cac so nguyen de hoan thien ma tran: \n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }
}

void arr2D_out(int* a[], int m, int n)
{
    cout << "Ma tran: " << m << "*" << n << endl;
    for(int i = 0; i < m; i++)
    {
        cout << "\t";
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    // khai báo NROW con trỏ kiểu int khởi tạo tất cả bằng null
    int mB = NROW, nB;
    int* B[mB] {};

    cout << "Nhập số cột: ";
    cin >> nB;

    if (nB > 0 && arr2D_alloc(B, mB, nB))
    {
        arr2D_input(B, mB, nB);
        arr2D_out(B, mB, nB);
    }

    arr2D_free(B);
    return 0;
}
