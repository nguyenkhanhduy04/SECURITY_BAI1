#include <iostream>
#include <string>
using namespace std;

const string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

int findIndex(char c){
    if(c==' ') return 26;
    if(isalpha(c)) return toupper(c)-'A';
    return -1;
}
char findChar(int idx){
    return alphabet[(idx+27)%27];
}

string generateKey(const string &text,const string &key){
    string newKey=key;
    while(newKey.size()<text.size()) newKey+=key;
    return newKey.substr(0,text.size());
}

string vigenereEncrypt(const string &text,const string &key){
    string res="";
    for(size_t i=0;i<text.size();i++){
        int idxT=findIndex(text[i]);
        int idxK=findIndex(key[i]);
        if(idxT!=-1 && idxK!=-1) res+=findChar(idxT+idxK);
        else res+=text[i];
    }
    return res;
}

string vigenereDecrypt(const string &cipher,const string &key){
    string res="";
    for(size_t i=0;i<cipher.size();i++){
        int idxC=findIndex(cipher[i]);
        int idxK=findIndex(key[i]);
        if(idxC!=-1 && idxK!=-1) res+=findChar(idxC-idxK+27);
        else res+=cipher[i];
    }
    return res;
}

int main(){
    string text,key;
    cout<<"Nhap chuoi: ";
    getline(cin,text);
    cout<<"Nhap khoa: ";
    getline(cin,key);
    string newKey=generateKey(text,key);
    string encrypted=vigenereEncrypt(text,newKey);
    cout<<"Ma hoa: "<<encrypted<<endl;
    cout<<"Giai ma: "<<vigenereDecrypt(encrypted,newKey)<<endl;
    return 0;
}
