---
layout:     post
title:      "Polimorfizm - podstawy"
subtitle:   "Bumfszszsz!"

date:       2015-04-18 22:00:00
author:     "Mrozo"
header-img: "img/post-bg-10.jpg"
---

<h2 class="section-heading toph">Polimorfizm czyli wielopostaciowość</h2>

<p class="midmar">Polimorfizm jest najważniejszym i bardzo szerokim konceptem w programowaniu obiektowym.</p>

<p class="midmar">Podczas pisania programu o wiele wygodniej jest traktować różne dane w podobny sposób. Bez względu na to, czy trzeba wyświetlić napis, czy może liczbę zazwyczaj czytelniej jest jeśli operacja nazywa się <i>Wyświetl</i> zamiast <i>WyświetlNapis</i> i <i>WyświetlLiczbę</i>. Oczywiście napis jest wyświetlany w inny sposób niż liczba, jednak wspólna nazwa tworzy wygodny abstrakcyjny interfejs.
<br><br>
<h3>Istota polimorfizmu:</h3>
<ul class="lowmar">
<li> system decyduje o szczegółach, nie programista </li>
<li> program ma być łatwo rozszerzalny </li>
</ul>
</p>

<p class="midmar">Jedną z właściwości klas dziedziczonych jest to, że wskaźnik do niej jest kompatybilny typem do wskaźnika wskazującego klasę rodzica:</p>

<pre class="colorx midmar"><code class="c++">class Polygon
{
  protected:
    int width, height;
  public:
    void setup (int _width, int _height)
    {
      width = _width;
      height = _height;
    }

    int area()
    {
      cout << "Polygon area" << endl;
      return (0);
    }
};

class Rectangle : public Polygon
{
  public:
    int area()
    {
      cout << "Rectangle area" << endl;
      return (width * height);
    }
};

class Triangle : public Polygon
{
  public:
    int area()
    {
      cout << "Triangle area" << endl;
      return (width * height / 2);
    }
};

int main ()
{
  Rectangle rectangle;
  Triangle triangle;

  Polygon * polygon1 = &#38;rectangle;
  Polygon * polygon2 = &#38;triangle;

  polygon1->setup(2,2);
  polygon2->setup(2,2);

  polygon1->area();
  polygon2->area();

  return 0;
}</code></pre>

<p class="lowmar">Wynik:</p>

<pre class="midmar">Polygon area
Polygon area</pre>

<p>Zauważ, że klasy trójkąt i kwadrat mają możliwość korzystania z klasy wielokąt. Dlaczego? No bo one SĄ wielokątami! Najtrudniejszym aspektem do ogarniecia jest fakt, iż klasa dziedziczona (dziecko) JEST jednocześnie klasą główną (rodzicem). Taka abstrakcja ;) <br>
W takim przypadku aby funkcja mogła zostać wywołana używamy strzałki "->" zamiast operatora kropki.</p>

<h2 class="section-heading toph">Klasy abstrakcyjne i funkcje wirtualne</h2>

<p class="lowmar">Co prawda powyższy kod działa, jednak program tworzy taki oto rezultat:</p>

<pre class="midmar">Polygon class area
Polygon class area</pre>

<p class="lowmar">A my przecież nie chcemy Polygona tylko dane figury, których pole chcemy obliczyć.</p>
<p class="midmar">Powodem złego działania jest to, że funkcja area() została już raz zadeklarowana przez kompilator jako wersja zdefiniowana w klasie bazowej - Polygon.<br><br>
Rozwiązanie: klasa abstrakcyjna.
Klasa abstrakcyjna to klasa, w której przynajmniej jedna z metod jest czysto wirtualna, czyli musimy stworzyć metodę czysto wirtualną dodając słowo <span class="blue">virtual</span> i przypisując do metody liczbę 0.</p>

<pre class="midmar">virtual int area() = 0;</pre>

<p class="lowmar">Metoda ta nie wykonuje żadnego kodu, no bo po co? Przecież klasy głównej używamy tylko do polimorfizmu. Dlaczego? Bo nie obliczysz pola z figury. Nie wiesz z jakiej. Dlatego z klasy abstrakcyjnej nie da się stworzyć obiektu, ona istnieje tylko po to, aby została przysłonięta. </p>

<p class="midmar">Po tej małej modyfikacji wynik naszego kodu jest następujący:</p>

<pre class="midmar">Rectangle area
Triangle area</pre>

<p>Zauważcie, że metody czysto wirtualne tak na prawdę nie istnieją - znowu abstrakcja.</p>

<h2 class="section-heading toph">Rozszerzalność (skalowalność)</h2>

<p class="midmar">Czas na przykład przydatności polimorfizmu:</p>

<pre class="colorx midmar"><code class="c++">class Postac
{
public:
   virtual void atakuj() = 0; //czysta funkcja wirtualna
};

class Mag : public Postac
{
public:
   virtual void atakuj()
   {
      cout<<"Atak Maga!"<<endl;
   }
};

class Elf : public Postac
{
public:
   virtual void atakuj()
   {
      cout<<"Atak Elfa!"<<endl;
   }
};

void atak(Postac *x) //ta funkcja jest mega uniwersalna!!!!
{
   x -> atakuj();
}

int main()
{
    Mag mag;
    Elf elf;

    Postac * wskaznik;

    wskaznik = &mag;
    wskaznik -> atakuj(); //sposób 1

    wskaznik = &elf;
    atak(wskaznik); //sposób 2

    return 0;
}</code></pre>

<p class="midmar">Przysłaniające metody atak() stają się automatycznie metodami wirtualnymi. Możemy dodać przed nie słowo virtual aczkolwiek nie musimy.</p>

<p class="midmar">Teraz spójrz na funkcję atak. Możesz od teraz stworzyć nawet 200 nowych ras do twojej gry, ustawić na nie wskaźnik polimorficzny i wsadzić je do tej funkcji jako argument. Funkcja będzie działała! Nie będziesz musiał tworzyć nowych do każdej rasy z osobna! To się nazywa rozszerzalność.</p>

<h2 class="section-heading toph">Dodatki</h2>

<p>Pamiętasz może cechy Linuxa? Linux również jest rozszerzalny - właśnie przez polimorfizm!</p>

<a href="../../../../files/lekcja10-polimorfizm.cpp" target="_blank">Kompletny kod - polimorfizm (click)</a>

<a href="../../../../files/lekcja10-rozszerzalnosc.cpp" target="_blank">Kompletny kod - rozszerzalność (click)</a>

