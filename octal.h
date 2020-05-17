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
    short oct[30];

};
/*constructor predeterminado*/
octal::octal(long valor)
{
  for(int i = 0; i <= 29; i++)
      oct[i] = 0;

  /*coloca los digitos del argumento dentro del arreglo*/
  for(int j = 29; valor != 0 && j >= 0; j--)
  {
      oct[j] = valor % 8; //residuo del valor
      valor /= 8;
  }

}

octal octal::operator+(const octal &op2) const
{
    octal temp;
    int acarreo = 0;
    for(int i = 29; i >= 0; i--)
    {
        temp.oct[i] = oct[i] + op2.oct[i] - acarreo;
        if(temp.oct[i] > 7)
        {
            temp.oct[i] %= 8; //reduce a 0-9
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
        if(op3.oct[i] > (oct[i] + acarreo)){

             temp.oct[i] = op3.oct[i] - (oct[i] + acarreo);

        }

        if(oct[i] > (op3.oct[i] + acarreo)){

             temp.oct[i] = (oct[i] + acarreo) - op3.oct[i] ;

        }
        temp.oct[i] = (oct[i] + acarreo) - op3.oct[i] ;

        if(temp.oct[i] > 7)
        {
            temp.oct[i] %= 8; //reduce a 0-7
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
    for(i = 0; (num.oct[i] == 0) && (i <= 29); i++);
    /*ignora ceros a la izquierda*/

    if(i == 30)
        salida << 0;
    else
        for( ; i <= 29; i++)
            salida << num.oct[i];
    return salida;
}

#endif // OCTAL_H
