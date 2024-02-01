using System;
using System.Collections.Generic;

namespace Lista3_Obiektówka
{
    interface IZarzadzaniePozycjami
    {
        void ZnajdzPozycjePoTytule(string tytul);
        void ZnajdzPozycjePoId(int id);
        void WypiszWszystkiePozycje();
    }

    interface IZarzadzanieBibliotekarzami
    {
        void ZnajdzBibliotekarzaPoImieniu(string imie);
        void ZnajdzBibliotekarzaPoDacieZatrudnienia(string dataZatrudnienia);
    }
    class Katalog : IZarzadzaniePozycjami
    {
        private string _dzialTematyczny;
        List<Pozycja> pozycje = new List<Pozycja>();

        public Katalog()
        {
            _dzialTematyczny = "nieznany";
        }

        public Katalog(string dzialTematyczny)
        {
            _dzialTematyczny = dzialTematyczny;
        }

        public string dzialTematyczny
        {
            get { return _dzialTematyczny; }
            set { _dzialTematyczny = value; }
        }

        public void DodajPozycje(Pozycja poz)
        {
            pozycje.Add(poz);
        }

        public void ZnajdzPozycjePoTytule(string tytul)
        {
            for (int i = 0; i < pozycje.Count; i++)
            {
                if (pozycje[i].tytul == tytul)
                {
                    pozycje[i].WypiszInfo();
                }
            }

        }

        public void ZnajdzPozycjePoId(int id)
        {
            for (int i = 0; i < pozycje.Count; i++)
            {
                if (pozycje[i].id == id)
                {
                    pozycje[i].WypiszInfo();
                }
            }
        }

        public void WypiszWszystkiePozycje()
        {
            for (int i = 0; i < pozycje.Count; i++)
            {
                pozycje[i].WypiszInfo();
            }
        }

    }

    abstract class Pozycja
    {
        private string _tytul;
        private int _id;
        private string _wydawnictwo;
        private int _rokWydania;

        public Pozycja()
        {
            _tytul = "nieznany";
            _id = 0;
            _wydawnictwo = "nieznany";
            _rokWydania = 0;
        }

        public Pozycja(string tytul, int id, string wydawnictwo, int rokWydania)
        {
            _tytul = tytul;
            _id = id;
            _wydawnictwo = wydawnictwo;
            _rokWydania = rokWydania;
        }

        public string tytul
        {
            get { return _tytul; }
            set { _tytul = value; }
        }

        public int id
        {
            get { return _id; }
            set { _id = value; }
        }

        public string wydawnictwo
        {
            get { return _wydawnictwo; }
            set { _wydawnictwo = value; }
        }

        public int rokWydania
        {
            get { return _rokWydania; }
            set { _rokWydania = value; }
        }

        public abstract void WypiszInfo();
    }

    class Ksiazka : Pozycja
    {
        private int _liczbaStron;
        List<Autor> autorzy = new List<Autor>();

        public Ksiazka()
        {
            _liczbaStron = 0;
        }

        public Ksiazka(string tytul, int id, string wydawnictwo, int rokWydania, int liczbaStron) : base(tytul, id, wydawnictwo, rokWydania)
        {
            _liczbaStron = liczbaStron;
        }

        public void DodajAutora(Autor au)
        {
            autorzy.Add(au);
        }

        public override void WypiszInfo()
        {
            Console.WriteLine("Tytuł: " + tytul);
            Console.WriteLine("ID: " + id);
            Console.WriteLine("Wydawnictwo: " + wydawnictwo);
            Console.WriteLine("Rok wydania: " + rokWydania);
            Console.WriteLine("Liczba stron: " + _liczbaStron);
            for (int i = 0; i < autorzy.Count; i++)
            {
                Console.WriteLine("Autor: ");
                Console.WriteLine("Imie: " + autorzy[i].imie);
                Console.WriteLine("Nazwisko: " + autorzy[i].nazwisko);
                Console.WriteLine("---------------------------------");
            }
        }
    }

    class Autor : Osoba
    {
        private string _narodowosc;

        public Autor()
        {
            _narodowosc = "nieznane";
        }

        public Autor(string imie, string nazwisko, string narodowsc) : base(imie, nazwisko)
        {
            _narodowosc = narodowsc;
        }

        public string narodowosc
        {
            get { return _narodowosc; }
            set { _narodowosc = value; }
        }

    }

    class Czasopismo : Pozycja
    {
        private int _numer;

