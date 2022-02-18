#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membantu validasi input
void empty_stdin (void) /* simple helper-function to empty stdin */
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int main(void)
{
    /* KAMUS */
    int A = 0;
    int B = 0;
    int C = 0;
    int pilihan;
    int pilih = 0;

    // Deskripsi Game
    printf("WATER JUG PROBLEM\n");
    printf("Terdapat dua buah ember, ember A berkapasitas 5 liter dan B berkapasitas 3 liter.\n");
    printf("Anda diminta mengambil 4 liter air dari danau menggunakan kedua ember tersebut,");
    printf("tetapi hanya boleh dengan instruksi yang tersedia.\n");
    printf("Anda dinyatakan memenangkan permainan jika isi ember A atau B sama dengan 4 liter.\n");

    /* ALGORITMA */
    while (A != 4){
        // Instruksi Game
        printf(" \n");
        printf("Instruksi yang dapat dilakukan:\n");
        printf("1. Mengisi ember A sampai penuh\n");
        printf("2. Mengisi ember B sampai penuh\n");
        printf("3. Mengosongkan ember A\n");
        printf("4. Mengosongkan ember B\n");
        printf("5. Menuangkan isi ember A ke ember B sampai B penuh\n");
        printf("6. Menuangkan isi ember B ke ember A sampai A penuh\n");
        printf("Pilih nomor instruksi : ");
        pilih = scanf("%d", &pilihan);

        // Validasi Input
        if (pilih == EOF) {   /* user generates manual EOF */
            return 1;
        }
        else if (pilih == 0) {    /* matching failure */
            fputs ("Masukan salah!\n", stderr);
            empty_stdin();
        }
        else if (pilihan < 1 || 6 < pilihan) {  /* validate range */
            fputs ("Masukan salah!\n", stderr);
            empty_stdin();
        }
        else {  /* good input */
            empty_stdin();
        }

        // Memproses Pilihan
        if (pilihan == 1){
            A = 5;
            printf("Air di ember A = %d liter dan air di ember B = %d liter.\n", A, B);
        }
        else if (pilihan == 2){
            B = 3;
            printf("Air di ember A = %d liter dan air di ember B = %d liter.\n", A, B);
        }
        else if (pilihan == 3){
            A = 0;
            printf("Air di ember A = %d liter dan air di ember B = %d liter.\n", A, B);
        }
        else if (pilihan == 4){
            B = 0;
            printf("Air di ember A = %d liter dan air di ember B = %d liter.\n", A, B);
        }
        else if (pilihan == 5){
            B = B + A;
            A = 0;
            while (B > 3){
                B = B - 1;
                A = A + 1;
            }
            printf("Air di ember A = %d liter dan air di ember B = %d liter.\n", A, B);
        }
        else if (pilihan == 6){
            A = A + B;
            B = 0;
            while (A > 5){
                A = A - 1;
                B = B + 1;
            }
            printf("Air di ember A = %d liter dan air di ember B = %d liter.\n", A, B);
        }
        else {
            printf("Air di ember A = %d liter dan air di ember B = %d liter.\n", A, B);
        }
    }

    // nilai akhir
    A = A - 4;
    B = B;
    C = 4;

    printf(" \n");
    printf("Selamat Anda Menang!\n");
    printf("Air di ember A = %d liter, air di ember B = %d liter, dan air di ember C = %d liter.\n", A, B, C);

    return 0;
}