#ifndef EYD_H
#define EYD_H
#include <iostream>
using namespace std;

class encriptacion
{
private:
    string data;
public:
    encriptacion(string);
    void encriptar(string);
};

class desencriptacion
{
private:
    string binary;
public:
    desencriptacion(string);
    void desencriptar();
};

#endif // EYD_H
