// Bu kod DevC++ ile çalýþtýrýlmýþtýr.  


#include <iostream> // C++ için temel kütüphane  
#include <cstdlib>  // malloc fonksiyonunun çalýþmasý için gerekli olan kütüphane
#include<locale.h> // Türkçe karakterlerin düzgün görüntülenmesi için gerekli olan kütüphane, görsellik 10 puan olduðu için eklemek daha iyi olur.
#include <bits/stdc++.h> // Ortaya eleman eklemek için gerekli hare ve tortoise algoritmasýnda kullanýlan fast-slow pointer mantýðýyla çalýþan kodlar için olan kütüphane  
using namespace std; // her seferinde std:: yapmamak için gerekli kod  
static const int MAX = 10; /* Hash Tablosunda girilen deðerleri mod 10'a böler ve herhangi bir deðer mod 10'a bölündüðünde
0-9 arasý bir sayý verir. Dolayýsý ile 0 ve 9 da dahil olmak üzere dizimizde deðerlerimizi yerleþtirebileceðimiz 10 adet alt alta indis - satýr vardýr. 

// Yiðitalp Dikmen 201813172039 2.Öðretim 2.Sýnýf Bilgisayar Mühendisliði


// Projemi GitHub Üzerinden de görüntüleyebilirsiniz : 


//  https://github.com/YigitalpDikmen/C-Binary-Tree-And-Hash-Console-App  


/* --------------------Burasý Ýkili Aðaç Binary Tree için Ana menüdeki 4 numaralý kýsýmýn Baþlangýcý --------------------------   */

class IkiliAgac // classýmýzý oluþturduk 
{
public: // herkese açýk yaptýk 
    struct Agacdugum // düðümümüz için structure oluþturduk 
    {
        int deger; // düðümün deðeri 
        Agacdugum* sol; // düðümün sað çocuðu - sað alt elemaný 
        Agacdugum* sag; // düðümün sol çocuðu - sol alt elemaný 
    }; // curly bracket ve end of statement.
    
	
	Agacdugum* kok; // kokumuz için iþaretçi oluþturduk 
	
	void temizleyici(); // temizleyici fonksiyon 
	
   
    
    IkiliAgac() //kurucu - constructor 
    {
        kok = NULL; // en baþta kökün boþ olmasý gerekli 
    }
    void dugumEkle(int); // düðüm ekleyici int tipi deðer döndüren bir fonksiyon 

    //Aðaçta dolaþmak için gerekli fonksiyonlar
    void InOrderDolasim(Agacdugum* dugumPtr); // in order þeklinde dolaþmak için 
    void PreOrderDolasim(Agacdugum* dugumPtr); // pre order þeklinde dolaþmak için 
    void PostOrderDolasim(Agacdugum* dugumPtr); // post order þeklinde dolaþmak için 

    //Düðümleri göstermek için fonksiyonlar
    void InOrderDugumGoster() /* Açýklama satýrý 361: in order için ekstra bir void tipi fonksiyon tanýmladýk, böyle yapmamýzýn sebebi ise 
	kok bu classýn ve structure'ýn içindeki bir pointer deðiþkeni olduðu için dýþarýdan gönderemeyiz. Dolayýsýyla bu void tipindeki fonksiyonu class'tan nesne
	türeterek main yapýsýnýn içine yazacaðýz oradan da buraya geldiði zaman buradaki kök'ü alýp döndürecek ve bu þekilde çalýþacak. */ 
    {
        InOrderDolasim(kok); 
    }
    void PreOrderDugumGoster() // satýr 361 deki açýklama aynen geçerlidir. 
    {
        PreOrderDolasim(kok);
    }
    void PostOrderDugumGoster() // satýr 361 deki açýklama aynen geçerlidir. 
    {
        PostOrderDolasim(kok);
    }

    bool DugumAra(int sayi); // onceden klass içi tanýmlýyoruz 
    void Sil(int sayi); // onceden klass içi tanýmlýyoruz 
    //sil isimli fonksiyon silinecek deðeri ve kokü DugumSil isimli fonksiyona geçirsin
    void DugumSil(int, Agacdugum*&);
    //biz bu fonksiyonu sileceðimiz düðüme ulaþmak için kullanacaðýz
    //bir düðüm silindiðinde alt aðacý baðlayacaðýmýz için sadece 
    //Agacdugüm tipinde bir iþaretçi deðil, 
    //bu yapýyý tutan iþaretçinin adresine iþaret ediyoruz
    //peki düðüme ulaþýnca ne yapacaðýz, tabiki sileceðiz:
    void GercekleSil(Agacdugum*&);
    //düðümü ortadan kaldýrýp alt aðacý baðlayacak
    
               
    
       
        
};


