#include "Array2D_T.h"

// Viết chương trình cộng hai ma trận với dữ liệu mỗi ma trận
// được cấp phát theo 2 cach khác nhau

// 1. Sử dụng con trỏ
// 2. Sử dụng con trỏ con trỏ

// Cộng 2 ma trận cùng kích thước
template <class T>
T** SumMatrix(T** a, T** b, int m, int n)
{
    T** sum;
    arr2D_alloc(sum, m, n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            sum[i][j] = a[i][j] + b[i][j];

    return sum;
}
int main()
{
    float **A, **B; // ma tran A, và ma tran B;

    int m, n;
    cout << "Nhap kich thuoc hai ma tran: ";
    cin >> m >> n;

    if(m > 0 && n >0)
    {
        arr2D_alloc(A, m, n);
        arr2D_alloc(B, m, n);
    }
    if(A && B)
    {
        arr2D_input(A, m, n);
        arr2D_input(B, m, n);
    }
    else
    {
        cout << "Error!!!" << endl;
        return 1;
    }

    arr2D_out(A, m, n);
    arr2D_out(B, m, n);

    cout << "Ma tran tong: ";
    float** tong = SumMatrix(A, B, m, n);
    arr2D_out(tong, m, n);

    arr2D_free(tong);
    arr2D_free(A);
    arr2D_free(B);
    return 0;
}
