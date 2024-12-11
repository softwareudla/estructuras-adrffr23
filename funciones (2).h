struct Libro{
    int id;
    char titulo[100];
    char autor[50];
    int añopublicacion;
    char estado[50];
};
int menu(int eleccion);
void buscarLibroId(struct Libro libros[], int idbus, int n);
void registrarLibros(struct Libro libros[], int i);
void mostrarLibros(struct Libro libros[], int n);
void buscarLibroTitulo(struct Libro libros[], int n);
void actualizarestado(struct Libro libros[], int n);
void eliminarLibroPorTitulo(struct Libro libros[], int n);