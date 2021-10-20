/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Girdi olarak bir dizi verilmesi ve ilgili dizinin kaç elemaný olduðunun kullanýcý tarafýndan belirlenmesi, büyükten küçüðe sýralanacak olan dizinin kullanýcýnýn belirlediði kadarýnýn sýralý þekilde ekrana yazýlmasý istenilmektedir.
 */

#include <iostream>

#define MAX 10000

using namespace std;

/*********
maxlar dizisinin en baþta bütün elemanlarý 0'dýr. Uygulama çalýþýrken maxlar dizisi 8, 6, 3 olsun ve sýradaki eleman 7 olsun. Önce maxlar dizisi 1 kaydýrýlýr. Kaydýrmadan sonra dizinin yeni hali 8, 8, 6 olur.
maxlar[j]=sayilar[i]; satýrý ile de sayý maxlar dizisinde olmasý gereken yere yazýlýr.
Nihai dizi þu þekildedir: 8, 7, 6
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
			/* sayilar dizisinin elemaný maxlar dizisinin elemanýnda büyükse yer deðiþtir */
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