/*------------------------------------ Eleman Sayma Denemesi Baþlangýç ----------------------- */  
        
/*------------------------------------ Eleman Sayma Denemesi Son ----------------------- */  
/*------------------------------------Tüm Aðacý Silme Denemesi Baþlangýç ----------------------- */  
        
void IkiliAgac::temizleyici(){ // Classýn içindeki fonksiyonu :: ile alýp tanýmlýyorum
		Agacdugum* silicidugum; // class içi structure a baðlý yeni bir dugum oluþturuyorum 
		silicidugum = new Agacdugum; // nesne 
		silicidugum = NULL; // sonra bunun hiçbir yeri iþaret etmemesini saðlýyorum 
		
		kok = silicidugum; /* ardýndan bu düðümü kök'e eþitliyorum. Dolayýsýyla kök de hiçbiryeri iþaret etmiyor. 
		Ben de tam olarak ne yaptýðýmý bilmiyorum, bu durumda elemanlarýn hala bellekte tutuluyor olmasý ancak iþaret edilemiyor olmasý gerekir. yani yanlýþ. 
		Ama kok'ü null yaptýðýmýz bir sonraki alt eleman kök olacak sonra o da null olacak sonra bir sonraki alt eleman null olacak bu þekilde bu þekilde giderken
		aðaçta bitanecik eleman kalýcak yani kökü kalmýþ olacak en sonunda o da null olmuþ olacak ve deðerler bellekte kalsa bile hiçbir yer iþaret edilmiycek. */
				
					}

/*------------------------------------ Tüm Aðacý Silme Denemesi Son ----------------------- */  
 

void IkiliAgac::dugumEkle(int sayi) // class içi fonksiyon 
{
    Agacdugum* yenidugum,//yeni düðümü iþaret edecek 
    * dugumPtr; //aðacý dolaþacak (önceden pBas ile dolaþmýþtýk.) 
    yenidugum = new Agacdugum; // nesne 
    yenidugum->deger = sayi; // yeni duðumun deðerini atama 
    yenidugum->sol = yenidugum->sag = NULL; // sol'unu ve saðýný boþ yaptýk

    if (!kok)//aðaç boþ mu?, boþsa:
        kok = yenidugum;
    else
    { //kök'ün adresini aðacý dolaþacak iþaretçiye atayalým
        dugumPtr = kok;
        while (dugumPtr != NULL) //aðaçta düðüm bulunduðu sürece
        {
            if (sayi < dugumPtr->deger)  // buradaki yapý aðaç prensibi ile ilgili yeni eklenecek eleman kendi üst elemanýndan büyükse saða, küçükse sola atanýr.
            {
                if (dugumPtr->sol) // bu durumda üst düðüm daha büyük olduðu için sola atama gerçekleþir 
                    dugumPtr = dugumPtr->sol;
                else // deðilse 
                {
                    dugumPtr->sol = yenidugum;
                    break; // döngüden çýkmak için 
                }
            }
            else if (sayi > dugumPtr->deger) // buradaki yapý aðaç prensibi ile ilgili yeni eklenecek eleman kendi üst elemanýndan büyükse saða, küçükse sola atanýr.
            {
                if (dugumPtr->sag) // bu durumda üst düðüm daha küçük olduðu için saða atama gerçekleþir 
                    dugumPtr = dugumPtr->sag;
                else { // deðilse 
                    dugumPtr->sag = yenidugum;
                    break; // döngüden çýkmak için 
                }
            }//else if sonu
            else
            {
                cout << "Agacta deger iki defa bulundu"; // ekrana bastýr 
                break; // çýk 
            }

        }//while sonu

    }//else sonu

}//fonksiyon sonu

void IkiliAgac::InOrderDolasim(Agacdugum* dugumPtr) // class içi fonksiyon 
{//sol-kök-sað
    if (dugumPtr)
    {
        InOrderDolasim(dugumPtr->sol); // sol alt aðaca git ve varsa in order dolaþ. 
        cout << dugumPtr->deger << endl; // kök düðümü iþle 
        InOrderDolasim(dugumPtr->sag); // sað alt aðaca git 
    }
}

