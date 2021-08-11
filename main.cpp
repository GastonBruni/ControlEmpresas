#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

/*Enunciado:
A)Posea un menu principal (puede ser la propia funcion main) con todas las operaciones disponibles.
B)Cargar la informacion, validando que el ID ingresando este entre los limites definidos. La carga termina con el ID = 1000. Considere que los datos no se ingresan en ningun orden en particular.
C)Emitir un listado indicando el total de la facturacion de cada zona.
D)Informar por pantalla los datos de las sucursales con el max y min de facturación.
*/

//Creo una Estructura de datos para las empresas
struct empresas{
    int id;
    char nombre[15];
    char direccion[50];
    char zona[15];
    float facturacion;
}emp[3];

void cargarEmpresas(){
    int mayor = 999;
        for(int i=0;i<=2;i++){
            cout<<"\n";
            cout<<". Recuerde que al cargar una empresa con id > a 999 terminara la carga de datos .";
            cout<<"\n";
            cout<<i+1<<". Ingrese id de la empresa: ";
            cin>>emp[i].id;
            if(emp[i].id < 999){
            fflush(stdin);//Vaciamos el buffer para permitir digitar los valores.
            cout<<i+1<<". Ingrese nombre de la empresa: ";
            cin.getline(emp[i].nombre,15,'\n');
            cout<<i+1<<". Ingrese direccion de la empresa: ";
            cin.getline(emp[i].direccion,50,'\n');
            cout<<". La zona ingresada puede ser una de las siguientes: (Norte,Sur,Este,Oeste,Centro).";
            cout<<"\n";
            cout<<i+1<<". Ingrese zona de la empresa: ";
            cin.getline(emp[i].zona,15,'\n');
            cout<<i+1<<". Ingrese facturacion de la empresa: ";
            cin>>emp[i].facturacion;
            }else{
            cout<<" Finalizo la carga de empresas.";
            cout<<"\n";
            fflush(stdin);
            system("exit");
            }
        }
    }

void mayorMenorFacturacionEmpresas(){
    int posMay=0,posMen=0;
    float mayor = 0, menor = 9999999;
        //Determinamos que empresa tiene mayor facturacion.
        for(int i=0;i<=2;i++){
            if(emp[i].facturacion > mayor){
                mayor = emp[i].facturacion;
                posMay = i;
            }
            //Determinamos que empresa tiene menor facturacion.
            if(emp[i].facturacion < menor){
                menor = emp[i].facturacion;
                posMen = i;
            }
        }
            cout<<"\n";

            cout<<"\n:Datos de la empresa con mayor facturacion: \n";
            cout<<"Nombre: "<<emp[posMay].nombre<<endl;
            cout<<"Facturacion: "<<emp[posMay].facturacion<<endl;

            cout<<"\n:Datos de la empresa con menor facturacion: \n";
            cout<<"Nombre: "<<emp[posMen].nombre<<endl;
            cout<<"Facturacion: "<<emp[posMen].facturacion<<endl;
}

void mostrarTotalEmpresas(){
    //Imprimimos los datos cargados por el usuario.
    for(int i=0; i<=2;i++){
        cout<<"\n";
        cout<<"Id: "<<emp[i].id<<endl;
        cout<<"Nombre: "<<emp[i].nombre<<endl;
        cout<<"Direccion: "<<emp[i].direccion<<endl;
        cout<<"Zona: "<<emp[i].zona<<endl;
        cout<<"Facturacion: "<<emp[i].facturacion<<endl;
        cout<<"\n";
     }
}

void mostrarFacturacionPorZona(){
    empresas aux;
    int i,j,fact,fact2;
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            if(strcmp(emp[j].zona,emp[j+1].zona)>0){
                aux=emp[j];
                emp[j]=emp[j+1];
                emp[j+1]=aux;
                fact = aux.facturacion;
                fact2 = fact2 + fact;
            }
        }
    }
    for(i=0;i<=2;i++){
        fflush(stdin);
        cout<<"La zona es: "<<emp[i].zona<<" y su facturacion: "<<fact2<<endl;
    }
}

int main(){

    //Creamos un menu
    int opc,opcExit;
    cout<<"\n";
    cout<<"\tBienvenido al menu principal"<<endl;
    cout<<"1. Cargar Empresas"<<endl;
    cout<<"2. Mostrar todas las Empresas"<<endl;
    cout<<"3. Mostrar empresas con > y < facturacion"<<endl;
    cout<<"4. Mostrar empresas con misma zona"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>opc;

    switch(opc){
        case 1: cargarEmpresas();
        break;
        case 2: mayorMenorFacturacionEmpresas();
        break;
        case 3: mostrarTotalEmpresas();
        break;
        case 4: mostrarFacturacionPorZona();
        break;
        case 5:cout<<"\nHasta luego!!\n";
        return 0;
    }

    getch();
    return main();

}



