#include <iostream>
using namespace std;

void inNamKhongCoNguoiSinhRa(int N[]) {
    for (int year = 1920; year <= 1970; year++) {
        if (N[year - 1920] == 0) {
            cout << "Nam " << year << " khong co nguoi nao sinh ra." << endl;
        }
    }
}

int demNamSinhRaKhongQua10(int N[]) {
    int count = 0;
    for (int year = 1920; year <= 1970; year++) {
        if (N[year - 1920] <= 10) {
            count++;
        }
    }
    return count;
}

int tinhSoNguoiTren50TuoiVaoNam1985(int N[]) {
    int total = 0;
    for (int year = 1920; year <= 1934; year++) {
        total += N[year - 1920];
    }
    return total;
}

int main() {
  
    int N[] = {45, 44, 72, 5, 82, 77, 15, 56, 22, 27, 6, 91, 69, 59, 69, 16, 69, 1, 76, 58, 88, 45, 66, 5, 86, 38, 100, 3, 80, 34, 99, 0, 29, 45, 16, 36, 29, 78, 75, 12, 60, 70, 63, 13, 95, 32, 56, 13, 51, 5, 99};
    inNamKhongCoNguoiSinhRa(N);
    cout << "So nam co so nguoi sinh ra khong qua 10: " << demNamSinhRaKhongQua10(N) << endl;
    cout << "So nguoi da tren 50 tuoi vao nam 1985: " << tinhSoNguoiTren50TuoiVaoNam1985(N) << endl;
    return 0;
}
