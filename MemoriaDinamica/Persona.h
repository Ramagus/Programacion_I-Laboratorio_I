typedef struct
{
    int legajo;
    char sexo;
    float altura;

} ePersona;

ePersona* new_Persona(); //Constructor por defecto
ePersona* new_Persona_Parametros(int legajo, char sexo, float altura); //Constructor parametrizado
void setLegajo(ePersona* unaPersona, int legajo);
int getLegajo(ePersona* unaPersona);
void delete_Persona(ePersona* unaPersona);
void mostrarPersona(ePersona* unaPersona);
