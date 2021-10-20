/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Program  ilk ba�lad���nda kullan�c�dan bir tam say�, bir i�lem ve tekrar bir tam say� ister. Daha sonra girilen i�lemi yapar ve sonucu ekranda g�sterir.
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
	else if(islem=='-') // ��karma
		sonuc=sayi_1-sayi_2;
	else if(islem=='*') // �arpma
		sonuc=sayi_1*sayi_2;
	else if(islem=='/'){
		if(sayi_2==0){
			cout << "Bolum s�f�r olamaz!" << endl;
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
