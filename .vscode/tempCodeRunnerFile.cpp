#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor
    Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    // Nhập từ bàn phím
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> real;
        cout << "Nhap phan ao: ";
        cin >> imag;
    }

    // Hiển thị ra màn hình
    void hienThi() {
        cout << "So phuc: " << real << " + " << imag << "i" << endl;
    }

    // Getter và setter cho phần thực
    float layPhanThuc() const {
        return real;
    }

    void ganPhanThuc(float r) {
        real = r;
    }

    // Getter và setter cho phần ảo
    float layPhanAo() const {
        return imag;
    }

    void ganPhanAo(float i) {
        imag = i;
    }

    // Lấy cả phần thực và phần ảo
    void layPhanThucVaAo(float &r, float &i) const {
        r = real;
        i = imag;
    }

    // Gán cả phần thực và phần ảo
    void ganPhanThucVaAo(float r, float i) {
        real = r;
        imag = i;
    }

    // Tính tổng của hai số phức
    Complex tong(const Complex &c) const {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main() {
    Complex a, b, c;

    // Nhập số phức thứ nhất
    cout << "Nhap so phuc thu nhat:\n";
    a.nhap();

    // Nhập số phức thứ hai
    cout << "\nNhap so phuc thu hai:\n";
    b.nhap();

    // Hiển thị số phức thứ nhất
    cout << "\nSo phuc thu nhat:\n";
    a.hienThi();

    // Hiển thị số phức thứ hai
    cout << "\nSo phuc thu hai:\n";
    b.hienThi();

    // Tính tổng
    c = a.tong(b);

    // Hiển thị tổng
    cout << "\nTong hai so phuc:\n";
    c.hienThi();

    return 0;
}
