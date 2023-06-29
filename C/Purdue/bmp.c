
#include <stdio.h>
#pragma pack(1)
#include <structs.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define DIB_HEADER_SIZE 40


void free_bmp(BMPImage *image)
{
    free(image);
}


bool check_bmp_header(BMPHeader *bmp_hdr, FILE *fp)
{

    if (
            bmp_hdr->type == 0x4d42 &&                                                                                 // 1
            bmp_hdr->offset == BMP_HEADER_SIZE &&                                                                      // 2
            bmp_hdr->dib_header_size == DIB_HEADER_SIZE &&                                                             // 3
            bmp_hdr->num_planes == 1 &&                                                                                // 4
            bmp_hdr->compression == 0 &&                                                                               // 5
            bmp_hdr->num_colors == 0 &&                                                                                // 6
            bmp_hdr->important_colors == 0 &&                                                                          // 6
            (bmp_hdr->bits_per_pixel == 16 || bmp_hdr->bits_per_pixel == 24) &&                                        // 7
            (((bmp_hdr->bits_per_pixel * bmp_hdr->width_px * bmp_hdr->height_px) / 8) == bmp_hdr->image_size_bytes) && // 8
            ((((bmp_hdr->bits_per_pixel * bmp_hdr->width_px * bmp_hdr->height_px) / 8) + 54) == bmp_hdr->size)         // 8
            )
    {
        return true;
    }
    else
    {
        return false;
    }
}

BMPImage *read_bmp(FILE *fp, char **error)
{
    BMPHeader *header = (BMPHeader *)malloc(sizeof(BMPHeader)); // declaro la vuelta y reservo su espacio en memoria.
    fread(header, sizeof(BMPHeader), 1, fp);
    if (check_bmp_header(header, fp) == 1)
    {
        BMPImage *imagen = (BMPImage*)malloc(sizeof(BMPImage));
        imagen->header=*header;
        imagen->data =(unsigned char*) malloc(header->image_size_bytes);
        if(imagen->data==NULL){
            free_bmp(imagen);
            char *message = "No hay espacio para leer la imagen";
            *error = malloc((strlen(message) + 1) * sizeof(**error));
            strcpy_s(*error,sizeof(error), message);
            return NULL;
        }else{

            fread(imagen->data,header->image_size_bytes,1,fp);
            return imagen;
        }
    }
    else
    {
        if (*error == NULL)
        {
            char *message = "La cabecera no se ha extraido bien";
            *error = malloc((strlen(message) + 1) * sizeof(**error));
            strcpy_s(*error,sizeof(error), message);
        }
        return NULL;
    }
}

bool write_bmp(FILE *fp, BMPImage *image, char **error){
    // Escribir el encabezado BMP en el archivo
    fwrite(&image->header, sizeof(BMPHeader), 1, fp);

    // Copiar los datos de la imagen, cambiando las zonas blancas por rojas
    unsigned char* dataBuffer = (unsigned char*)malloc(image->header.image_size_bytes);
    if (dataBuffer == NULL) {
        *error = "Error al asignar memoria para los datos de la imagen.";
        return false;
    }

    memcpy(dataBuffer, image->data, image->header.image_size_bytes); // Copiar los datos de la imagen

    int bytesPerPixel = image->header.bits_per_pixel / 8;
    int imageSize = image->header.width_px * image->header.height_px * bytesPerPixel;
    for (int i = 0; i < imageSize; i += bytesPerPixel) {

        if (dataBuffer[i] == 204 && dataBuffer[i + 1] == 72 && dataBuffer[i + 2] == 63) {

            dataBuffer[i] = 35;//azul
            dataBuffer[i + 1] = 54;// verde
            dataBuffer[i + 2] = 95;//rojo
        }

    }


    // Escribir los datos de la imagen modificados en el archivo
    fwrite(dataBuffer, 1, image->header.image_size_bytes, fp);

    // Liberar la memoria asignada
    free(dataBuffer);

    return true;
}


BMPImage *crop_bmp(BMPImage *image, int x, int y, int w, int h, char **error);
