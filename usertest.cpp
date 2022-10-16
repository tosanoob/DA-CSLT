#include <iostream>
#include "base.h"
#include "sach.cpp"
#include "dssach.cpp"
#include "user.cpp"
#include "dsuser.cpp"
using namespace std;

int main() {
    DSUser lib;
    ifstream inp("inputuser.txt");
    ofstream out("outputuser.txt");

    read_file(inp,lib);
    cout<<"read passed\n";
    User b;
    cin>>b;
    lib.push(b.getten(),b.getcmd());
    lib.display(lib.gethead());
    string a;
    cout<<"Nhap ten tim kiem: ";
    cin.ignore();
    getline(cin,a,'\n');
    User* temp = lib.searchname(a);
    cout<<*temp;
    cout<<"display passed\n";
    write_file(out,lib);
    cout<<"write passed\n";
    return 0;
}
