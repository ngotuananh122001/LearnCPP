#include <iostream>
#include <cstring>
#include <string>
using namespace std;


typedef struct Student {
    char* name;
    Student* next;
    Student* prev;
};

typedef struct Class {
    char name[30];
    Student* lst;
    Class* next;
};

void MenuClass(Class* &classes);
void ManageClass(Class* classes);
void CreateClass(Class* &classes);
void ShowClasses(Class* classes);
void ManageStudent(Class* _class);
void Menu();
void AddStudent(Class* _class);
void HienThi(Class* _class);
int CompareName(char *s1, char *s2);
void ParseName(char *s, int &m, int &n);


int main() {
    Class* classes = nullptr;

    MenuClass(classes);

    return 0;
}

void MenuClass(Class* &classes) {
    char luaChon;
    do {
        cout << "|=====================================|\n";
        cout << "|   1. Hien thi danh sach cac lop     |\n";
        cout << "|   2. Tao mot lop hoc moi            |\n";
        cout << "|   0. De thoat                       |\n";
        cout << "|=====================================|\n";
        cout << "--< Lua chon: ";

        cin >> luaChon;
        cin.ignore(1000, '\n');

        switch (luaChon) {
        case '1':
            system("cls");
            ShowClasses(classes);
            ManageClass(classes);
            break;
        case '2':
            CreateClass(classes);
            break;
        case '0':
            cout << "hen gap lai!" << endl;
            break;
        default:
            cout << "Nhap sai!";
        }
        cout << "\n";
    } while (luaChon != '0');
}

void ManageClass(Class* classes) {
    int found = 0;
    do {
        cout << "\nNhap ten lop muon quan ly (an 0 de thoat): ";
        char name[30];
        cin.getline(name, 30);

        // An esc
        if (name[0] == '0') {
            system("cls");
            break;
        }

        Class* _class = classes;
        while (_class) {
            if (strcmp(_class->name, name) != 0) {
                _class = _class->next;
            } else {
                break;
            }
        }

        if (!_class) {
            cout << "Khong tim thay lop nay!\n";
            continue;
        }

        found = 1;
        ManageStudent(_class);
    } while (!found);

}

// Create a new class
// Tạo ra danh sách sinh vien trước
// sau đó them vao lop
void CreateClass(Class* &classes) {
    Class* newClass = new Class;

    cout << "Nhap ten lop: ";
    cin.getline(newClass->name, 30);

    // Tao ra sinh vien dau tien
    // Hack
    Student* student = new Student;
    student->name = "";
    student->next = nullptr;
    student->prev = nullptr;

    newClass->lst = student;
    newClass->next = nullptr;

    if (!classes) {
        classes = newClass;
    } else {
        classes->next = newClass;
    }
    cout << "Tao thanh cong mot lop moi\n";
}

void ManageStudent(Class* _class) {
    Menu();
    bool is_done = false;
    while (!is_done) {
        char luachon;
        cin >> luachon;
        cin.ignore(10000, '\n');

        switch (luachon) {
        case '1':
            system("cls");
            AddStudent(_class);
            Menu();
            break;
        case '2':
            system("cls");
            HienThi(_class);
            Menu();
            break;
        default:
            system("cls");
            is_done = true;
        }
    }
}

void Menu() {
    cout << "\n|================= Menu ============|\n";
    cout << "|  1. Them sinh vien vao lop        |" << endl;
    cout << "|  2. In danh sach lop              |" << endl;
    cout << "|===================================|" << endl;

    cout << "Bam phim 1-2 de chon, phim bat ky de quay lai trang chu : ";
}

void AddStudent(Class* _class) {
    cout << "\n======== Nhap thong tin ======\n";
    int cnt = 0;
    char name[30] {}; // luu du lieu tam thoi tu user
    while (1) {
        cout << "Nhap ten sinh vien: ";
        cin.getline(name, 30);

        if (strlen(name) == 0)
            break;

        /*
            Them sv moi vao lop (add node)
        */
        Student* newStudent = new Student;
        newStudent->name = new char[strlen(name) + 1];
        strcpy(newStudent->name, name);
        cnt++;

        /*
            Sort ds theo thu tu
        */

        Student* student = _class->lst;
        while (student->next) {
            if (CompareName(newStudent->name, student->name) < 0) {
                break;
            }

            student = student->next;
        }

        // Đã duyệt tới sv cuoi cùng
        if (!student->next) {
            if (CompareName(newStudent->name, student->name) > 0) {
                // Sinh viên mới này, nên chèn vào cuối ds lớp
                student->next = newStudent;
                newStudent->next = nullptr;
                newStudent->prev = student;
                continue;
            }

        }

        // Chen vao truoc student hien tai
        newStudent->prev = student->prev;
        newStudent->next = student;

        // neu truoc student == null -> student hien la phan tu dau tien
        if (student->prev != nullptr) {
            student->prev->next = newStudent;
        }
        student->prev = newStudent;

        // bay gio, newStudent co the la phan tu dau tien
        if (newStudent->prev == nullptr) {
            _class->lst = newStudent;
        }
    }

    cout << "Them thanh cong " << cnt << " sinh vien." << endl;
}

/*
    Ham nhan 2 tham so tra ve
    m: vi tri bat dau ten
    n: vi tri bat dau ten dem, neu khong co ten dem n = -1;
*/
void ParseName(char *s, int &m, int &n) {
    int len = strlen(s);

    // Tim vi tri bat dau ten
    m = len - 1;
    while (s[m] != ' ')
        m--;
    m++;

    // Tim vi tri bat dau ten dem
    n = 0;
    while (s[n] != ' ')
        n++;
    n++;
    if (n == m)
        n = -1;
}

int CompareName(char *s1, char *s2) {
    int m1, n1;
    int m2, n2;
    ParseName(s1, m1, n1);
    ParseName(s2, m2, n2);

    // So sanh ten
    if (strcmp(s1 + m1, s2 + m2) != 0)
        return strcmp(s1 + m1, s2 + m2);

    // So sanh ten dem neu ten giong nhau
    if (n1 != -1 && n2 == -1)
        return 1; // s2 khong co ten dem nen nho hon

    if (n1 == -1 && n2 != -1)
        return -1; // s1 khong co ten dem nen nho hon

    if (n1 != -1 && n2 != -1)
        if (strcmp(s1 + n1, s2 + n2) != 0)
            return strcmp(s1 + n1, s2 + n2);

    // So sanh ho neu ten giong nhau, ten dem giong nhau, hoac ca hai khong co ten dem
    return strcmp(s1, s2);
}

// Hien thi thong tin lop hoc
void HienThi(Class* _class) {
    cout << "|====== Danh sach sinh vien =========|\n";
    Student* student = _class->lst;
    if (!student) {
        cout << "  Lop chua co sinh vien nao!" << endl;
    } else {
        while(student) {
            cout << "|  " << student->name << endl;
            student = student->next;
        }
    }

    cout << "|====================================|\n";
}

// Hien thi danh sach lop hocj
void ShowClasses(Class* classes) {
    cout <<     "|====== Danh sach cac lop =========|\n";
    Class* _class = classes;
    if (!_class) {
        cout << "|  Chua co lop nao. Tao moi ?      |\n";
        cout << "|                                  |\n";
    } else {
        while (_class) {
            cout << "|  " << _class->name << endl;
            _class = _class->next;
        }
    }


    cout << "|==================================|\n";
}
