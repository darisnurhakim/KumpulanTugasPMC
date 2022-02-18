#include <stdio.h>

struct mahasiswa{
    char  nama[80];
    int   nim;
    float absen;
};

int main(){
    int jumlahMahasiswa;
    printf("Daftar Mahasiswa kelas 01 PMC\n");
    printf("Masukkan Jumlah Mahasiswa: ");
    scanf("%d",&jumlahMahasiswa);

    struct mahasiswa data[jumlahMahasiswa];
    for(int i = 0; i < jumlahMahasiswa; i++){
        printf("Masukkan Nama Mahasiswa: ");
        scanf("%s",&data[i].nama);
        printf("Masukkan NIM Mahasiswa: ");
        scanf("%d",&data[i].nim);
        printf("Masukkan Persentase Kehadiran Mahasiswa: ");
        scanf("%f",&data[i].absen);
    }
    printf("\nDaftar Mahasiswa yang absennya dibawah 80\n");
    for (int n = 0, m = 1; n < jumlahMahasiswa; n ++){
        if (data[n].absen < 80){
            printf("%d. %s\t%d\n", m, data[n].nama, data[n].nim);
            m++;
        }
    }
    return 0;
}