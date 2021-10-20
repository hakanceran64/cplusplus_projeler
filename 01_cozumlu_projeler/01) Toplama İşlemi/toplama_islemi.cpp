/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Kullan�c�dan double tipinde iki say� al�n�z ve bu iki say�y� toplay�n�z.
 */

#include <iostream>
#include <iomanip>

/* using namespace std; kullan�larak her defas�nda std class'�n�n �a�r�lmas� zorunlulu�u ortadan kald�r�ld�. �rne�in: std::cin >> sayi1 >> sayi2; */
using namespace std;

int main(){
	/*  double virg�ll� say�lar (floating point numbers) i�in de�i�ken tan�mlarken kullan�l�r.
		Virg�ll� Say�lar i�in tan�mlanacak di�er de�i�ken tipi nispeten daha k���k say�lar i�in kullan�lan float't�r. */
	
	double sayi1, sayi2, toplam;
	
	cout << "Toplanacak iki sayiyi giriniz: " << endl;
	
	/*  Birden fazla de�i�ken tek bir cin komutu ile kullan�c�dan al�nabilece�i gibi birden fazla cin ile de al�nabilir.
		�rne�in: 	cin >> sayi1;
					cin >> sayi2; */
	cin >> sayi1 >> sayi2;
	toplam = sayi1 + sayi2;
	
	/* fixed << setprecision(2) kodu iomanip k�t�phanesi ile kullan�labilir. fixed << setprecision(2) virg�lden sonra iki basamak g�sterilsin demektir. */
	cout << fixed << setprecision(2) << toplam << endl;
	
	system("PAUSE");
	return 0;
}
