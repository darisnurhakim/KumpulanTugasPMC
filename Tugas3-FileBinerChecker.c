#include <stdio.h>

int main (){
    char namaFile[] = "";
    unsigned char cek[12];
    FILE *file;

    printf("Program File Type Checker\n");

    printf("\nMasukkan nama file : ");
    scanf("%s",namaFile);
    file = fopen(namaFile, "rb");

    while (file == NULL){
        printf("File tidak ditemukan!\n");
        printf("\nMasukkan nama file : ");
        scanf("%s",namaFile);
        file = fopen(namaFile, "rb");
    }
    
    fread(cek,sizeof(cek),1,file);
    // File signature PDF = 25 50 44 46
    if ((cek[0] == 0x25) && (cek[1] == 0x50) && (cek[2] == 0x44) && (cek[3] == 0x46)){
        printf("Type file tersebut adalah PDF.");
    }
    /* File signature JPG
    FF D8 FF DB
    FF D8 FF EE
    FF D8 FF E0 00 10 4A 46 49 46 00 01 */
    else if (((cek[0] == 0xFF) && (cek[1] == 0xD8) && (cek[2] == 0xFF) && (cek[3] == 0xDB) || (cek[3] == 0xEE)) ||
            ((cek[0] == 0xFF) && (cek[1] == 0xD8) && (cek[2] == 0xFF) && (cek[3] == 0xE0) && (cek[4] == 0x00) && 
            (cek[5] == 0x10) && (cek[6] == 0x4A) && (cek[7] == 0x46) && (cek[8] == 0x49) && (cek[9] == 0x46) && 
            (cek[10] == 0x00) && (cek[11] == 0x01))){
        printf("Type file tersebut adalah JPG.");
    }
    // File signature PNG = 89 50 4E 47 0D 0A 1A 0A
    else if ((cek[0] == 0x89) && (cek[1] == 0x50) && (cek[2] == 0x4E) && (cek[3] == 0x47) && (cek[4] == 0x0D) && 
            (cek[5] == 0x0A) && (cek[6] == 0x1A) && (cek[7] == 0x0A)){
        printf("Type file tersebut adalah PNG.");
    }
    else{
        printf("Type file tersebut tidak terdefinisi.");
    }
    fclose(file);
}