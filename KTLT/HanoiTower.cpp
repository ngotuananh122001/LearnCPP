#include <iostream>
#include <cstring>
using namespace std;

/*
    Bai toan Thap Ha Noi
    Bước 1: Giải bài toán di chuyen n -1 đĩa từ A sang B với C làm trung gian
    Bước 2: Di chuyển đĩa còn lại trong A (đĩa lớn nhất) sang C
    Bước 3: Giải bài toán di chuyển n - 1 đĩa từ B sang C với A làm trung gian

*/
int cnt = 0; // Theo dõi số bước di chuyển

void THN(int n, char from, char to, char tmp)
{
    if(n == 1){
        cout << "Di chuyen 1 dia tu " << from << " sang " << to << endl;
        cnt++;
    }
    else
    {
        THN(n - 1, from, tmp, to);
        THN(1, from, to, tmp);
        THN(n - 1, tmp, to, from);
    }
}


int main()
{
    THN(3, 'A', 'C', 'B');
    cout << "Tong so buoc di chuyen: " << cnt << endl;
    return 0;
}

