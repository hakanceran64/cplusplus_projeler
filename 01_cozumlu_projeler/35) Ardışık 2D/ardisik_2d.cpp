/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Bu soruda girdi olarak verilen NxN'lik bir say� tablosu i�erisinde en uzun ard���k say� dizisindeki ard���k say� miktar�n� bulmam�z istenmektedir. Burada dikkat etmemiz gereken durumlar ard���k say� dizisi artabilir veya azalabilir ve dizi sa�a-sola, a�a��-yukar�, sa�-alt-�apraza ve sol-alt-�apraza do�ru olabilir.
 */

#include <iostream>

#define MAX 101

using namespace std;

int main(){
	
	int tablo[MAX][MAX]; // �ki boyutlu dizi tan�mlanmas�
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
			// Sat�r Artan
			x=tablo[i][j];
			k=j;
			yeni_max_ardisik=0;

			while(tablo[i][k]==x && k<n){
				++x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Sat�r Azalan
			x=tablo[i][j];
			k=j;
			yeni_max_ardisik=0;
			
			while(tablo[i][k]==x && k<n){
				--x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// S�tun Artan
			x=tablo[i][j];
			k=i;
			yeni_max_ardisik=0;
			
			while(tablo[k][j]==x && k<n){
				++x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// S�tun Azalan
			x=tablo[i][j];
			k=i;
			yeni_max_ardisik=0;
			
			while(tablo[k][j]==x && k<n){
				--x; ++k; ++yeni_max_ardisik;
			}
			
			if(yeni_max_ardisik>max_ardisik){
				max_ardisik=yeni_max_ardisik;
			}
			
			// Sa�-Alt Artan
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
			
			// Sa�-Alt Azalan
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
			
			// Sa�-�st Artan
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

			// Sa�-�st Azalan
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

