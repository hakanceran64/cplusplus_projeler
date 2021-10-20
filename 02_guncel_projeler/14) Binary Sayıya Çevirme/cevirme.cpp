/*
 * Author: Hakan Ceran
 * Date: 17.09.2017
 * Content: Virg�ll� bir say�y� (floating point number) ikili say�ya (binary number) �eviren program kodlar�n� yaz�n�z.
 */

#include <iostream>
#include <clocale> // T�rk�e karakterler i�in
#include <cmath> // Matematik k�t�phanesi
#include <windows.h> // Konsol ekran� renkleri

using namespace std;

// Bu kod 1023 decimal de�erine kadar �al��maktad�r. Bunun sebebi binarySayi de�i�keninin tamsay�(integer) olarak tan�mlanmas�d�r.
// E�er say� long olarak tan�mlan�rsa, bu say� b�y�yecektir. Nitekim long 8byte, int ise 4byre'dir.

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9");
	
	float sayi=0.0;
	float virgullu_kisim=0, tam_kisim=0;
	float binary_sayi=0, kalan=0;
	
	cout << "�kilik tabana �evirece�in virg�ll� say�y� gir: ";
	cin >> sayi;
	
	// Girilen say�nn virg�ll� ve tam k�sm�n�  ay�ral�m
	tam_kisim=int(sayi);
	virgullu_kisim=sayi-int(sayi);
	
	// Tam k�sm�n� binary'ye �evirmek
	for(int i=0; tam_kisim>0; i++){
		kalan=(int)tam_kisim%2;
		binary_sayi+=pow(10,i)*kalan;
		tam_kisim=tam_kisim/2;		
	}
	
	// Virg�lden sonraki k�sm� binary'ye �evirmek i�in
	for(int i=1; virgullu_kisim!='\0'; i++){
		virgullu_kisim*=2;
		tam_kisim=(int)virgullu_kisim;
		virgullu_kisim=virgullu_kisim-int(virgullu_kisim);
		binary_sayi+=pow(10,-i)*tam_kisim;
		cout << tam_kisim;
	}
	
	// Virg�ldem sonra 3 basamak g�stermesinin sebebi ve koddaki g�ze �arpan s�k�nt�lar� irdeleyiniz.
	cout << binary_sayi << endl;

	system("PAUSE");
	return 0;
}

