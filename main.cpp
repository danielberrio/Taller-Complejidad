#include "binario.h"
#include "decimal.h"
#include "octal.h"
#include <conio.h>
using namespace std;

int main()
{

    int op=0;

    do
    {
        cout<<"\nSISTEMAS NUMERICOS"<<endl;
        cout<<"\n1.DECIMAL";
        cout<<"\n2.OCTAL";
        cout<<"\n3.BINARIO";
        cout<<"\n4.SALIR";
        cout<<"\nESCOJA OPCION: ";
        cin>>op;
        switch(op)
        {
        case 1:

            system("cls"); // limpiar la consola
            int dec1, dec2, resp1;
            cout<<"\t\t**** DECIMAL ****\n\n";
            cout<<"¿QUE DESEA? \n";
            cout<<"\n1.SUMAR";
            cout<<"\n2.RESTAR";
            cout<<"\n3.SALIR\n";
            cout<<"Ingrese una opcion: ";
            cin>>resp1;
            cout<<endl;

            if(resp1 == 1)

            {
                //suma decimal
                cout<<"Ingrese el primer numero de la suma: ";
                cin>>dec1;
                cout<<"Ingrese el segundo numero de la suma: ";
                cin>>dec2;
                decimal n1(dec1);
                decimal n2(dec2);
                decimal resultado = n1 + n2;
                cout<<n1<<" + "<<n2<<" = "<<resultado<<endl;
            }

            else
            {
                if(resp1 == 2)
                {
                    //resta decimal
                    cout<<"Ingrese el primer numero de la resta: ";
                    cin>>dec1;
                    cout<<"Ingrese el segundo numero de la resta: ";
                    cin>>dec2;
                    decimal n1(dec1);
                    decimal n2(dec2);
                    decimal resultado = n1 - n2;
                    cout<<n1<<" - "<<n2<<" = "<<resultado<<endl;
                }

                else
                {
                    cout<<"Adios. \n";
                    break;
                }
            }

            break;

        case 2:
            system("cls"); // limpiar la consola
            int oct1, oct2, resp2;
            cout<<"\t\t**** OCTAL ****\n\n";
            cout<<"¿QUE DESEA? \n";
            cout<<"\n1.SUMAR";
            cout<<"\n2.RESTAR";
            cout<<"\n3.SALIR\n";
            cout<<"Ingrese una opcion: ";
            cin>>resp2;
            cout<<endl;

            if(resp2 == 1)
            {
                cout<<"Ingrese el primer numero de la suma: ";
                cin>>oct1;

                cout<<"Ingrese el segundo numero de la suma: ";
                cin>>oct2;

                octal n1(oct1);
                octal n2(oct2);
                octal resultado = n1 + n2;
                cout<<n1<<" + "<<n2<<" = "<<resultado<<endl;
            }

            else
            {
                if(resp2 == 2)
                {
                    cout<<"Ingrese el primer numero de la resta: ";
                    cin>>oct1;
                    cout<<"Ingrese el segundo numero de la resta: ";
                    cin>>oct2;
                    octal n1(oct1);
                    octal n2(oct2);
                    octal resultado = n1 - n2;
                    cout<<n1<<" - "<<n2<<" = "<<resultado<<endl;
                }

                else
                {
                    cout<<"Adios. \n";
                    break;
                }
            }

            break;

        case 3:
            system("cls"); // limpiar la consola
            int bin1, bin2, resp3;
            cout<<"\t\t**** BINARIO ****\n\n";
            cout<<"¿QUE DESEA? \n";
            cout<<"\n1.SUMAR";
            cout<<"\n2.RESTAR";
            cout<<"\n3.SALIR\n";
            cout<<"Ingrese una opcion: ";
            cin>>resp3;
            cout<<endl;

            if(resp3 == 1)
            {
                cout<<"Ingrese el primer numero de la suma: ";
                cin>>bin1;
                cout<<"Ingrese el segundo numero de la suma: ";
                cin>>bin2;
                binario n1(bin1);
                binario n2(bin2);
                binario resultado = n1 + n2;
                cout<<n1<<" + "<<n2<<" = "<<resultado<<endl;
            }

            else
            {
                if(resp3 == 2)
                {
                    cout<<"Ingrese el primer numero de la resta: ";
                    cin>>bin1;
                    cout<<"Ingrese el segundo numero de la resta: ";
                    cin>>bin2;
                    binario n1(bin1);
                    binario n2(bin2);
                    binario resultado = n1 - n2;
                    cout<<n1<<" - "<<n2<<" = "<<resultado<<endl;
                }

                else
                {
                    cout<<"Adios. \n";
                    break;
                }
            }

            break;

        case 4:
            system("cls");
            cout<<"\nAdios"<<endl;

            break;

        default:
            cout<<"Opcion incorrecta, ingrese una opción valida. \n\n";

            break;

        }

    }
    while(op!=4);


    return 0;
}

