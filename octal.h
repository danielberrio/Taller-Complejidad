#ifndef OCTAL_H
#define OCTAL_H

#include <iostream>
using namespace std;

class octal
{
public:
    friend ostream &operator<<(ostream &, const octal &);
public:
    octal(long = 0);
    octal operator+(const octal &) const;
    octal operator-( octal &);
private:
    short dec[30];

};
/*constructor predeterminado*/
octal::octal(long valor)
{
  for(int i = 0; i <= 29; i++)
      dec[i] = 0;

  /*coloca los digitos del argumento dentro del arreglo*/
  for(int j = 29; valor != 0 && j >= 0; j--)
  {
      dec[j] = valor % 8; //residuo del valor
      valor /= 8;
  }

}

octal octal::operator+(const octal &op2) const
{
    octal temp;
    int acarreo = 0;
    for(int i = 29; i >= 0; i--)
    {
        temp.dec[i] = dec[i] + op2.dec[i] - acarreo;
        if(temp.dec[i] > 7)
        {
            temp.dec[i] %= 8; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}
octal octal::operator-(octal &op3)
{
    octal temp;
    int acarreo = 0;
    for(int i = 29; i >= 0; i--)
    {

        //op3 es el segundo numero
        if(op3.dec[i]>(dec[i] + acarreo)){
            dec[i-1] -= 1;
            acarreo = 8;
        }

        temp.dec[i] = (dec[i] + acarreo) - op3.dec[i];

        if(temp.dec[i] > 7)
        {
            temp.dec[i] %= 8; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}

/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const octal &num)
{
    int i;
    for(i = 0; (num.dec[i] == 0) && (i <= 29); i++);
    /*ignora ceros a la izquierda*/

    if(i == 30)
        salida << 0;
    else
        for( ; i <= 29; i++)
            salida << num.dec[i];
    return salida;
}

#endif // OCTAL_H
