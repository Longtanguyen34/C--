#include <iostream>
#include <string>
#define Max 100  // Số phần tử tối đa của Stack

using namespace std;

// Định nghĩa struct Wood
struct Wood {
    string type;
    double size;
    int age;
};

// Định nghĩa Stack
struct Stack {
    int Top;  //Vị trí đỉnh stack
    Wood Data[Max];  // Mảng lưu trữ dữ liệu
};

// Hàm khởi tạo stack
void initStack(Stack& S) {
    S.Top = 0;  // Stack rỗng
}

// Kiểm tra stack rỗng
bool isEmpty(Stack S) {
    return S.Top == 0;
}

// Kiểm tra stack đầy
bool isFull(Stack S) {
    return S.Top == Max;
}

// Thêm phần tử vào stack (Push)
bool push(Stack& S, Wood wood) {
    if (isFull(S)) {
        cout << "Ngan xep day!" << endl;
        return false;
    }
    S.Data[++S.Top] = wood;
    return true;
}

// Xóa phần tử khỏi đỉnh stack (Pop)
bool pop(Stack& S, Wood& wood) {
    if (isEmpty(S)) {
        cout << "Ngan xep rong!" << endl;
        return false;
    }
    wood = S.Data[S.Top--];
    return true;
}

// Hàm nhập dữ liệu cho các thanh gỗ
void inputWoods(Stack& S) {
    int n;
    cout << "Nhap so luong thanh go: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string type;
        double size;
        int age;

        cout << "Nhap loai thanh go: ";
        cin >> type;
        cout << "Nhap kich thuoc thanh go: ";
        cin >> size;
        cout << "Nhap tuoi thanh go: ";
        cin >> age;

        if (!push(S, {type, size, age})) {
            cout << "Khong the them thanh go vao stack!" << endl;
            return;
        }
    }
}

// Hàm in ra thông tin các thanh gỗ trong stack
void printWoods(Stack S) {
    cout << "Danh sach thanh go trong stack:\n";
    while (!isEmpty(S)) {
        Wood wood;
        pop(S, wood);
        cout << "Loai: " << wood.type
             << ", Kich thuoc: " << wood.size
             << ", Tuoi: " << wood.age << endl;
    }
}

// Hàm chèn thanh gỗ vào vị trí K bất kỳ
bool Insert_k(Stack& S, Wood newWood, int k) {
    if (k < 1 || k > S.Top ) {
        cout << "Vi tri khong hop le!" << endl;
        return false;
    }

   else {
    Stack tempStack;
    initStack(tempStack);

    // Chuyển các phần tử từ stack ban đầu qua stack tạm cho đến vị trí K
    while (S.Top >= k) {
        Wood wood;
        pop(S, wood);
        push(tempStack, wood);
    }

    // Thêm phần tử mới vào vị trí K
    push(S, newWood);

    // Chuyển lại các phần tử từ stack tạm về stack ban đầu
    while (tempStack.Top > 0) {
        Wood wood;
        pop(tempStack, wood);
        push(S, wood);
    }
    return true; 
    }
}

int main() {
    Stack S;
    initStack(S);
    inputWoods(S);
    cout << "Stack ban dau:\n";
    printWoods(S);

    // Nhập thanh gỗ mới
    string type;
    double size;
    int age;

    cout << "Nhap loai thanh go moi: ";
    cin >> type;
    cout << "Nhap kich thuoc thanh go moi: ";
    cin >> size;
    cout << "Nhap tuoi thanh go moi: ";
    cin >> age;

    Wood newWood = {type, size, age};

    // Nhập vị trí cần chèn
    int p;
    cout << "Nhap vi tri can chen:";
    cin >> p;

    // Chèn thanh gỗ mới vào vị trí bất kỳ
    if (Insert_k(S, newWood, p)) {
        cout << "Stack sau khi chen thanh go moi:\n";
        printWoods(S);
    }

    return 0;
}
