#ifndef TYPEUSER_H
#define TYPEUSER_H
#include <iostream>
using namespace std;


class administrador
{
private:
    string password;
public:
    administrador(string);
    void acceso();
};

class usuario
{
private:
    string contra;
    int cont;
public:
    usuario(string);
    void access();
};
#endif // TYPEUSER_H