void IkiliAgac::PreOrderDolasim(Agacdugum* dugumPtr)
{//kök-sol-sað
    if (dugumPtr)
    {
        cout << dugumPtr->deger << endl; // kök düðümü iþle 
        PreOrderDolasim(dugumPtr->sol); // sol alt aðaca git ve varsa in order dolaþ. 
        PreOrderDolasim(dugumPtr->sag); // sað alt aðaca git
    }
}

void IkiliAgac::PostOrderDolasim(Agacdugum* dugumPtr)
{//sol-sað-kök
    if (dugumPtr)
    {
        PostOrderDolasim(dugumPtr->sol); // sol alt aðaca git ve varsa in order dolaþ. 
        PostOrderDolasim(dugumPtr->sag); // sað alt aðaca git
        cout << dugumPtr->deger << endl; // kök düðümü iþle 
    }
}

//*****
bool IkiliAgac::DugumAra(int sayi) // class içi düðüm arama fonksiyonu 
{
    Agacdugum* dugumPtr = kok; // ilk önce deðeri kökte arýyoruz 
    while (dugumPtr)
    {
        if (dugumPtr->deger == sayi) // kök'de bu deðer varsa 
            return true; // true deðerini döndür 
        else if (sayi < dugumPtr->deger) // kök'de bu deðer yok ise 
            dugumPtr = dugumPtr->sol; // sola bak 
        else // solda da yoksa 
            dugumPtr = dugumPtr->sag; // saða bak 
    }
    return false; // hiçbir yerde yoksa false deðerini döndür 
}
//*****
void IkiliAgac::Sil(int sayi) // Main içinde Nesne oluþturup buraya göndericez.
{
    DugumSil(sayi, kok); // buradan da köke ulaþacak.
}
//****
void IkiliAgac::DugumSil(int num, Agacdugum*& dugumPtr)
{//biz bu fonksiyonu sileceðimiz düðüme ulaþmak için kullanacaðýz
    //bir düðüm silindiðinde alt aðacý baðlayacaðýmýz için sadece 
    //Agacdugüm tipinde bir iþaretçi deðil, 
    //bu yapýyý tutan iþaretçinin adresine iþaret ediyoruz
    //peki düðüme ulaþýnca ne yapacaðýz, tabiki sileceðiz:
    if (num < dugumPtr->deger)//sayý solda mý diye bakalým
        DugumSil(num, dugumPtr->sol);
    else if (num > dugumPtr->deger)//sayi saðda mý diye bakalým
        DugumSil(num, dugumPtr->sag);
    else //sayýya ulaþtýðýmýzda silme iþlemini gerçekleyelim
        GercekleSil(dugumPtr);
}

void IkiliAgac::GercekleSil(Agacdugum*& dugumPtr) // Eðer aðaçta olmayan bir düðüm silinmeye çalýþýlýr ise program hata verir bu fonksiyonu o yüzden yaptýk. 
{
    Agacdugum* temp; //sol alt aðacý gösterecek olan gecici iþaretçi
    
    if (dugumPtr == NULL) // boþ ise 
        cout << "Bos dugumu silemezsin.\n"; // ekrana bastýr 
    else if (dugumPtr->sag == NULL) // sað boþ ise 
    {
        temp = dugumPtr;
        dugumPtr = dugumPtr->sol; // sol çocuðu yeniden atayalým
        delete temp;
    }//else if sonu
    else if (dugumPtr->sol == NULL) // sol boþ ise 
    {
        temp = dugumPtr;
        dugumPtr = dugumPtr->sag; // sol çocuðu yeniden atayalým
        delete temp;
    }//else sonu
    // dugümüm iki çocuðu var ise : 
    else
    {
        
        temp = dugumPtr->sag; // 1 dügüm saða taþýyalým.
        
        while (temp->sol) // sol düðümün sonuna gidelim.
            temp = temp->sol;
        
        temp->sol = dugumPtr->sol; // Sol altaðacý yeniden atayalým.
        temp = dugumPtr;
        
        dugumPtr = dugumPtr->sag; // Sað altaðacý yeniden atayalým.
        delete temp;
    }//else sonu
}//fonksiyon sonu




/* --------------------Burasý Ýkili Aðaç Binary Tree için Ana menüdeki 4 numaralý kýsýmýn Sonu --------------------------   */
/* --------------------Burasý Çýrpýlama Hash Tablosu için Ana menüdeki 5 numaralý kýsýmýn Baþlangýcý --------------------------   */

