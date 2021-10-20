/*
 * Author: Hakan Ceran
 * Date: 04.09.2017
 * Content: Ýki nokta arasý uzaklýðý hesaplayan program kodlarýný yazýnýz. Bu soruda noktalarýn tanýmlanmasý/modellenmesi aþamasýnda struct yapýsý kullanýlmasý istenilmektedir.
 *			Struct yapýsý ve fonksiyonlar þöyle olmalýdýr:
 *			- struct nokta: bir noktanýn koordinat sistemindeki bilgilerini (x,y) saklayan yapýdýr.
 *			- bilgileri_al(): kullanýcýdan bilgileri alan fonksiyondur.
 *			- uzaklik_hesapla(): noktalar arasý uzaklýk hesaplayýp, double tipinde döndüren fonksiyondur.
 *			- iki nokta arasý uzaklýk sqrt(pow(x_1-x_2,2)+pow(y_1-y_2,2)) formülü ile hesaplanýr.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct nokta{
	int x,y;
};

void bilgileri_al(struct nokta *n){
	/* n yapýsý iþaretçi deðiþken olduðundan üye deðiþkenlerine this operatörü (->) ile ulaþýlýyor */
	cin >> n->x >> n->y;
}

double uzaklik_hesapla(struct nokta *n1, struct nokta *n2){
	int x_fark=abs(n1->x - n2->x);
	int y_fark=abs(n1->y - n2->y);
	
	return sqrt(pow(x_fark,2)+pow(y_fark,2));
}

int main(){
	
	struct nokta nokta1, nokta2;
	
	cout << "1. nokta koordinatlarini giriniz: ";
	bilgileri_al(&nokta1);
	
	cout << "2. nokta koordinatlari giriniz: ";
	bilgileri_al(&nokta2);
	
	cout << fixed << setprecision(2);
	cout << "Noktalar arasi uzaklik: " << uzaklik_hesapla(&nokta1,&nokta2) << endl << endl;

	system("PAUSE");
	return 0;
}

