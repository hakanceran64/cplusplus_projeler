/*
 * Author: Hakan Ceran
 * Date: 19.09.2017
 * Content: Eðer bir inek 2 yaþýndan her yýl bir dana doðuruyor ise x yýl sonra (ineklerden hiç biri ölmezse) toplam kaç inek olur problemini hesaplayan program kodlarýný yazýnýz.
 *			Bu probleme Dudeney's Cows denir.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi

using namespace std; // std::

int fib(int);

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	int n;
	
	cout << "Kaç yýl sonra ne kadar ineðiniz olacaðýný hesaplayýnýz: ";
	cin >> n;
	
	for(int i=0; i<n; i++){
		cout << i+1 << ". yýl toplam inek sayýsý: " << fib(i) << endl;
	}

	system("PAUSE");
	return 0;
}

// Dudeney'in inekleri problemi fibonacci serisi ile çözülebilir. Bu örnekte recursive (özyinelemeli) fonksiyon kullanýlmýþtýr. Ýstenirse recursive yapý kullanýlmadan yapýlabilir.
int fib(int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

