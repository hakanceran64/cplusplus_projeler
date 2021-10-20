/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Bu soruda girdi olarak verilen NxN'lik bir sayý tablosu içerisinde en uzun ardýþýk sayý dizisindeki ardýþýk sayý miktarýný bulmamýz istenmektedir. Burada dikkat etmemiz gereken durumlar ardýþýk sayý dizisi artabilir veya azalabilir ve dizi saða-sola, aþaðý-yukarý, sað-alt-çapraza ve sol-alt-çapraza doðru olabilir.
 */

#include <iostream>

#define MAX 101

using namespace std;

int main(){
	
	int tablo[MAX][MAX]; // Ýki boyutlu dizi tanýmlanmasý
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> tablo[i][j];
		}
	}
	
	int max_ardisik=0, yeni_max_ardisik, k, l, x;
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			// Satýr Artan
			x=tablo[i][j];
			k=j;
			yeni_max_ardisik=0;

			while(tablo[i][k]==x && k<n){
				++x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Satýr Azalan
			x=tablo[i][j];
			k=j;
			yeni_max_ardisik=0;
			
			while(tablo[i][k]==x && k<n){
				--x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Sütun Artan
			x=tablo[i][j];
			k=i;
			yeni_max_ardisik=0;
			
			while(tablo[k][j]==x && k<n){
				++x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Sütun Azalan
			x=tablo[i][j];
			k=i;
			yeni_max_ardisik=0;
			
			while(tablo[k][j]==x && k<n){
				--x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Sað-Alt Artan
			x=tablo[i][j];
			k=i;
			l=j;
			yeni_max_ardisik=0;
			
			while(tablo[k][l]==x && k<n && l<n){
				++x; ++k; ++l; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Sað-Alt Azalan
			x=tablo[i][j];
			k=i;
			l=j;
			yeni_max_ardisik=0;
			
			while(tablo[k][l]==x && k<n && l<n){
				--x; ++k; ++l; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Sað-Üst Artan
			x=tablo[i][j];
			k=i;
			l=j;
			yeni_max_ardisik=0;
			
			while(tablo[k][l]==x && k<n && l>=0){
				++x; ++k; --l; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}

			// Sað-Üst Azalan
			x=tablo[i][j];
			k=i;
			l=j;
			yeni_max_ardisik=0;
			
			while(tablo[k][l]==x && k<n && l>=0){
				--x; ++k; --l; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
		}
	}
	
	cout << "Max ardisik: " << max_ardisik << endl;

	system("PAUSE");
	return 0;
}

