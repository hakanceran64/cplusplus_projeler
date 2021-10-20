/*
 * Author: Hakan Ceran
 * Date: 31.08.2017
 * Content: Girdi olarak n(n<=100) sayısı boyutunda ekrana yıldız karakteriyle K harfi yazan programı yazınız.
 */

#include <iostream>

using namespace std;

int main(){
	
	int n, n2;
	
	cout << "Bir n degeri giriniz : ";
	cin >> n;
	
	n2=n/2;
	
	for(int i=n2; i>0; --i){
		cout << "*";
		for(int j=0; j<i; ++j){
			cout << " ";
		}
		cout << "*" << endl;
	}
	
	cout << "*" << endl;
	
	for(int i=1; i<=n2; ++i){
		cout << "*";
		for(int j=0; j<i; ++j){
			cout << " ";
		}
		cout << "*" << endl;
	}

	system("PAUSE");
	return 0;
}

