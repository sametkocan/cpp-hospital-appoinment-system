#include "sistemYoneticii.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

void sistemYonetici::hastaKaydet(Hasta h)
{
	ofstream dosyam("hastalar.txt", ios::app);
	dosyam << h.getTC() << " " << h.getPassword() <<" " << h.getName() << " " << h.getSurname() << " " << h.getBirthday().getGun()<<" " <<h.getBirthday().getAy() <<" "<<h.getBirthday().getYil()<< "\n";
	hastalar.push_back(h);
}

bool sistemYonetici::sadeceRakamMi(string str)
{
for (char c : str) {
	if (!isdigit(c)) return false; // Eðer bir karakter bile rakam deðilse hata ver
}
return true;
}

int sistemYonetici::hataAyiklamaliSayiAl(int min, int max) {
	int deger;
	while (!(cin >> deger) || deger < min || deger > max) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Gecersiz giris! Lutfen " << min << " ile " << max << " arasinda bir sayi giriniz: ";
	}
	return deger;
}

void sistemYonetici::sistemiBaslat()
{
	string hastahaneAdi;
	ifstream hDosya("hastaneler.txt");
	
	if (!hDosya)
	{
		cout << "Hastane Dosyasi Okuma Hatasi!\n";
	}

	while (hDosya >> hastahaneAdi)
	{
		hastaHane geciciH(hastahaneAdi);
		hastaHaneler.push_back(geciciH);
	}
	hDosya.close();


	string calistigiHastahane, drAdi, drSoyadi, drBransi;
	ifstream dDosya("doktorlar.txt");
	if (!dDosya)
	{
		cout << "Doktor Dosyasi Okuma Hatasi!\n";
	}
	while (dDosya >> calistigiHastahane >> drAdi >> drSoyadi >> drBransi)
	{
		Doktor geciciDr(drAdi, drSoyadi, drBransi);

		for (int i = 0; i < hastaHaneler.size(); i++)
		{
			if (hastaHaneler.at(i).getHastahaneAdi() == calistigiHastahane)
			{
				hastaHaneler.at(i).doktorEkle(geciciDr);
				break;
			}
		}
	}
	dDosya.close();


	string tc, sifre, isim, soyisim;
	int gun, ay, yil;

	ifstream dosyam("hastalar.txt");
	if (!dosyam)
	{
		cout << "Dosya Okuma Hatasi\n";
	}

	while (dosyam >> tc >> sifre >> isim >> soyisim >> gun >> ay >> yil)
	{
		dogumTarihi geciciTarih(gun, ay, yil);
		Hasta geciciHasta(tc, sifre, isim, soyisim, geciciTarih);
		hastalar.push_back(geciciHasta);
		
	}
	dosyam.close();

}



bool sistemYonetici::hastaGirisYap(string tc, string sifre)
{
	for (int i = 0; i < hastalar.size(); i++)
	{
		if (hastalar.at(i).getTC() == tc && hastalar.at(i).getPassword() == sifre)
		{
			return true;
		}
	}

	return false; //donguden cýkarsa bulamamýs demektir bu yuzden direkt false dondurmek gerekir.
}



