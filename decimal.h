#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
using namespace std;

class decimal
{
public:
    friend ostream &operator<<(ostream &, const decimal &);
public:
    decimal(long = 0);
    //declaramos los operadores a sobrecargar
    decimal operator+(const decimal &) const;
    decimal operator-( decimal &);
private:
    short dec[30]; //tamaño del vector decimal

};
/*constructor predeterminado*/
decimal::decimal(long valor)
{
  for(int i = 0; i <= 29; i++)
      dec[i] = 0;

  /*coloca los digitos del argumento dentro del arreglo*/
  for(int j = 29; valor != 0 && j >= 0; j--)
  {
      dec[j] = valor % 10; //residuo del valor
      valor /= 10;
  }

}
//sobrecarga del operador suma
decimal decimal::operator+(const decimal &op2) const
{
    decimal temp; //declaramos un temporal para la operacion
    int acarreo = 0;
    for(int i = 29; i >= 0; i--) //ciclo para recorrer cada posicion del arreglo
    {
        temp.dec[i] = dec[i] + op2.dec[i] + acarreo;
        //si el numero es mayor a 9 se lleva su acarreo
        if(temp.dec[i] > 9)
        {
            temp.dec[i] %= 10; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}

//sobrecarga del operador -
decimal decimal::operator-(decimal &op3)
{
    decimal temp; //temporal para la operación
    int acarreo = 0;

    for(int i = 29; i >= 0; i--) //ciclo para recorrer cada posicion del arreglo
    {
        if(op3.dec[i] > (dec[i] + acarreo)) //condicion por si el segundo número ingresado es mayor que el primero
        {

             temp.dec[i] = op3.dec[i] - (dec[i] + acarreo);

        }
        temp.dec[i] = (dec[i] + acarreo) - op3.dec[i] ;
        //si el numero es mayor a 9 se lleva su acarreo
        if(temp.dec[i] > 9)
        {
            temp.dec[i] %= 10; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }

    return temp;
}

/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const decimal &num)
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

#endif // DECIMAL_H
