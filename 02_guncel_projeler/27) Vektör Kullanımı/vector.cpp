/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: Ön Bilgiler:
 *			- Vektör uzunluðu olmayan bir dizi gibi çalýþýr.
 *			- Vectör'e yeni eleman eklemek için push_back() metodu kullanýlýr.
 *			- Vectör'ün içerisinde o anda kaç eleman olduðunu size() metodu ile öðrenilebilir.
 *			- Vectör'ün her bir elemanýna, bir dizinin her bir elemanýna eriþiyor gibi, [] parantezleri kullanýlarak eriþilir.
 *			- Ayrýntýlý bilgi için: http://www.cplusplus.com/reference/vector/vector/ adresini ziyaret edebilirsiniz.
 *
 *			Bu projede istenen vectör kullanarak, kullanýcýnýn istediði kadar sayý almasýný ve vektöre alýnan sayýlarýn ekrana yazýlmasýdýr.
 *			Kullanýcý istediði kadar sayý girebilir. -1 numarasýnýn girildiði ekrana vektör içerisindeki sayýlarýn yazýlmasýný saðlayýnýz.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <vector>

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	vector<int> v;
	int sayi=0;
	
	cout << "Vektör'e sayý giriniz çýkmak için -1 giriniz: ";
	
	// Sayýlar vektöre bu þekilde atýlýr. Vektör uzunluðu olmayan bir dizi gibi düþünülebilir.
	while(sayi!=-1){
		cin >> sayi;
		
		if(sayi==-1) // -1'i vektöre kaydetmesin.
			break;
		
		v.push_back(sayi);
	}
	
	// Vektörün baþlangýcýndan sonuna kadar tüm elemanlarý yazdýrmayý saðlayan döngü
	for(vector<int>::iterator ite=v.begin(); ite!=v.end(); ite++){
		cout << *ite << "\t";
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}


