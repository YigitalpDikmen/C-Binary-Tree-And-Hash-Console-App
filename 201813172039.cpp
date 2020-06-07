// Bu kod DevC++ ile �al��t�r�lm��t�r.  


#include <iostream> // C++ i�in temel k�t�phane  
#include <cstdlib>  // malloc fonksiyonunun �al��mas� i�in gerekli olan k�t�phane
#include<locale.h> // T�rk�e karakterlerin d�zg�n g�r�nt�lenmesi i�in gerekli olan k�t�phane, g�rsellik 10 puan oldu�u i�in eklemek daha iyi olur.
#include <bits/stdc++.h> // Ortaya eleman eklemek i�in gerekli hare ve tortoise algoritmas�nda kullan�lan fast-slow pointer mant���yla �al��an kodlar i�in olan k�t�phane  
using namespace std; // her seferinde std:: yapmamak i�in gerekli kod  
static const int MAX = 10; /* Hash Tablosunda girilen de�erleri mod 10'a b�ler ve herhangi bir de�er mod 10'a b�l�nd���nde
0-9 aras� bir say� verir. Dolay�s� ile 0 ve 9 da dahil olmak �zere dizimizde de�erlerimizi yerle�tirebilece�imiz 10 adet alt alta indis - sat�r vard�r. 

// Yi�italp Dikmen 201813172039 2.��retim 2.S�n�f Bilgisayar M�hendisli�i


// Projemi GitHub �zerinden de g�r�nt�leyebilirsiniz : 


//  https://github.com/YigitalpDikmen/C-Binary-Tree-And-Hash-Console-App  


/* --------------------Buras� �kili A�a� Binary Tree i�in Ana men�deki 4 numaral� k�s�m�n Ba�lang�c� --------------------------   */

class IkiliAgac // class�m�z� olu�turduk 
{
public: // herkese a��k yapt�k 
    struct Agacdugum // d���m�m�z i�in structure olu�turduk 
    {
        int deger; // d���m�n de�eri 
        Agacdugum* sol; // d���m�n sa� �ocu�u - sa� alt eleman� 
        Agacdugum* sag; // d���m�n sol �ocu�u - sol alt eleman� 
    }; // curly bracket ve end of statement.
    
	
	Agacdugum* kok; // kokumuz i�in i�aret�i olu�turduk 
	
	void temizleyici(); // temizleyici fonksiyon 
	
   
    
    IkiliAgac() //kurucu - constructor 
    {
        kok = NULL; // en ba�ta k�k�n bo� olmas� gerekli 
    }
    void dugumEkle(int); // d���m ekleyici int tipi de�er d�nd�ren bir fonksiyon 

    //A�a�ta dola�mak i�in gerekli fonksiyonlar
    void InOrderDolasim(Agacdugum* dugumPtr); // in order �eklinde dola�mak i�in 
    void PreOrderDolasim(Agacdugum* dugumPtr); // pre order �eklinde dola�mak i�in 
    void PostOrderDolasim(Agacdugum* dugumPtr); // post order �eklinde dola�mak i�in 

    //D���mleri g�stermek i�in fonksiyonlar
    void InOrderDugumGoster() /* A��klama sat�r� 361: in order i�in ekstra bir void tipi fonksiyon tan�mlad�k, b�yle yapmam�z�n sebebi ise 
	kok bu class�n ve structure'�n i�indeki bir pointer de�i�keni oldu�u i�in d��ar�dan g�nderemeyiz. Dolay�s�yla bu void tipindeki fonksiyonu class'tan nesne
	t�reterek main yap�s�n�n i�ine yazaca��z oradan da buraya geldi�i zaman buradaki k�k'� al�p d�nd�recek ve bu �ekilde �al��acak. */ 
    {
        InOrderDolasim(kok); 
    }
    void PreOrderDugumGoster() // sat�r 361 deki a��klama aynen ge�erlidir. 
    {
        PreOrderDolasim(kok);
    }
    void PostOrderDugumGoster() // sat�r 361 deki a��klama aynen ge�erlidir. 
    {
        PostOrderDolasim(kok);
    }

