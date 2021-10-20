/*
 * Author: Hakan Ceran
 * Date: 19.09.2019
 * Content: Sihirli kare n2 h�creye b�l�nm�� 1'den n2'ye kadar say�lar�n, sat�rlar, s�tunlar ve k��egenler toplam� n(n2+1)/2 olacak �ekilde yerle�tirilmi� bir karedir.
 *			�rnek: A�a��da 3 boyutlu ve 5 boyutlu sihirli kareler verilmi�tir. Bu sihirli karelerden faydalanarak, tek boyutlu sihirli karelerin ��z�lmesi algoritmas�n� olu�turunuz.
 *				4 9 2
 *				3 5 7
 *				8 1 6
 *
 *				11 18 25 02 09
 *				10 12 19 21 03
 *				04 06 13 20 22
 *				23 05 07 14 16
 *				17 24 01 08 15
 *
 *			Algoritmay� bulduktan sonra da bu i�lemleri yapan program kodlar�n� yaz�n�z.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <stdlib.h>

using namespace std; // std::

/************************************************************************************************
 * Tek boyutlu sihirli karelerde algoritma �u �ekildedir.                                       *
 * 1) Herhangi bir satr�n ortas�na 1 yaz.                                                       *
 * 2) Kareyi bir silindir gibi d���nerek, her defas�nda sa� alt �apraza bir sonraki say�y� yaz. *
 * 3) E�er �aprazda bo� yer kalmad�ysa, bir kare yukar� ��k ve 2. ad�ma git.                    *
 * 4) Sihirli kare doluysa bitir.                                                               *
 ************************************************************************************************/

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	int n=0; // Kare boyutu
	
	// E�er boyut tek de�ilse, kullan�c�dan tekrar boyut girilmesi istenir.
	if(n%2==0){
		cout << "Sihirli karenin boyutunu giriniz(n*n): " << endl;
		cin >> n;
	}
	
	cout << endl;
	
	int sihirli_kare[n][n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			sihirli_kare[i][j]=0;
		}
	}
	
	int row=n-1, col=n/2, k=0;
	
	while(k<n*n){
		// Bu yer doldurulduysa, bir kare yukar� ��k
		if(sihirli_kare[row][col]!=0){
			row=abs(row-1)%n;
		} else { // Sa� �a�raz� doldur
			sihirli_kare[row][col]=k+1;
			k++;
			if(sihirli_kare[(row+1)%n][(col+1)%n]==0){
				row=(row+1)%n;
				col=(col+1)%n;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << sihirli_kare[i][j] << "\t";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}


