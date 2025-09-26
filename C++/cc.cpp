#include <iostream>
#include <string>
using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

int findIndex(char c) {
    if (c == ' ') return 26;
    if (isalpha(c)) return toupper(c) - 'A';
    return -1; // ký tự khác
}

char findChar(int idx) {
    return alphabet[idx % 27];
}

string caesarEncrypt(const string &text, int shift) {
    string res="";
    for(char c:text){
        int idx=findIndex(c);
        if(idx!=-1){
            res+=findChar(idx+shift);
        } else res+=c;
    }
    return res;
}

string caesarDecrypt(const string &cipher,int shift){
    string res="";
    for(char c:cipher){
        int idx=findIndex(c);
        if(idx!=-1){
            res+=findChar(idx-shift+27);
        } else res+=c;
    }
    return res;
}

int main(){
    string text;
    int shift;
    cout<<"Nhap chuoi: ";
    getline(cin,text);
    cout<<"Nhap KHOA : ";
    cin>>shift;
    cin.ignore();
    string encrypted=caesarEncrypt(text,shift);
    cout<<"Ma hoa: "<<encrypted<<endl;
    cout<<"Giai ma: "<<caesarDecrypt(encrypted,shift)<<endl;
    return 0;
}
