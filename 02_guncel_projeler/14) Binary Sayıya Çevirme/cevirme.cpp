/*
 * Author: Hakan Ceran
 * Date: 17.09.2017
 * Content: Virgüllü bir sayýyý (floating point number) ikili sayýya (binary number) çeviren program kodlarýný yazýnýz.
 */

#include <iostream>
#include <clocale> // Türkçe karakterler için
#include <cmath> // Matematik kütüphanesi
#include <windows.h> // Konsol ekraný renkleri

using namespace std;

// Bu kod 1023 decimal deðerine kadar çalýþmaktadýr. Bunun sebebi binarySayi deðiþkeninin tamsayý(integer) olarak tanýmlanmasýdýr.
// Eðer sayý long olarak tanýmlanýrsa, bu sayý büyüyecektir. Nitekim long 8byte, int ise 4byre'dir.

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9");
	
	float sayi=0.0;
	float virgullu_kisim=0, tam_kisim=0;
	float binary_sayi=0, kalan=0;
	
	cout << "Ýkilik tabana çevireceðin virgüllü sayýyý gir: ";
	cin >> sayi;
	
	// Girilen sayýnn virgüllü ve tam kýsmýný  ayýralým
	tam_kisim=int(sayi);
	virgullu_kisim=sayi-int(sayi);
	
	// Tam kýsmýný binary'ye çevirmek
	for(int i=0; tam_kisim>0; i++){
		kalan=(int)tam_kisim%2;
		binary_sayi+=pow(10,i)*kalan;
		tam_kisim=tam_kisim/2;		
	}
	
	// Virgülden sonraki kýsmý binary'ye çevirmek için
	for(int i=1; virgullu_kisim!='\0'; i++){
		virgullu_kisim*=2;
		tam_kisim=(int)virgullu_kisim;
		virgullu_kisim=virgullu_kisim-int(virgullu_kisim);
		binary_sayi+=pow(10,-i)*tam_kisim;
		cout << tam_kisim;
	}
	
	// Virgüldem sonra 3 basamak göstermesinin sebebi ve koddaki göze çarpan sýkýntýlarý irdeleyiniz.
	cout << binary_sayi << endl;

	system("PAUSE");
	return 0;
}

