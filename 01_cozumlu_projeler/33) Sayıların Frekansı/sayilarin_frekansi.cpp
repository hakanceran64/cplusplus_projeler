/*
 * Author: Hakan Ceran
 * Date: 28.08.2017
 * Content: Kullan�c�dan -1 girene kadar say� alan ve daha sonra kullan�c�n�n "hangi sayidan ka� tane var?" sorusuna cevap veren bir program yaziniz.
 */

#include <iostream>

#define MAX 1000

using namespace std;

int main(){
	
	int sayilar[MAX];
	int sorgular[MAX];
	int x=0, indis, sayi, indis2;
	
	/* -1 girilene kadar sayilari kullan�c�dan iste. */
	cout << "-1 girilene kadar sayilar" << endl;
	for(indis=0; x!=-1; ++indis){
		cin >> x;
		sayilar[indis]=x;
	}
	
	/* -1 girilene kadar girilen sayilar dizisindeki aranacak sayilari iste */
	cout << "-1 girilene kadar girilen sayilar dizisindeki aranacak sayilar" << endl;
	x=0;
	for(indis=0; x!=-1; ++indis){
		cin >> x;
		sorgular[indis]=x;
	}
	
	/* istenilen say�lardan ka� tane oldu�unu bul */
	for(indis=0; sorgular[indis]!=-1; ++indis){
		sayi=0;
		for(indis2=0; sayilar[indis2]!=-1; ++indis2){
			if(sorgular[indis]==sayilar[indis2])
				++sayi;
		}
		cout << sayi << " ";
	}
	
	system("PAUSE");
	return 0;
}

