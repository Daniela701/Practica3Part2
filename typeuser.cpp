#include "typeuser.h"
#include "eyd.h"
#include <fstream>
#include <sstream>

administrador::administrador(string pass){
    password=pass;
    int large;
    bool determinante=true;
    ifstream fl,tem;
    string dato;
    fl.open("../AppCajero/BD/sudo.txt");
    fl>>dato;
    //ciclo que desencripta cada linea del archivo sudo y termina al llegar al final del documento
    while(!fl.eof()){
        desencriptacion clave(dato);
        clave.desencriptar();
        fl>>dato;
    }
    fl.close();
    tem.open("../AppCajero/BD/temporal.txt");
    tem>>dato;
    tem.close();
    large=dato.length();
    //se evalua si la clave ingresada es igual o no a la clave ya registrada en la base de datos
    for (int i=0; i<large; i++){
        if(dato[i]!=password[i]){
            determinante=false;
            break;
        }
    }
    if (determinante==false){
        system("CLS");
        cout<<"xxxxxxxxxxxxxxxxxxx"<<endl;
        cout<<"x  Datos erroneos x "<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxx"<<endl;
        exit(-1);
    }
    remove("../AppCajero/BD/temporal.txt");
}

void administrador::acceso(){
    int opcion;
    system("CLS");
    cout<<"===================================="<<endl;
    cout<<"*     Bienvenido Administrador     *"<<endl;
    cout<<"===================================="<<endl;
    cout<<"-> Digite 1 para registrar usuarios |"<<endl;
    cout<<"===================================="<<endl;
    cout<<"-> Digite 0 para salir              |"<<endl;
    cout<<"===================================="<<endl;
    cin>>opcion;
    if (opcion==1){
        string d;
        system("CLS");
        cout<<"===================================="<<endl;
        cout<<"*       Registro de usuarios       *"<<endl;
        cout<<"===================================="<<endl;
        cout<<"======================================================================="<<endl;
        cout<<"-> Digite cedula(8 digitos),clave(4 digitos),saldo del nuevo usuario   |"<<endl;
        cout<<"======================================================================="<<endl;
        cout<<"======================================="<<endl;
        cout<<"-> Digite 0 para salir                 |"<<endl;
        cout<<"======================================="<<endl;
        cin>>d;
        if(d=="0"){
            system("CLS");
            cout<<"*****************"<<endl;
            cout<<"* Vuelva pronto *"<<endl;
            cout<<"*****************"<<endl;
            exit(-1);
        }
        else{
        //se encriptan todos los datos del usuario que se ha registrado y se guarda en el documento usuarios
        encriptacion datos(d);
        datos.encriptar("usuarios");
        system("CLS");
        cout<<"********************"<<endl;
        cout<<"* Registro exitoso *"<<endl;
        cout<<"********************"<<endl;
    }
    }
    else{
        system("CLS");
        cout<<"*****************"<<endl;
        cout<<"* Vuelva pronto *"<<endl;
        cout<<"*****************"<<endl;
        exit(-1);
    }
}

usuario::usuario(string pass){
    cont=0;
    int large;
    bool determinante=true;
    ifstream fl, tem;
    string dato,coma={44};
    fl.open("../AppCajero/BD/usuarios.txt");
    fl>>dato;
    //ciclo para determinar si la cedula y clave digitadas por el usuario si son correctas
    while(!fl.eof()){
        cont++;
        desencriptacion user(dato);
        user.desencriptar();
        tem.open("../AppCajero/BD/temporal.txt");
        tem>>dato;
        contra=dato;
        tem.close();
        large=dato.length();
        for (int i=0; i<large; i++){
            if(dato[i+1]==coma[0] and i>8){
                large=i;
            }
            if(dato[i]!=pass[i]){
                determinante=false;
                break;
            }
            else{
                determinante=true;
            }
        }
        if (determinante==true){
            break;
        }
        fl>>dato;
    }
    if (determinante==false){
        system("CLS");
        cout<<"xxxxxxxxxxxxxxxxxxx"<<endl;
        cout<<"x  Datos erroneos x "<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxx"<<endl;
        exit(-1);
    }
    fl.close();
    remove("../AppCajero/BD/temporal.txt");

}

