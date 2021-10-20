/*
 * Author: Hakan Ceran
 * Date: 06.09.2017
 * Content: Girdi olarak verilen bir araban�n bilgilerini bir yap� eleman�na kaydeden, bu yap�daki bilgileri ekrana yazd�ran fonksiyonlar� ve yap�y� i�eren program kodlar�n� yaz�n�z.
 *			Yap� ve fonksiyonlar a�a��da a��klanm��t�r.
 *			- Araba yap�s�: Bir araban�n bilgilerini saklayabilen bir yap�d�r. Bu bilgiler araban�n markas�, modeli, model y�l�, motor hacmi ve yal�t t�r�d�r.
 *			- bilgileri_al(): Parametre olarak bir araba yap�s� i�aret�isi alan ve kullan�c�dan ald��� bilgileri bu yap�ya kaydeden fonksiyondur.
 *			- bilgileri_yaz(): Parametre olarak bir araba yap�s� i�aret�isi alan ve bu yap�daki bilgileri ekrana yazd�ran fonksiyondur.
 */

#include <iostream>

using namespace std;

// Araba yap�s�n� buraya yaz�n�z.
struct araba{
	char marka[10];
	char model[10];
	int model_yili;
	double motor_hacmi;
	char yakit_turu[10];
};

// bilgileri_al() fonksiyonunu buraya yaz�n�z.
void bilgileri_al(struct araba *x){
	cout << "Bilgileri giriniz: " << endl;
	
	cout << "Marka: ";
	cin >> x->marka;
	
	cout << "Model: ";
	cin >> x->model;
	
	cout << "Model yili: ";
	cin >> x->model_yili;
	
	cout << "Motor hacmi: ";
	cin >> x->motor_hacmi;
	
	cout << "Yakit turu: ";
	cin >> x->yakit_turu;
}

// bilgileri_yaz() fonksiyonu buraya yaz�n�z.
void bilgileri_yaz(struct araba *x){
	cout << endl << "Aracin bilgileri: " << endl;
	
	cout << "Marka: " << x->marka << endl;
	cout << "Model: " << x->model << endl;
	cout << "Model yili: " << x->model_yili << endl;
	cout << "Motor hacmi: " << x->motor_hacmi << endl;
	cout << "Yakit turu: " << x->yakit_turu << endl << endl;
}

int main(){
	
	struct araba a;
	
	bilgileri_al(&a);
	bilgileri_yaz(&a);

	system("PAUSE");
	return 0;
}

