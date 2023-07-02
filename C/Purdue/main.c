#include <stdio.h>
#pragma pack(1)
#include <structs.h>
#include <bmp.c>
#include <stdbool.h>

int main()
{

    char *error = NULL;
    FILE *fichero, *imagenCortada,*ImagenColor;
    fopen_s(&fichero, "CuadradosP.bmp", "rb");

    if (fichero == NULL)
    {
        printf("\nNo se ha podido abrir el archivo");
    }
    else
    {
        BMPImage *imagen = read_bmp(fichero, &error);
        if (imagen == NULL)
        {
            printf("\nError: %s", error);
            free(error);
        }
        else
        {
            printf("\nImagen leida correctamente");
            printf("\ntype %x", imagen->header.type);                         // Magic identifier: 0x4d42
            printf("\nsize %i", imagen->header.size);                         // File size in bytes
            printf("\nreserved1 %i", imagen->header.reserved1);               // Not used
            printf("\nreserved2 %i", imagen->header.reserved2);               // Not used
            printf("\noffset %i", imagen->header.offset);                     // Offset to image data in bytes from beginning of file (54 bytes)
            printf("\ndib_header_size %i", imagen->header.dib_header_size);   // DIB Header size in bytes (40 bytes)
            printf("\nwidth_px %i", imagen->header.width_px);                 // Width of the image
            printf("\nheight_px %i", imagen->header.height_px);               // Height of image
            printf("\nnum_planes %i", imagen->header.num_planes);             // Number of color planes
            printf("\nbits_per_pixel %i", imagen->header.bits_per_pixel);     // Bits per pixel
            printf("\ncompression %i", imagen->header.compression);           // Compression type
            printf("\nimage_size_bytes %i", imagen->header.image_size_bytes); // Image size in bytes
            printf("\nx_resolution_ppm %i", imagen->header.x_resolution_ppm); // Pixels per meter
            printf("\ny_resolution_ppm %i", imagen->header.y_resolution_ppm); // Pixels per meter
            printf("\nnum_colors %i", imagen->header.num_colors);             // Number of colors
            printf("\nimportant_colors %i", imagen->header.important_colors); // Important colors
            puts("\n");
            fopen_s(&imagenCortada, "Imagen_salida_Cortada.bmp", "wb");
            fopen_s(&ImagenColor, "Imagen_salida_Color.bmp", "wb");
            if (imagenCortada == NULL)
            {
                printf("\nNo se ha podido abrir el archivo de escritura de corte");
            }
            else
            {
                /*Quiero usar la funcion crop_bmp partiendo a la mitad la imagen de "imagen"*/
                BMPImage *imagen2 = crop_bmp(imagen, 0, imagen->header.height_px / 2, imagen->header.width_px, imagen->header.height_px / 2, &error);
                bool exito = write_bmp(imagenCortada, imagen2, &error);
                if (exito == false)
                {
                    printf("\nError: %s", error);
                }
                else
                {
                    printf("Corte Escrito correctamente");
                }
            }
            if (ImagenColor == NULL)
            {
                printf("\nNo se ha podido abrir el archivo de escritura a color");
            }
            else
            {
                /*Quiero usar la funcion crop_bmp partiendo a la mitad la imagen de "imagen"*/
                bool exito = changeColor(ImagenColor, imagen, &error);
                if (exito == false)
                {
                    printf("\nError: %s", error);
                }
                else
                {
                    printf("\nColor Escrito correctamente");
                }
            }
            fclose(imagenCortada);
            fclose(fichero);
            free(imagen);
        }
    }

    return 0;
}
