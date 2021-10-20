/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Bu soruda girdi olarak bitmi� bir XOX oyununun son hali verilecektir ve X oyuncusunun ka� puan ald���n hesaplanmas� istenecektir.
 *			Girdi olarak ilk sat�rda oyunun ka�a ka�l�k bir tahtada oynand��� bilgisi bir n say�s� (n<=100) ile verilecektir.
 *			Bu oyun tahtas�n�n nxn'lik oldu�unu belirtmektedir. Daha sonraki n sat�rda her sat�rda n tane X ve O kar���k bir karakterler verilecektir.
 *			Buradan elde edilecek olan nxn'lik tablonun son halidir.
 *			��kt� olarak ise X kullan�c�s�n�n puan� hesaplanacakt�r. X kullan�c�s�n puan� bir sat�rdaki, s�tundaki, sa� �aprazdaki ya da sol �aprazdaki maksimum ard arda gelen X say�s�d�r.
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
			
			// Sat�r Kontrol�
			k=j;
			yeni_x_puan=0;
			while(tablo[i][k]=='X' && k<n){
				++k; ++yeni_x_puan;
			}
			if(yeni_x_puan>x_puan)
				x_puan=yeni_x_puan;
			
			// S�tun Kontrol�
			k=i;
			yeni_x_puan=0;
			while(tablo[k][j]=='X' && k<n){
				++k; ++yeni_x_puan;
			}
			if(yeni_x_puan>x_puan)
				x_puan=yeni_x_puan;
			
			// Sa�-Alt Kontrol�
			k=i;
			l=j;
			yeni_x_puan=0;
			while(tablo[k][l]!='X' && k<n && l<n){
				++k; ++l; ++yeni_x_puan;
			}
			if(yeni_x_puan>x_puan)
				x_puan=yeni_x_puan;
			
			// Sa�-�st Kontrol�
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

