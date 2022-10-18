#include <iostream>
#include "base.h"
#include "sach.cpp"
#include "dssach.cpp"
#include "user.cpp"
#include "dsuser.cpp"
using namespace std;

int main() {
    
    ifstream inp("input.txt");
    
    ifstream inpuser("inputuser.txt");
    
    
    DSSach a;
    DSUser lib;
    read_file(inp,a);
    read_file(inpuser,lib);
    cout<<"read passed\n";
    //borrow;
    User* returner = lib.searchname("Truong Tan Cuong");
    int check = returner->trasach(returner->searchname("Another"),a);
    returner->display(returner->gethead());
    if (check==1) cout<<"return passed\n";

    User* borrower = lib.searchname("Nguyen Nguyen Anh");
    check = borrower->muonsach(a.searchname("PTTKGT"),a);
    if (check==1) cout<<"borrow passed\n";
    borrower->display(borrower->gethead());
    
    inp.close();
    inpuser.close();

    ofstream out("output.txt");
    write_file(out,&a);
    cout<<"write list passed\n";
    out.close();
    ofstream outuser("outputuser.txt");
    write_file(outuser,lib);
    cout<<"write user passed\n";
    
    return 0;
}
