#ifndef INTERFACE_H
#define INTERFACE_H
#include"binarytree.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<stdlib.h>
using namespace std;


class interface
{
public:
    interface();
private:
    void readfile();
    void write();
    void add();
    void del();
    void print();
    void search();
    BinaryTree x;
    void screen();
};

#endif // INTERFACE_H
