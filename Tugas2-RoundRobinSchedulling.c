#include <stdio.h>
#include <stdlib.h>

int main(){
    // input
    int jmlProses,kuantum;

    printf("Round Robin Schedulling\n\n");
    printf("Masukkan jumlah proses yang akan dilakukan: ");
    scanf("%d",&jmlProses);

    int datang[jmlProses-1], eksekusi[jmlProses-1];
    int i = 0;

    while (i < jmlProses){
        printf("Waktu kedatangan proses ke %d: ",i);
        scanf("%d",&datang[i]);
        printf("Waktu eksekusi proses ke %d: ",i);
        scanf("%d",&eksekusi[i]);
        i++;
    }
    printf("Masukkan waktu kuantum: ");
    scanf("%d",&kuantum);

    //proses masuk antrian
    int proses1 = 0, proses2 = 0, n = 1;
    int urutan = 0;
    int proses3 = 0, proses4 = 0, temp, flag = 0, o = 0, q = 2;
    int urutanproses[jmlProses];
    int* waktuproses = (int*)calloc(jmlProses-1, sizeof(int));

    for (int waktu1 = 0; datang[jmlProses-1] >= waktu1; waktu1++){
        if ((datang[proses1] == waktu1) && ((kuantum * n) == waktu1)){
            printf("\n-----------------------------------------------------------------------------------------------------------\n");
            printf("Waktu : %d ms\n", waktu1);
            proses2 = urutanproses[0];
            printf("Proses ke %d diantrikan kembali dan Proses ke %d masuk ke antrian\n",proses2,proses1);
            for (int m = 0; m <= proses1; m++){
                urutanproses[m] = urutanproses[m + 1];
                if (urutanproses[m] == urutanproses[proses1]){
                    urutanproses[m] = proses2;
                }
            }
            for (int l = 0; l < proses1; l++){
                printf("P[%d]\t",urutanproses[l]);
            }
            urutanproses[urutan] = urutan;
            urutan++;
            for (int k = 0; k < proses1 + 1; k++){
                printf("P[%d]\t",urutanproses[k]);
            }
            printf("\n");
            waktuproses[proses3] = waktu1 - (o * kuantum);
            if ((eksekusi[proses3] <= kuantum)){
                waktuproses[proses4] += waktuproses[proses3] - temp;
                temp = waktuproses[proses3];
                waktuproses[proses3] = 0;
                if (waktuproses[proses4] > q * kuantum){
                    waktuproses[proses3] = waktuproses[proses4] - q * kuantum;
                    waktuproses[proses4] = q * kuantum;
                    q++;
                    proses4++;
                    if (proses4 == proses3){
                        proses4 = 0;
                    }
                }
            }
            else if (waktuproses[proses3] >= kuantum){
                waktuproses[proses3] = kuantum;
                o++;
                waktuproses[proses3 + 1] = waktu1 - (o * kuantum);
                proses3++;
            }
            for (int p = 0; p < jmlProses; p++){
                printf("P[%d]: %d ms\t", p, waktuproses[p]);
            }
            n++;
            proses1++;
            proses2++;
        }
        else if (datang[proses1] == waktu1){
            printf("\n-----------------------------------------------------------------------------------------------------------\n");
            printf("Waktu : %d ms\n", waktu1);
            printf("Proses ke %d masuk ke antrian\n",proses1);
            urutanproses[urutan] = urutan;
            urutan++;
            for (int k = 0; k < proses1 + 1; k++){
                printf("P[%d]\t",urutanproses[k]);
            }
            printf("\n");
            waktuproses[proses3] = waktu1 - (o * kuantum);
            if ((eksekusi[proses3] <= kuantum)){
                waktuproses[proses4] += waktuproses[proses3] - temp;
                temp = waktuproses[proses3];
                waktuproses[proses3] = 0;
                if (waktuproses[proses4] > q * kuantum){
                    waktuproses[proses3] = waktuproses[proses4] - q * kuantum;
                    waktuproses[proses4] = q * kuantum;
                    q++;
                    proses4++;
                    if (proses4 == proses3){
                        proses4 = 0;
                    }
                }
            }
            else if (waktuproses[proses3] >= kuantum){
                waktuproses[proses3] = kuantum;
                o++;
                waktuproses[proses3 + 1] = waktu1 - (o * kuantum);
                proses3++;
            }
            for (int p = 0; p < jmlProses; p++){
                printf("P[%d]: %d ms\t", p, waktuproses[p]);
            }
            proses1++;
        }
        else if ((kuantum * n) == waktu1){
            printf("\n-----------------------------------------------------------------------------------------------------------\n");
            printf("Waktu : %d ms\n", waktu1);
            proses2 = urutanproses[0];
            printf("Proses ke %d diantrikan kembali\n",proses2);
            for (int m = 0; m <= proses1; m++){
                urutanproses[m] = urutanproses[m + 1];
                if (urutanproses[m] == urutanproses[proses1]){
                    urutanproses[m] = proses2;
                }
            }
            for (int l = 0; l < proses1; l++){
                printf("P[%d]\t",urutanproses[l]);
            }
            printf("\n");
            waktuproses[proses3] = waktu1 - (o * kuantum);
            if ((eksekusi[proses3] <= kuantum)){
                waktuproses[proses4] += waktuproses[proses3] - temp;
                temp = waktuproses[proses3];
                waktuproses[proses3] = 0;
                if (waktuproses[proses4] > q * kuantum){
                    waktuproses[proses3] = waktuproses[proses4] - q * kuantum;
                    waktuproses[proses4] = q * kuantum;
                    q++;
                    proses4++;
                    if (proses4 == proses3){
                        proses4 = 0;
                    }
                }
            }
            else if (waktuproses[proses3] >= kuantum){
                waktuproses[proses3] = kuantum;
                o++;
                waktuproses[proses3 + 1] = waktu1 - (o * kuantum);
                proses3++;
            }
            for (int p = 0; p < jmlProses; p++){
                printf("P[%d]: %d ms\t", p, waktuproses[p]);
            }
            n++;
            proses2++;
        }
    }
    // proses penyelesaian
	int totaleksekusi = 0, a = 0;
	int b = 0, e = 1;
	int simpanwaktu[jmlProses-1];

	while (a < jmlProses){
		totaleksekusi += eksekusi[a];
		simpanwaktu[a] = waktuproses[a];
		a++;
	}

	for (int waktu2 = datang[jmlProses-1] + 1; totaleksekusi >= waktu2; waktu2++){
		if ((eksekusi[urutanproses[b]] - waktuproses[urutanproses[b]] > kuantum) && (waktuproses[urutanproses[b]] < kuantum)){
			simpanwaktu[urutanproses[b]] += 1;
			if (simpanwaktu[urutanproses[b]] == kuantum){
				urutanproses[jmlProses] = urutanproses[b];
				for (int c = 0; c < jmlProses; c++){
					urutanproses[c] = urutanproses[c+1];
				}
				printf("\n-----------------------------------------------------------------------------------------------------------\n");
				printf("Waktu : %d ms\n", waktu2);
				printf("Proses ke %d diproses, proses ke %d diantrikan kembali\n",urutanproses[b],urutanproses[b-1]);
                for (int k = e-1; k < proses1; k++){
                    printf("P[%d]\t",urutanproses[k]);
                }
                printf("\n");
                for (int p = 0; p < jmlProses; p++){
                    printf("P[%d]: %d ms\t", p, simpanwaktu[p]);
                }
			}
		}
		else if (waktuproses[urutanproses[b]] <= kuantum){
			simpanwaktu[urutanproses[b]] += 1;
			if (simpanwaktu[urutanproses[b]] == eksekusi[urutanproses[b]]){
				printf("\n-----------------------------------------------------------------------------------------------------------\n");
            	printf("Waktu : %d ms\n", waktu2);
				printf("Proses ke %d selesai, proses ke %d diproses\n",urutanproses[b],urutanproses[b+1]);
                for (int k = e; k < proses1; k++){
                    printf("P[%d]\t",urutanproses[k]);
                }
                printf("\n");
                for (int p = 0; p < jmlProses; p++){
                    printf("P[%d]: %d ms\t", p, simpanwaktu[p]);
                }
                e++;
				b++;
			}
		}
		else if ((waktuproses[urutanproses[b]] <= q * kuantum) && (waktuproses[urutanproses[b]] >= kuantum)){
			simpanwaktu[urutanproses[b]] += 1;
			if (simpanwaktu[urutanproses[b]] == eksekusi[urutanproses[b]]){
				printf("\n-----------------------------------------------------------------------------------------------------------\n");
            	printf("Waktu : %d ms\n", waktu2);
				printf("Proses ke %d selesai, proses ke %d diproses\n",urutanproses[b],urutanproses[b+1]);
                for (int k = e; k < proses1; k++){
                    printf("P[%d]\t",urutanproses[k]);
                }
                printf("\n");
                for (int p = 0; p < jmlProses; p++){
                    printf("P[%d]: %d ms\t", p, simpanwaktu[p]);
                }
                e++;
				b++;
			}
		}
	}
	printf("\n-----------------------------------------------------------------------------------------------------------\n");
	printf("Waktu : %d ms\n", totaleksekusi);
	printf("Proses ke %d selesai\n",urutanproses[jmlProses-1]);
    for (int y = 0; y < jmlProses; y++){
        printf("P[%d]: %d ms\t", y, eksekusi[y]);
    }
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\n--Perhitungan Selesai--\n");
}