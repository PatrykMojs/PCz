using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_6
{
    class Zwierze
    {
        private string pozywienie;
        private int wiek;
        private string pochodzenie;

        public string Pozywienie
        {
            get { return pozywienie; }
            set { pozywienie = value; }
        }
        public int Wiek
        {
            get { return wiek; }
            set { wiek = value; }
        }
        public string Pochodzenie
        {
            get { return pochodzenie; }
            set { pochodzenie = value; }
        }

        public Zwierze()
        {
            this.pozywienie = " ";
            this.wiek = 0;
            this.pochodzenie = " ";
        }
        public Zwierze(string pozywienie, int wiek, string pochodzenie)
        {
            this.pozywienie = pozywienie;
            this.wiek = wiek;
            this.pochodzenie = pochodzenie;
        }

        public virtual void WypiszInfo()
        {
            Console.WriteLine($"Pożywienie: {pozywienie}\nWiek: {wiek}\nPochodzenie: {pochodzenie}");
        }
    }

    class Ssak : Zwierze
    {
        private string srodowisko;

        public string Srodowisko
        {
            get { return srodowisko; }
            set { srodowisko = value; }
        }

        public Ssak() : base()
        {
            this.srodowisko = " ";
        }

        public Ssak(string pozywienie, int wiek, string pochodzenie, string srodowisko) :
            base(pozywienie, wiek, pochodzenie)
        {
            this.srodowisko = srodowisko;
        }

        // Dziedziczy z klasy zwierze WypiszInfo()
        // this.GetType().name to nazwa klasy, żeby było wiadomo jaki gatunek
        public override void WypiszInfo()
        {
            Console.WriteLine($"\n{this.GetType().Name}");
            base.WypiszInfo();
            Console.WriteLine($"Naturalne środowisko: {srodowisko}");
        }
    }

    class Gad : Zwierze
    {
        private bool trujacy;

        public bool Trujacy
        {
            get { return trujacy; }
            set { trujacy = value; }
        }

        public Gad() : base()
        {
            this.trujacy = false;
        }

        public Gad(string pozywienie, int wiek, string pochodzenie, bool trujacy) :
            base(pozywienie, wiek, pochodzenie)
        {
            this.trujacy = trujacy;
        }

        // Dziedziczy z klasy zwierze WypiszInfo()
        // this.GetType().name to nazwa klasy, żeby było wiadomo jaki gatunek
        public override void WypiszInfo()
        {
            Console.WriteLine($"\n{this.GetType().Name}");
            base.WypiszInfo();
            Console.WriteLine($"Trujący: {trujacy}");
        }
    }

    class Ptak : Zwierze
    {
        private double rozpietoscSkrzydel;
        private int wytrzymalosc;

        public double RozpietoscSkrzydel
        {
            get { return rozpietoscSkrzydel; }
            set { rozpietoscSkrzydel = value; }
        }
        public int Wytrzymalosc
        {
            get { return wytrzymalosc; }
            set { wytrzymalosc = value; }
        }

        public Ptak() : base()
        {
            this.rozpietoscSkrzydel = 0.0;
            this.wytrzymalosc = 0;
        }

        public Ptak(string pozywienie, int wiek, string pochodzenie, double rozpietoscSkrzydel, int wytrzymalosc) :
            base(pozywienie, wiek, pochodzenie)
        {
            this.rozpietoscSkrzydel = 0.0;
            this.wytrzymalosc = 0;
        }

        // Dziedziczy z klasy zwierze WypiszInfo()
        // this.GetType().name to nazwa klasy, żeby było wiadomo jaki gatunek
        public override void WypiszInfo()
        {
            Console.WriteLine($"\n{this.GetType().Name}");
            base.WypiszInfo();
            Console.WriteLine($"Rozpiętość skrzydeł: {rozpietoscSkrzydel}\nWytrzymałość: {wytrzymalosc}");
        }
    }

    class Opiekun
    {
        private List<Klatka> klatki = new List<Klatka>();

        private string imie;
        private string nazwisko;
        private string dataUrodzenia;
        private string dataZatrudnienia;

        // Gettery i settery
        public string Imie
        {
            get { return imie; }
            set { imie = value; }
        }
        public string Nazwisko
        {
            get { return nazwisko; }
            set { nazwisko = value; }
        }
        public string DataUrodzenia
        {
            get { return dataUrodzenia; }
            set { dataUrodzenia = value; }
        }
        public string DataZatrudnienia
        {
            get { return dataZatrudnienia; }
            set { dataZatrudnienia = value; }
        }

        public Opiekun()
        {
            this.imie = " ";
            this.nazwisko = " ";
            this.dataUrodzenia = " ";
            this.dataZatrudnienia = " ";
        }

        public Opiekun(string imie, string nazwisko, string dataUrodzenia, string dataZatrudnienia)
        {
            this.imie = imie;
            this.nazwisko = nazwisko;
            this.dataUrodzenia = dataUrodzenia;
            this.dataZatrudnienia = dataZatrudnienia;
        }

        // Przypisujemy opiekunowi klatkę
        public void PrzypiszKlatke(Klatka k)
        {
            klatki.Add(k);
        }

        // Podajemy klatkę do wyczyszczenia
        public void WyczyscKlatke(Klatka k)
        {
            k.Czysta = true;
        }


        // Wypisuje info o osobach oraz jakimi klatkami się zajmują
        public void WypiszInfo()
        {
            Console.WriteLine($"Imie: {imie}\nNazwisko: {nazwisko}\n" +
                $"Data urodzenia: {dataUrodzenia}\nData zatrudnienia: {dataZatrudnienia}");
            Console.WriteLine("Klatki należące do tej osoby:");
            foreach (Klatka k in klatki)
            {
                Console.WriteLine($"ID klatki: {k.Id}");
            }
        }
    }

    class Klatka
    {
        private List<Zwierze> zwierzeta = new List<Zwierze>();

        private int pojemnosc;
        private int id;
        private bool czysta;

        public int Pojemnosc
        {
            get { return pojemnosc; }
            set { pojemnosc = value; }
        }
        public int Id
        {
            get { return id; }
            set { id = value; }
        }
        public bool Czysta
        {
            get { return czysta; }
            set { czysta = value; }
        }

        public Klatka()
        {
            this.pojemnosc = 0;
            this.id = 0;
            this.czysta = true;
        }

        public Klatka(int pojemnosc, int id, bool czysta)
        {
            this.pojemnosc = pojemnosc;
            this.id = id;
            this.czysta = czysta;
        }

        // Sprawdza czy jest miejsce w klatce, jeżeli nie ma to daje kominukat
        // w przeciwnym razie dodaje zwierze
        public void DodajZwierze(Zwierze z)
        {
            if (zwierzeta.Count >= pojemnosc)
            {
                Console.WriteLine("Klatka jest pełna");
            }
            else
            {
                zwierzeta.Add(z);
            }
        }

        // Wypisuje informacje o klatce oraz zwierzętach w tej klatce
        public void WypiszInfo()
        {
            Console.WriteLine($"\nID: {id}\nPojemność: {pojemnosc}\nCzysta?: {czysta}");
            Console.WriteLine("Zwierzęta w tej klatce:");
            for (int i = 0; i < zwierzeta.Count; i++)
            {
                zwierzeta[i].WypiszInfo();
            }
        }
    }

    class Zoo
    {
        private List<Klatka> klatki = new List<Klatka>();
        public List<Opiekun> pracownicy = new List<Opiekun>();

        private string nazwa;

        public string Nazwa
        {
            get { return nazwa; }
            set { nazwa = value; }
        }

        public Zoo()
        {
            this.nazwa = " ";
        }

        public Zoo(string nazwa)
        {
            this.nazwa = nazwa;
        }

        public void DodajKlatke(Klatka k)
        {
            klatki.Add(k);
        }

        public void DodajKlatke(int pojemnosc, int id, bool czysta)
        {
            Klatka k = new Klatka(pojemnosc, id, czysta);
            klatki.Add(k);
        }

        public void ZatrudnijPracownika(Opiekun o)
        {
            pracownicy.Add(o);
        }

        // Poszukuje podanej klatki i zwiększa jej rozmiar
        public void ZwiekszRozmiarKlatki(Klatka k, int rozmiar)
        {
            for (int i = 0; i < klatki.Count; i++)
            {
                if (klatki[i] == k)
                {
                    klatki[i].Pojemnosc += rozmiar;
                }
            }
        }

        // Poszukuje klatki po podanym id i zwiększa jej rozmiar
        public void ZwiekszRozmiarKlatki(int id, int rozmiar)
        {
            for (int i = 0; i < klatki.Count; i++)
            {
                if (klatki[i].Id == id)
                {
                    klatki[i].Pojemnosc += rozmiar;
                }
            }
        }

        // Wypisuje info o klatkach oraz o zwierzętach w nich
        public void WypiszInfoKlatki()
        {
            foreach (Klatka k in klatki)
            {
                k.WypiszInfo();
                Console.WriteLine("------------");
            }
        }

        // Wypisuje informacje o pracownikach
        public void WypiszInfoPracownicy()
        {
            foreach (Opiekun o in pracownicy)
            {
                o.WypiszInfo();
                Console.WriteLine("-------------------");
            }
        }
    }


    internal class Program
    {
        static void Main(string[] args)
        {
            Zoo zoo = new Zoo("Zoo Wrocław");

            Zwierze pies = new Ssak("Wszystko", 4, "Cały świat", "Cały świat");
            Zwierze kot = new Ssak("Wszystko", 3, "Cały świat", "Cały świat");
            Zwierze krowa = new Ssak("Wszystko", 6, "Europa", "Europa");
            Zwierze bocian = new Ptak("Wszystko", 2, "Europa", 124.5, 10);
            Zwierze kobra = new Gad("Wszystko", 6, "Afryka", true);
            Zwierze krokodyl = new Gad("Mięso", 1, "Afryka", true);

            Klatka klatka1 = new Klatka(2, 123, true);
            Klatka klatka2 = new Klatka(3, 456, true);
            Klatka klatka3 = new Klatka(5, 789, true);

            klatka1.DodajZwierze(pies);
            klatka1.DodajZwierze(kot);
            klatka1.DodajZwierze(krowa);
            zoo.DodajKlatke(klatka1);
            zoo.DodajKlatke(klatka2);
            zoo.DodajKlatke(klatka3);

            klatka2.DodajZwierze(bocian);
            klatka3.DodajZwierze(kobra);
            klatka3.DodajZwierze(krokodyl);

            zoo.ZwiekszRozmiarKlatki(123, 2);

            klatka1.DodajZwierze(krowa);

            Opiekun o1 = new Opiekun("Jan", "Kowalski", "12.03.1998", "05.04.2020");
            Opiekun o2 = new Opiekun("Anna", "Nowak", "23.07.2000", "08.05.2021");

            zoo.ZatrudnijPracownika(o1);
            zoo.ZatrudnijPracownika(o2);

            o1.PrzypiszKlatke(klatka1);
            o2.PrzypiszKlatke(klatka2);
            o2.PrzypiszKlatke(klatka3);

            Console.WriteLine("------------------------------------------");
            Console.WriteLine("Informaje o klatkach");
            zoo.WypiszInfoKlatki();
            Console.WriteLine("------------------------------------------");

            klatka2.Czysta = false;

            klatka2.WypiszInfo();
            Console.WriteLine("------------------------------------------");

            o2.WyczyscKlatke(klatka2);

            Console.WriteLine("------------------------------------------");
            klatka2.WypiszInfo();
            Console.WriteLine("------------------------------------------");

            zoo.WypiszInfoPracownicy();



            Console.ReadKey();
        }
    }



}
