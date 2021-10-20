/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Girilen n sayý (n<10000) içerisinde en büyük 3 sayýyý bulup ekrana yazdýran program kodlarýný yazýnýz. Girdi olarak programa ilk satýrda kaç sayý girileceði verilecektir. 2. satýrda ise n tane doðal sayý verilecektir. Program çýktý olarak ekrana gelen, girilen n sayýdan en büyük 3 tanesini büyükten küçüðe sýralý bir þekilde yazdýracaktýr.
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