// constantýmý en üste koydum 10 olarak. 

class Dugum { // class tanýmlýyoruz 
public: // herkese açýk yapýyoruz 

//-------------------- Node düðüm yapýmýz ------------

    int Anahtar; //önceden veri diyorduk þimdi anahtar olarak adlandýrýyoruz. Çünkü bu veriye ulaþýrsak devamýnda barýndýrdýðý verilere de ulaþacaðýz. 
    Dugum* pSonraki; // bir sonraki düðümün verisini iþaret eden iþaretçi.  
    
//-------------------- Node düðüm yapýmýz ------------    
    
	Dugum(int Anahtar) // Constructorumuz 
    {
        this->Anahtar = Anahtar; // deðiþkenlerin karýþmamasý adýna this kullandýk. 
        pSonraki = NULL; // ilk baþta herhangi bir yeri iþaret etmiycek.  
    }
    
};
class HashTable { // Hash Tablosu için gerekli sýnýf. 
public: // Herkese açýk yaptýk. 
    Dugum* Veri[MAX]; //pointer dizisi. yani dizi adres tutacak
    HashTable(); //kurucu fonksiyon
    void Ekle(int Anahtar); //baðlý listelerde eklememe iþlemi pek yok, o yüzden void
    Dugum* Bul(int Anahtar);//düðümü komple getirecek.düðümün olmadýðýný Null ile anlayacaðýz
    void Sil(int Anahtar); // Silmek için kullanacaðýmýz fonksiyonu sýnýf içi tanýmladýk. 
};

HashTable::HashTable() // Constructorumuz 
{
    for (int i = 0; i < MAX; i++) // Max = 10 ise 0-9 arasý 10 tane slotumuz var ve bu slotlardaki tüm veriler birbiriyle baðlantýlý. En baþtaki null olursa devamý da null olur. 
        Veri[i] = NULL; // dolayýsýyla bu kýsým ile program ilk çalýþtýðýnda tüm tabloyu boþaltmýþ olacak. 
}


void HashTable::Ekle(int Anahtar) // Eleman ekleyici Hash fonksiyonu 
{
    Dugum* pYeni = new Dugum(Anahtar); // yeni düðüm
    int mod = Anahtar % MAX; // mod deðeri burada girilen elemanýn Max deðerine göre modu alýndýktan sonra çýkan sonuca göre diziye yerleþecek indexin deðeri oluyor. 
    if (!Veri[mod]) //ilgili hücrede bir adres var mý
    {//eðer varsa oaryaa baðlý bir baðlý liste var demektir
        Veri[mod] = pYeni;
        return;
    }
    //buraya geldiysek baðlý liste var:
    Dugum* pTemp = Veri[mod];//ilgili indisteki adres bilgisini pTemp'e atacaðýz.
    while (pTemp->pSonraki != NULL)
    {//son elemana kadar gideceðiz. Liste konusunda görmüþtük
        pTemp = pTemp->pSonraki;
    }
    pTemp->pSonraki = pYeni;//son düðüme yeni düðümü ekleyebiliriz.
}
Dugum* HashTable::Bul(int Anahtar)
{
    int mod = Anahtar % MAX;
    Dugum* pTemp = Veri[mod];
    while (pTemp != NULL)
    {//döngü burada düðümün kendisini kontrol edecek
        if (pTemp->Anahtar == Anahtar)//aradýðýmýz anahtar buysa adres dönecek
            return pTemp;
        pTemp = pTemp->pSonraki;
    }
    //listede aradýðýmýzý bulamadýk
    return NULL;
}

