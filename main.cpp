#include <iostream>
#include "eyd.h"
#include "typeuser.h"
using namespace std;

/* Clave Administrador: AbCd
 Programa que simula un cajero automatico. Al ingresar como administrador debera
 ingresar la informacion del usuario de la siguiente manera: cedula,clave,saldo esto
 teniendo en cuenta que la cedula sera de 8 digitos(ni mas ni menos), y la clave
 sera de 4 digitos(ni mas ni menos), ademas el saldo estara en COP. Al ingresar como
 usuario debera digitar su informacion asi: cedula,clave. Al correr el programa se le
 ira indicando al usuario que numero o dato va a digitar segun lo que desee hacer, ya
 sea consultar saldo o retirar.
*/

int main()
{
    int op;
    string pass;
    cout<<"============================================="<<endl;
    cout<<"*     Bienvenido al Cajero Electronico      *" << endl;
    cout<<"============================================="<<endl;
    cout<<"-> Digite 1 para ingresar como administrador |"<<endl;
    cout<<"============================================="<<endl;
    cout<<"-> Digite 2 para ingresar como usuario       |"<<endl;
    cout<<"============================================="<<endl;
    cout<<"-> Digite 3 para salir                       |"<<endl;
    cout<<"============================================="<<endl;
    cin>>op;
    if(op==1){
        system("CLS");
        cout<<"======================================="<<endl;
        cout<<"*      Verifiquemos su identidad      *"<<endl;
        cout<<"======================================="<<endl;
        cout<<"-> Ingrese la clave para darle acceso  |"<<endl;
        cout<<"======================================="<<endl;
        cout<<"-> Digite 0 para salir                 |"<<endl;
        cout<<"======================================="<<endl;
        cin>>pass;
        if(pass=="0"){
            system("CLS");
            cout<<"*****************"<<endl;
            cout<<"* Vuelva pronto *"<<endl;
            cout<<"*****************"<<endl;
            exit(-1);
        }
        else{
            //se llama a la clase administrador y con el objeto admi se ejecuta la funcion acceso
            administrador admi(pass);
            admi.acceso();
        }
    }
    else if (op==2){
        system("CLS");
        cout<<"=============================================="<<endl;
        cout<<"*  Verifiquemos su identidad como usuario    *"<<endl;
        cout<<"=============================================="<<endl;
        cout<<"-> Ingrese su cedula y clave (cedula,clave)   |"<<endl;
        cout<<"=============================================="<<endl;
        cout<<"-> Digite 0 para salir                        |"<<endl;
        cout<<"=============================================="<<endl;
        cin>>pass;
        if(pass=="0"){
            system("CLS");
            cout<<"*****************"<<endl;
            cout<<"* Vuelva pronto *"<<endl;
            cout<<"*****************"<<endl;
            exit(-1);
        }
        else{
            //se llama a la clase usuario y con el objeto user se ejecuta la funcion access
            usuario user(pass);
            user.access();
        }
    }
    else{
        system("CLS");
        cout<<"*****************"<<endl;
        cout<<"* Vuelva pronto *"<<endl;
        cout<<"*****************"<<endl;
    }
    return 0;
}
