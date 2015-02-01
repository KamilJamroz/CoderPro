---
layout:     post
title:      "Hello World!"
subtitle:   "Czyli duża dawka teorii."
date:       2015-01-31 01:00:00
author:     "Mrozo"
header-img: "img/post-bg-01.jpg"
---

<h2 class="section-heading toph">Nauka c++ - co nas czeka?</h2>


<p class="midmar">Jednym z powodów uczenia się C++ jest chęć opanowania jego możliwości obiektowych. Jednak do tego potrzebne są podstawy języka C, gdyż z niego pochodzą typy podstawowe, operatory i duża część składni.
Każdy poprawnie napisany program w C będzie jednocześnie poprawnym programem języka C++, czyli C jest podzbiorem C++. Bla Bla Blah</p>


<p class="midmar">Tak, wiem że każdy z was chciałby po tygodniu robić własne Wiedźminy, jednak zanim zaczniemy tworzyć takie cuda, musimy zająć się tym:</p>

<pre class="colorx">
<code class="c++">
&#35;include &#60;iostream&#62;

using namespace std;

int main()
{
   cout << "Hello World!";
   return 0;
}
</code>
</pre>

Niestety zanim przejdziemy do bardziej skomplikowanych struktur musimy zrozumieć co właściwie dzieje się nieco wyżej.

<h2 class="section-heading">&#35;include</h2>

<p>&#35;include to dyrektywa preprocesora, a po polsku: include znaczy "zawierać", "io" to skrót od "input", "output", a stream to "strumień".
Łącząc wszystko w jedną całość uzyskamy coś w rodzaju "załącz strumień wejścia i wyjścia"
Oznacza to, że kiedy program zacznie się kompilować właśnie w tym miejscu pojawi się kod, który pozwoli komputerowi kontaktować się z użytkownikiem. Jeżeli wpiszemy coś do konsoli, komputr będzie mógł to odczytać (wejście) i zwrócić nam jakąś informację (wyjście).
Przydatna biblioteka, prawda?
Właśnie, to jest polecenie wczytujące bibliotekę, czyli zbiór poleceń.
Dzięki temu my nie musimy pisać paruset linijek kodu. Oczywiście isnieje więcej bibliotek, nauczymy się nawet pisać włane. </p>

<h2 class="section-heading">using namespace std;</h2>

<p class="lowmar">Using namespace std oznacza "używanie przestrzeni nazw std"
Każde polecenie znajduje się w danej przestrzeni nazw. Po co i co to jest?
Jeżeli programista1 chciałby napisać sobie polecenie "jakasfunkcja" i w tym samym momencie drugi programista zrobiłby takie samo, a oba wczytalibyśmy z bibliotek. Program nie miałby pojęcia, o które polecenie nam chodzi, dlatego powstały przestrzenie nazw. Od teraz możemy napisać:</p>

<pre>
programista1::jakasfunkcja
programista2::jakasfunkcja
</pre>

<p class="lowmar">Dzięki temu program się nie pogubi. No dobrze, ale po co to using namespace? Jeżeli wiemy, że w namym programie nie będziemy używać dwóch jednakowych zestawów poleceń możemy ustawić jedną przestrzeń jako domyślną:</p>

<pre>using namespace programista1;</pre>

<p class="lowmar">I od teraz nie musimy pisać za każdym razem:</p>

<pre>
programista1::obliczpierwiastek
programista1::superpolecenie
programista1::funkcja3
programista1::siema
</pre>

<p class="lowmar">tylko możemy zrobić tak:</p>

<pre>
obliczpierwiastek
superpolecenie
funkcja3
siema
</pre>

<p class="lowmar">i program sam będzie wiedział jakiej przestrzeni używamy.
Pomyślcie ile właśnie zaoszczędziliście czasu.
Oczywiście w ogromnych projektach może to stanowić problem, dlatego możemy również ustawić przestrzeń nie dla wszystkich poleceń, ale tylko dla jednego:
</p>

<pre>
using std::cout;
using std::endl;
using std::cin;
</pre>

