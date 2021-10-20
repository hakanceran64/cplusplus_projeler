/*
 * Author: Hakan Ceran
 * Date: 28.08.2017
 * Content: Kullanýcýdan -1 girene kadar sayý alan ve daha sonra kullanýcýnýn "hangi sayidan kaç tane var?" sorusuna cevap veren bir program yaziniz.
 */

#include <iostream>

#define MAX 1000

using namespace std;

int main(){
	
	int sayilar[MAX];
	int sorgular[MAX];
	int x=0, indis, sayi, indis2;
	
	/* -1 girilene kadar sayilari kullanýcýdan iste. */
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
	
	/* istenilen sayýlardan kaç tane olduðunu bul */
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

