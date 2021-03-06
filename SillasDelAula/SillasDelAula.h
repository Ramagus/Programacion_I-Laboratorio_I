void hardcodearSillas(int arrayDeSillas[], int cantidad);
void harcodearLegajos(int arrayDeLegajos[], int cantidad);
void harcodearEdades(int arrayDeEdades[], int cantidad);
void inicializarArray(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad, int valorInicial);
void calcularMinimo(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad);
void calcularMaximo(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad);
int estaLibre(int arrayDeSillas[], int cantidad, int indice, int valorInicial);
int ocuparSilla(int arrayDeSillas[], int cantidad, int indice, int valorInicial, int legajo);
int cantidadSillasOcupadas(int arrayDeSillas[], int cantidad, int valorInicial);
int cantidadSillasLibres(int arrayDeSillas[], int cantidad, int valorInicial);
int indiceDeLaPrimeraSillaLibre(int arrayDeSillas[], int cantidad, int valorInicial);
void mostrarMasViejo(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad);
void mostrarTodo(int arrayDeSillas[], int arrayDeLegajos[], int arrayDeEdades[], int cantidad);