    bool DugumAra(int sayi); // onceden klass i�i tan�ml�yoruz 
    void Sil(int sayi); // onceden klass i�i tan�ml�yoruz 
    //sil isimli fonksiyon silinecek de�eri ve kok� DugumSil isimli fonksiyona ge�irsin
    void DugumSil(int, Agacdugum*&);
    //biz bu fonksiyonu silece�imiz d���me ula�mak i�in kullanaca��z
    //bir d���m silindi�inde alt a�ac� ba�layaca��m�z i�in sadece 
    //Agacdug�m tipinde bir i�aret�i de�il, 
    //bu yap�y� tutan i�aret�inin adresine i�aret ediyoruz
    //peki d���me ula��nca ne yapaca��z, tabiki silece�iz:
    void GercekleSil(Agacdugum*&);
    //d���m� ortadan kald�r�p alt a�ac� ba�layacak
    
               
    
       
        
};


/*------------------------------------ Eleman Sayma Denemesi Ba�lang�� ----------------------- */  
        
/*------------------------------------ Eleman Sayma Denemesi Son ----------------------- */  
/*------------------------------------T�m A�ac� Silme Denemesi Ba�lang�� ----------------------- */  
        
void IkiliAgac::temizleyici(){ // Class�n i�indeki fonksiyonu :: ile al�p tan�ml�yorum
		Agacdugum* silicidugum; // class i�i structure a ba�l� yeni bir dugum olu�turuyorum 
		silicidugum = new Agacdugum; // nesne 
		silicidugum = NULL; // sonra bunun hi�bir yeri i�aret etmemesini sa�l�yorum 
		
		kok = silicidugum; /* ard�ndan bu d���m� k�k'e e�itliyorum. Dolay�s�yla k�k de hi�biryeri i�aret etmiyor. 
		Ben de tam olarak ne yapt���m� bilmiyorum, bu durumda elemanlar�n hala bellekte tutuluyor olmas� ancak i�aret edilemiyor olmas� gerekir. yani yanl��. 
		Ama kok'� null yapt���m�z bir sonraki alt eleman k�k olacak sonra o da null olacak sonra bir sonraki alt eleman null olacak bu �ekilde bu �ekilde giderken
		a�a�ta bitanecik eleman kal�cak yani k�k� kalm�� olacak en sonunda o da null olmu� olacak ve de�erler bellekte kalsa bile hi�bir yer i�aret edilmiycek. */
				
					}

/*------------------------------------ T�m A�ac� Silme Denemesi Son ----------------------- */  
 

void IkiliAgac::dugumEkle(int sayi) // class i�i fonksiyon 
{
    Agacdugum* yenidugum,//yeni d���m� i�aret edecek 
    * dugumPtr; //a�ac� dola�acak (�nceden pBas ile dola�m��t�k.) 
    yenidugum = new Agacdugum; // nesne 
    yenidugum->deger = sayi; // yeni du�umun de�erini atama 
    yenidugum->sol = yenidugum->sag = NULL; // sol'unu ve sa��n� bo� yapt�k

    if (!kok)//a�a� bo� mu?, bo�sa:
        kok = yenidugum;
    else
    { //k�k'�n adresini a�ac� dola�acak i�aret�iye atayal�m
        dugumPtr = kok;
        while (dugumPtr != NULL) //a�a�ta d���m bulundu�u s�rece
        {
            if (sayi < dugumPtr->deger)  // buradaki yap� a�a� prensibi ile ilgili yeni eklenecek eleman kendi �st eleman�ndan b�y�kse sa�a, k���kse sola atan�r.
            {
                if (dugumPtr->sol) // bu durumda �st d���m daha b�y�k oldu�u i�in sola atama ger�ekle�ir 
                    dugumPtr = dugumPtr->sol;
                else // de�ilse 
                {
                    dugumPtr->sol = yenidugum;
                    break; // d�ng�den ��kmak i�in 
                }
            }
            else if (sayi > dugumPtr->deger) // buradaki yap� a�a� prensibi ile ilgili yeni eklenecek eleman kendi �st eleman�ndan b�y�kse sa�a, k���kse sola atan�r.
            {
                if (dugumPtr->sag) // bu durumda �st d���m daha k���k oldu�u i�in sa�a atama ger�ekle�ir 
                    dugumPtr = dugumPtr->sag;
                else { // de�ilse 
                    dugumPtr->sag = yenidugum;
                    break; // d�ng�den ��kmak i�in 
                }
            }//else if sonu
            else
            {
                cout << "Agacta deger iki defa bulundu"; // ekrana bast�r 
                break; // ��k 
            }

        }//while sonu

    }//else sonu

}//fonksiyon sonu

