#include <iostream>
using namespace std;

/*
    @ Recurision binary search
    @ Return index posion of target in list if founded,
        otherwise, return 0-1
*/
int BinarySearch(int lst[], int l, int r, int target) {
    if (l > r)
        return -1;

    int mid = (l + r) / 2;
    if (lst[mid] == target)
        return mid;
    else if (lst[mid] < target)
        return BinarySearch(lst, mid+1, r, target);
    else
        return BinarySearch(lst, l, mid-1, target);
}


void Verify(int pos) {
    if (pos >= 0)
        cout << "Found the target at " << pos << endl;
    else
        cout << "Not found target in list." << endl;
}

int main() {
    int lst[] {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(lst)/sizeof(lst[0]);
    int pos = BinarySearch(lst, 0, n, 12);
    Verify(pos);

    pos = BinarySearch(lst, 0, n, 6);
    Verify(pos);

    return 0;
}