void sistemYonetici::hastahaneyeGoreRandevuAl()
{
	int hastahanesecim,doktorSecim,saatSecim;
	for (int i = 0; i < hastaHaneler.size(); i++)
	{
		cout << i + 1 <<". " << hastaHaneler.at(i).getHastahaneAdi() << "\n";
	}
	cout << "Randevu Aradiginiz Hastahaneyi Seciniz\n";
	hastahanesecim=hataAyiklamaliSayiAl(1,hastaHaneler.size());
	hastahanesecim--;
	hastaHane& secilenHastahane = hastaHaneler.at(hastahanesecim);
	vector<Doktor>& secilenDoktorlar = secilenHastahane.getDoktorlar();

	for (int j = 0; j < secilenDoktorlar.size(); j++)
	{
		cout << j + 1 << ". " << secilenDoktorlar.at(j).getDoctorname() << " " << secilenDoktorlar.at(j).getDoctorSurname() << " [" << secilenDoktorlar.at(j).getBrans() << "]\n";
	}
	
	cout << "Randevu Almak Istediginiz Doktoru Seciniz\n";
	cin >> doktorSecim;
	doktorSecim--;
	Doktor& secilenDoktor = secilenDoktorlar.at(doktorSecim);
	cout << "\n--- " << secilenDoktor.getDoctorname() << " " << secilenDoktor.getDoctorSurname() << " Icin Uygun Saatler---\n";
	secilenDoktor.getRandevular();

	cout << "Hangi Saati Secmek Ýstersiniz?(1-18)\n";
	cin >> saatSecim;
	saatSecim--;

	if (!secilenDoktor.randevuAl(saatSecim))
	{
		cout << "Secilen Saat Dolu Lutfen Uygun Bir Randevu Seciniz\n";

	}
	else
	{
		cout << "Randevunuz Onaylandi\n";
	}
}




void sistemYonetici::poliklinigeGoreRandevuAl()
{
	cout << "--- POLIKLINIK SECINIZ ---\n";
	cout << "1. Goz\n";
	cout << "2. Dahiliye\n";
	cout << "3. Kardiyoloji\n";
	cout << "4. Ortopedi\n";
	cout << "5. Kulak Burun Bogaz\n";
	int polSecim,DoktorSecim,saatSecim;
	cin >> polSecim;

	string secilenBrans = "";

	if (polSecim == 1) secilenBrans = "Goz";
	else if (polSecim == 2) secilenBrans = "Dahiliye";
	else if (polSecim == 3) secilenBrans = "Kardiyoloji";
	else if (polSecim == 4) secilenBrans = "Ortopedi";
	else if (polSecim == 5) secilenBrans = "Kulak Burun Bogaz";
	int i = 1;

	vector<shared_ptr<Doktor>> BulunanDoktorlar; // Polikliniðe uyan doktorlarý referans olarak deðil, shared_ptr (smart pointer) ile tutuyoruz. 
// Neden? Çünkü ana vektör (doktorlar) geniþlediðinde/reallocate olduðunda eski adresler çöp olur (dangling pointer). 
// shared_ptr, nesnenin yaþam döngüsünü takip ederek bellek hatalarýný (memory corruption) engeller.


	for (int a = 0; a< hastaHaneler.size();a++)
	{
		for (int b=0;b<hastaHaneler.at(a).getDoktorlar().size();b++)
		{
			if (hastaHaneler.at(a).getDoktorlar().at(b).getBrans() == secilenBrans)
			{
				cout << i <<". " << hastaHaneler.at(a).getDoktorlar().at(b).getDoctorname() <<" " << hastaHaneler.at(a).getDoktorlar().at(b).getDoctorSurname() << "[ " << hastaHaneler.at(a).getHastahaneAdi() << "]\n";
				i++;
				BulunanDoktorlar.push_back(make_shared<Doktor>(hastaHaneler.at(a).getDoktorlar().at(b))); // bulunan doktorun adresini bulunanDoktorlar pointerý sayesinde tuttum.

		    }
		}
	}

	cout << "Randevu Almak Istediginiz Doktoru Secin\n";
	cin >> DoktorSecim;
	DoktorSecim--;

	Doktor* SecilenDoktor = BulunanDoktorlar.at(DoktorSecim).get(); //get() shared_ptr kutusunun icini acarak raw pointer ýný bize verir boylece esitligin 2 tarafýnýn tip uyumu saglanmýs olur.
	SecilenDoktor->getRandevular(); //pointer oldugu icin icinde ki randevu basan fonksiyona . yerine -> ile eristik.
	cout << "Randevu Almak Istediginiz Saati Giriniz\n";
	cin >> saatSecim;
	saatSecim--;

	if (!SecilenDoktor->randevuAl(saatSecim))
	{
		cout << "Bu Randevu Dolu Lutfen Uygun Olan Bir Randevu Seciniz\n";
	}
	else
	{
		cout << "Randevunuz Basariyla Onaylandi!\n";
	}

}


