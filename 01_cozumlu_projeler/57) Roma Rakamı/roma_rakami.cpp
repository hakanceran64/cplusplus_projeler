/*
 * Author: Hakan Ceran
 * Date: 04.09.2017
 * Content: Girdi olarak girilen ve roma rakamlar� ile yaz�lm�� olan bir say�y� g�n�m�zde kullan�lan 10'luk sistem ve rakamlar� ile yaz�lm�� say�ya �eviren program kodlar�n� yaz�n�z.
 *			Girilen roma rakam�n�n uzunlu�unu maksimum 100 karakter olarak s�n�rland�r�n�z.
 *			- Roma rakam�ndan 10'luk sisteme �evirme i�lemi �u �ekilde yap�l�r: sa�dan sola do�ru Roma rakamlar�n�n de�erleri kendinden �nce gelen Roma rakamlar�n�n en az birinden k���k ise ��kar�l�r, kendinden �nce b�y�k yoksa toplan�r.
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	int arap, uzunluk, carpan;
	char roma[100];
	int deger[100];
	
	cout << "Roma rakamini giriniz: ";
	cin >> roma;
	
	uzunluk=strlen(roma);
	for(int i=0; i<uzunluk; ++i)
		switch(roma[i]){
			case 'I':
				deger[i]=1;
				break;
			case 'V':
					deger[i]=5;
					break;
			case 'X':
					deger[i]=10;
					break;
			case 'L':
					deger[i]=50;
					break;
			case 'C':
					deger[i]=100;
					break;
			case 'D':
					deger[i]=500;
					break;
			case 'M':
					deger[i]=1000;
					break;
			default:
					deger[i]=0;
					break;
		}
	arap=deger[uzunluk-1];
	for(int i=uzunluk-2; i>=0; --i){
		carpan=1;
		for(int j=i+1; j<uzunluk; ++j)
			if(deger[i]<deger[j]){
				carpan=-1;
				break;
			}
		arap+=carpan*deger[i];
	}
	
	cout << arap << endl;

	system("PAUSE");
	return 0;
}

