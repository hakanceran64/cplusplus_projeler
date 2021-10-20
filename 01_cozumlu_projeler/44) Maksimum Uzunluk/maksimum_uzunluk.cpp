/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Bu soruda girdi olarak bitmiþ bir XOX oyununun son hali verilecektir ve X oyuncusunun kaç puan aldýðýn hesaplanmasý istenecektir.
 *			Girdi olarak ilk satýrda oyunun kaça kaçlýk bir tahtada oynandýðý bilgisi bir n sayýsý (n<=100) ile verilecektir.
 *			Bu oyun tahtasýnýn nxn'lik olduðunu belirtmektedir. Daha sonraki n satýrda her satýrda n tane X ve O karýþýk bir karakterler verilecektir.
 *			Buradan elde edilecek olan nxn'lik tablonun son halidir.
 *			Çýktý olarak ise X kullanýcýsýnýn puaný hesaplanacaktýr. X kullanýcýsýn puaný bir satýrdaki, sütundaki, sað çaprazdaki ya da sol çaprazdaki maksimum ard arda gelen X sayýsýdýr.
 */

#include <iostream>

#define MAX 101

using namespace std;

int main(){
	
	char tablo[MAX][MAX];
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	cout << "Matrisi giriniz: \n";
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> tablo[i][j];
		}
	}
	
	int x_puan=0, yeni_x_puan, k, l;
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(tablo[i][j]!='X')
				continue;
			
			// Satýr Kontrolü
			k=j;
			yeni_x_puan=0;
			while(tablo[i][k]=='X' && k<n){
				++k; ++yeni_x_puan;
			}
			if(yeni_x_puan>x_puan)
				x_puan=yeni_x_puan;
			
			// Sütun Kontrolü
			k=i;
			yeni_x_puan=0;
			while(tablo[k][j]=='X' && k<n){
				++k; ++yeni_x_puan;
			}
			if(yeni_x_puan>x_puan)
				x_puan=yeni_x_puan;
			
			// Sað-Alt Kontrolü
			k=i;
			l=j;
			yeni_x_puan=0;
			while(tablo[k][l]!='X' && k<n && l<n){
				++k; ++l; ++yeni_x_puan;
			}
			if(yeni_x_puan>x_puan)
				x_puan=yeni_x_puan;
			
			// Sað-Üst Kontrolü
			k=i;
			l=j;
			yeni_x_puan=0;
			while(tablo[k][l]!='X' && k<n && l<n){
				++k; --l; ++yeni_x_puan;
			}
			if(yeni_x_puan>x_puan)
				x_puan=yeni_x_puan;
		}
	}
	
	cout << x_puan << endl;

	system("PAUSE");
	return 0;
}

