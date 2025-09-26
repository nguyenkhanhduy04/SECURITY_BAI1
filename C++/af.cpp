#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findIndex(char c){
    if(c==' ') return 26;
    if(isalpha(c)) return toupper(c)-'A';
    return -1;
}
char findChar(int idx){
    return alphabet[(idx+27)%27];
}

int modInverse(int a,int m){
    a%=m;
    for(int x=1;x<m;x++)
        if((a*x)%m==1) return x;
    throw runtime_error("Khong co nghich dao modulo");
}

string affineEncrypt(const string &text,int a,int b){
    string res="";
    for(char c:text){
        int idx=findIndex(c);
        if(idx!=-1){
            res+=findChar(a*idx+b);
        }else res+=c;
    }
    return res;
}

string affineDecrypt(const string &cipher,int a,int b){
    string res="";
    int a_inv=modInverse(a,27);
    for(char c:cipher){
        int idx=findIndex(c);
        if(idx!=-1){
            res+=findChar(a_inv*((idx-b+27)%27));
        }else res+=c;
    }
    return res;
}

int main(){
    string text;
    int a,b;
    cout<<"Nhap chuoi: ";
    getline(cin,text);
    cout<<"Nhap khoa a: ";
    cin>>a;
    cout<<"Nhap khoa b: ";
    cin>>b;
    cin.ignore();
    string encrypted=affineEncrypt(text,a,b);
    cout<<"Ma hoa: "<<encrypted<<endl;
    cout<<"Giai ma: "<<affineDecrypt(encrypted,a,b)<<endl;
    return 0;
}
