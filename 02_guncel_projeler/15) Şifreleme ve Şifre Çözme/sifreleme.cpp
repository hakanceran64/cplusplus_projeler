/*
 * Author: Hakan Ceran
 * Date: 17.09.2017
 * Content: Bu projede Cesar þifrelemeye benzer bir biçimde þifreleme yapan bir uygulama yazmanýz istenmektedir.
 *			Fakat her bir harf için farklý sayýda kaydýrma yapýlmalýdýr, bunun için pi sayýsý kullanýlmalýdýr.
 *			Bir baþka ifade ile virgülden sonraki ilk basamak ilk harfi þifrelemek için, ikinci basamak 2. harfi þifrelemek için vb. kullanýlmaktadýr.
 *			Örneðin: 3.141... þeklinde devam eden pi sayýsýna göre abc kelimesini þifreleyelim. Þifrelenmiþ kelime beç olacaktýr.
 */

#include <iostream>
#include <iomanip>
#include <clocale> // Türkçe karakterler için
#include <windows.h> // Konsol ekraný renkleri

using namespace std;

// Bu fonksiyon karakteri sayýya çevirmek için kullanýlmaktadýr.
int donustur(char a){
	switch(a){
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
}
int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9");
	
	// pi sayýsýnýn virgülden sonraki kýsmý
	char pi[135]="14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058";
	char kelime[135]; // Alacaðýmýz karakterler
	int secim;
	
	cout << "Kelimeyi giriniz: ";
	// cin boþluga kadar girdi alýrken cin.getlinesatýrý tamamen alýr.
	cin.getline(kelime,135);
	
	a: // Yanlýþ giriþte buraya geri dönmeni istedik
	cout << "Þifrelemek için 1'e þifre çözmek için 2'ye basýnýz: ";
	cin >> secim;
	
	if(secim==1){
		for(int i=0; kelime[i]!='\0'; i++){
			kelime[i]=kelime[i]+donustur(pi[i]);
		}
		cout << "Þifrelenmiþ veri: ";
	} else if(secim==2){
		for(int i=0; kelime[i]!='\0'; i++){
			kelime[i]=kelime[i]-donustur(pi[i]);
		}
		cout << "Þifresi çözülmüþ veri: ";
	} else {
		cout << "Hatalý giriþ yaptýnýz." << endl;
		goto a;
	}
	
	cout << kelime << endl;
	
	system("PAUSE");
	return 0;
}

