#include <iostream>
#include <vector>
using namespace std;

void QuickSortImp(int *a, int L, int R) {
    int i = L, j = R;
    int x = a[(L + R)/2];
    do {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (L < j) {
        QuickSortImp(a, L, j);
    }

    if (i < R) {
        QuickSortImp(a, i, R);
    }
}

void QuickSort(int *a, int n) {
    QuickSortImp(a, 0, n-1);
}



int main() {
    int a[] {9, -1, 2, -3, 5, 0};
    QuickSort(a, 6);

    for(int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
