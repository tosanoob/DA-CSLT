#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "base.h"
#include "sach.cpp"
#include "dssach.cpp"
#include "user.cpp"
using namespace std;

//-----------------------------------------------------
User *DSUser::push(User a)
{
    User *temp = new User(a);
    tail->set_next(temp);
    temp->set_prev(tail);
    soluong++;
    tail = temp;
    return tail;
}

User *DSUser::push(string ten, string cmd)
{
    User *temp = new User(ten, cmd);
    string ma = incre(tail->getuid());
    temp->setuid(ma);
    tail->set_next(temp);
    temp->set_prev(tail);
    soluong++;
    tail = temp;
    return tail;
}

bool DSUser::del_user(User *a)
{
    User *tempprev = a->to_prev(), *tempnext = a->to_next();
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

User *DSUser::searchname(string ten)
{
    User *temp = head;
    int i = 1;
    while (temp->getten() != ten && i <= soluong)
    {
        temp = temp->to_next();
        i++;
    }
    return temp;
}

User *DSUser::display(User *start)
{
    User *temp = start;
    if (temp == NULL)
        return temp;
    for (int i = 0; i < 20; i++)
    {
        cout << temp->getuid() << setw(40) << temp->getten() << setw(15) << temp->getcmd() << '\n';
        temp = temp->to_next();
        if (temp == NULL)
            break;
    }
    return temp;
}

int read_file(ifstream &inp, DSUser &lib)
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
        User a;
        check = read_user(inp, a);
        if (check == 0)
            return 0;
        User *temp = new User(a);
        lib.head = temp;
        lib.tail = temp;
        lib.soluong++;
    }
    while (!inp.eof())
    {
        User a;
        check = read_user(inp, a);
        if (check == 0)
            break;
        lib.push(a);
    }
    return 1;
}

int write_file(ofstream &out, DSUser &lib)
{
    if (!out)
    {
        cout << "Error output file";
        return 0;
    }
    User *temp = lib.head;
    while (temp != NULL)
    {
        write_user(out, temp);
        temp = temp->to_next();
    }
    return 1;
}

DSUser:: ~DSUser() {
    int i;
    User *temp = head, *pretemp = head;
    for (i = 0; i < soluong; i++)
    {
        temp = temp->to_next();
        delete pretemp;
        pretemp = temp;
    }
}