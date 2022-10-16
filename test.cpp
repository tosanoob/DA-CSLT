#include <iostream>
#include <fstream>
#include "base.h"
#include "sach.cpp"
#include "dssach.cpp"
using namespace std;

int main() {
    ifstream inp("input.txt");
    ofstream out("output.txt");

    DSSach a;
    read_file(inp,a);
    cout<<"passread\n";

    a.display(a.gethead());
    Sach b;
    cin>>b;
    a.push(b.gettsach(),b.getttgia(),b.getsoban());
    string ma;
    cin>>ma;
    a.del_sach(a.searchma(ma));
    cout<<"delete success\n";
    write_file(out,&a);
    cout<<"success\n";
    return 0;
}