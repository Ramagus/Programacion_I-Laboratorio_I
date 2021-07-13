typedef struct
{
  int legajo;
  int nota;
  char nombre[50];
  int estaVacio; //0 para no, 1 para esta vacio

} eAlumno;

void inicializarAlumnos(eAlumno listado[], int cantidad);
int dameElIndiceLibre(eAlumno listado[], int cantidad);
int cargarAlumnosTest(eAlumno listado[], int cantidad);
eAlumno agregarAlumno(eAlumno listado[], int cantidad);
void cargarListado(eAlumno listado[], int cantidad);
void mostrarUnAlumno(eAlumno alguno);
void mostrarAlumnos(eAlumno listado[], int cantidad, int tieneAlumnos);
int buscarAlumnoPorLegajo(eAlumno listado[], int cantidad, int legajo);
int buscarAlumnoPorNombre(eAlumno listado[], int cantidad, char nombre[]);
int borrarAlumno(eAlumno listado[], int cantidad, char nombre[], int indice);
int contarLugaresLibres(eAlumno listado[], int cantidad);
