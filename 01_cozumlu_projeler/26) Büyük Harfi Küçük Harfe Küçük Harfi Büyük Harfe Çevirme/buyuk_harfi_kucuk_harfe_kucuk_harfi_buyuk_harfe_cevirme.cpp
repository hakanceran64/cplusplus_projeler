/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Kullan�c�n�n girece�i karakteri b�y�k ise k���k harfe, k���k ise b�y�k harfe �eviren program� yaz�n�z.
 */

#include <iostream>

using namespace std;

void buyukten_kucuk(char *cp);
void kucukten_buyuk(char *cp);
void donustur();

int main(){
	
	donustur();

	system("PAUSE");
	return 0;
}

void buyukten_kucuk(char *cp){
	*cp+=32;
}

void kucukten_buyuk(char *cp){
	*cp-=32;
}

void donustur(){
	char c;
	
	/* c de�i�keninin adresi &c ile fonksiyona g�nderilir. Fonksiyon ise g�nderilen o adreste bulunan de�erde (*c) de�i�iklik yapar. */
	while(true){
		cout << "Girdi: ";
		cin >> c;
		
		if(c=='0')
			return;
		if(c>='A' && c<='Z'){
			buyukten_kucuk(&c);
		} else{
			kucukten_buyuk(&c);
		}
		
		cout << "Sonuc: " << c << endl;
	}
}
