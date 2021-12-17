#include <iostream>
using namespace std;

/*
    Ta noi: Biến là đại diện cho một vùng nhớ
                ltv thao tác với biến đơn giản hơn nhiều, so với thao tác trực tiếp với vùng nhớ (bằng cách nào đó)

    Địa chỉ của biến:
        -> Chính xác hơn phải là "Địa chỉ của vùng nhớ mà biến đại diện"
        -> Biến chỉ là một cái tên
        ==> Nhiều tên cùng đại diện cho một vùng nhớ,
            ta có khái niệm: "tham chiếu" ~ reference trong C++

    1 reference được khởi tạo một lần duy nhất để xác định vùng nhớ
    và nó đại diện
    Sau đó nó làm việc chính xác như một biến thông thường khác,
    kết quả là ta có nhiều hơn một biến cùng đại diện cho vùng nhớ xác đinh


*/

/*
    Xây dựng hàm để hiện thị mảng
    -> Để tạo một mảng trong stack giống với đối số
        là một công việc tốn thời gian và đặc biệt rất dễ
        làm cho stack bị tràn (dữ liệu của mảng lớn)

    -> Khi truyền một mảng tới một hàm, mảng luôn suy biến thành
    một con trỏ, trỏ tới phần tử đầu tiên của mảng đó\

    -> Ưu điểm: giải quyết được vấn đề không gian bộ nhớ của stack
    -> Nhược điểm: khi mảng suy biến thành một con trỏ, không còn biết
    chính xác kích thước của mảng nữa.
        Dẫn tới: phải truyền vào hàm cả kích thước mảng
*/

//void arr_out(int arr[], int n)
//{
//    for(int i = 0; i < n; i++)
//        cout << arr[i] << " ";
//    cout << endl;
//}

/*
    Nếu sử dụng tham chiếu mảng làm tham số,
    mặc dù vẫn phải xác định kích thước mảng cụ thể.
    Nhưng trong TH này tham số thực sự là một alias của mảng ban đầu,
    không phải là một con trỏ
*/
int main()
{
    int value = 5;
    int& ref = value;

    cout << "Địa chỉ vùng nhớ mà ref đại diện: " << &ref << endl;
    cout << "Địa chỉ vùng nhớ mà vaule đại diện: " << &value << endl;

    cout << "ref = " << ref << endl; //5
    cout << "value = " << value << endl; // 5

    int a =  1000;
    ref = a; // Điều này chỉ có nghĩa là gán giá trị ref = giá trị của a
    // Một biến tham chiếu không thể tham chiếu tới vùng nhớ khác sau khi khởi tao


    cout << value << endl; // 1000;

    /*
        Ý nghĩa tham chiếu một lần duy nhất
        ===> ý tưởng triển khai tham chiếu là :
        int*const p;
        // khác biệt là p ở đây là con trỏ nên để thao tác phải dùng dereference
    */
    return 0;
}
