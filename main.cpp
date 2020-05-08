#include <iostream>
#include "binario.h"
#include "decimal.h"
using namespace std;
int main()
{
    decimal n10(56745);
    decimal n11(34467);
    decimal n12;
    binario n1(45);
    binario n2(44);
    binario n3;
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
            //system("clear");
            n12 = n10 - n11;
            cout << "\n\n";
            cout<<"\n"<<n10;
            cout<< " \n- ";
            cout<<"\n"<<n11;
            cout<<"\n------";
            cout<< " \n="<< n12;
            //cout << "\n\n";
            break;
        case 2:
            break;
        case 3:
            system("cls");
            cout << "\nn1 es " << n1;
            cout << "\nn2 es " << n2;
            cout << "\nn3 es " << n3;

            n3 = n1 - n2;
            
            cout << "\n\n" << n1 << " - " << n2 << " = " << n3;

            cout << "\n\n";
            break;
        case 4:
            system("cls");
            cout<<"\nAdios"<<endl;
            break;
        default:
            break;

        }

    }
    while(op!=4);



    return 0;
}
