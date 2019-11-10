//JOSE LUIS PACHECO B.
//V-26169922
//PROGRAMACION NO NUMERICA I
//UNIVERSIDAD CENTROCCIDENTAL LISANDRO ALVARADO

#include <iostream>
#include <cstdlib>

#include "Lista.h"
#include "Pila.h"
#include "Cola.h"


using namespace std;


int main(){
    int continuar=true;
    do {

        cout << "\n\nPROGRAMACION NO NUMERICA I - UCLA" << endl;
        cout << "\n=======MENU DE OPCIONES=========\n\n" << endl;
        int resp = 0;

        cout << "(1) LLENAR E IMPRIMIR PILA." << endl;
        cout << "(2) LLENAR E IMPRIMIR COLA." << endl;
        cout << "(3) TABLA DE MULTIPLICAR." << endl;
        cout << "(4) SALIR." << endl;
        cout << "\nSELECCION: ";
        cin >> resp;
        switch (resp) {
            case 1 : {

                //LEER E IMPRIMIR 10 NUMEROS CON PILAS:

                int cont = 1;
                int num = 0;
                int dato = 0;


                Pila<int> pila1; //pila principal
                Pila<int> pila2; //pila auxiliar

                for (int i = 0; i < 10; i++) {

                    cout << "Ingrese el numero (" << i + 1 << "): ";
                    cin >> num;
                    pila1.Insertar(num);

                }

                //PARA IMPRIMIR:

                cout << "\n\nCONTENIDO DE LA PILA:\n\n";

                do {
                    dato = pila1.ObtTope()->info;
                    cout << dato << endl;
                    pila2.Insertar(dato);
                    pila1.Remover(pila1.ObtTope()->info);
                } while (!pila1.Vacia());

                //PARA DEVOLVER EL CONTENIDO DE LA PILA AUX A LA ORIGINAL...
                do {
                    dato = pila2.ObtTope()->info;
                    pila1.Insertar(dato);
                    pila2.Remover(dato);
                } while (!pila2.Vacia());

                cout << "\n";

                system("PAUSE");
                system("CLS");
                break;
            }

            case 2: {
                //LEER E IMPRIMIR 10 NUMEROS CON COLAS:

                int num = 0;
                int marca = -1;
                bool encontrada = false;
                int frente = 0;

                Cola<int> cola1;


                for (int i = 0; i < 10; i++) {

                    cout << "Ingrese el numero (" << i + 1 << "): ";
                    cin >> num;
                    cola1.Insertar(num);

                }

                //PARA IMPRIMIR:

                cout << "\n\nCONTENIDO DE LA COLA:\n\n";
                cola1.Insertar(marca);

                do {


                    cola1.Remover(frente);

                    if (frente == marca)
                        encontrada = true;
                    else {
                        cout << frente << endl;
                        cola1.Insertar(frente);
                    }
                } while (encontrada == false);

                cout << "\n";
                system("PAUSE");

                system("CLS");
                break;
            }
            case 3: {
                //TABLAS DE MULTIPLICAR:

                int numero1;

                Cola<int> num2;
                //se crea y llena una cola de 10 elementos (factor 2 de la multiplicacion)
                for (int j = 1; j <= 10; j++) {
                    num2.Insertar(j);
                }
                //se crea y llena una pila con 10 elementos de una misma cola repetida
                Pila<Cola<int>> num1;
                for (int i = 1; i < 10; i++) {
                    num1.Insertar(num2);
                }
                Cola<int> colaaux; //se crea una cola auxiliar para buscar...
                Pila<int> pilaaux; //se crea una pila auxiliar para buscar...

                cout << "\nIngrese el numero del que desea generar la tabla:";
                cin >> numero1;


                //Proceso de busqueda en la  pila
                //Se selecciona la cola adecuada de la pila...

                for (int k = 1; k < numero1 -
                                    1; k++) { //saco hasta una antes para que la 1era que quede en la pila sea la que necesito estudiar
                    pilaaux.Insertar(num1.ObtTope()->info.getFrente()->getInfoNodo());
                    num1.Remover(num1.ObtTope()->info); //quitamos la cola que esta en el tope de la pila
                }

                //ahora queda en el tope de la pila num1 la cola que necesitamos

                int marca = -1;
                int dato;
                bool encontrada = false;
                num1.ObtTope()->info.Insertar(marca);

                cout << "TABLA DE MULTIPLICAR DEL : " << numero1 << endl <<endl;

                do {

                    num1.ObtTope()->info.Remover(dato); //aqui dato sea el elemento removido de la cola / el primero

                    if (dato == marca)
                        encontrada = true;
                    else {
                        cout << numero1 << " x " << dato << " = ";
                        cout << numero1 * dato;
                        num1.ObtTope()->info.Insertar(dato);
                        cout << endl;
                    }
                } while (encontrada == false);

                cout << "\n";
                system("PAUSE");
                system("CLS");
                break;

            }
            case 4: //salir
            {
                continuar = false;
                break;

            }
            default: {
                cout << "\n\nIngrese una opcion valida.\n";

                system("PAUSE");
                system("CLS");
                break;

            }
        }

}while(continuar!=0);
    return 0;
}
