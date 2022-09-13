#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{
    int legajo;
    float nota;
    char sexo;

} eAlumno;

int main()
{
    eAlumno unAlumno; //= {1000, 7, 'F'};
    eAlumno* pAlumno;

    pAlumno = &unAlumno;

    printf("Ingrese legajo: ");
    //scanf("%d", &(*pAlumno).legajo);
    scanf("%d", &pAlumno->legajo);

    printf("Ingrese nota: ");
    //scanf("%f", &(*pAlumno).nota);
    scanf("%f", &pAlumno->nota);

    printf("Ingrese sexo: ");
    fflush(stdin);
    //(*pAlumno).sexo = toupper(getche());
    pAlumno->sexo = toupper(getche());

    printf("\n\nLEGAJO\tNOTA\tSEXO\n\n");
    //printf("%d\t%.2f\t%c\n\n", (*pAlumno).legajo, (*pAlumno).nota, (*pAlumno).sexo);
    printf("%d\t%.2f\t%c\n\n", pAlumno->legajo, pAlumno->nota, pAlumno->sexo);

    system("pause");
    system("cls");

    eAlumno lista[3] = {{1001, 8, 'M'}, {1002, 9, 'F'}, {1003, 10, 'M'}};
    eAlumno* pLista;

    pLista = lista;

    int i;

    printf("LEGAJO\tNOTA\tSEXO\n\n");

    for(i = 0; i < 3; i++)
    {
        //printf("%d\t%.2f\t%c\n", (*(pLista + i)).legajo, (*(pLista + i)).nota, (*(pLista + i)).sexo);
        printf("%d\t%.2f\t%c\n", (pLista + i)->legajo, (pLista + i)->nota, (pLista + i)->sexo);
    }

    return 0;
}
