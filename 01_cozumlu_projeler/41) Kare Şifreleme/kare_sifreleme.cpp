/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Eski çaðlarda kullanýlan bilgi gizleme yöntemlerinden biriside kare þifrelemedir.
 *			Bu þifreleme yönteminde þifrelenecek metin içerisindeki boþluklar çýkarýlarak soldan saða doðru bir dikdörtgen içerisine yerleþtirilir.
 *			Daha sonra bu dikdörtgen içerisindeki metinler yukarýdan aþaðýya doðru yazýlarak ilgili metin þifrelenmiþ olur.
 *			- Bu soruda size girdi olarak ilk satýrda dikdörtgen boyutlarý (boy:n, en:m, n, m<=100) verilecektir. Çýktý olarak beklenen ise metnin þifrelenmiþ halidir.
 */

#include <iostream>
#include <cstring>

#define MAX 100

using namespace std;

int main(){
	
	int n, m, son_uzunluk;
	char cumle[MAX][MAX];
	
	cout << "Bir n ve m degeri giriniz: ";
	cin >> n >> m;
	
	cout << "Metni giriniz:";
	for(int i=0; i<n; ++i){
		cin >> cumle[i]; // Her satýrda yazýlan m karakterlik metni al
	}
	
	// girilen cümlenin uzunluðunu bul
	son_uzunluk=strlen(cumle[n-1]);
	
	// Matrise satýr satýr yerleþtirilen cümleyi sutun sutun oku
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			if(j<n-1 || i<son_uzunluk)
				cout << cumle[j][i];
		}
		cout << " ";
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}