void IkiliAgac::InOrderDolasim(Agacdugum* dugumPtr) // class i�i fonksiyon 
{//sol-k�k-sa�
    if (dugumPtr)
    {
        InOrderDolasim(dugumPtr->sol); // sol alt a�aca git ve varsa in order dola�. 
        cout << dugumPtr->deger << endl; // k�k d���m� i�le 
        InOrderDolasim(dugumPtr->sag); // sa� alt a�aca git 
    }
}

void IkiliAgac::PreOrderDolasim(Agacdugum* dugumPtr)
{//k�k-sol-sa�
    if (dugumPtr)
    {
        cout << dugumPtr->deger << endl; // k�k d���m� i�le 
        PreOrderDolasim(dugumPtr->sol); // sol alt a�aca git ve varsa in order dola�. 
        PreOrderDolasim(dugumPtr->sag); // sa� alt a�aca git
    }
}

void IkiliAgac::PostOrderDolasim(Agacdugum* dugumPtr)
{//sol-sa�-k�k
    if (dugumPtr)
    {
        PostOrderDolasim(dugumPtr->sol); // sol alt a�aca git ve varsa in order dola�. 
        PostOrderDolasim(dugumPtr->sag); // sa� alt a�aca git
        cout << dugumPtr->deger << endl; // k�k d���m� i�le 
    }
}

//*****
bool IkiliAgac::DugumAra(int sayi) // class i�i d���m arama fonksiyonu 
{
    Agacdugum* dugumPtr = kok; // ilk �nce de�eri k�kte ar�yoruz 
    while (dugumPtr)
    {
        if (dugumPtr->deger == sayi) // k�k'de bu de�er varsa 
            return true; // true de�erini d�nd�r 
        else if (sayi < dugumPtr->deger) // k�k'de bu de�er yok ise 
            dugumPtr = dugumPtr->sol; // sola bak 
        else // solda da yoksa 
            dugumPtr = dugumPtr->sag; // sa�a bak 
    }
    return false; // hi�bir yerde yoksa false de�erini d�nd�r 
}
//*****
void IkiliAgac::Sil(int sayi) // Main i�inde Nesne olu�turup buraya g�ndericez.
{
    DugumSil(sayi, kok); // buradan da k�ke ula�acak.
}
//****
void IkiliAgac::DugumSil(int num, Agacdugum*& dugumPtr)
{//biz bu fonksiyonu silece�imiz d���me ula�mak i�in kullanaca��z
    //bir d���m silindi�inde alt a�ac� ba�layaca��m�z i�in sadece 
    //Agacdug�m tipinde bir i�aret�i de�il, 
    //bu yap�y� tutan i�aret�inin adresine i�aret ediyoruz
    //peki d���me ula��nca ne yapaca��z, tabiki silece�iz:
    if (num < dugumPtr->deger)//say� solda m� diye bakal�m
        DugumSil(num, dugumPtr->sol);
    else if (num > dugumPtr->deger)//sayi sa�da m� diye bakal�m
        DugumSil(num, dugumPtr->sag);
    else //say�ya ula�t���m�zda silme i�lemini ger�ekleyelim
        GercekleSil(dugumPtr);
}

void IkiliAgac::GercekleSil(Agacdugum*& dugumPtr) // E�er a�a�ta olmayan bir d���m silinmeye �al���l�r ise program hata verir bu fonksiyonu o y�zden yapt�k. 
{
    Agacdugum* temp; //sol alt a�ac� g�sterecek olan gecici i�aret�i
    
    if (dugumPtr == NULL) // bo� ise 
        cout << "Bos dugumu silemezsin.\n"; // ekrana bast�r 
    else if (dugumPtr->sag == NULL) // sa� bo� ise 
    {
        temp = dugumPtr;
        dugumPtr = dugumPtr->sol; // sol �ocu�u yeniden atayal�m
        delete temp;
    }//else if sonu
    else if (dugumPtr->sol == NULL) // sol bo� ise 
    {
        temp = dugumPtr;
        dugumPtr = dugumPtr->sag; // sol �ocu�u yeniden atayal�m
        delete temp;
    }//else sonu
    // dug�m�m iki �ocu�u var ise : 
    else
    {
        
        temp = dugumPtr->sag; // 1 d�g�m sa�a ta��yal�m.
        
        while (temp->sol) // sol d���m�n sonuna gidelim.
            temp = temp->sol;
        
        temp->sol = dugumPtr->sol; // Sol alta�ac� yeniden atayal�m.
        temp = dugumPtr;
        
        dugumPtr = dugumPtr->sag; // Sa� alta�ac� yeniden atayal�m.
        delete temp;
    }//else sonu
}//fonksiyon sonu




