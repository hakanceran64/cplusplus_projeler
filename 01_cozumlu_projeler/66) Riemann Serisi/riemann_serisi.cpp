/*
 * Author: Hakan Ceran
 * Date: 07.09.2017
 * Content: 3. Dereceden denklemlerin Riemann toplamýný hesaplayan program kodlarýný yazmanýz istenmektedir.
 *			Girdi olarak programa 3. dereceden bir fonksiyonun katsayýlarý, Riemann toplamýný hesaplamada kullanýlacak aralýk ve bu aralýðýn kaç eþit parçaya bölünmesi gerektiði bilgileri, program ise girilen denklemi ve Riemann toplamýný sonuç olarak kullanýcýya sunacaktýr. Aþaðýda açýklamalarý verilen yapýlarý ve fonksiyonlarý kullanarak kodlarý oluþturunuz.
 *			- Denklem yapýsý: 3. Dereceden bir denklemin katsayýlarýný saklayabilen bir yapýdýr.
 *			- fonksiyon_yaz(): Parametre olarak gelen denklem yapýsý iþaretçisinin fonksiyonunu ekrana yazan fonksiyondur.
 *			- riemann_hesapla(): Parametre olarak gelen denklem yapýsý iþaretçisinin ifade ettiði fonksiyon için yine parametre olarak gelen aralýða ve parça sayýsýna göre Riemann toplamýný bulup çaðrýldýðý noktaya döndüren fonksiyondur.
 *			- fonksiyon_hesapla(): Parametre olarak gelen denklme yapýsý iþaretçisinin ifade ettiði fonksiyon için, yine parametre olarak verilen x deðerine karþýlýk gelen y deðerini hesaplayýp çaðrýldýðý noktaya döndüren fonksiyondur. (Bu fonksiyonu riemann_hesapla fonksiyonu içerisinde kullanmanýz beklenmektedir.)
 *			NOT: Ondalýklý sayýlar için double kullanýnýz(float deðil) ve Riemann toplamýný hesaplarken orta deðeri kullanýnýz.
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
	
	// Aralýk deðerini al.
	cout << "Aralik degerini ve bolum sayisini giriniz: ";
	cin >> ilk_deger >> son_deger >> dikdortgen_sayisi;
	
	// Riemann toplamýný hesapla ve ekrana yaz.
	cout << "Riemann toplami: " << riemann_hesapla(&f,ilk_deger,son_deger,dikdortgen_sayisi) << endl << endl;

	system("PAUSE");
	return 0;
}

