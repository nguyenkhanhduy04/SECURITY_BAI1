#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm hoán vị mã hóa
string permutationEncrypt(const string &text, const vector<int> &perm) {
    int n = perm.size();
    string result = text;
    for (int i = 0; i < (int)text.size(); i += n) {
        // lấy block n ký tự
        string block = text.substr(i, n);
        // thêm ký tự đệm nếu chưa đủ n
        while ((int)block.size() < n) block += 'X';
        string newBlock(n, ' ');
        for (int j = 0; j < n; j++) {
            newBlock[j] = block[perm[j]];
        }
        result.replace(i, n, newBlock);
    }
    return result;
}

// Hàm hoán vị giải mã
string permutationDecrypt(const string &cipher, const vector<int> &perm) {
    int n = perm.size();
    // Tạo mảng ngược
    vector<int> inv(n);
    for (int i = 0; i < n; i++) inv[perm[i]] = i;

    string result = cipher;
    for (int i = 0; i < (int)cipher.size(); i += n) {
        string block = cipher.substr(i, n);
        string newBlock(n, ' ');
        for (int j = 0; j < n; j++) {
            newBlock[j] = block[inv[j]];
        }
        result.replace(i, n, newBlock);
    }
    return result;
}

int main() {
    string text;
    int n;
    cout << "Nhap chuoi: ";
    getline(cin, text);

    cout << "Nhap so phan tu hoan vi: ";
    cin >> n;

    vector<int> perm(n);
    cout << "Nhap hoan vi (index bat dau 1): ";
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
        perm[i]--; // chuyển từ 1-based sang 0-based
    }

    // Mã hóa
    string encrypted = permutationEncrypt(text, perm);
    cout << "Ma hoa: " << encrypted << endl;

    // Giải mã
    string decrypted = permutationDecrypt(encrypted, perm);
    cout << "Giai ma: " << decrypted << endl;

    return 0;
}
