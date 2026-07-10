# Hospital Appointment System (MHRS Clone)

Bu proje, C++ modern standartları (C++11 ve üzeri) kullanılarak geliştirilmiş, nesne yönelimli (OOP) bir Merkezi Hekim Randevu Sistemi (MHRS) uygulamasıdır.

## Mimari ve Gelişmiş Özellikler

Bu sistemde basit dosya işlemlerinin ötesine geçerek, modern yazılım geliştirme pratiklerini uyguladık:

* **Modern Bellek Yönetimi (Smart Pointers):** Manuel `new`/`delete` yerine `std::unique_ptr` ve `std::shared_ptr` kullanarak bellek sızıntılarını (memory leak) sıfırladık ve daha güvenli bir bellek yönetimi sağladık.
* **Veritabanı Simülasyonu (Flat-file):** Verileri kalıcı kılmak için `.txt` dosyalarını bir veritabanı gibi (`fstream` ile) kullandık. İlişkisel veri okuma mantığı ile hasta, doktor ve hastane verilerini birbirine bağladık.
* **Zaman Doğrulaması:** `ctime` ve `time.h` kütüphanelerini kullanarak hasta doğum tarihleri ve randevu süreçleri için dinamik zaman kontrolleri yaptık.
* **Zırhlı Giriş (Robustness):** `cin` tampon belleğini yöneterek, geçersiz veri girişlerinde programın çökmesini engelleyen `hataAyiklamaliSayiAl` fonksiyonunu tasarladık.
* **Modüler Yapı:** Proje, sınıflar arası (Hasta, Doktor, Hastahane, SistemYonetici) düşük bağımlılık (loose coupling) prensibine göre ayrıldı.

### Neyi, Neden Yaptık?
1. **Smart Pointers:** Manuel bellek yönetimi hatalara açıktır. `Smart pointer` kullanarak, nesnelerin yaşam döngüsünü otomatik yöneterek sistemin stabilitesini artırdık.
2. **Flat-file Veritabanı:** SQL kurulumuna gerek duymadan, uygulamanın her ortamda (başka bir kütüphaneye ihtiyaç duymadan) çalışabilmesini sağlamak için dosya tabanlı bir sistem tercih ettik.
3. **Zaman Fonksiyonları:** Randevuların güncelliğini ve hasta yaş doğrulamasını gerçek zamanlı verilerle yapmak için `time.h` kütüphanesini sistemin temeline yerleştirdik.

## Teknik Detaylar
- **Dil:** C++ (Modern)
- **Paradigma:** Nesne Yönelimli Programlama (OOP)
- **Bellek Yönetimi:** RAII prensibi ile Akıllı İşaretçiler (Smart Pointers)
- **Dosya İşleme:** `std::fstream` (CSV formatlı veri parse etme)

## Çalıştırma
```bash
g++ *.cpp -o hastane_sistemi
./hastane_sistemi
