#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "LinkedList.h"
using namespace std;
int main(){
    char opc;
    int n;
    LinkedList a;
    LinkedList b(3);
    a.print();
    b.print();
    system("pause");
    system("cls");
    a.insertarElementos(opc,n);
    b.insert(10);
    b.remove(5);
    system("pause");
    system("cls");
    a.print();
    b.print();
    system("pause");
    system("cls");
    cout<<a<<endl;
    cout<<b<<endl;
    system("pause");
    system("cls");
    cout<<"La primera lista tiene "<<a.getSize()<<" elementos\n";
    cout<<"La segunda lista tiene "<<b.getSize()<<" elementos\n";
    system("pause");
    system("cls");
    return 0;
}