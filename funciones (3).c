#include <stdio.h>
#include "funciones (2).h"
#include "string.h"

int menu(int eleccion){
    printf("\n");
    printf("Que accion desea ejecutar?\n1.-Registrar libros\n2.-Mostrar libros\n3.-Buscar libro por ID\n4.-Buscar libro por Titulo\n5.-Actualizar Estado\n6.-Eliminar libro\n7.-Salir\n");
    scanf("%d",&eleccion);
    return eleccion;
}
void registrarLibros(struct Libro libros[], int i){
    int len;
    printf("Ingrese el ID del libro %d: ", i+1);
    scanf("%d", & libros[i].id);
    for(int e=0; e<i; e++){
        do{
            if(libros[i].id==libros[e].id){
            printf("El ID que ha sido ingresado no es unico, vuelva a ingresar\n");
            scanf("%d", &libros[i].id);
            }

        }while(libros[i].id==libros[e].id);
    }
    printf("Ingrese el titulo del libro %d: ", i+1);
    fflush(stdin);
    fgets(libros[i].titulo,100,stdin);
    len=strlen(libros[i].titulo)-1;
    libros[i].titulo[len]='\0';
    for(int o=0; o<i;o++){
        while(strcmp(libros[i].titulo,libros[o].titulo)==0){
            printf("Este titulo de libro ya existe, Ingrese el titulo del libro %d: ", i+1);
            fflush(stdin);
            fgets(libros[i].titulo,100,stdin);
            len=strlen(libros[i].titulo)-1;
            libros[i].titulo[len]='\0';
        }
    }
    printf("Ingrese el autor del libro %d: ", i+1);
    fflush(stdin);
    fgets(libros[i].autor,50,stdin);
    len=strlen(libros[i].autor)-1;
    libros[i].autor[len]='\0';
    printf("Ingrese el anio del libro %d: ", i+1);
    scanf("%d", & libros[i].añopublicacion);
    do{
        if(libros[i].añopublicacion<0 || libros[i].añopublicacion>2024){
        printf("El año ingresado no es real, vuelva a ingresar el valor\n");
        scanf("%d", & libros[i].añopublicacion);
    }
    }while(libros[i].añopublicacion<0 || libros[i].añopublicacion>2024);
    
    strcpy(libros[i].estado,"Disponible");
}
void mostrarLibros(struct Libro libros[], int n){
    printf("\n");
    printf("\n-------------------------------------------------------------------------");
    printf("\nID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for(int i=0;i<n; i++){
        printf("\n                                 |%i|", i + 1);
        if(libros[i].id !=0){
            printf("\n====================================================================");
            printf("\n%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libros[i].id,
                                                   libros[i].titulo,
                                                   libros[i].autor,
                                                   libros[i].añopublicacion, 
                                                   libros[i].estado);
            printf("\n====================================================================");
        }else if (libros[i].id == 0){
            printf("\n====================================================================");
            printf("\nEse Libro No Existe N/A ");
            printf("\n====================================================================");
        }
    }
    printf("\n-------------------------------------------------------------------------");
    printf("\n");
}

void buscarLibroTitulo(struct Libro libros[], int n){
    int z=0;
    printf("\n");
    char titulo[100];
    printf("Ingrese el titulo del libro a buscar: ");
    fflush(stdin);
    fgets(titulo,100,stdin);
    titulo[strcspn(titulo, "\n")] = '\0';
    for(int i=0; i<20; i++){
        if(strcmp(libros[i].titulo,titulo)==0){
            printf("El libro %s tiene: \nID:%d\nAutor:%s\nAnio:%d\nEstado:%s\n",
                                                                                libros[i].titulo,
                                                                                libros[i].id,
                                                                                libros[i].autor,
                                                                                libros[i].añopublicacion,
                                                                                libros[i].estado );
            z++;

        }
    }
    if(z==0){
        printf("El libro no existe\n");
    }
    printf("\n");
}
void buscarLibroId(struct Libro libros[], int idbus, int n){
    int t=0;
    printf("\n");
    for(int i=0; i<20;i++){
        if(idbus==libros[i].id){
            printf("\n==============================================================================");
            printf("\nEl ID %d pertenece al libro: \n%s\t\tautor:%s\t\tanio:%d\t\tEstado:%s\n",libros[i].id,
                                                                                          libros[i].titulo,
                                                                                          libros[i].autor,
                                                                                          libros[i].añopublicacion, 
                                                                                          libros[i].estado );
            t++;
            printf("\n==============================================================================");
        }
    }
    if(t==0){
        printf("El ID buscado no existe\n");
    }
    printf("\n");
}
void actualizarestado(struct Libro libros[], int n){
    int z=0;
    int suma=0;
    int escoger=0;
    char Buscar[50];
    printf("Ingrese el titulo del libro a editar el estado: ");
    fflush(stdin);
    fgets(Buscar,50,stdin);
    Buscar[strcspn(Buscar, "\n")] = '\0';
    for(int i=0; i<n; i++){
        if(strcmp(Buscar,libros[i].titulo)==0){
            suma++;
                do{
                    printf("A que estado desea cambiar?\n1.-Disponible\n2.-Prestado\n");
                    scanf("%d",&escoger);
                    switch (escoger)
                    {
                    case 1:
                        strcpy(libros[i].estado,"Disponible");
                        printf("El estado ha sido actualizado\nEl estado del libro %s es:%s", libros[i].titulo,libros[i].estado);
                        z=0;
                        break;
                    case 2:
                        strcpy(libros[i].estado,"Prestado");
                        printf("El estado ha sido actualizado\nEl estado del libro %s es:%s", libros[i].titulo,libros[i].estado);
                        z=0;
                        break;
                    default:
                        printf("La opción no es correcta\n");
                        z=1;
                        break;
                    }
                }while(z==1);
        }
    }
    if(suma==0){
        printf("El nombre del libro no se encontro\n");
    }
}
void eliminarLibroPorTitulo(struct Libro libros[], int n) {
    char titulo_a_eliminar[100];
    printf("\n");
    printf("Ingrese el titulo del libro que desea eliminar: ");
    fflush(stdin);
    fgets(titulo_a_eliminar,100, stdin);
    titulo_a_eliminar[strcspn(titulo_a_eliminar, "\n")] = 0; 

    int encontrado = 0;
    for (int i = 0; i < 20; i++) {
        if (strcmp(libros[i].titulo, titulo_a_eliminar) == 0) {
            encontrado = 1;

            // Desplazar los elementos hacia la izquierda
            for (int j = i; j < 20 - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (n)--; // Reducir el número de libros
            printf("Libro '%s' eliminado.\n", titulo_a_eliminar);
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontro un libro con el titulo '%s'.\n", titulo_a_eliminar);
    }
}