<p>Znamy już podstawy przestrzeni nazw. W takim razie jakie polecenia znajdująsię w przestrzeni nazw ::std? (standard library)
Te, których dzisiaj będziemy używać to cout, cin oraz endl.</p>

<h2 class="section-heading">Cout Cin Endl</h2>

<p class="lowmar"><b>cout</b> (c out) to polecenie, za pomocą którego program może wyświetlić dane na naszym ekranie.</p>
<pre>
cout << "Hello World!";                   <span class="output">Hello World!</span>
cout << "2+8";                            <span class="output">2+8</span>
cout << 2+8;                              <span class="output">10</span>
</pre>

<p>Tak! W C++ możemy dodawać, odejmować, mnożyć, dzielić, używać nawiasów do wymuszania pierwszeństwa działania. Jeżeli chcielibyśmy użyć bardziej zaawansowanych form matematycznych takich jak pierwiastki czy logarytmy wystarczy wczytać bibliotekę math.c. Wszystko zawarte w cudzysłowiach jest uznawane za tekst.
Teraz wprowadźmy zmienne.

<b>Zmienna</b> to nic innego jak pojemnik na dane. Każda zmienna ma swój rodzaj: może to być tekst, liczba całkowita, liczba zmiennoprzecinkowa, znak.
Jak możemy powiedzieć jakiego rodzaju jest zmienna? A oto mała tabelka do wkłucia:
</p>

<table class="FormatCSV" cellspacing="1" cellpadding="0"><tbody><tr><th>Nazwa typu</th><th>Ilość<br>Bajtów</th><th>Zakres wartości</th></tr><tr><td>bool</td><td>1</td><td><b>false</b> lub <b>true</b></td></tr><tr><td>char</td><td>1</td><td>od -128 do 127</td></tr><tr><td>unsigned char</td><td>1</td><td>od 0 do 255</td></tr><tr><td>wchar_t</td><td>2</td><td>od 0 do 65'535</td></tr><tr><td>short</td><td>2</td><td>od -32'768 do 32'767</td></tr><tr><td>unsigned short</td><td>2</td><td>od 0 do 65'535</td></tr><tr><td>int</td><td>4</td><td>od -2'147'483'648 do 2'147'483'647</td></tr><tr><td>unsigned int</td><td>4</td><td>od 0 do 4'294'967'295</td></tr><tr><td>long</td><td>4</td><td>od -2'147'483'648 do 2'147'483'647</td></tr><tr><td>unsigned long</td><td>4</td><td>od 0 do 4'294'967'295</td></tr><tr><td>long long</td><td>8</td><td>od -9'223'372'036'854'775'808</br>do 9'223'372'036'854'775'807</td></tr><tr><td>unsigned long long</td><td>8</td><td>od 0 do 18'446'744'073'709'551'615</td></tr><tr><td>float</td><td>4</td><td>3.4E +/- 38 (7 cyfr)</td></tr><tr><td>double</td><td>8</td><td>1.7E +/- 308 (15 cyfr)</td></tr><tr><td>long double</td><td>8</td><td>1.7E +/- 308 (15 cyfr)</td></tr></tbody></table>

<p class="midmar">Jak widzicie mamy parę typów zmiennych. Najbardziej podstawowe to:
<br><br>
int    - liczba całkowia<br>
float  - liczba zmiennoprzecinkowa<br>
char   - znak<br>
string - łańcuch znaków, czyli tekst</p>

<p class="lowmar">Stwórzmy zmienną o nazwie liczba przechowującą liczbę całkowitą 230:</p>

<pre>
  int liczba = 230;
</pre>

<p class="lowmar">Wyświetlijmy ją na ekranie za pomocą polecenia cout:</p>

<pre>
  cout << liczba;                   <span class="output">230</span>
</pre>

<p class="lowmar">Zawartość zmiennej możemy w każdej chwili zmienić:</p>

<pre>
  int liczba = 230;
  cout << liczba;                   <span class="output">230</span>
  liczba = 20;
  cout << liczba;                   <span class="output">20</span>
</pre>

<p>Zauważcie, że tylko na samym początku dopisujemy int, ten proces nazywa się deklaracją zmiennej.
Po zadeklarowaniu (stworzeniu i nadaniu wartości) zmiennej już nie będziemy mogli zmienić jej rodzaju.</p>

