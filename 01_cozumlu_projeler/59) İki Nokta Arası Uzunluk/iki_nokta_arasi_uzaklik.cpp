/*
 * Author: Hakan Ceran
 * Date: 04.09.2017
 * Content: �ki nokta aras� uzakl��� hesaplayan program kodlar�n� yaz�n�z. Bu soruda noktalar�n tan�mlanmas�/modellenmesi a�amas�nda struct yap�s� kullan�lmas� istenilmektedir.
 *			Struct yap�s� ve fonksiyonlar ��yle olmal�d�r:
 *			- struct nokta: bir noktan�n koordinat sistemindeki bilgilerini (x,y) saklayan yap�d�r.
 *			- bilgileri_al(): kullan�c�dan bilgileri alan fonksiyondur.
 *			- uzaklik_hesapla(): noktalar aras� uzakl�k hesaplay�p, double tipinde d�nd�ren fonksiyondur.
 *			- iki nokta aras� uzakl�k sqrt(pow(x_1-x_2,2)+pow(y_1-y_2,2)) form�l� ile hesaplan�r.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct nokta{
	int x,y;
};

void bilgileri_al(struct nokta *n){
	/* n yap�s� i�aret�i de�i�ken oldu�undan �ye de�i�kenlerine this operat�r� (->) ile ula��l�yor */
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

