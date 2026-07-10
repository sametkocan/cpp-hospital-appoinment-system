#define _CRT_SECURE_NO_WARNINGS //microsoft eski ve guvenmedigi localtime gibi fonklarý kullanmamýzý engellemek icin hata verir ama biz bilincli olarak bu fonklarý kullanýyoruz o yuzden 
#include"hasta.h"				//bu kod parcasý ile windows a sorun olmadýgýný ve hata vermemesi gerektigini soyluyoruz.
#include<ctime>

Hasta::Hasta(string id, string pswrd, string nm, string snm, dogumTarihi bd):TC(id), password(pswrd), name(nm), surname(snm), birthday(bd) 
{ 
	yasHesapla(); 
}

void Hasta::yasHesapla()
{
	time_t simdikiZaman = time(0); //pc nin simdiki zamanini saniye cinsinden buyuk bir sayi olarak tutar
	tm* ltm = localtime(&simdikiZaman); //saniye olarak tutulan zamani gun,ay,yil olarak ayýrýr ve ltm ye verir.

	int guncelYil = 1900 + ltm->tm_year; //yýl verisi 1900 den baslanarak hesaplandýgý icin donen sayýya 1900 ekledik.
	int guncelAy = 1 + ltm->tm_mon; // ay verisi 0 dan basladýgý icin(ocak=0) donen ay verisine 1 ekledik.
	int guncelGun = ltm->tm_mday;

	yas = guncelYil - birthday.getYil();

	if (guncelAy < birthday.getAy() || (guncelAy == birthday.getAy() && guncelGun < birthday.getGun()))
	{
		yas--;
	}
}