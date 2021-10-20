/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Girdi olarak bir dizi verilmesi ve ilgili dizinin ka� eleman� oldu�unun kullan�c� taraf�ndan belirlenmesi, b�y�kten k����e s�ralanacak olan dizinin kullan�c�n�n belirledi�i kadar�n�n s�ral� �ekilde ekrana yaz�lmas� istenilmektedir.
 */

#include <iostream>

#define MAX 10000

using namespace std;

/*********
maxlar dizisinin en ba�ta b�t�n elemanlar� 0'd�r. Uygulama �al���rken maxlar dizisi 8, 6, 3 olsun ve s�radaki eleman 7 olsun. �nce maxlar dizisi 1 kayd�r�l�r. Kayd�rmadan sonra dizinin yeni hali 8, 8, 6 olur.
maxlar[j]=sayilar[i]; sat�r� ile de say� maxlar dizisinde olmas� gereken yere yaz�l�r.
Nihai dizi �u �ekildedir: 8, 7, 6
**********/

void kaydir(int indis, int *maxlar, int n){
	for(int k=n-1; k>indis; --k){
		maxlar[k]=maxlar[k-1];
	}
}

int main(){
	
	int n, k, sayilar[MAX], maxlar[MAX]={0};
	
	cout << "k ve n degeri giriniz: ";
	cin >> k >> n;
	
	cout << "Sayilari giriniz: ";

	for(int i=0; i<k; ++i){
		cin >> sayilar[i];
	}
	
	for(int i=0; i<k; ++i){
		for(int j=0; j<k; ++j){
			/* sayilar dizisinin eleman� maxlar dizisinin eleman�nda b�y�kse yer de�i�tir */
			if(sayilar[i]>=maxlar[j]){
				kaydir(j,maxlar,n);
				maxlar[j]=sayilar[i];
				break;
			}
		}
	}
	
	/* Ekrana Yaz */
	for(int i=0; i<n; ++i){
		cout << maxlar[i] << " ";
	}
	
	cout << "\n";

	system("PAUSE");
	return 0;
}

