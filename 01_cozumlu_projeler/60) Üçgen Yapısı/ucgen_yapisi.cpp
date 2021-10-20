/*
 * Author: Hakan Ceran
 * Date: 06.09.2017
 * Content: Girdi olarak verilen bir ��genin 3 k��e koordinatlar� ile ��genin �evresini ve alan�n� hesaplayan program kodlar�n� yaz�n�z.
 *			Girdi 3 sat�rdan olu�acak ve s�ras� ile ilk sat�rda 1. k��enin x ve y koordinatlar�, 2. sat�rda 2. k��enin x ve y koordinatlar� ve 3. sat�rda 3. k��egenin x ve y koordinatlar� bulunacakt�r.
 *			Programda a�a��da belirtilen yapi ve fonksiyonlar� yaz�n�z.
 *			- ��gen yap�s�: Bir ��genin 3 k��e noktalar�n�n koordinatlar�n� saklayabilen bir yap�.
 *			- bilgileri_al(): Bir ��genin kullan�c� taraf�ndan girilen koordinat bilgilerini parametre olarak gelen ��gen yap�s� i�aret�isine kaydeden bir fonksiyon.
 *			- cevre_hesapla(): Parametre olarak gelen bir ��gen yap�s� i�aret�isinin �evresini hesaplay�p geri d�nen bir fonksiyon.
 *			- alan_hesapla(): Parametre olarak gelen bir ��gen yap�s� i�aret�isinin alan�n� hesaplay�p geri d�nen bir fonksiyon.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct ucgen{
	int x1, y1;
	int x2, y2;
	int x3, y3;
};

void bilgileri_al(struct ucgen *x){
	cout << "Bilgileri giriniz: (x1,x2,x3,y1,y2,y3) ";
	cin >> x->x1 >> x->y1 >> x->x2 >> x->y2 >> x->x3 >> x->y3;
}

double cevre_hesapla(struct ucgen *x){
	double kenar1=sqrt(pow(abs(x->x1 - x->x2),2)+pow(abs(x->y1 - x->y2),2));
	double kenar2=sqrt(pow(abs(x->x1 - x->x3),2)+pow(abs(x->y1 - x->y3),2));
	double kenar3=sqrt(pow(abs(x->x2 - x->x3),2)+pow(abs(x->y2 - x->y3),2));
	
	return kenar1 + kenar2 + kenar3;
}

double alan_hesapla(struct ucgen *x){
	double kenar1=sqrt(pow(abs(x->x1 - x->x2),2)+pow(abs(x->y1 - x->y2),2));
	double kenar2=sqrt(pow(abs(x->x1 - x->x3),2)+pow(abs(x->y1 - x->y3),2));
	double kenar3=sqrt(pow(abs(x->x2 - x->x3),2)+pow(abs(x->y2 - x->y3),2));
	double u=(kenar1+kenar2+kenar3)/2;
	
	return sqrt(u*(u-kenar1)*(u-kenar2)*(u-kenar3));
}

int main(){
	
	struct ucgen u;
	
	bilgileri_al(&u);
	
	cout << fixed << setprecision(2);
	cout << "Cevresi: " << cevre_hesapla(&u) << endl;
	cout << "Alani: " << alan_hesapla(&u) << endl;

	system("PAUSE");
	return 0;
}

