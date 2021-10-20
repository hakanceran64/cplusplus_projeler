/*
 * Author: Hakan Ceran
 * Date: 02.09.2017
 * Content: Girilen n kelimeyi (n<=10000) alfabetik olarak sýralayan bir program yazýnýz. Her kelimenin uzunluðu en fazla 100 karakter olmalýdýr.
 *			Girdi olarak ilk satýrda n sayýsý girilecek, ikinci satýrda ise aralarýnda boþluk olan n tane kelime girilecektir.
 *			Çýktý olarak ise kelimeler alfabetik olarak sýralý þekilde her bir satýra bir kelime yazdýrýlacaktýr.
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	char kelimeler[1000][100];
	char tmp[100];
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	for(int i=0; i<n; ++i)
		cin >> kelimeler[i];
	for(int i=n-1; i>0; --i)
		for(int j=0; j<i; ++j)
			if(strcmp(kelimeler[j],kelimeler[j+1])>0){
				strncpy(tmp,kelimeler[j],100);
				strncpy(kelimeler[j],kelimeler[j+1],100);
				strncpy(kelimeler[j+1],tmp,100);
			}
	cout << endl << "Kelimelerin siralanmis hali: " << endl;
	for(int i=0; i<n; ++i)
		cout << kelimeler[i] << endl;

	system("PAUSE");
	return 0;
}

