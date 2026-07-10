#include"Doktor.h"


Doktor::Doktor(string nm , string snm , string brn) :name(nm), surname(snm), brans(brn)
{
	for (int i = 0; i < 18; i++)
	{
		randevuSlotlari[i] = false;
	}
}

void Doktor::getRandevular()
{
	string saatler[18] =
	{ "08:00", "08:30", "09:00", "09:30", "10:00", "10:30", "11:00", "11:30", "13:00", "13:30", "14:00", "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30" };

	for (int i = 0; i < 18; i++)
	{
		if (randevuSlotlari[i] == false)
		{
			cout << saatler[i] << "[BOS]\n";
		}
		else
		{
			cout << saatler[i] << "[DOLU]\n";
		}
	}
}

bool Doktor::randevuAl(int slotNo)
{
	if (randevuSlotlari[slotNo] == true) //doluysa false dondurcek.
	{
		return false;
	}
	
	randevuSlotlari[slotNo] = true; //if e girmediyse bostur o zaman biz doldurucagýz.
	return true;
}