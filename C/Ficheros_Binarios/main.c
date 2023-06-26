#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar las palabras y su cantidad
struct Palabra {
    char palabra[100];
    int cantidad;
    struct Palabra* siguientePalabra;
};

int main() {
    char archivoDiccionario[100] = "Diccionario.txt";
    char archivoFrase[100] = "Frase.txt";
    char archivoBinario[100] = "Salida_Binario.bin";
    FILE* ficheroDiccionario = fopen(archivoDiccionario, "r");
    FILE* ficheroFrase = fopen(archivoFrase, "r");
    FILE* fichero_Binario=fopen(archivoBinario,"wb+");

    if (ficheroDiccionario == NULL || ficheroFrase == NULL) {
        printf("No se pudo abrir uno o ambos archivos.\n");
        return 1;
    }

    // Crear lista enlazada vacía
    struct Palabra* listaPalabras = NULL;

    // Leer palabras del archivo1 y crear nodos en la lista enlazada
    char palabra[100];
    while (fscanf(ficheroDiccionario, "%s", palabra) == 1) {
        // Crear un nuevo nodo de palabra
       // printf("\nPalabra vale: %s",palabra);
        struct Palabra* nuevoNodo = (struct Palabra*)malloc(sizeof(struct Palabra));
        strcpy(nuevoNodo->palabra, palabra);
        nuevoNodo->cantidad = 0;
        nuevoNodo->siguientePalabra = NULL;

        // Insertar el nuevo nodo al final de la lista enlazada
        if (listaPalabras == NULL) {
            listaPalabras = nuevoNodo;
        } else {
            struct Palabra* nodoActual = listaPalabras;
            while (nodoActual->siguientePalabra != NULL) {
                nodoActual = nodoActual->siguientePalabra;
            }
            nodoActual->siguientePalabra = nuevoNodo;
        }
    }

    // Leer la frase del archivo2 y contar las palabras en la lista enlazada
    char palabraFrase[100];
    while (fscanf(ficheroFrase, "%s", palabraFrase) == 1) {
        struct Palabra* nodoActual = listaPalabras;
        while (nodoActual != NULL) {
            if (strcmp(nodoActual->palabra, palabraFrase) == 0) {
                nodoActual->cantidad++;
                break;
            }
            nodoActual = nodoActual->siguientePalabra;
        }
    }

    // Imprimir las palabras y su cantidad
    struct Palabra* nodoActual = listaPalabras;
    while (nodoActual != NULL) {
        printf("\nPalabra: %s, Cantidad: %d\n", nodoActual->palabra, nodoActual->cantidad);
        fwrite(nodoActual,sizeof(struct Palabra),1,fichero_Binario);
        nodoActual = nodoActual->siguientePalabra;
    }

    // Liberar la memoria de la lista enlazada
    nodoActual = listaPalabras;
    while (nodoActual != NULL) {
        struct Palabra* nodoSiguiente = nodoActual->siguientePalabra;
        free(nodoActual);
        nodoActual = nodoSiguiente;
    }

    // Cerrar los archivos
    fclose(ficheroDiccionario);
    fclose(ficheroFrase);
    fclose(fichero_Binario);

    /// El binario
    ///
    ///
    printf("\nEmpieza la lectura Binaria\n");
    // Abrir el archivo binario en modo lectura
    FILE* fichero_Binario_lectura = fopen(archivoBinario, "rb");
    if (fichero_Binario_lectura == NULL) {
        printf("No se pudo abrir el archivo binario.\n");
        return 1;
    }

    // Leer y mostrar el contenido del archivo binario
    struct Palabra palabraBinaria;
    while (fread(&palabraBinaria, sizeof(struct Palabra), 1, fichero_Binario_lectura) == 1) {
        printf("Palabra: %s, Cantidad: %d\n", palabraBinaria.palabra, palabraBinaria.cantidad);
    }

    // Cerrar el archivo binario
    fclose(fichero_Binario_lectura);


    return 0;
}