/* --------------------Buras� �kili A�a� Binary Tree i�in Ana men�deki 4 numaral� k�s�m�n Sonu --------------------------   */
/* --------------------Buras� ��rp�lama Hash Tablosu i�in Ana men�deki 5 numaral� k�s�m�n Ba�lang�c� --------------------------   */

// constant�m� en �ste koydum 10 olarak. 

class Dugum { // class tan�ml�yoruz 
public: // herkese a��k yap�yoruz 

//-------------------- Node d���m yap�m�z ------------

    int Anahtar; //�nceden veri diyorduk �imdi anahtar olarak adland�r�yoruz. ��nk� bu veriye ula��rsak devam�nda bar�nd�rd��� verilere de ula�aca��z. 
    Dugum* pSonraki; // bir sonraki d���m�n verisini i�aret eden i�aret�i.  
    
//-------------------- Node d���m yap�m�z ------------    
    
	Dugum(int Anahtar) // Constructorumuz 
    {
        this->Anahtar = Anahtar; // de�i�kenlerin kar��mamas� ad�na this kulland�k. 
        pSonraki = NULL; // ilk ba�ta herhangi bir yeri i�aret etmiycek.  
    }
    
};
class HashTable { // Hash Tablosu i�in gerekli s�n�f. 
public: // Herkese a��k yapt�k. 
    Dugum* Veri[MAX]; //pointer dizisi. yani dizi adres tutacak
    HashTable(); //kurucu fonksiyon
    void Ekle(int Anahtar); //ba�l� listelerde eklememe i�lemi pek yok, o y�zden void
    Dugum* Bul(int Anahtar);//d���m� komple getirecek.d���m�n olmad���n� Null ile anlayaca��z
    void Sil(int Anahtar); // Silmek i�in kullanaca��m�z fonksiyonu s�n�f i�i tan�mlad�k. 
};

HashTable::HashTable() // Constructorumuz 
{
    for (int i = 0; i < MAX; i++) // Max = 10 ise 0-9 aras� 10 tane slotumuz var ve bu slotlardaki t�m veriler birbiriyle ba�lant�l�. En ba�taki null olursa devam� da null olur. 
        Veri[i] = NULL; // dolay�s�yla bu k�s�m ile program ilk �al��t���nda t�m tabloyu bo�altm�� olacak. 
}


void HashTable::Ekle(int Anahtar) // Eleman ekleyici Hash fonksiyonu 
{
    Dugum* pYeni = new Dugum(Anahtar); // yeni d���m
    int mod = Anahtar % MAX; // mod de�eri burada girilen eleman�n Max de�erine g�re modu al�nd�ktan sonra ��kan sonuca g�re diziye yerle�ecek indexin de�eri oluyor. 
    if (!Veri[mod]) //ilgili h�crede bir adres var m�
    {//e�er varsa oaryaa ba�l� bir ba�l� liste var demektir
        Veri[mod] = pYeni;
        return;
    }
    //buraya geldiysek ba�l� liste var:
    Dugum* pTemp = Veri[mod];//ilgili indisteki adres bilgisini pTemp'e ataca��z.
    while (pTemp->pSonraki != NULL)
    {//son elemana kadar gidece�iz. Liste konusunda g�rm��t�k
        pTemp = pTemp->pSonraki;
    }
    pTemp->pSonraki = pYeni;//son d���me yeni d���m� ekleyebiliriz.
}
Dugum* HashTable::Bul(int Anahtar)
{
    int mod = Anahtar % MAX;
    Dugum* pTemp = Veri[mod];
    while (pTemp != NULL)
    {//d�ng� burada d���m�n kendisini kontrol edecek
        if (pTemp->Anahtar == Anahtar)//arad���m�z anahtar buysa adres d�necek
            return pTemp;
        pTemp = pTemp->pSonraki;
    }
    //listede arad���m�z� bulamad�k
    return NULL;
}

