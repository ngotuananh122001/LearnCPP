#include <iostream>
using namespace std;

/*
    @Return index position of target if found, else return -1
    @ precondition: list is sorted
*/
int BinarySearch(int lst[], int n, int target) {
    int first = 0;
    int last = n;

    while (first <= last) {
        int mid_idx = (first + last) / 2;

        // compare midPoint with target
        if (lst[mid_idx] == target)
            return mid_idx;
        else if (lst[mid_idx] < target)
            first = mid_idx + 1;
        else
            last = mid_idx -1;
    }

    return -1;
}

void Verify(int pos) {
    if (pos >= 0)
        cout << "Found the target at " << pos << endl;
    else
        cout << "Not found target in list." << endl;
}

int main() {
    int lst[] {1,2,3,4,5,6,7,8,9,10};

    int pos = BinarySearch(lst, 10, 12);
    Verify(pos);

    pos = BinarySearch(lst, 10, 6);
    Verify(pos);

    return 0;
}