void HashTable::Sil(int Anahtar)//Kapalý adresleme yöntemi kullanacaðýz
{//Baðlý listelere benziyor
    int mod = Anahtar % MAX;
    //ilk durum hiç elemanýn(düðümün) olmadýðý durum
    if (!Veri[mod]) //Hiç bir elemanýn olmadýðý durum
    {
        return;
    }
    //buraya geldiysek en az 1 düðüm var
    //ilk düðümü çýkarmaya çalýþacaðýz:
    if (!Veri[mod]->pSonraki) //tek düðüm olma durumudur
    {
        if (Veri[mod]->Anahtar == Anahtar)
        {//tamam 1 düðüm var ama bu benim aradýðým düðüm mü.
        //Eðer öyle ise bu tek düðümü silelim
            delete Veri[mod]; //silicem ama yeterli deðil, çünkü adresini silmedik
            Veri[mod] = NULL; //NULL yapmazsam hafýza hatasýyla karþýlaþýrým,
             //çünkü orada düðüm var zannedecek
        }
        return; //aradýðýmýz düðümse veya deðilse her iki durumda da iþlemi bitiriyoruz
    }
    //buraya geldiysek birden fazla düðüm var demektir.
    //Birden fazla elemanýn(düðümün) olmasý durumu:
    if (Veri[mod]->Anahtar == Anahtar)
    {//birden fazla düðüm var ama ilk düðüm aradýðýmýz düðüm ve sileceðiz
    //ilk düðüm sileceðiz, dolayýsýyla baðlý olan sonraki düðüme baðlanmalýyý
        Dugum* pDon = Veri[mod]->pSonraki;//silinen düðüme baðlý olan düðüme ulaþamazdýk
        delete Veri[mod]; //silinen düðüm, þimdi ona baðlý olan düðüme baðlanalým:
        Veri[mod] = pDon;
        return;
    }
    //tek bir durum kaldý: aradýðýmýz düðüm arada bir yerde
    //Listelerdeki aradan çýkarmaya benziyor.
    Dugum* pTemp = Veri[mod];//öncelikle ilk düðümün adresini alýyorum pTemp içerisine.
    while (pTemp->pSonraki != NULL)//son düðüme gidecek kadar bir döngü yapýyoruz
    {
        if (pTemp->pSonraki->Anahtar == Anahtar)
        {//çýkaracaðýmýz düðümden önceki düðümün adresini bilmemiz gerekecek
            Dugum* pDon = pTemp->pSonraki; //düðümün adresini yedekliyoruz
            pTemp->pSonraki = pDon->pSonraki;//sonraki düðüme baðlýyoruz
            delete pDon;//silmek istediðimiz düðümü siliyoruz
            return;//silme iþlemi gerçeklendiðine göre return
        }//ilk düðüm deðilse while ile sonraki düðüme geçeceðiz:
        pTemp = pTemp->pSonraki;
    }
    //buraya geldiysek silinecek düðüm yok demektir.
}

/* --------------------Burasý Çýrpýlama Hash Tablosu için Ana menüdeki 5 numaralý kýsýmýn Sonu --------------------------   */
/* -------------------- 6 Numaralý Kýsým Çýkýþ-Exit için herhangi özel bir kod bulunmamaktadýr --------------------------   */
/* ------------------------------------------------- MAÝN FONKSÝYONUNA GÝRÝÞ !!!!!!!-------------------------------------- */


