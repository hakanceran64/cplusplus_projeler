/*
 * Author: Hakan Ceran
 * Date: 07.09.2017
 * Content: 3. Dereceden denklemlerin Riemann toplam�n� hesaplayan program kodlar�n� yazman�z istenmektedir.
 *			Girdi olarak programa 3. dereceden bir fonksiyonun katsay�lar�, Riemann toplam�n� hesaplamada kullan�lacak aral�k ve bu aral���n ka� e�it par�aya b�l�nmesi gerekti�i bilgileri, program ise girilen denklemi ve Riemann toplam�n� sonu� olarak kullan�c�ya sunacakt�r. A�a��da a��klamalar� verilen yap�lar� ve fonksiyonlar� kullanarak kodlar� olu�turunuz.
 *			- Denklem yap�s�: 3. Dereceden bir denklemin katsay�lar�n� saklayabilen bir yap�d�r.
 *			- fonksiyon_yaz(): Parametre olarak gelen denklem yap�s� i�aret�isinin fonksiyonunu ekrana yazan fonksiyondur.
 *			- riemann_hesapla(): Parametre olarak gelen denklem yap�s� i�aret�isinin ifade etti�i fonksiyon i�in yine parametre olarak gelen aral��a ve par�a say�s�na g�re Riemann toplam�n� bulup �a�r�ld��� noktaya d�nd�ren fonksiyondur.
 *			- fonksiyon_hesapla(): Parametre olarak gelen denklme yap�s� i�aret�isinin ifade etti�i fonksiyon i�in, yine parametre olarak verilen x de�erine kar��l�k gelen y de�erini hesaplay�p �a�r�ld��� noktaya d�nd�ren fonksiyondur. (Bu fonksiyonu riemann_hesapla fonksiyonu i�erisinde kullanman�z beklenmektedir.)
 *			NOT: Ondal�kl� say�lar i�in double kullan�n�z(float de�il) ve Riemann toplam�n� hesaplarken orta de�eri kullan�n�z.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct denklem{
	double a, b, c, d;
};

void fonksiyon_yaz(struct denklem *d){
	cout << "y=" << d->a << "x^3";
	cout << (d->b < 0 ? "-" : "+") << abs(d->b) << "x^2";
	cout << (d->c < 0 ? "-" : "+") << abs(d->c) << "x";
	cout << (d->d < 0 ? "-" : "+") << abs(d->d) << endl << endl;
}

double fonksiyon_hesapla(struct denklem *d, double x){
	return d->a*x*x*x + d->b*x*x + d->c*x + d->d;
}

double riemann_hesapla(struct denklem *d, double a, double b, int n){
	double x, y, toplam=0, dx=(b-a)/n;
	for(int i=0; i<n; ++i){
		x=a+i*dx+dx/2;
		y=fonksiyon_hesapla(d,x);
		toplam+=y*dx;
	}
	return toplam;
}

int main(){
	
	struct denklem f;
	
	double ilk_deger, son_deger;
	int dikdortgen_sayisi;
	
	cout << fixed << setprecision(1);
	
	// Fonksiyonu al.
	cout << "Denklem katsayilarini giriniz: ";
	cin >> f.a >> f.b >> f.c >> f.d;
	
	// Fonksiyonu yaz.
	cout << endl << "Girilen denklem: " << endl;
	fonksiyon_yaz(&f);
	
	// Aral�k de�erini al.
	cout << "Aralik degerini ve bolum sayisini giriniz: ";
	cin >> ilk_deger >> son_deger >> dikdortgen_sayisi;
	
	// Riemann toplam�n� hesapla ve ekrana yaz.
	cout << "Riemann toplami: " << riemann_hesapla(&f,ilk_deger,son_deger,dikdortgen_sayisi) << endl << endl;

	system("PAUSE");
	return 0;
}

