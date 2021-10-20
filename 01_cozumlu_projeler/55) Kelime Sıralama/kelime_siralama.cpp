/*
 * Author: Hakan Ceran
 * Date: 02.09.2017
 * Content: Girilen n kelimeyi (n<=10000) alfabetik olarak s�ralayan bir program yaz�n�z. Her kelimenin uzunlu�u en fazla 100 karakter olmal�d�r.
 *			Girdi olarak ilk sat�rda n say�s� girilecek, ikinci sat�rda ise aralar�nda bo�luk olan n tane kelime girilecektir.
 *			��kt� olarak ise kelimeler alfabetik olarak s�ral� �ekilde her bir sat�ra bir kelime yazd�r�lacakt�r.
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

