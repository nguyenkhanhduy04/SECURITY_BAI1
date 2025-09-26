#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// ====== Tạo ma trận 5x5 ======
vector<vector<char>> createMatrix(const string &key) {
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // 25 chữ cái, bỏ J
    string combined = "";
    vector<vector<char>> matrix(5, vector<char>(5));
    bool used[26] = {false};

    // lấy chữ cái từ key trước
    for(char c: key) {
        c = toupper(c);
        if(c == 'J') c = 'I';
        if(isalpha(c) && !used[c - 'A']) {
            used[c - 'A'] = true;
            combined += c;
        }
    }
    // thêm các chữ còn thiếu
    for(char c: alphabet) {
        if(!used[c - 'A']) {
            used[c - 'A'] = true;
            combined += c;
        }
    }
    // nhét vào ma trận 5x5
    int k=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            matrix[i][j] = combined[k++];
    return matrix;
}

// ====== Tìm vị trí trong ma trận ======
pair<int,int> findPos(const vector<vector<char>> &matrix, char c){
    if(c=='J') c='I';
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(matrix[i][j]==c)
                return {i,j};
    return {-1,-1};
}

// ====== Chuẩn bị văn bản (không chèn X, chỉ thêm A cuối nếu lẻ) ======
string prepareText(const string &text){
    string res="";
    for(char c:text){
        if(isalpha(c)){
            char up=toupper(c);
            if(up=='J') up='I';
            res+=up;
        }
    }
    if(res.size()%2!=0) res+='A';
    return res;
}

// ====== Mã hóa ======
string encryptPlayfair(const string &text,const string &key){
    auto matrix=createMatrix(key);
    string prepared=prepareText(text);
    string cipher="";
    for(size_t i=0;i<prepared.size();i+=2){
        char a=prepared[i],b=prepared[i+1];
        auto [row1,col1]=findPos(matrix,a);
        auto [row2,col2]=findPos(matrix,b);
        if(row1==row2){ // cùng hàng
            cipher+=matrix[row1][(col1+1)%5];
            cipher+=matrix[row2][(col2+1)%5];
        } else if(col1==col2){ // cùng cột
            cipher+=matrix[(row1+1)%5][col1];
            cipher+=matrix[(row2+1)%5][col2];
        } else { // hình chữ nhật
            cipher+=matrix[row1][col2];
            cipher+=matrix[row2][col1];
        }
    }
    return cipher;
}

// ====== Giải mã ======
string decryptPlayfair(const string &text,const string &key){
    auto matrix=createMatrix(key);
    string prepared=text;
    string plain="";
    for(size_t i=0;i<prepared.size();i+=2){
        char a=prepared[i],b=prepared[i+1];
        auto [row1,col1]=findPos(matrix,a);
        auto [row2,col2]=findPos(matrix,b);
        if(row1==row2){
            plain+=matrix[row1][(col1+4)%5];
            plain+=matrix[row2][(col2+4)%5];
        } else if(col1==col2){
            plain+=matrix[(row1+4)%5][col1];
            plain+=matrix[(row2+4)%5][col2];
        } else {
            plain+=matrix[row1][col2];
            plain+=matrix[row2][col1];
        }
    }
    return plain;
}

int main(){
    string key,text;
    cout<<"Nhap key: ";
    getline(cin,key);
    cout<<"Nhap chuoi can ma hoa: ";
    getline(cin,text);

    string enc=encryptPlayfair(text,key);
    cout<<"Ma hoa: "<<enc<<endl;

    string dec=decryptPlayfair(enc,key);
    cout<<"Giai ma: "<<dec<<endl;

    return 0;
}
