#include <stdio.h>
#pragma pack(1)
#include <structs.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define DIB_HEADER_SIZE 40

bool check_bmp_header(BMPHeader *bmp_hdr, FILE *fp)
{

    printf("\nSIZE OF %llu", sizeof(bmp_hdr));
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
    BMPImage *imagen = (BMPImage *)malloc(sizeof(BMPImage)); // declaro la vuelta y reservo su espacio en memoria.
    fread(imagen, sizeof(BMPImage), 1, fp);
    if (check_bmp_header(&imagen->header, fp) == 1)
    {
        return imagen;
    }
    else
    {
        if (*error == NULL)
        {

        }
        return NULL;
    }
}

int write_bmp(FILE *fp, BMPImage *image, char **error);

void free_bmp(BMPImage *image)
{
    free(image);
}

BMPImage *crop_bmp(BMPImage *image, int x, int y, int w, int h, char **error);