<p class="lowmar"><b>cin</b> (c in), to polecenie, za pomocą którego jesteśmy w stanie wprowadzić dane do środka programu.
<pre>
  int liczba = 0;
  cin >> liczba;                   <span class="output">to podaje użytkownik</span>
  cout << liczba;                  <span class="output">to co wprowadził zostało zapisane i teraz jest wyświetlone</span>
</pre>
</p>

<p class="lowmar">A teraz połączmy strumienie (tak, to co braliśmy na linuxie!) i dodajmy <b>endl</b>, czyli zakończenie linii (end line):</p>

<pre class="midmar">
  string imie = "";
  cin >> imie;                   <span class="output">przyjmijmy, że wpisuje Kasia</span>
  cout << "Witaj " << imie << "." << endl << "Pierogi.";
</pre>

<p class="lowmar">Rezultat:</p>

<pre>
  Witaj Kasia.
  Pierogi.
</pre>

<p class="lowmar">Podobny efekt możemy uzyskać za pomocą <b>\n</b>:</p>

<pre class="midmar">
  string imie = "";
  cin >> imie;                   <span class="output">przyjmijmy, że wpisuje Kasia</span>
  cout << "Witaj " << imie << ".\nPierogi.";
</pre>

<h2 class="section-heading">Funkcja Main()</h2>

<p class="midmar">Funkcje to bardzo ważny i rozległy temat, dlatego dzisiaj dowiemy się tylko o co chodzi z tym main.

Każdy program rozpoczyna swoje działanie od funkcji main().
W jej środku znajdują się wszystkie instrukcje.
Return 0, czyli zwróć 0 mówi programowi żeby zakończył swoje działanie.</p>

<pre>
  int main()
  {
    instrukcje
    return 0;
  }
</pre>

<h2 class="section-heading">Mechanika Tworzenia Programu</h2>

<p>Załóżmy, że napisaliśmy ten kod. Jak mamy go uruchomić?</p>
<p>1. Za pomocą edytora tekstu piszemy program i zapisujemy go w pliku. Plik ten jest kodem źródłowym programu.</p>
<p>2. Kompilujemy kod źródłowy, czyli uruchamiamy program tłumaczący nasze wypociny na 0110001000001101010, czyli kod maszynowy (komputer w końcu może go zrozumieć). Taki kod nazywamy kodem wynikowym programu.</p>
<p>3. Konsoliduje się kod wynikowy z dodatkowymi zasobami. Na przykład z bibliotekami. Konsolidacja polega na łączeniu własnego kodu wynikowego z kodem wynikowym używanych funkcji (tych poleceń z bibliotek) oraz dodatkowym kodem startowym, który pozwala nasz program w ogóle uruchomić.
Plik zawierający efekt końcowy to tak zwany kod wykonalny.</p>

<h2 class="section-heading">Dodatek</h2>

<p>Wielu z was ma problem z pisaniem zmiennych w prawidłowym miejscu.
Na razie każda zmienna powinna znajdować się w ciele funkcji, to znaczy między nawiasami { i }, w przeciwnym wypadku zostanie zmienną globalną czego byśmy sobie nie życzyli. Więcej o zmiennych globalnych dowiemy się podczas nauki o funkcjach. Na tę chwilę używajcie zmiennych lokalnych.</p>

<h2 class="section-heading">Zadania</h2>

<p class="lowmar">1. Napisz program, który prosi użytkownika o wprowadzenie wieku, a następnie wyświetla wiek użytkownika podany w miesiącach.</p>

<p>2. Napisz program, który prosi użytkownika o podanie liczby godzin i minut, po czym wyświetla je w formie: "Czas: godzina:minuty". Przykład: "Czas: 23:56". </p>

<blockquote>Niejednokrotnie powtarzałem, że materiały ówcześniej przerobione oraz przyswojone z gimnazjum pozwolą wam na wykonanie poniższych zadań, a jeżeli nie: i tu już pomi... krótki koleś z ciebie!</blockquote>
