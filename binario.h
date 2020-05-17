#ifndef BINARIO_H
#define BINARIO_H

#include <iostream>
using namespace std;
class binario
{
    friend ostream &operator<<(ostream &, const binario &);

public:
    binario(long = 0);
    //declaramos los operadores a sobrecargar
    binario operator+(const binario &) const;
    binario operator-(binario &);
    virtual void menu() const;
private:
    short bin[40]; //tamaño del vector binario
};

/*constructor predeterminado; convierte un entero decimal en un objeto binario*/
binario::binario(long valor)
{
    for(int i = 0; i <= 39; i++)
        bin[i] = 0;

    /*coloca los digitos del argumento dentro del arreglo*/
    for(int j = 39; valor != 0 && j >= 0; j--)
    {
        bin[j] = valor % 2; //deja el resduo de la división del valor entre 2
        valor /= 2;
    }
}

//sobrecarga del operador suma
binario binario::operator+(const binario &op2) const
{
    binario temp; //temporal para la operación
    int acarreo = 0;

    for(int i = 39; i >= 0; i--)
    {
        temp.bin[i] = bin[i] + op2.bin[i] + acarreo;
        //si el numero es mayor a 1 se lleva su acarreo
        if(temp.bin[i] > 1)
        {
            temp.bin[i] %= 2; //reduce a 0 - 1
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}
//sobrecarga del operador -
binario binario::operator-(binario &op2)
{
    binario temp;
    int acarreo = 0;

    for(int i = 39; i >= 0; i--)
    {

        temp.bin[i] = bin[i] - op2.bin[i]-acarreo;

         if(temp.bin[i] > 1)
        {
            temp.bin[i] %= 2; //reduce a 0 - 1
            acarreo = 1;
        }
        else
            acarreo = 0;

        /*si la resta da como resultado un negativo eentonces se cambia el valor y el carreo
        para que así se ajuste al resultado que se quiere llegar*/

        if(temp.bin[i]==-1)
        {
            acarreo=1;
            temp.bin[i] = 1;
        }
        else
        {
            if(temp.bin[i]==-2)
            {
                acarreo=1;
                temp.bin[i]=0;
            }
        }



    }
    return temp;
}
/*operador de salida sobrecargado*/
ostream& operator<<(ostream &salida, const binario &num)
{
    int i;
    for(i = 0; (num.bin[i] == 0) && (i <= 39); i++);
    /*ignora ceros a la izquierda*/

    if(i == 40)
        salida << 0;
    else
        for( ; i <= 39; i++)
            salida << num.bin[i];
    return salida;
}

#endif // BINARIO_H
