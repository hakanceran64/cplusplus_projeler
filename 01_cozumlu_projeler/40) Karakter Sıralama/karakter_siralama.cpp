/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Kullan�c� taraf�ndan girilen n(n<=1000) karakterlik bir metni alfabetik olarak s�ralay�p ekrana yazd�rman�z istenmektedir.
 *			- Girilen karakterler i�erisinde b�y�k k���k karakterler olabilir.
 *			- Girilen karakterler n'den fazla olabilir. �lk n karakterden sonra olan karakterleri g�zard� ediniz.
 *			- B�y�k ve k���k karakterleri kendi aralar�nda s�ralamay�n�z. �rne�in: B ile b ayn� aral��a sahiptir ve b karakterleri kendi i�erisinde s�ralanmayacakt�r.
 */

#include <iostream>

#define MAX 1000

using namespace std;

// �ki karakterin yerini de�i�tiren fonksiyon
void degistir(char *c1, char *c2){
	char tmp=*c1;
	*c1=*c2;
	*c2=tmp;
}

int main(){
	
	int n;
	char karakterler[MAX];
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	cout << "Karakterleri giriniz: ";
	for(int i=0; i<n; ++i){
		cin >> karakterler[i];
	}
	
	karakterler[n]='\0';
	
	char c1, c2;
	
	for(int i=n; i>0; --i){
		for(int j=1; j<i; ++j){
			c1=karakterler[j-1];
			c2=karakterler[j];

			if(c1>='A' && c1<='Z')
				c1+=32;
			if(c2>='A' && c2<='Z')
				c2+=32;
			if(c1>c2)
				degistir(&karakterler[j-1],&karakterler[j]);
		}
	}
	
	cout << karakterler << endl;

	system("PAUSE");
	return 0;
}