void HashTable::Sil(int Anahtar)//Kapal� adresleme y�ntemi kullanaca��z
{//Ba�l� listelere benziyor
    int mod = Anahtar % MAX;
    //ilk durum hi� eleman�n(d���m�n) olmad��� durum
    if (!Veri[mod]) //Hi� bir eleman�n olmad��� durum
    {
        return;
    }
    //buraya geldiysek en az 1 d���m var
    //ilk d���m� ��karmaya �al��aca��z:
    if (!Veri[mod]->pSonraki) //tek d���m olma durumudur
    {
        if (Veri[mod]->Anahtar == Anahtar)
        {//tamam 1 d���m var ama bu benim arad���m d���m m�.
        //E�er �yle ise bu tek d���m� silelim
            delete Veri[mod]; //silicem ama yeterli de�il, ��nk� adresini silmedik
            Veri[mod] = NULL; //NULL yapmazsam haf�za hatas�yla kar��la��r�m,
             //��nk� orada d���m var zannedecek
        }
        return; //arad���m�z d���mse veya de�ilse her iki durumda da i�lemi bitiriyoruz
    }
    //buraya geldiysek birden fazla d���m var demektir.
    //Birden fazla eleman�n(d���m�n) olmas� durumu:
    if (Veri[mod]->Anahtar == Anahtar)
    {//birden fazla d���m var ama ilk d���m arad���m�z d���m ve silece�iz
    //ilk d���m silece�iz, dolay�s�yla ba�l� olan sonraki d���me ba�lanmal�y�
        Dugum* pDon = Veri[mod]->pSonraki;//silinen d���me ba�l� olan d���me ula�amazd�k
        delete Veri[mod]; //silinen d���m, �imdi ona ba�l� olan d���me ba�lanal�m:
        Veri[mod] = pDon;
        return;
    }
    //tek bir durum kald�: arad���m�z d���m arada bir yerde
    //Listelerdeki aradan ��karmaya benziyor.
    Dugum* pTemp = Veri[mod];//�ncelikle ilk d���m�n adresini al�yorum pTemp i�erisine.
    while (pTemp->pSonraki != NULL)//son d���me gidecek kadar bir d�ng� yap�yoruz
    {
        if (pTemp->pSonraki->Anahtar == Anahtar)
        {//��karaca��m�z d���mden �nceki d���m�n adresini bilmemiz gerekecek
            Dugum* pDon = pTemp->pSonraki; //d���m�n adresini yedekliyoruz
            pTemp->pSonraki = pDon->pSonraki;//sonraki d���me ba�l�yoruz
            delete pDon;//silmek istedi�imiz d���m� siliyoruz
            return;//silme i�lemi ger�eklendi�ine g�re return
        }//ilk d���m de�ilse while ile sonraki d���me ge�ece�iz:
        pTemp = pTemp->pSonraki;
    }
    //buraya geldiysek silinecek d���m yok demektir.
}

/* --------------------Buras� ��rp�lama Hash Tablosu i�in Ana men�deki 5 numaral� k�s�m�n Sonu --------------------------   */
/* -------------------- 6 Numaral� K�s�m ��k��-Exit i�in herhangi �zel bir kod bulunmamaktad�r --------------------------   */
/* ------------------------------------------------- MA�N FONKS�YONUNA G�R�� !!!!!!!-------------------------------------- */


