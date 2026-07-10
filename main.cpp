#include"sistemYoneticii.h"

int main()
{
	sistemYonetici sys;
	sys.sistemiBaslat();

	while (true)
	{
		int secim;
		string tc, password, isim, soyisim;
		int gun, ay, yil;
		cout << "1. Hasta Kayit Ol\n2. Hasta Giris Yap\n3. Cikis\n";
		secim = sys.hataAyiklamaliSayiAl(1, 3);

		switch (secim)
		{
		 case 1:
		 {
			 cout << "TC Kimliginizi Giriniz\n";
			 cin >> tc;
			 while (!sys.sadeceRakamMi(tc)||tc.length()<9)
			 {
				 cout << "Lutfen Gecerli Bir TC Giriniz\n";
				 cin >> tc;
			 }

			 cout << "Sifrenizi Giriniz\n";
			 cin >> password;
			 cout << "Isminizi Giriniz\n";
			 cin.ignore();
			 getline(cin, isim);
			 cout << "Soy Isminizi Giriniz\n";
			 getline(cin, soyisim);
			 cout << "Dogum Tarihinizi Giriniz(gun ay yil)";
			 cin >> gun>> ay >>yil;
			 dogumTarihi geciciTarih(gun, ay, yil);
			 Hasta geciciHasta(tc, password, isim, soyisim, geciciTarih);
			 sys.hastaKaydet(geciciHasta);
			 break;
		  }
		 case 2:
		 {
			 cout << "TC: ";
			 cin >> tc;
			 while (!sys.sadeceRakamMi(tc) || tc.length() < 9)
			 {
				 cout << "Lutfen Gecerli Bir TC Giriniz\n";
				 cin >> tc;
			 }
			 cout << "sifre: ";
			 cin >> password;

			 if (sys.hastaGirisYap(tc, password))
			 {
				 cout << "Giris Basarili Hosgeldiniz!";
				 while (true)
				 {
					 int icSecim;
					 cout << "\n===== Randevu Paneli =====\n";
					 cout << "1. Hastahaneye Gore Randevu Al\n";
					 cout << "2. Poliklinige Gore Randevu Al\n";
					 cout << "3. Cikis (Ana Menuye Don)\n";
					 icSecim = sys.hataAyiklamaliSayiAl(1, 3);

					 if (icSecim == 1)
					 {
						 sys.hastahaneyeGoreRandevuAl();
					 }
					 else if (icSecim == 2)
					 {
						 sys.poliklinigeGoreRandevuAl();
					 }
					 else if (icSecim == 3)
					 {
						 cout << "Ana Menuye Donuluyor...\n";
						 break;
					 }
					 else
					 {
						 cout << "Yanlis Secim,Tekrar Dene(1-3)\n";
					 }

				 }

			 }

			 else
			 {
				 cout << "Hatali TC veya Sifre Girisi!\n";
			 }
			 break;
		 }
		 case 3:
		 {
			 cout << "Sistem Kapatiliyor...\n";
			 return 0;
		 }
		 default:
		 {
			 cout << "Hatali Secim Lutfen Tekrar Secim Yapiniz(1-3)\n";
		 }

		}

	}
}