        public Czasopismo()
        {
            _numer = 0;
        }

        public Czasopismo(string tytul, int id, string wydawnictwo, int rokWydania, int numer) : base(tytul, id, wydawnictwo, rokWydania)
        {
            _numer = numer;
        }

        public int numer
        {
            get { return _numer; }
            set { _numer = value; }
        }

        public override void WypiszInfo()
        {
            Console.WriteLine("Tytuł: " + tytul);
            Console.WriteLine("ID: " + id);
            Console.WriteLine("Wydawnictwo: " + wydawnictwo);
            Console.WriteLine("Rok wydania: " + rokWydania);
            Console.WriteLine("Numer: " + _numer);
            Console.WriteLine("");
        }
    }

    class Osoba
    {
        private string _imie;
        private string _nazwisko;

        public Osoba()
        {
            _imie = "nieznane";
            _nazwisko = "nieznane";
        }

        public Osoba(string imie, string nazwisko)
        {
            _imie = imie;
            _nazwisko = nazwisko;
        }

        public string imie
        {
            get { return _imie; }
            set { _imie = value; }
        }

        public string nazwisko
        {
            get { return _nazwisko; }
            set { _nazwisko = value; }
        }
    }

    class Bibliotekarz : Osoba
    {
        private string _dataZatrudnienia;
        private double _wynagrodzenie;

        public Bibliotekarz()
        {
            _dataZatrudnienia = "nieznana";
            _wynagrodzenie = 0;
        }

        public Bibliotekarz(string imie, string nazwisko, string dataZatrudnienia, double wynagrodzenie) : base(imie, nazwisko)
        {
            _dataZatrudnienia = dataZatrudnienia;
            _wynagrodzenie = wynagrodzenie;
        }

        public string dataZatrudnienia
        {
            get { return _dataZatrudnienia; }
            set { _dataZatrudnienia = value; }
        }

        public double wynagrodzenie
        {
            get { return _wynagrodzenie; }
            set { _wynagrodzenie = value; }
        }
    }

    class Biblioteka : IZarzadzaniePozycjami, IZarzadzanieBibliotekarzami
    {
        private string _adres;
        List<Bibliotekarz> osoba = new List<Bibliotekarz>();
        List<Katalog> katalog = new List<Katalog>();

        public Biblioteka()
        {
            _adres = "nieznany";
        }

        public Biblioteka(string adres)
        {
            _adres = adres;
        }

        public string adres
        {
            get { return _adres; }
            set { _adres = value; }
        }

        public void DodajBibliotekarza(Bibliotekarz os)
        {
            osoba.Add(os);
        }

        public void WypiszBibliotekarzy()
        {
            for (int i = 0; i < osoba.Count; i++)
            {
                Console.WriteLine("Imie: " + osoba[i].imie);
                Console.WriteLine("Nazwisko: " + osoba[i].nazwisko);
                Console.WriteLine("Data zatrudnienia: " + osoba[i].dataZatrudnienia);
                Console.WriteLine("Wynagrodzenie: " + osoba[i].wynagrodzenie);
                Console.WriteLine("");
            }

        }

        public void DodajKatalog(Katalog kat)
        {
            katalog.Add(kat);
        }

        public void DodajPozycje(Pozycja p, string dzialTematyczny)
        {
            for (int i = 0; i < katalog.Count; i++)
            {
                if (katalog[i].dzialTematyczny == dzialTematyczny)
                {
                    katalog[i].DodajPozycje(p);
                }
            }
        }

        public void ZnajdzPozycjePoTytule(string tytul)
        {
            for (int i = 0; i < katalog.Count; i++)
            {
                katalog[i].ZnajdzPozycjePoTytule(tytul);
            }
        }

        public void ZnajdzPozycjePoId(int id)
        {
            for (int i = 0; i < katalog.Count; i++)
            {
                katalog[i].ZnajdzPozycjePoId(id);
            }
        }

        public void WypiszWszystkiePozycje()
        {
            for (int i = 0; i < katalog.Count; i++)
            {
                katalog[i].WypiszWszystkiePozycje();
            }
        }

        public void ZnajdzBibliotekarzaPoImieniu(string imie)
        {
            for (int i = 0; i < osoba.Count; i++)
            {
                if (osoba[i].imie == imie)
                {
                    Console.WriteLine("Imie: " + osoba[i].imie);
                    Console.WriteLine("Nazwisko : " + osoba[i].nazwisko);
                    Console.WriteLine("Data zatrudnienia: " + osoba[i].dataZatrudnienia);
                    Console.WriteLine("Wynagrodzenie: " + osoba[i].wynagrodzenie);
                }
            }
        }

