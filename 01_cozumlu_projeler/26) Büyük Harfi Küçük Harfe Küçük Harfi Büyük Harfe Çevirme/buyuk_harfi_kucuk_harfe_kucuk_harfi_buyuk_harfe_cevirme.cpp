/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Kullanýcýnýn gireceði karakteri büyük ise küçük harfe, küçük ise büyük harfe çeviren programý yazýnýz.
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
	
	/* c deðiþkeninin adresi &c ile fonksiyona gönderilir. Fonksiyon ise gönderilen o adreste bulunan deðerde (*c) deðiþiklik yapar. */
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
