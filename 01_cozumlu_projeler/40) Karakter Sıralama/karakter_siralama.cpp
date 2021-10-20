/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Kullanýcý tarafýndan girilen n(n<=1000) karakterlik bir metni alfabetik olarak sýralayýp ekrana yazdýrmanýz istenmektedir.
 *			- Girilen karakterler içerisinde büyük küçük karakterler olabilir.
 *			- Girilen karakterler n'den fazla olabilir. Ýlk n karakterden sonra olan karakterleri gözardý ediniz.
 *			- Büyük ve küçük karakterleri kendi aralarýnda sýralamayýnýz. Örneðin: B ile b ayný aralýða sahiptir ve b karakterleri kendi içerisinde sýralanmayacaktýr.
 */

#include <iostream>

#define MAX 1000

using namespace std;

// Ýki karakterin yerini deðiþtiren fonksiyon
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

