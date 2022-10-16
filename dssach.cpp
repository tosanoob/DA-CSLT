#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "base.h"
#include "sach.cpp"
using namespace std;

Sach *DSSach::push(Sach a)
{
    Sach *temp = new Sach(a);
    tail->set_next(temp);
    temp->set_prev(tail);
    soluong++;
    tail = temp;
    return tail;
}

Sach *DSSach::push(string ten, string tga, int cpy)
{
    string ma = incre(tail->getma());
    Sach *temp = new Sach(ten, tga, cpy);
    temp->setma(ma);
    tail->set_next(temp);
    temp->set_prev(tail);
    soluong++;
    tail = temp;
    return tail;
}

bool DSSach::del_sach(Sach *a)
{
    Sach *tempprev = a->to_prev(), *tempnext = a->to_next();
    if (tempprev != NULL)
        tempprev->set_next(tempnext);
    else
        head = tempnext;
    if (tempnext != NULL)
        tempnext->set_prev(tempprev);
    else
        tail = tempprev;
    soluong--;
    delete a;
}

Sach *DSSach::searchname(string ten)
{
    Sach *temp = head;
    int i = 1;
    while (temp->gettsach() != ten && i <= soluong)
    {
        temp = temp->to_next();
        i++;
    }
    return temp;
}
Sach *DSSach::searchma(string ma)
{
    Sach *temp = head;
    int i = 1;
    while (temp->getma() != ma && i <= soluong)
    {
        temp = temp->to_next();
        i++;
    }
    return temp;
}
Sach *DSSach::display(Sach *start)
{
    Sach *temp = start;
    if (temp == NULL)
        return temp;
    for (int i = 0; i < 20; i++)
    {
        cout << temp->getma() << setw(40) << temp->gettsach() << setw(30) << temp->getttgia() << setw(10) << temp->getsoban() << '\n';
        temp = temp->to_next();
        if (temp == NULL)
            break;
    }
    return temp;
}
int read_file(ifstream &inp, DSSach &lib)
{
    if (!inp)
    {
        cout << "Error input file";
        return 0;
    }
    int check = 1;
    if (lib.gethead() == NULL)
    {
        // phan tu dau tien
        Sach a;
        check = read_line(inp, a);
        if (check == 0)
            return 0;
        Sach *temp = new Sach(a);
        lib.head = temp;
        lib.tail = temp;
        lib.soluong++;
    }
    Sach a;
    while (!inp.eof())
    {
        check = read_line(inp, a);
        if (check == 0)
            break;
        lib.push(a);
    }
    return 1;
}

int write_file(ofstream &out, DSSach *lib)
{
    if (!out)
    {
        cout << "Error output file";
        return 0;
    }
    Sach *temp = lib->head;
    while (temp != NULL)
    {
        write_line(out, temp);
        temp = temp->to_next();
    }
    return 1;
}

DSSach::~DSSach()
{
    int i;
    Sach *temp = head, *pretemp = head;
    for (i = 0; i < soluong; i++)
    {
        temp = temp->to_next();
        delete pretemp;
        pretemp = temp;
    }
}