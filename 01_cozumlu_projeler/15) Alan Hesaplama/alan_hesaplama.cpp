/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Fonksiyonlar ile alan hesabý
 */

#include <stdio.h>
#include <conio.h>

int kare_alan(){ // Kare
	int kenar, alan;

	printf("Bir kenar uzunlugunu giriniz: "); scanf("%d",&kenar);
	
	alan = kenar * kenar;
	
	printf("Girdiginiz degerlere gore karenin alani: %d'dir.",alan);
	
	return 0;
}
int ucgen_alan(){ // Üçgen
	int yukseklik, taban, alan;

	printf("Yuksekligi giriniz: "); scanf("%d",&yukseklik);
	printf("Taban uzunlugunu giriniz: "); scanf("%d",&taban);
	
	alan = yukseklik * taban / 2;
	
	printf("Girdiginiz degerlere gore ucgenin alani: %d'dir.",alan);
	
	return 0;
}
int daire_alan(){ // Daire
	int yaricap;
	float alan, pi=3.14;

	printf("Yaricap degerini giriniz: "); scanf("%d",&yaricap);
	
	alan = yaricap * pi;
	
	printf("Girdiginiz degerlere gore dairenin alani: %.2f'dir.",alan);
	
	return 0;
}
int dikdortgen_alan(){ // Dikdörtgen
	int en, boy, alan;

	printf("Dikdortgenin enini giriniz: "); scanf("%d",&en);
	printf("Dikdortgenin boyunu giriniz: "); scanf("%d",&boy);
	
	alan = en * boy;
	
	printf("Girdiginiz degerlere gore dikdortgenin alani: %d'dir.",alan);
	
	return 0;
}

int main(){ // Ana Fonksiyon
	int secim;
	int alan;

	printf("1) Kare\n2) Dikdortgen\n3) Ucgen\n4) Daire\n\n");
	
	printf("Alan hesaplamak icin bir secim yapiniz: ");
	scanf("%d",&secim);
	
	switch(secim){
		case 1:
			kare_alan();
			break;
		case 2:
			dikdortgen_alan();
			break;
		case 3:
			ucgen_alan();
			break;
		case 4:
			daire_alan();
			break;
		default:
			printf("Yanlis secim yaptiniz!");
	}
	
	getch();
	return 0;
}
