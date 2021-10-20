/*
 * Author: Hakan Ceran
 * Date: 19.09.2019
 * Content: Sihirli kare n2 hücreye bölünmüþ 1'den n2'ye kadar sayýlarýn, satýrlar, sütunlar ve köþegenler toplamý n(n2+1)/2 olacak þekilde yerleþtirilmiþ bir karedir.
 *			Örnek: Aþaðýda 3 boyutlu ve 5 boyutlu sihirli kareler verilmiþtir. Bu sihirli karelerden faydalanarak, tek boyutlu sihirli karelerin çözülmesi algoritmasýný oluþturunuz.
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
 *			Algoritmayý bulduktan sonra da bu iþlemleri yapan program kodlarýný yazýnýz.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <stdlib.h>

using namespace std; // std::

/************************************************************************************************
 * Tek boyutlu sihirli karelerde algoritma þu þekildedir.                                       *
 * 1) Herhangi bir satrýn ortasýna 1 yaz.                                                       *
 * 2) Kareyi bir silindir gibi düþünerek, her defasýnda sað alt çapraza bir sonraki sayýyý yaz. *
 * 3) Eðer çaprazda boþ yer kalmadýysa, bir kare yukarý çýk ve 2. adýma git.                    *
 * 4) Sihirli kare doluysa bitir.                                                               *
 ************************************************************************************************/

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	int n=0; // Kare boyutu
	
	// Eðer boyut tek deðilse, kullanýcýdan tekrar boyut girilmesi istenir.
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
		// Bu yer doldurulduysa, bir kare yukarý çýk
		if(sihirli_kare[row][col]!=0){
			row=abs(row-1)%n;
		} else { // Sað çaðrazý doldur
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


