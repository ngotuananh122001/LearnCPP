#include <iostream>
#include <cstring>
using namespace std;

// C-string nên tránh, chỉ sử dụng khi bắt buộc
// ngoài ra ưu tiên sử dụng string (C++)

/*
    Những vấn đề cần lưu ý:
        1. Kích thước thực sự của mảng -> sizeof
        2. Số ký tự được coi là một phần của xâu -> strlen
        3. Xâu kết thúc khi gặp null terminator, bất kể nd còn lại của
            mảng là gì

*/
int main()
{
    char message[30] {};
    cin.getline(message, 30);
    // chỉ trích xuất tối đa 29 ký tự và gắn thêm null terminator -> 30
    // Mọi ký tự còn lại nằm lại trong bộ đệm

    cin.ignore(INT_MAX, '\n');

    cout << msg << endl;
    cout << "Content: " << message << endl;
    cout << "Size of arr: " << sizeof(message) << endl;
    cout << "Kich thuoc xau (So ki tu phan content): " << strlen(message) << endl;
}
