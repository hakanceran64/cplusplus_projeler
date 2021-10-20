/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Kullanýcýdan double tipinde iki sayý alýnýz ve bu iki sayýyý toplayýnýz.
 */

#include <iostream>
#include <iomanip>

/* using namespace std; kullanýlarak her defasýnda std class'ýnýn çaðrýlmasý zorunluluðu ortadan kaldýrýldý. Örneðin: std::cin >> sayi1 >> sayi2; */
using namespace std;

int main(){
	/*  double virgüllü sayýlar (floating point numbers) için deðiþken tanýmlarken kullanýlýr.
		Virgüllü Sayýlar için tanýmlanacak diðer deðiþken tipi nispeten daha küçük sayýlar için kullanýlan float'týr. */
	
	double sayi1, sayi2, toplam;
	
	cout << "Toplanacak iki sayiyi giriniz: " << endl;
	
	/*  Birden fazla deðiþken tek bir cin komutu ile kullanýcýdan alýnabileceði gibi birden fazla cin ile de alýnabilir.
		Örneðin: 	cin >> sayi1;
					cin >> sayi2; */
	cin >> sayi1 >> sayi2;
	toplam = sayi1 + sayi2;
	
	/* fixed << setprecision(2) kodu iomanip kütüphanesi ile kullanýlabilir. fixed << setprecision(2) virgülden sonra iki basamak gösterilsin demektir. */
	cout << fixed << setprecision(2) << toplam << endl;
	
	system("PAUSE");
	return 0;
}
