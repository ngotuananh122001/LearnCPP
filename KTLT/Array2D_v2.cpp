/*
    =====> Mảng hai chiều với số cột cố định
    1. Số dòng được xác định khi chương trình thực thi
    2. Kích thước mỗi dòng là cố định NCOL
    -> Mỗi dòng xem như một mảng một chiều
*/

/*
    Mảng động có số dòng cố định: Ta cần khai báo một mảng gồm NROW con trỏ
    , tại thời điểm chạy, các con trỏ này sẽ quản lý vùng nhớ đc cấp phát

    Mảng động có số cột cố định: Ta định nghĩa ra mảng số thực NCOL phần tử,
    tại thời điểm chạy, cấp phát ô nhớ đủ chứa m mảng số thực định nghĩa ở trên
*/

#include <iostream>
#define NCOL 33
using namespace std;

typedef float floatArr1D[NCOL]; // floatArr1D là alias, thay thế cho kiểu "mảng NCOL phần tử kiểu float"

// Chú ý tại đây ta cần một tham chiêu tới chính biến chứa mảng 2 chiều
int arr2D_alloc(floatArr1D* &a, int m)
{
    a = new floatArr1D[m];
    if(a == nullptr)    return 0;
    return 1;
}

void arr2D_free(floatArr1D a[])
{
    if(a != nullptr)
        delete a;
}

void arr2D_input(floatArr1D a[], int m, int n)
{
    cout << "Nhap lien tuc cac so nguyen de hoan thien ma tran: \n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }
}

void arr2D_out(floatArr1D a[], int m, int n)
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
    // Mảng 2 chiều số cột cố định
    floatArr1D *B {};
    int mB, nB = NCOL;
    cout << "Nhap so hang cua ma tran: ";
    cin >> mB;

    if(mB > 0 && arr2D_alloc(B, mB))
    {
        arr2D_input(B, mB, nB);
        arr2D_out(B, mB, nB);
    }

    arr2D_free(B);
    return 0;
}
