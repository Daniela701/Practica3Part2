#include "eyd.h"
#include "typeuser.h"
#include <fstream>

encriptacion::encriptacion(string datos){
    data=datos;
}

void encriptacion::encriptar(string arch){
    ofstream f;
    int large,num,s=4;
    string cb,def,file="../AppCajero/BD/"+arch+".txt";
    //variable que contiene los numeros del 0-9 e incluye la coma(,)
    string carac={44,48,49,50,51,52,53,54,55,56,57};
    //variable que contiene los binarios correspondientes a los elementos de la variable carac
    string binarc={"0010110000110000001100010011001000110011001101000011010100110110001101110011100000111001"};
    //variable letrasM con los numeros ascii correspondientes a las letras mayusculas y letrasm con las minusculas
    string letrasM={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90},letrasm={97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
    //variable binarM contiene los numeros binarios correspondientes de la A-Z(mayusculas) y binam con las minusculas
    string binarM={"0100000101000010010000110100010001000101010001100100011101001000010010010100101001001011010011000100110101001110010011110101000001010001010100100101001101010100010101010101011001010111010110000101100101011010"};
    string binarm={"0110000101100010011000110110010001100101011001100110011101101000011010010110101001101011011011000110110101101110011011110111000001110001011100100111001101110100011101010111011001110111011110000111100101111010"};

    large=data.length();
    cb="";
    def="";
    //ciclo para pasar la cadena de caracteres a cadena de bits
    for (int i=0; i<large;i++){
         for (int l=0; l<26; l++){
             if(data[i]==letrasM[l]){
                 num=8*l;
                 for(int b=num; b<num+8;b++){
                         cb+=binarM[b];
                    }
                }
             else if(data[i]==letrasm[l]){
                  num=8*l;
                  for(int b=num; b<num+8;b++){
                          cb+=binarm[b];
                    }
                }
             else if(data[i]==carac[l]){
                  num=8*l;
                  for(int b=num; b<num+8;b++){
                          cb+=binarc[b];
                    }
                }
            }
        }
    large=cb.length();
    data="";
    num=s-1;
    //ciclo para hacer el proceso de encriptacion por el metodo 2 con semilla 4
    for (int i=0;i<large;i++){
           while(cb[i+num]==data[0]){
               num-=1;
           }
           def+=cb[i+num];
           for (int j=i;j<i+num;j++){
               def+=cb[j];
             }
           for(int j=0; j<s-1;j++){
            i++;
           }
        }
//metodo app para escribir en un archivo sin modificar su informacion(seguir en la siguiente linea)
f.open(file, ios::app);
f<<def<<endl;
f.close();
}

desencriptacion::desencriptacion(string d){
    binary=d;
 }

void desencriptacion::desencriptar(){

    ofstream tem;
    int large,num,cont0=0,cont1=0,mul,s=4;
    string cb,def;
    string binario={"01"},letras;

    def="";
    letras="";
    large=binary.length();
    num=s-1;
    //ciclo que hace el proceso contrario que en la encriptacion(metodo 2 semilla 4)
    for (int i=0;i<large;i++){
         while(binary[i+num]==def[0]){
             num-=1;
          }
         for (int j=i+1;j<i+s;j++){
             if(binary[j]!=def[0]){
               cb+=binary[j];
              }
             }
         cb+=binary[i];
         for (int j=0; j<s-1; j++){
             i++;
         }
       }
    large=cb.length();
    num=1;
    s=8;
    //ciclo que convierte los bits a cadenas de caracteres de letras o numeros segun el caso
    for (int i=0; i<large;i++){
        mul=s*num;
        cont0=0;
        cont1=0;
        for(int j=i; j<mul;j++){
            cont0++;
            if(cont0==1 and cb[j]==binario[1]){
                cont1+=128;
            }
            else if(cont0==2 and cb[j]==binario[1]){
                cont1+=64;
            }
            else if(cont0==3 and cb[j]==binario[1]){
                cont1+=32;
            }
            else if(cont0==4 and cb[j]==binario[1]){
                cont1+=16;
            }
            else if(cont0==5 and cb[j]==binario[1]){
                cont1+=8;
            }
            else if(cont0==6 and cb[j]==binario[1]){
                cont1+=4;
            }
            else if(cont0==7 and cb[j]==binario[1]){
                cont1+=2;
            }
            else if(cont0==8 and cb[j]==binario[1]){
                cont1+=1;
            }
        }
       letras+=cont1;
       num++;
       for(int j=0; j<7;j++){
           i++;
       }
      }
    //se crea el documento que contiene la cadena letras
    tem.open("../AppCajero/BD/temporal.txt");
    tem<<letras;
    tem.close();
}
