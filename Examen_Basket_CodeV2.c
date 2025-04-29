#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char nombre[5][30];
    int puntos[5][4];
    float promedio[5];
    int val, valido, len, vacio;
    float totalPuntos;
    int theBest = 0;
    printf("\n== NBA TOURNAMENT 2025 ==\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nAtleta %d\n", i + 1);
        do
        {
            valido = 1;
            printf("Ingrese el nombre: ");
            fflush(stdin);
            fgets(nombre[i], 30, stdin);

            len = strlen(nombre[i]) - 1;
            nombre[i][len] = '\0';

            if (strlen(nombre[i]) == 0)
            {
                valido = 0;
            }

            for (int j = 0; nombre[i][j] != '\0'; j++)
            {
                if (nombre[i][j] >= '0' && nombre[i][j] <= '9')
                {
                    valido = 0;
                }
            }
            if (valido == 0)
            {
                printf("Error: El nombre no puede estar vacio ni contener numeros\n");
            }

        } while (!valido);
        totalPuntos = 0;
        for (int j = 0; j < 4; j++)
        {
            do
            {
                valido = 1;
                printf("Ingrese los puntos del partido %d: ", j + 1);
                val = scanf("%d", &puntos[i][j]);
                while (getchar() != '\n');
                if (val != 1)
                {
                    valido = 0;
                }
                if (puntos[i][j] < 0)
                {
                    valido = 0;
                }
                if (valido == 0)
                {
                    printf("Error: No puede ingresar letras ni numeros negativos\n");
                }

            } while (!valido);

            totalPuntos += puntos[i][j];
        }
        promedio[i] = totalPuntos / 4;
        printf("Promedio: %.2f\n", promedio[i]);
        float maxProm;

        if (promedio[i] > maxProm)
        {
            maxProm = promedio[i];
            theBest = i;
        }
    }

    printf("\n== RESULTADOS DEL CAMPEONATO ==\n");
    printf("#\tNombre\t\tP1\tP2\tP3\tP4\tPromedio\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t\t%d\t%d\t%d\t%d\t%.2f\n", i + 1, nombre[i], puntos[i][0], puntos[i][1], puntos[i][2], puntos[i][3], promedio[i]);
    }

    printf("\n== THE BEST ==\n");
    printf("El mejor jugador es: %s\n", nombre[theBest]);
    printf("Promedio de Anotaciones: %.2f\n", promedio[theBest]);

    return 0;
}