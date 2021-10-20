/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Program  ilk baþladýðýnda kullanýcýdan bir tam sayý, bir iþlem ve tekrar bir tam sayý ister. Daha sonra girilen iþlemi yapar ve sonucu ekranda gösterir.
 */

#include <iostream>

using namespace std;

int main(){
	
	int sayi_1, sayi_2, sonuc;
	char islem;
	
	cout << "Islem giriniz: ";
	cin >> sayi_1 >> islem >> sayi_2;
	
	if(islem=='+') // toplama
		sonuc=sayi_1+sayi_2;
	else if(islem=='-') // çýkarma
		sonuc=sayi_1-sayi_2;
	else if(islem=='*') // çarpma
		sonuc=sayi_1*sayi_2;
	else if(islem=='/'){
		if(sayi_2==0){
			cout << "Bolum sýfýr olamaz!" << endl;
			return 0;
		}
		sonuc=sayi_1/sayi_2;
	} else if(islem=='%')
		sonuc=sayi_1%sayi_2;
	else{
		cout << "Yanlis islem yaptiniz!" << endl;
		return 0;
	}
	
	cout << "Sonuc: " << sayi_1 << " " << islem << " " << sayi_2 << " = " << sonuc << endl;
	
	system("PAUSE");
	return 0;
}