int main() {
   setlocale(LC_ALL, "Turkish"); // LC_ALL diyerek t�m koddaki t�rk�e karakterleri g�r�nt�lenebilir yapt�k. LC_TIME vb. gibi farkl� kullan�mlar� mevcuttur. 
   
   int genel, deger, deger3, yigin, kuyruk, liste, ekleliste, cikarliste; // switch case i�in gerekli de�erler 
   
   /* Agac icin global degerler */  int agac_secim; IkiliAgac Agac; int agac_dugum_eleman_ekle; int agac_dugum_eleman_sil; int agac_eleman_sayici = 0; 
   
   /* Hash icin global degerler */  int cirpi_secim; int cirpi_dugum_eleman_ekle; int cirpi_dugum_eleman_sil; HashTable h;
 
  
/*   Ana menu text */      
   
   
    do {  // Programdan 6 tu�una bas�l�nca ��k�� yap�lmas� i�in do-while ile ��z�m �rettim 

     cout<<"1) Y���n Uygulamas�"<<endl; // aray�z 
     cout<<"2) Kuyruk Uygulamas�"<<endl; // aray�z 
     cout<<"3) Tek Y�nl� Ba�l� Liste Uygulamas�"<<endl; // aray�z 
     cout<<"4) �kili A�a� (Binary Tree) Uygulamas�"<<endl; // aray�z 
     cout<<"5) ��rp�lama Hash Uygulamas� (Tek Y�nl� Kuyruk Linked List Dizisi)"<<endl;  // aray�z 
     cout<<"6) Programdan ��k�� "<<endl;     // aray�z 
   
	  cout<<"Ana Men�de Yapmak istedi�iniz i�lemin numaras�n� tu�lay�n�z (1-6 aras�): "<<endl; // aray�z 
    
   
    
      cin>>genel;  // switch case i�in de�er giri�i 
      switch(genel) { // switch yap�s� 
      

/*  ---------------------------------- �kili A�a� K�sm� Ba�lang�� Case 4 --------------------- */  
         
		 
		 case 4: { // 4 tu�una bas�l�r ise yap�lacaklar 
            			            
            
                // Binary Tree �kili Agac Men� Text 		 
	 	  
            
              do{ // do - while yap�s� 
              
                    cout<<"1) Agaca Eleman Ekle"<<endl; // aray�z 
                    cout<<"2) Agactan Eleman Sil/��kar"<<endl; // aray�z 
                    cout<<"3) Agaci Temizle"<<endl; // aray�z 
                    cout<<"4) Agactaki Eleman Say�s�n� G�ster"<<endl; // aray�z 
                    cout<<"5) Agaci In Order Dola�arak Elemanlar� G�ster"<<endl; // aray�z 
                    cout<<"6) Agaci Pre Order Dola�arak Elemanlar� G�ster"<<endl; // aray�z 
                    cout<<"7) Agaci Post Order Dola�arak Elemanlar� G�ster"<<endl; // aray�z 
                    cout<<"8) Ana Men�ye Geri D�n "<<endl; // aray�z 
			   
              cout<<"�kili A�a� (Binary Tree) Uygulamas�nda Yapmak istedi�iniz i�lemin numaras�n� tu�lay�n�z (1-8 aras�): "<<endl; // aray�z 
              
			  cin>>agac_secim; // kullan�c�dan veri giri�i bekleniyor 
              switch(agac_secim) { // switch yap�s� 
              
               case 1: // i� i�e switch case, 1 tu�una bas�l�r ise yap�lacaklar 
			    {
			
			    cout << "A�aca Eklenecek Eleman�n de�erini giriniz" <<endl;   // aray�z 
			    
				cin>>agac_dugum_eleman_ekle; // veri giri�i bekleniyor   
			    Agac.dugumEkle(agac_dugum_eleman_ekle); // a�aca eleman ekleme fonksiyonu 
			    
			    cout << " " <<endl; // aray�z 
			    cout << "Eleman Eklenmi�tir." <<endl; // aray�z 
			    
			    agac_eleman_sayici++; // bir yandan da elemanlar�n say�s�n� takip ediyoruz. 
            
               	break; }
                       
               case 2: // 2 ye bas�l�r ise 
			    {
			    	    cout << "In Order Dola��m ile A�a�taki T�m Elemanlar�n de�eri:" << endl; // aray�z 
                        Agac.InOrderDugumGoster(); // eleman silmeden �nceki hali 
			    	
			     cout << "A�actan Silinecek Eleman�n de�erini giriniz" <<endl; // aray�z
			     
			     cin>>agac_dugum_eleman_sil; // silinecek eleman�n veri giri�i bekleniyor 
			     
			     if (Agac.DugumAra(agac_dugum_eleman_sil)){ // ilk �nce o eleman a�a�ta var m� diye ar�yoruz
				 
			     Agac.Sil(agac_dugum_eleman_sil); // sonra var ise true de�er d�n�yor ve eleman siliniyor. 
			     cout<<"Bu eleman� ba�ar� ile sildiniz"<<endl;} // aray�z 
			      
			     else { // o eleman yok ise 
                 cout<<"A�a�ta olmayan bir eleman�/de�eri silemezsiniz"<<endl;} // bunu diyor 
                 
                 
                 		cout << " A�a�taki Eleman Silindikten Sonra In Order Dola��m ile A�a�taki T�m Elemanlar�n de�eri:" << endl; // ve i�lem sonras� a�a� hali 
                        Agac.InOrderDugumGoster(); // g�ster 
			      
			      			      
			      agac_eleman_sayici--;  // sayac� eksiltmeyi unutmuyoruz 
               	
               break; }
               
               case 3:
			    {
			    				    	

			    	Agac.temizleyici(); // a�a� temizleyici fonksiyon 
			    	
			    	agac_eleman_sayici = 0;  // sayac� s�f�rlamay� da unutmuyoruz 
			    	
			    	cout << "A�a� Temizlenmi�tir"<<endl;  // aray�z 
               	
               break; }
               
               case 4: // 4' e bas�l�r ise 
			    {
			    	 
             
                 cout << "Agactaki Eleman Sayisi:  " << agac_eleman_sayici <<endl; // elemanlar�n say�s�n� verir 
				           	
               break; }
               
               case 5: // 5'e bas�l�r ise 
			    {
			    	 
			   	    cout << "In Order Dola��m ile A�a�taki Elemanlar" << endl; // aray�z 
                    Agac.InOrderDugumGoster(); // g�sterici fonksiyon 
               	
               break; }
               
                
				case 6: // 6'ya bas�l�r ise 
			    {
			    	 
			        cout << "Pre Order Dola��m ile A�a�taki Elemanlar" << endl; // aray�z 
			        Agac.PreOrderDugumGoster(); // g�sterici fonksiyon 
               	
               break; }
               
               
                case 7: // 7'ye bas�l�r ise 
			    {
			    	 
			        cout << "Post Order Dola��m ile A�a�taki Elemanlar" << endl; // aray�z 
			        Agac.PostOrderDugumGoster(); // g�sterici fonksiyon 
               	
               break; }
               
               
               
               case 8: // 8'e bas�l�r ise 
			    {
			    	 
			    	cout<<"Ana men�ye geri d�nd�n�z "<<endl; // aray�z 
               	
               break; }
               
               
            default: { // hatal� de�er girilir ise 
            	
            cout<<"Yanl�� Numara, L�tfen 1 ile 8 aras�nda bir de�er tu�lay�n�z"<<endl; // aray�z 
            break;}
                    
			  
			  }
			  
		} while(agac_secim !=8); // d�ng�den ��kar 
         	            
        
		
		    
            break;
         }
         
/*  ---------------------------------- �kili A�a� K�sm� Son Case 4 --------------------- */ 
/*  ---------------------------------- ��rp�lama Hash K�sm� Ba�lang�� Case 5 --------------------- */  
         
		 
		 case 5: { // 5'e bas�l�r ise 
            
            
                    // Tablo Men� Text 		 
	 	          
              do{
              
                    cout<<" "<<endl;  // aray�z             
                    cout<<"1) Tabloya Eleman Ekle"<<endl; // aray�z 
                    cout<<"2) Tablodan Eleman Sil/��kar"<<endl; // aray�z 
                    cout<<"3) Tabloyu Temizle"<<endl; // aray�z 
                    cout<<"4) Tablodaki Eleman Say�s�n� G�ster"<<endl;  // aray�z 
                    cout<<"5) Tablodaki Elemanlar� G�ster"<<endl; // aray�z 
                    cout<<"6) Ana Men�ye Geri D�n "<<endl; // aray�z 

			   
              cout<<" Hash Tablosu Uygulamas�nda Yapmak istedi�iniz i�lemin numaras�n� tu�lay�n�z (1-6 aras�): "<<endl; // aray�z 
              
			  cin>>cirpi_secim; // kullan�c�dan veri giri�i bekleniyor 
              switch(cirpi_secim) { // switch yap�s� 
              
               case 1: // 1'e bas�l�r ise 
			    {
			
			    cout << "Tabloya eklemek istedi�iniz eleman�n de�erini giriniz"<<endl;  // aray�z 
			    cin>>cirpi_dugum_eleman_ekle; // veri giri�i 
			    h.Ekle(cirpi_dugum_eleman_ekle); // eleman ekleme fonksiyonu 
			    
			    cout << "Eleman Eklenmi�tir"<<endl;  // aray�z 
            
               	break; }
                       
               case 2: // 2'ye bas�l�r ise 
			    {
			    	
			        cout << "Tablodaki Elemanlar �unlard�r: (indis s�ralamas�na g�redir) "<<endl;  // aray�z 
			   
			   for (int i = 0; i <= 100000; i++) { // Maalesef 100000 e kadar olan elemanlar� bast�rabiliyor. Nas� bast�raca��m� tam olarak kavrayamad�m. 
			    Dugum* pTemp = h.Bul(i); // Constant Max'da ka� indis tan�mlanm�� ise oraya kadar gider. Ve t�m elemanlar� bulur. 
			            //d���mleri yazd�ral�m:
                        while (pTemp != NULL)
                    {
                    	
                    	
                        cout << pTemp->Anahtar << " ";
                        pTemp = pTemp->pSonraki;
                               }
                           } 
                   
				   cout << " "<<endl;         // aray�z 
                   cout << "��kartmak �stedi�iniz Eleman�n de�erini giriniz: "<<endl;    // aray�z 
				   cin>>cirpi_dugum_eleman_sil;     // veri giri�i  
				   h.Sil(cirpi_dugum_eleman_sil); // eleman silici fonksiyon 
				   				   
				   cout << "Eleman ��kart�lm��t�r"<<endl;  // aray�z 
                           
               	
               break; }
               
               case 3: //3'e bas�l�r ise 
			    {
			    	
			    	
			    for (int i = 0; i <= 100000; i++) {  // her�eyi siliyo 
			    	h.Sil(i); // silici fonksiyon 

                          }
			    	
			    	
			    	cout << "Tablo Temizlenmi�tir"<<endl;  // aray�z 
                    
               	
               break; }
               
               case 4: // 4'e bas�l�r ise 
			    {
			    	
			    	
			         int tablo_sayma = 0;
			   
			   for (int i = 0; i <= 100000; i++) {     // i <= MAX; b�yle idi normalde 
			    Dugum* pTemp = h.Bul(i); // Constant Max'da ka� indis tan�mlanm�� ise oraya kadar gider. Ve t�m elemanlar� bulur. 
			    
			            //d���mleri yazd�ral�m:
                        while (pTemp != NULL)
                    {
                        pTemp->Anahtar;

						tablo_sayma++;  
						
                        pTemp = pTemp->pSonraki;
                               }
                               
                               
                           }
                           
                if (tablo_sayma == 0){ // e�er 
                cout << "Tabloda Hi� Eleman Yoktur, Tablodaki Eleman Say�s�: 0 "<<endl; } // aray�z 
                else{ // de�ilse 
                cout << "Tablodaki Eleman Say�s�: " << tablo_sayma <<endl; }   // aray�z         
                           
               	
               break; }
               
               
               
               case 5: // 5'e bas�l�r ise 
			    {
			    
				
				if (0){}	
			    	
			    	
			   
			   else{	 
			   cout << "Tablodaki Elemanlar �unlard�r: (indis s�ralamas�na g�redir) "<<endl;  // aray�z 
			   
			   for (int i = 0; i <= 100000; i++) {
			    Dugum* pTemp = h.Bul(i); // Constant Max'da ka� indis tan�mlanm�� ise oraya kadar gider. Ve t�m elemanlar� bulur. 
			    
			            //d���mleri yazd�ral�m: 
                        while (pTemp != NULL) 
                    {
                        cout << pTemp->Anahtar << " ";
                        pTemp = pTemp->pSonraki;
                               }
                           }
                           
                       }
               	
               break; }
               
               
               
                
				      
               case 6: // 6'ya bas�l�r ise 
			    {
			    	 
			    	cout<<"Ana men�ye geri d�nd�n�z "<<endl; // aray�z 
               	
               break; }
               
               
            default: { // yanl�� de�er girilirse 
            	
            cout<<"Yanl�� Numara, L�tfen 1 ile 6 aras�nda bir de�er tu�lay�n�z"<<endl; // aray�z 
            break;}
                    
			  
			  }
			  
		} while(cirpi_secim !=6); // d�ng�den ��kar 
         	            
        
		
            
            
            
            break; // d�ng�y� k�rar 
         }
         
/*  ---------------------------------- ��rp�lama Hash K�sm� Son Case 5 --------------------- */ 
/*  ---------------------------------- Ana Men� Exit - ��k�� K�sm� Ba�lang�� Case 6 --------------------- */  
         
		 
		 case 6: {
            cout<<"��k�� yapt�n�z, konsol ekran�n� kapatmak i�in herhangi bir tu�a bas�n�z "<<endl; // aray�z 
            break;
         }
         
/*  ---------------------------------- Ana Men� Exit - ��k�� K�sm� Son Case 6 --------------------- */ 
/* -------------------------------------------- Ana men�deki Default yap�s� ba�lang�� ------------------------------- */ 
         
		 default: { // farkl� bi say�ya bas�l�rsa buras� m�dahale ediyor. 
            cout<<"Yanl�� Numara, L�tfen 4, 5 veya 6'y� tu�lay�n�z"<<endl;
         }
/* -------------------------------------------- Ana men�deki Default yap�s� son ------------------------------- */           
         
      }
   } 
     while(genel!=6); // ��k��� buras� sa�l�yo 
      return 0;  // main fonksiyonuna 0 yani false de�eri d�n�yor ve uygulama sonlanm�� oluyor.  
   }
   
/*--------------------------------- Son----------------------------- */     
/* Copyright Yi�italp Dikmen 2020 TM T�m Haklar� Sakl�d�r */   




