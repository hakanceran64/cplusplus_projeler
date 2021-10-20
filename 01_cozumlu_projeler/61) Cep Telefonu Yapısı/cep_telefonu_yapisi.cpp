/*
 * Author: Hakan Ceran
 * Date: 06.09.2017
 * Content: Girdi olarak verilen bir cep telefonunun bilgilerini bir yap�ya kaydeden, bu yap�daki bilgileri ekrana yazd�ran fonksiyonlar� ve yap�y� i�eren program kodlar�n� yaz�n�z.
 *			Yap� ve fonksiyonlar a�a��da a��klanm��t�r.
 *			- cep_telefonu: Bir cep telefonunun bilgilerini modelleyebilen ve saklayabilen bir yap�d�r.
 *			- bilgileri_al(): Parametre olarak bir cep_telefonu yapisi i�aretcisi al�r ve kullan�c�dan ald��� bilgileri vbu yap�ya kaydeder.
 *			- bilgileri_yaz(): Parametre olarak bir cep_telefonu yapisi i�aret�isi al�r ve bu yap�daki bilgileri ekrana yazd�r�r.
 */

#include <iostream>

using namespace std;

// Cep Telefonu yaz�s�n� buraya yaz�n�z.
struct cep_telefonu{
	char marka[10];
	char model[10];
	char isletim_sistemi[10];
	char ekran_boyutu[10];
	int dahili_bellek;
	char kamera_cozunurluk[10];
	char ekran_cozunurluk[10];
};

// bilgileri_al() fonksiyonunu buraya yaz�n�z.
void bilgileri_al(struct cep_telefonu *x){
	cout << "Bilgileri giriniz: " << endl;
	
	cout << "Marka: ";
	cin >> x->marka;
	
	cout << "Model: ";
	cin >> x->model;
	
	cout << "Isletim sistemi: ";
	cin >> x->isletim_sistemi;
	
	cout << "Ekran boyutu: ";
	cin >> x->ekran_boyutu;
	
	cout << "Dahili bellek: ";
	cin >> x->dahili_bellek;
	
	cout << "Kamera cozunurlugu: ";
	cin >> x->kamera_cozunurluk;
	
	cout << "Ekran cozunurlugu: ";
	cin >> x->ekran_cozunurluk;
}

// bilgileri_yaz() fonksiyonunu buraya yaz�n�z.
void bilgileri_yaz(struct cep_telefonu *x){
	cout << endl << "Cep telefonu bilgileri: " << endl;
	
	cout << "Marka: " << x->marka << endl;
	cout << "Model: " << x->model << endl;
	cout << "Isletim sistemi: " << x->isletim_sistemi << endl;
	cout << "Ekran boyutu: " << x->ekran_boyutu << endl;
	cout << "Dahili bellek: " << x->dahili_bellek << endl;
	cout << "Kamera cozunurlugu: " << x->kamera_cozunurluk << endl;
	cout << "Ekran cozunurlugu: " << x->ekran_cozunurluk << endl << endl;
}

int main(){
	struct cep_telefonu a;
	bilgileri_al(&a);
	bilgileri_yaz(&a);

	system("PAUSE");
	return 0;
}