int main() {
   setlocale(LC_ALL, "Turkish"); // LC_ALL diyerek tüm koddaki türkçe karakterleri görüntülenebilir yaptýk. LC_TIME vb. gibi farklý kullanýmlarý mevcuttur. 
   
   int genel, deger, deger3, yigin, kuyruk, liste, ekleliste, cikarliste; // switch case için gerekli deðerler 
   
   /* Agac icin global degerler */  int agac_secim; IkiliAgac Agac; int agac_dugum_eleman_ekle; int agac_dugum_eleman_sil; int agac_eleman_sayici = 0; 
   
   /* Hash icin global degerler */  int cirpi_secim; int cirpi_dugum_eleman_ekle; int cirpi_dugum_eleman_sil; HashTable h;
 
  
/*   Ana menu text */      
   
   
    do {  // Programdan 6 tuþuna basýlýnca çýkýþ yapýlmasý için do-while ile çözüm ürettim 

     cout<<"1) Yýðýn Uygulamasý"<<endl; // arayüz 
     cout<<"2) Kuyruk Uygulamasý"<<endl; // arayüz 
     cout<<"3) Tek Yönlü Baðlý Liste Uygulamasý"<<endl; // arayüz 
     cout<<"4) Ýkili Aðaç (Binary Tree) Uygulamasý"<<endl; // arayüz 
     cout<<"5) Çýrpýlama Hash Uygulamasý (Tek Yönlü Kuyruk Linked List Dizisi)"<<endl;  // arayüz 
     cout<<"6) Programdan Çýkýþ "<<endl;     // arayüz 
   
	  cout<<"Ana Menüde Yapmak istediðiniz iþlemin numarasýný tuþlayýnýz (1-6 arasý): "<<endl; // arayüz 
    
   
    
      cin>>genel;  // switch case için deðer giriþi 
      switch(genel) { // switch yapýsý 
      

/*  ---------------------------------- Ýkili Aðaç Kýsmý Baþlangýç Case 4 --------------------- */  
         
		 
		 case 4: { // 4 tuþuna basýlýr ise yapýlacaklar 
            			            
            
                // Binary Tree Ýkili Agac Menü Text 		 
	 	  
            
              do{ // do - while yapýsý 
              
                    cout<<"1) Agaca Eleman Ekle"<<endl; // arayüz 
                    cout<<"2) Agactan Eleman Sil/Çýkar"<<endl; // arayüz 
                    cout<<"3) Agaci Temizle"<<endl; // arayüz 
                    cout<<"4) Agactaki Eleman Sayýsýný Göster"<<endl; // arayüz 
                    cout<<"5) Agaci In Order Dolaþarak Elemanlarý Göster"<<endl; // arayüz 
                    cout<<"6) Agaci Pre Order Dolaþarak Elemanlarý Göster"<<endl; // arayüz 
                    cout<<"7) Agaci Post Order Dolaþarak Elemanlarý Göster"<<endl; // arayüz 
                    cout<<"8) Ana Menüye Geri Dön "<<endl; // arayüz 
			   
              cout<<"Ýkili Aðaç (Binary Tree) Uygulamasýnda Yapmak istediðiniz iþlemin numarasýný tuþlayýnýz (1-8 arasý): "<<endl; // arayüz 
              
			  cin>>agac_secim; // kullanýcýdan veri giriþi bekleniyor 
              switch(agac_secim) { // switch yapýsý 
              
               case 1: // iç içe switch case, 1 tuþuna basýlýr ise yapýlacaklar 
			    {
			
			    cout << "Aðaca Eklenecek Elemanýn deðerini giriniz" <<endl;   // arayüz 
			    
				cin>>agac_dugum_eleman_ekle; // veri giriþi bekleniyor   
			    Agac.dugumEkle(agac_dugum_eleman_ekle); // aðaca eleman ekleme fonksiyonu 
			    
			    cout << " " <<endl; // arayüz 
			    cout << "Eleman Eklenmiþtir." <<endl; // arayüz 
			    
			    agac_eleman_sayici++; // bir yandan da elemanlarýn sayýsýný takip ediyoruz. 
            
               	break; }
                       
               case 2: // 2 ye basýlýr ise 
			    {
			    	    cout << "In Order Dolaþým ile Aðaçtaki Tüm Elemanlarýn deðeri:" << endl; // arayüz 
                        Agac.InOrderDugumGoster(); // eleman silmeden önceki hali 
			    	
			     cout << "Aðactan Silinecek Elemanýn deðerini giriniz" <<endl; // arayüz
			     
			     cin>>agac_dugum_eleman_sil; // silinecek elemanýn veri giriþi bekleniyor 
			     
			     if (Agac.DugumAra(agac_dugum_eleman_sil)){ // ilk önce o eleman aðaçta var mý diye arýyoruz
				 
			     Agac.Sil(agac_dugum_eleman_sil); // sonra var ise true deðer dönüyor ve eleman siliniyor. 
			     cout<<"Bu elemaný baþarý ile sildiniz"<<endl;} // arayüz 
			      
			     else { // o eleman yok ise 
                 cout<<"Aðaçta olmayan bir elemaný/deðeri silemezsiniz"<<endl;} // bunu diyor 
                 
                 
                 		cout << " Aðaçtaki Eleman Silindikten Sonra In Order Dolaþým ile Aðaçtaki Tüm Elemanlarýn deðeri:" << endl; // ve iþlem sonrasý aðaç hali 
                        Agac.InOrderDugumGoster(); // göster 
			      
			      			      
			      agac_eleman_sayici--;  // sayacý eksiltmeyi unutmuyoruz 
               	
               break; }
               
               case 3:
			    {
			    				    	

			    	Agac.temizleyici(); // aðaç temizleyici fonksiyon 
			    	
			    	agac_eleman_sayici = 0;  // sayacý sýfýrlamayý da unutmuyoruz 
			    	
			    	cout << "Aðaç Temizlenmiþtir"<<endl;  // arayüz 
               	
               break; }
               
               case 4: // 4' e basýlýr ise 
			    {
			    	 
             
                 cout << "Agactaki Eleman Sayisi:  " << agac_eleman_sayici <<endl; // elemanlarýn sayýsýný verir 
				           	
               break; }
               
               case 5: // 5'e basýlýr ise 
			    {
			    	 
			   	    cout << "In Order Dolaþým ile Aðaçtaki Elemanlar" << endl; // arayüz 
                    Agac.InOrderDugumGoster(); // gösterici fonksiyon 
               	
               break; }
               
                
				case 6: // 6'ya basýlýr ise 
			    {
			    	 
			        cout << "Pre Order Dolaþým ile Aðaçtaki Elemanlar" << endl; // arayüz 
			        Agac.PreOrderDugumGoster(); // gösterici fonksiyon 
               	
               break; }
               
               
                case 7: // 7'ye basýlýr ise 
			    {
			    	 
			        cout << "Post Order Dolaþým ile Aðaçtaki Elemanlar" << endl; // arayüz 
			        Agac.PostOrderDugumGoster(); // gösterici fonksiyon 
               	
               break; }
               
               
               
               case 8: // 8'e basýlýr ise 
			    {
			    	 
			    	cout<<"Ana menüye geri döndünüz "<<endl; // arayüz 
               	
               break; }
               
               
            default: { // hatalý deðer girilir ise 
            	
            cout<<"Yanlýþ Numara, Lütfen 1 ile 8 arasýnda bir deðer tuþlayýnýz"<<endl; // arayüz 
            break;}
                    
			  
			  }
			  
		} while(agac_secim !=8); // döngüden çýkar 
         	            
        
		
		    
            break;
         }
         
/*  ---------------------------------- Ýkili Aðaç Kýsmý Son Case 4 --------------------- */ 
/*  ---------------------------------- Çýrpýlama Hash Kýsmý Baþlangýç Case 5 --------------------- */  
         
		 
		 case 5: { // 5'e basýlýr ise 
            
            
                    // Tablo Menü Text 		 
	 	          
              do{
              
                    cout<<" "<<endl;  // arayüz             
                    cout<<"1) Tabloya Eleman Ekle"<<endl; // arayüz 
                    cout<<"2) Tablodan Eleman Sil/Çýkar"<<endl; // arayüz 
                    cout<<"3) Tabloyu Temizle"<<endl; // arayüz 
                    cout<<"4) Tablodaki Eleman Sayýsýný Göster"<<endl;  // arayüz 
                    cout<<"5) Tablodaki Elemanlarý Göster"<<endl; // arayüz 
                    cout<<"6) Ana Menüye Geri Dön "<<endl; // arayüz 

			   
              cout<<" Hash Tablosu Uygulamasýnda Yapmak istediðiniz iþlemin numarasýný tuþlayýnýz (1-6 arasý): "<<endl; // arayüz 
              
			  cin>>cirpi_secim; // kullanýcýdan veri giriþi bekleniyor 
              switch(cirpi_secim) { // switch yapýsý 
              
               case 1: // 1'e basýlýr ise 
			    {
			
			    cout << "Tabloya eklemek istediðiniz elemanýn deðerini giriniz"<<endl;  // arayüz 
			    cin>>cirpi_dugum_eleman_ekle; // veri giriþi 
			    h.Ekle(cirpi_dugum_eleman_ekle); // eleman ekleme fonksiyonu 
			    
			    cout << "Eleman Eklenmiþtir"<<endl;  // arayüz 
            
               	break; }
                       
               case 2: // 2'ye basýlýr ise 
			    {
			    	
			        cout << "Tablodaki Elemanlar Þunlardýr: (indis sýralamasýna göredir) "<<endl;  // arayüz 
			   
			   for (int i = 0; i <= 100000; i++) { // Maalesef 100000 e kadar olan elemanlarý bastýrabiliyor. Nasý bastýracaðýmý tam olarak kavrayamadým. 
			    Dugum* pTemp = h.Bul(i); // Constant Max'da kaç indis tanýmlanmýþ ise oraya kadar gider. Ve tüm elemanlarý bulur. 
			            //düðümleri yazdýralým:
                        while (pTemp != NULL)
                    {
                    	
                    	
                        cout << pTemp->Anahtar << " ";
                        pTemp = pTemp->pSonraki;
                               }
                           } 
                   
				   cout << " "<<endl;         // arayüz 
                   cout << "Çýkartmak Ýstediðiniz Elemanýn deðerini giriniz: "<<endl;    // arayüz 
				   cin>>cirpi_dugum_eleman_sil;     // veri giriþi  
				   h.Sil(cirpi_dugum_eleman_sil); // eleman silici fonksiyon 
				   				   
				   cout << "Eleman Çýkartýlmýþtýr"<<endl;  // arayüz 
                           
               	
               break; }
               
               case 3: //3'e basýlýr ise 
			    {
			    	
			    	
			    for (int i = 0; i <= 100000; i++) {  // herþeyi siliyo 
			    	h.Sil(i); // silici fonksiyon 

                          }
			    	
			    	
			    	cout << "Tablo Temizlenmiþtir"<<endl;  // arayüz 
                    
               	
               break; }
               
               case 4: // 4'e basýlýr ise 
			    {
			    	
			    	
			         int tablo_sayma = 0;
			   
			   for (int i = 0; i <= 100000; i++) {     // i <= MAX; böyle idi normalde 
			    Dugum* pTemp = h.Bul(i); // Constant Max'da kaç indis tanýmlanmýþ ise oraya kadar gider. Ve tüm elemanlarý bulur. 
			    
			            //düðümleri yazdýralým:
                        while (pTemp != NULL)
                    {
                        pTemp->Anahtar;

						tablo_sayma++;  
						
                        pTemp = pTemp->pSonraki;
                               }
                               
                               
                           }
                           
                if (tablo_sayma == 0){ // eðer 
                cout << "Tabloda Hiç Eleman Yoktur, Tablodaki Eleman Sayýsý: 0 "<<endl; } // arayüz 
                else{ // deðilse 
                cout << "Tablodaki Eleman Sayýsý: " << tablo_sayma <<endl; }   // arayüz         
                           
               	
               break; }
               
               
               
               case 5: // 5'e basýlýr ise 
			    {
			    
				
				if (0){}	
			    	
			    	
			   
			   else{	 
			   cout << "Tablodaki Elemanlar Þunlardýr: (indis sýralamasýna göredir) "<<endl;  // arayüz 
			   
			   for (int i = 0; i <= 100000; i++) {
			    Dugum* pTemp = h.Bul(i); // Constant Max'da kaç indis tanýmlanmýþ ise oraya kadar gider. Ve tüm elemanlarý bulur. 
			    
			            //düðümleri yazdýralým: 
                        while (pTemp != NULL) 
                    {
                        cout << pTemp->Anahtar << " ";
                        pTemp = pTemp->pSonraki;
                               }
                           }
                           
                       }
               	
               break; }
               
               
               
                
				      
               case 6: // 6'ya basýlýr ise 
			    {
			    	 
			    	cout<<"Ana menüye geri döndünüz "<<endl; // arayüz 
               	
               break; }
               
               
            default: { // yanlýþ deðer girilirse 
            	
            cout<<"Yanlýþ Numara, Lütfen 1 ile 6 arasýnda bir deðer tuþlayýnýz"<<endl; // arayüz 
            break;}
                    
			  
			  }
			  
		} while(cirpi_secim !=6); // döngüden çýkar 
         	            
        
		
            
            
            
            break; // döngüyü kýrar 
         }
         
/*  ---------------------------------- Çýrpýlama Hash Kýsmý Son Case 5 --------------------- */ 
/*  ---------------------------------- Ana Menü Exit - Çýkýþ Kýsmý Baþlangýç Case 6 --------------------- */  
         
		 
		 case 6: {
            cout<<"Çýkýþ yaptýnýz, konsol ekranýný kapatmak için herhangi bir tuþa basýnýz "<<endl; // arayüz 
            break;
         }
         
/*  ---------------------------------- Ana Menü Exit - Çýkýþ Kýsmý Son Case 6 --------------------- */ 
/* -------------------------------------------- Ana menüdeki Default yapýsý baþlangýç ------------------------------- */ 
         
		 default: { // farklý bi sayýya basýlýrsa burasý müdahale ediyor. 
            cout<<"Yanlýþ Numara, Lütfen 4, 5 veya 6'yý tuþlayýnýz"<<endl;
         }
/* -------------------------------------------- Ana menüdeki Default yapýsý son ------------------------------- */           
         
      }
   } 
     while(genel!=6); // çýkýþý burasý saðlýyo 
      return 0;  // main fonksiyonuna 0 yani false deðeri dönüyor ve uygulama sonlanmýþ oluyor.  
   }
   
/*--------------------------------- Son----------------------------- */     
/* Copyright Yiðitalp Dikmen 2020 TM Tüm Haklarý Saklýdýr */   




