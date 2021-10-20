/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Hesap Makinasi 2
 */

#include <iostream>

using namespace std;

int main(){
	
	int sayi_1, sayi_2, sonuc;
	bool sonuc_hesapla;
	char islem, cevap='e';
	
	while(cevap=='e'){
		cout << "Islem giriniz: ";
		cin >> sayi_1 >> islem >> sayi_2;
		
		sonuc_hesapla=true;
		
		switch(islem){
			case '+':
				sonuc=sayi_1+sayi_2;
				break;
			case '-':
				sonuc=sayi_1-sayi_2;
				break;
			case '*':
				sonuc=sayi_1*sayi_2;
				break;
			case '/':
				if(sayi_2==0){
					cout << "Bolum sifir olamaz" << endl;
					sonuc_hesapla=false;
					break;
				}
				sonuc=sayi_1/sayi_2;
				break;
			case '%':
				sonuc=sayi_1%sayi_2;
				break;
			default:
				cout << "Yanlis islem girdiniz!" << endl;
				sonuc_hesapla=false;
				break;
		}
		
		/* sonuc_hesapla true ise */
		if(sonuc_hesapla){
			cout << "Sonuc: " << sayi_1 << " " << islem << " " << sayi_2 << " = " << sonuc << endl;
		}
		cout << "Islem yapmaya devam etmek istiyor musunuz?" << endl;
		cin >> cevap;
	}

	system("PAUSE");
	return 0;
}

