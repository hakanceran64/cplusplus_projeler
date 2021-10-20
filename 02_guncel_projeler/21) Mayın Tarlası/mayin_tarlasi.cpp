/*
 * Author: Hakan Ceran
 * Date: 21.09.2017
 * Content: Bu projede, basit may�n tarlas� oyunu yazman�z istenmektedir. Oyunun kriterleri a�a��da listelendi�i gibidir:
 *			1. Kullan�c�n�n istedi�i boyutta bir rastgele 0 ve 1'lerden olu�an matris �retilsin. 0'lar toprak 1'ler ise may�n olsun.
 *			2. Kullan�c� matrisin index'ini girince o index toprak ise a��ls�ni may�n ise patlas�n.
 *			3. May�n tarlas� her defas�nda ekrana yaz�ls�n.
 *			4. A��lmam�� index 5 olarak g�r�ns�n. A��lan yer toprak ise 0, may�n ise 1 g�r�ns�n.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std; // std::

// 0'lar toprak 1'ler may�n olsun
int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	int satir=0, sutun=0, toprak=0;
	
	cout << "May�n tarlas�n�n boyutunu giriniz: ";
	cin >> satir >> sutun;
	
	// t dizisi tarlan�n oyunu oynayan ki�iye g�sterilecek hali. Oyuncu nerede may�n oldu�unu bilmeyecektir.
	int t[satir][sutun];
	int tarla[satir][sutun];
	
	// Rastgele olarak tarlay� olu�tur.
	srand(time(NULL));
	
	for(int i=0; i<satir; i++){
		for(int j=0; j<sutun; j++){
			// %50 ihtimalle may�n vard�r. �sterseniz bu oran� de�i�tirebilirsiniz.
			tarla[i][j]=rand()%2;
			
			// B�t�n may�n ve topra��n �zerini kapatal�m
			t[i][j]=5;
			
			// Bulunmas� gereken toprak say�s�
			if(tarla[i][j]==0){
				toprak++;
			}
		}
	}
	
	// Test ama�l� may�nlar� yazd�ral�m
	cout << "Kontrol ama�l� may�n tarlas� g�steriliyor" << endl;
	for(int i=0; i<satir; i++){
		for(int j=0; j<sutun; j++){
			cout << tarla[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	// Kullan�c� oyun oynamaya ba�las�n
	int i=0, j=0;
	
	while(true){
		system("cls");
		
		// Oyun bu matris �zerinden oynanacakt�r.
		for(i=0; i<satir; i++){
			for(j=0; j<sutun; j++){
				cout << t[i][j] << " ";
			}
			cout << endl;
		}
		
		cout << "A�mak istedi�iniz indexleri giriniz: ";
		cin >> i >> j;
		
		if(i>=0 && j>=0 && i<satir && j<sutun){
			if(t[i][j]==5 && tarla[i][j]==0){
				// Kullan�c� 1. sat�r 1. sutunu a�mak isterse toprak[0][0] a��lmal�
				t[i][j]=tarla[i][j];
				toprak--;
				if(toprak==0){
					cout << "B�t�n may�nlar� buldunuz." << endl;
					
					system("PAUSE");
					return 0;
				}
			} else if(t[i][j]==5 && tarla[i][j]==1){
				cout << "May�na bast�n�z!" << endl;
				
				system("PAUSE");
				return 0;
			} else{
				cout << "Daha �nce a�t���n�z bir yeri tekrar a�maya �al��t�n�z!" << endl;
			}
		} else{
			cout << "Ge�ersiz bir index girdiniz." << endl;
		}
	}

	system("PAUSE");
	return 0;
}


