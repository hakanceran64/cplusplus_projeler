/*
 * Author: Hakan Ceran
 * Date: 06.09.2017
 * Content: Girdi olarak verilen bir arabanýn bilgilerini bir yapý elemanýna kaydeden, bu yapýdaki bilgileri ekrana yazdýran fonksiyonlarý ve yapýyý içeren program kodlarýný yazýnýz.
 *			Yapý ve fonksiyonlar aþaðýda açýklanmýþtýr.
 *			- Araba yapýsý: Bir arabanýn bilgilerini saklayabilen bir yapýdýr. Bu bilgiler arabanýn markasý, modeli, model yýlý, motor hacmi ve yalýt türüdür.
 *			- bilgileri_al(): Parametre olarak bir araba yapýsý iþaretçisi alan ve kullanýcýdan aldýðý bilgileri bu yapýya kaydeden fonksiyondur.
 *			- bilgileri_yaz(): Parametre olarak bir araba yapýsý iþaretçisi alan ve bu yapýdaki bilgileri ekrana yazdýran fonksiyondur.
 */

#include <iostream>

using namespace std;

// Araba yapýsýný buraya yazýnýz.
struct araba{
	char marka[10];
	char model[10];
	int model_yili;
	double motor_hacmi;
	char yakit_turu[10];
};

// bilgileri_al() fonksiyonunu buraya yazýnýz.
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

// bilgileri_yaz() fonksiyonu buraya yazýnýz.
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

