#include <stdio.h>
#include "funciones (2).h"
#include "string.h"

int main (int argc, char *argv[]) {

    struct Libro libros[20];
    int opc;
    int i=0;
    int id;
    do{
    opc = menu(opc);
    switch (opc)
    {
        case 1:
            registrarLibros(libros, i);
            i++;
            break;
        case 2:
            mostrarLibros(libros,i);
            break;
        case 3:
            printf("Ingrese el id del libro a buscar: ");
            scanf("%d", &id);
            buscarLibroId(libros, id, i);
            break;
        case 4:
            buscarLibroTitulo(libros,i);
            break;
        case 5:
            actualizarestado(libros, i);
            break;
        case 6:
            eliminarLibroPorTitulo(libros, i);
            i--;
            break;
        case 7:
            opc=7;
            break;
        default:
            printf("Digito incorrecto vuelva a ingresar otro digito");
            break;
        
    }
    }while(opc != 7);


    return 0;
}