void usuario::access(){
    ifstream file,tem;
    int op,large,contador=0;
    int long num=0;
    string coma={44},user,saldo,line,data;
    system("CLS");
    cout<<"===================================="<<endl;
    cout<<"*       Bienvenido Usuario         *"<<endl;
    cout<<"===================================="<<endl;
    cout<<"-> Digite 1 para consultar saldo    |"<<endl;
    cout<<"===================================="<<endl;
    cout<<"-> Digite 2 para retirar dinero     |"<<endl;
    cout<<"===================================="<<endl;
    cout<<"-> Digite 3 para salir              |"<<endl;
    cout<<"===================================="<<endl;
    cin>>op;

    large=contra.length();
    //ciclo para contener en la variable user solo la cedula del usuario y en saldo la cantidad de dinero
    for(int i=0; i<large; i++){
        if (i<8){
            user+=contra[i];
        }
        if(i>13){
            saldo+=contra[i];
        }
    }
    if(op==1){
        system("CLS");
        cout<<"*****************************************************"<<endl;
        cout<<"* El usuario "+user+" tiene un saldo de "+saldo+" pesos *"<<endl;
        cout<<"*****************************************************"<<endl;
        cout<<"*****************"<<endl;
        cout<<"* Vuelva pronto *"<<endl;
        cout<<"*****************"<<endl;
        num=stoi(saldo);//funcion para covertir un string a int
        num-=1000;
       }
    else if(op==2){
        system("CLS");
        cout<<"===================================================="<<endl;
        cout<<"*            Querido usuario "+user+"              *"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"-> Digite la cantidad de dinero que desea retirar   |"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"(Tenga en cuenta que su saldo es de "+saldo+" pesos)   |"<<endl;
        cout<<"===================================================="<<endl;
        cout<<"-> Digite 0 para salir                              |"<<endl;
        cout<<"===================================================="<<endl;
        cin>>op;
        num=stoi(saldo);
        num-=1000;
        if(op==0){
            system("CLS");
            cout<<"*****************"<<endl;
            cout<<"* Vuelva pronto *"<<endl;
            cout<<"*****************"<<endl;
            exit(-1);
        }
        else if(num<op){
            system("CLS");
            cout<<"**********************"<<endl;
            cout<<"* Saldo insuficiente *"<<endl;
            cout<<"**********************"<<endl;
        }
        else{
            system("CLS");
            cout<<"******************"<<endl;
            cout<<"* Retiro exitoso *"<<endl;
            cout<<"******************"<<endl;
            num-=op;
        }
    }
    else{
        system("CLS");
        cout<<"*****************"<<endl;
        cout<<"* Vuelva pronto *"<<endl;
        cout<<"*****************"<<endl;
        exit(-1);
    }
        stringstream sstream;
        sstream<<num;
        saldo=sstream.str();//proceso de convercion de un int a un string
        //ciclo para agregar a la linea en que se cambiara informacion la cedula y la clave
        for(int i=0; i<large; i++){
            if (i<14){
                line+=contra[i];
            }
        }
        large=saldo.length();
        //agregamos en esa linea a cambiar el nuevo saldo del usuario
        for(int j=0;j<large;j++){
            line+=saldo[j];
            }
        file.open("../AppCajero/BD/usuarios.txt");
        file>>data;
        //Ciclo para escribir en un archivo temporal toda la informacion incluyendo la que se cambio
        while(!file.eof()){
            contador++;
            desencriptacion arch(data);
            arch.desencriptar();
            tem.open("../AppCajero/BD/temporal.txt");
            tem>>data;
            tem.close();
            if (contador==cont){
                encriptacion change(line);
                change.encriptar("temporal2");//remplazamos la linea original por la cambiada
            }
            else{
                encriptacion original(data);
                original.encriptar("temporal2");//se escriben las demas lineas tal y como estan en el archivo original
            }
            file>>data;
        }
        file.close();
        remove("../AppCajero/BD/temporal.txt");
        //eliminamos el archivo original (ya que tiene informacion desactualizada)
        remove("../AppCajero/BD/usuarios.txt");
        //renombramos el archivo temporal2 (el que contiene los cambios), le ponemos el nombre que tenia el archivo original
        rename("../AppCajero/BD/temporal2.txt","../AppCajero/BD/usuarios.txt");
 }
