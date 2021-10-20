/*
 * Author: Hakan Ceran
 * Date: 06.09.2017
 * Content: Girdi olarak verilen bir üçgenin 3 köþe koordinatlarý ile üçgenin çevresini ve alanýný hesaplayan program kodlarýný yazýnýz.
 *			Girdi 3 satýrdan oluþacak ve sýrasý ile ilk satýrda 1. köþenin x ve y koordinatlarý, 2. satýrda 2. köþenin x ve y koordinatlarý ve 3. satýrda 3. köþegenin x ve y koordinatlarý bulunacaktýr.
 *			Programda aþaðýda belirtilen yapi ve fonksiyonlarý yazýnýz.
 *			- üçgen yapýsý: Bir üçgenin 3 köþe noktalarýnýn koordinatlarýný saklayabilen bir yapý.
 *			- bilgileri_al(): Bir üçgenin kullanýcý tarafýndan girilen koordinat bilgilerini parametre olarak gelen üçgen yapýsý iþaretçisine kaydeden bir fonksiyon.
 *			- cevre_hesapla(): Parametre olarak gelen bir üçgen yapýsý iþaretçisinin çevresini hesaplayýp geri dönen bir fonksiyon.
 *			- alan_hesapla(): Parametre olarak gelen bir üçgen yapýsý iþaretçisinin alanýný hesaplayýp geri dönen bir fonksiyon.
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

