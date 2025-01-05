#include <iostream>
#include <cstdlib> // Dung system("cls") va system("pause")
using namespace std;

void clearScreen() {
    system("cls");
}

void pauseScreen() {
    system("pause");
}

// Ham tim cac bo 3 ca the phu hop
void timBoBaCaThe(int* doThichNghi, int soLuong, int mucDoChuan) {
    int tongBoBa = 0; // Dem so bo ba thoa man

    cout << "\nCac bo ba ca the thoa man muc do chuan la:\n";
    for (int i = 0; i < soLuong - 2; i++) {
        for (int j = i + 1; j < soLuong - 1; j++) {
            for (int k = j + 1; k < soLuong; k++) {
                if (doThichNghi[j] - doThichNghi[i] == mucDoChuan &&
                    doThichNghi[k] - doThichNghi[j] == mucDoChuan) {
                    tongBoBa++;
                    cout << "Vi tri " << i << ", " << j << ", " << k << " la cac ca the "
                        << doThichNghi[i] << ", " << doThichNghi[j] << ", " << doThichNghi[k] << " thoa man.\n";
                }
            }
        }
    }

    cout << "\nTong so bo ba thoa man muc do: " << tongBoBa << "\n";
}

int main() {
    int choice;
    do {
        clearScreen();
        cout << "=== CHUONG TRINH TIM BO BA CA THE ===\n";
        cout << "1. Nhap muc do va so luong ca the\n";
        cout << "2. Hien thi cac bo ba ca the phu hop\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int mucDoChuan, soLuong;
            cout << "\nNhap vao muc do thich nghi chuan: ";
            cin >> mucDoChuan;
            cout << "Nhap vao so luong ca the: ";
            cin >> soLuong;

            // Cap phat mang dong
            int* doThichNghi = new int[soLuong];
            cout << "\nNhap vao do thich nghi cua tung ca the:\n";
            for (int i = 0; i < soLuong; i++) {
                cout << "Ca the " << i << ": ";
                cin >> doThichNghi[i];
            }

            // Goi ham tim bo ba
            timBoBaCaThe(doThichNghi, soLuong, mucDoChuan);

            // Giai phong bo nho
            delete[] doThichNghi;

            pauseScreen();
            break;
        }

        case 2: {
            cout << "\nChuc nang hien thi chua duoc cai dat!\n";
            pauseScreen();
            break;
        }

        case 0:
            cout << "\nKet thuc chuong trinh. Tam biet!\n";
            break;

        default:
            cout << "\nLua chon khong hop le! Vui long nhap lai.\n";
            pauseScreen();
            break;
        }
    } while (choice != 0);

    return 0;
}
