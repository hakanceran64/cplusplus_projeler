/*
 * Author: Hakan Ceran
 * Date: 07.09.2017
 * Content: Girdi olarak verilen bir bilgisayar�n bilgilerini bir yap�ya kaydeden ve bu yap�daki bilgileri ekrana yazd�ran fonksiyonlar ile yap�y� i�eren program kodlar�n� yaz�n�z.
 *			Yap� ve fonksiyonlar a�a��da a��klanm��t�r.
 *			- bilgisayar yap�s�: Bir bilgisayar bilgilerini saklayabilen bir yap�d�r. Bu bilgiler bilgisayar�n markas�, modeli, i�lemci h�z�, ram kapasitesi ve hdd kapasitesidir.
 *			- bilgileri_al(): Parametre olarak bir bilgisayar yap�s� i�aret�isi alan ve kullan�c�dan ald��� bilgileri bu yap�ya keydeden fonksiyondur.
 *			- bilgileri_yaz(): Parametre olarak bir bilgisayar yap�s� i�aret�isi alan ve bu yap�daki bilgileri ekrana yazd�ran fonksiyondur.
 */

#include <iostream>

using namespace std;

// Bilgisayar yap�s�n� buraya yaz�n�z.
struct bilgisayar{
	char marka[10];
	char model[10];
	char islemci_model[10];
	double islemci_hizi;
	int ram_kapasite;
	int hdd_kapasite;
};

// bilgileri_al() fonksiyonunu buraya yaz�n�z.
void bilgileri_al(struct bilgisayar *x){
	cout << "Bilgileri giriniz: " << endl;
	
	cout << "Marka: ";
	cin >> x->marka;
	
	cout << "Model: ";
	cin >> x->model;
	
	cout << "Islemci model: ";
	cin >> x->islemci_model;
	
	cout << "Islemci hizi: ";
	cin >> x->islemci_hizi;
	
	cout << "Ram kapasite: ";
	cin >> x->ram_kapasite;
	
	cout << "HDD kapasite: ";
	cin >> x->hdd_kapasite;
}

// bilgileri _yaz() fonksiyonunu buraya yaz�n�z.
void bilgileri_yaz(struct bilgisayar *x){
	cout << endl << "Bilgisayarin bilgileri: " << endl;
	
	cout << "Marka: " << x->marka << endl;
	cout << "Model: " << x->model << endl;
	cout << "Islemci model: " << x->islemci_model << endl;
	cout << "Islemci hizi: " << x->islemci_hizi << endl;
	cout << "Ram kapasite: " << x->ram_kapasite << endl;
	cout << "HDD kapasite: " << x->hdd_kapasite << endl << endl;
}

int main(){
	
	struct bilgisayar a;

	bilgileri_al(&a);
	bilgileri_yaz(&a);

	system("PAUSE");
	return 0;
}

