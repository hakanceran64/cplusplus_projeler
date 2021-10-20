/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Girilen n say� (n<10000) i�erisinde en b�y�k 3 say�y� bulup ekrana yazd�ran program kodlar�n� yaz�n�z. Girdi olarak programa ilk sat�rda ka� say� girilece�i verilecektir. 2. sat�rda ise n tane do�al say� verilecektir. Program ��kt� olarak ekrana gelen, girilen n say�dan en b�y�k 3 tanesini b�y�kten k����e s�ral� bir �ekilde yazd�racakt�r.
 */

#include <iostream>

#define MAX 10000
#define MAX_SAYISI 3

using namespace std;

void kaydir(int indis, int *maxlar){
	for(int k=MAX_SAYISI-1; k>indis; --k){
		maxlar[k]=maxlar[k-1];
	}
}

int main(){
	
	int n, sayilar[MAX],maxlar[MAX_SAYISI]={0};
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	cout << endl << "Sayilari giriniz: ";
	for(int i=0; i<n; ++i){
		cin >> sayilar[i];
	}
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<MAX_SAYISI; ++j){
			if(sayilar[i]>=maxlar[j]){
				kaydir(j,maxlar);
				maxlar[j]=sayilar[i];
				break;
			}
		}
	}
	
	cout << "En buyuk 3 sayi: ";
	for(int i=0; i<MAX_SAYISI; ++i){
		cout << maxlar[i] << " ";
	}
	
	cout << endl << endl;

	system("PAUSE");
	return 0;
}