        public void ZnajdzBibliotekarzaPoDacieZatrudnienia(string dataZatrudnienia)
        {
            for (int i = 0; i < osoba.Count; i++)
            {
                if (osoba[i].dataZatrudnienia == dataZatrudnienia)
                {
                    Console.WriteLine("Imie: " + osoba[i].imie);
                    Console.WriteLine("Nazwisko : " + osoba[i].nazwisko);
                    Console.WriteLine("Data zatrudnienia: " + osoba[i].dataZatrudnienia);
                    Console.WriteLine("Wynagrodzenie: " + osoba[i].wynagrodzenie);
                }
            }
        }

        public void ZnajdzBibliotekarzaPoWynagrodzeniu(double wynagrodzenie)
        {
            for (int i = 0; i < osoba.Count; i++)
            {
                if (osoba[i].wynagrodzenie == wynagrodzenie)
                {
                    Console.WriteLine("Imie: " + osoba[i].imie);
                    Console.WriteLine("Nazwisko : " + osoba[i].nazwisko);
                    Console.WriteLine("Data zatrudnienia: " + osoba[i].dataZatrudnienia);
                    Console.WriteLine("Wynagrodzenie: " + osoba[i].wynagrodzenie);
                }
            }
        }
    }


    internal class Program
    {
        static void Main(string[] args)
        {
            //Zadanie 1
            Console.WriteLine("Zadanie 1");
            Pozycja ksiazka = new Ksiazka("Super tytul", 1, "Wydawnictwo Ksiazek", 2021, 200);
            Pozycja czasopismo = new Czasopismo("Czasopismo jakies", 1, "Wydawnictwo Czasopism", 2022, 20);
            Katalog katalog = new Katalog("Katalog_nazwa");
            katalog.DodajPozycje(ksiazka);
            Console.WriteLine(katalog.dzialTematyczny);
            ksiazka.WypiszInfo();
            czasopismo.WypiszInfo();
         

            //zadanie 2
            Console.WriteLine("Zadanie 2");
            Biblioteka biblioteka = new Biblioteka("Nazwa Bibliteki");
            Bibliotekarz b = new Bibliotekarz("Anna", "Kowalska", "05.04.2000", 3000); ;
            Bibliotekarz b2 = new Bibliotekarz("Jan", "Nowak", "02.05.1985", 2500);
            biblioteka.DodajBibliotekarza(b);
            biblioteka.DodajBibliotekarza(b2);
            biblioteka.WypiszBibliotekarzy();
            

            Katalog katalog1 = new Katalog("fantasy");

            biblioteka.DodajKatalog(katalog1);

            Autor autor1 = new Autor("Dawid", "Robak", "Polska");
            Autor autor2 = new Autor("George", "Johnson", "Anglia");

            Ksiazka ksiazka1 = new Ksiazka("Tutul Dawida", 2, "dwd", 2012, 4221);

            Pozycja pozycja = ksiazka1;
            Ksiazka ksiazka2 = new Ksiazka("Tutul Georga", 3, "grg", 1999, 5231);
            Pozycja pozycja2 = new Czasopismo("Super", 4, "hwh", 2002, 50);

            ksiazka1.DodajAutora(autor1);
            ksiazka2.DodajAutora(autor2);

            pozycja.WypiszInfo();
            ksiazka1.DodajAutora(autor2);
            pozycja.WypiszInfo();

            katalog1.DodajPozycje(pozycja);
            katalog1.WypiszWszystkiePozycje();

            biblioteka.DodajPozycje(pozycja2, "pozycja");
            biblioteka.ZnajdzPozycjePoTytule("Tutul Georga");
            biblioteka.ZnajdzPozycjePoId(2);
            biblioteka.WypiszWszystkiePozycje();
            Console.WriteLine("\n");

            biblioteka.ZnajdzBibliotekarzaPoImieniu("Jan");
            biblioteka.ZnajdzBibliotekarzaPoDacieZatrudnienia("05.04.2000");
            biblioteka.ZnajdzBibliotekarzaPoWynagrodzeniu(3000);

            Console.WriteLine("Aplikacja konsolowa zakończona. Naciśnij Enter, aby zamknąć konsolę.");
            Console.ReadLine();
        }
    }
}
