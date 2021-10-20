/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Eski �a�larda kullan�lan bilgi gizleme y�ntemlerinden biriside kare �ifrelemedir.
 *			Bu �ifreleme y�nteminde �ifrelenecek metin i�erisindeki bo�luklar ��kar�larak soldan sa�a do�ru bir dikd�rtgen i�erisine yerle�tirilir.
 *			Daha sonra bu dikd�rtgen i�erisindeki metinler yukar�dan a�a��ya do�ru yaz�larak ilgili metin �ifrelenmi� olur.
 *			- Bu soruda size girdi olarak ilk sat�rda dikd�rtgen boyutlar� (boy:n, en:m, n, m<=100) verilecektir. ��kt� olarak beklenen ise metnin �ifrelenmi� halidir.
 */

#include <iostream>
#include <cstring>

#define MAX 100

using namespace std;

int main(){
	
	int n, m, son_uzunluk;
	char cumle[MAX][MAX];
	
	cout << "Bir n ve m degeri giriniz: ";
	cin >> n >> m;
	
	cout << "Metni giriniz:";
	for(int i=0; i<n; ++i){
		cin >> cumle[i]; // Her sat�rda yaz�lan m karakterlik metni al
	}
	
	// girilen c�mlenin uzunlu�unu bul
	son_uzunluk=strlen(cumle[n-1]);
	
	// Matrise sat�r sat�r yerle�tirilen c�mleyi sutun sutun oku
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			if(j<n-1 || i<son_uzunluk)
				cout << cumle[j][i];
		}
		cout << " ";
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}

