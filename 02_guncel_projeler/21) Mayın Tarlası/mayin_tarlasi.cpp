/*
 * Author: Hakan Ceran
 * Date: 21.09.2017
 * Content: Bu projede, basit mayýn tarlasý oyunu yazmanýz istenmektedir. Oyunun kriterleri aþaðýda listelendiði gibidir:
 *			1. Kullanýcýnýn istediði boyutta bir rastgele 0 ve 1'lerden oluþan matris üretilsin. 0'lar toprak 1'ler ise mayýn olsun.
 *			2. Kullanýcý matrisin index'ini girince o index toprak ise açýlsýni mayýn ise patlasýn.
 *			3. Mayýn tarlasý her defasýnda ekrana yazýlsýn.
 *			4. Açýlmamýþ index 5 olarak görünsün. Açýlan yer toprak ise 0, mayýn ise 1 görünsün.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std; // std::

// 0'lar toprak 1'ler mayýn olsun
int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	int satir=0, sutun=0, toprak=0;
	
	cout << "Mayýn tarlasýnýn boyutunu giriniz: ";
	cin >> satir >> sutun;
	
	// t dizisi tarlanýn oyunu oynayan kiþiye gösterilecek hali. Oyuncu nerede mayýn olduðunu bilmeyecektir.
	int t[satir][sutun];
	int tarla[satir][sutun];
	
	// Rastgele olarak tarlayý oluþtur.
	srand(time(NULL));
	
	for(int i=0; i<satir; i++){
		for(int j=0; j<sutun; j++){
			// %50 ihtimalle mayýn vardýr. Ýsterseniz bu oraný deðiþtirebilirsiniz.
			tarla[i][j]=rand()%2;
			
			// Bütün mayýn ve topraðýn üzerini kapatalým
			t[i][j]=5;
			
			// Bulunmasý gereken toprak sayýsý
			if(tarla[i][j]==0){
				toprak++;
			}
		}
	}
	
	// Test amaçlý mayýnlarý yazdýralým
	cout << "Kontrol amaçlý mayýn tarlasý gösteriliyor" << endl;
	for(int i=0; i<satir; i++){
		for(int j=0; j<sutun; j++){
			cout << tarla[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	// Kullanýcý oyun oynamaya baþlasýn
	int i=0, j=0;
	
	while(true){
		system("cls");
		
		// Oyun bu matris üzerinden oynanacaktýr.
		for(i=0; i<satir; i++){
			for(j=0; j<sutun; j++){
				cout << t[i][j] << " ";
			}
			cout << endl;
		}
		
		cout << "Açmak istediðiniz indexleri giriniz: ";
		cin >> i >> j;
		
		if(i>=0 && j>=0 && i<satir && j<sutun){
			if(t[i][j]==5 && tarla[i][j]==0){
				// Kullanýcý 1. satýr 1. sutunu açmak isterse toprak[0][0] açýlmalý
				t[i][j]=tarla[i][j];
				toprak--;
				if(toprak==0){
					cout << "Bütün mayýnlarý buldunuz." << endl;
					
					system("PAUSE");
					return 0;
				}
			} else if(t[i][j]==5 && tarla[i][j]==1){
				cout << "Mayýna bastýnýz!" << endl;
				
				system("PAUSE");
				return 0;
			} else{
				cout << "Daha önce açtýðýnýz bir yeri tekrar açmaya çalýþtýnýz!" << endl;
			}
		} else{
			cout << "Geçersiz bir index girdiniz." << endl;
		}
	}

	system("PAUSE");
	return 0;
}


