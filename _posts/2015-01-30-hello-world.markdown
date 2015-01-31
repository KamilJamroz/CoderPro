---
layout:     post
title:      "Hello World!"
subtitle:   "Czyli duża dawka teorii."
date:       2015-01-31 01:00:00
author:     "Mrozo"
header-img: "img/post-bg-01.jpg"
---

<h2 class="section-heading">Nauka c++ - co nas czeka?</h2>


<p>Jednym z powodów uczenia się C++ jest chęć opanowania jego możliwości obiektowych. Jednak do tego potrzebne są podstawy języka C, gdyż z niego pochodzą typy podstawowe, operatory i duża część składni.
Każdy poprawnie napisany program w C będzie jednocześnie poprawnym programem języka C++, czyli C jest podzbiorem C++. Bla Bla Bla</p>



Tak, wiem że każdy z was chciałby po tygodniu robić własne Wiedźminy, jednak zanim zaczniemy tworzyć takie cuda, musimy zająć się tym:

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


Niestety, zanim przejdziemy do bardziej skomplikowanych struktur, musimy zrozumieć co właściwie dzieje się nieco wyżej.

<h2 class="section-heading">&#35;include</h2>

<p>&#35;include to dyrektywa preprocesora, a po polsku: include znaczy "zawierać", "io" to skrót od "input", "output", a stream to "strumień".
Łącząc wszystko w jedną całość uzyskamy coś w rodzaju "Zawrzyj strumień wejścia i wyjścia"
Oznacza to, że kiedy program zacznie się kompilować właśnie w tym miejscu pojawi się kod, który pozwoli komputerowi kontaktować się z użytkownikiem. Jeżeli wpiszemy coś do konsoli, komputr będzie mógł to odczytać (wejście) i zwrócić nam jakąś informację (wyjście).
Przydatna biblioteka, co?
Właśnie, to jest polecenie wczytujące bibliotekę, czyli zbiór poleceń.
Dzięki temu my nie musimy pisać paruset linijek kodu. Oczywiście isnieje więcej bibliotek, nauczymy się nawet pisać włane. </p>


<h2 class="section-heading">using namespace std;</h2>

<p class="midmar">Using namespace std oznacza "używanie przestrzeni nazw std"
Każde polecenie znajduje się w danej przestrzeni nazw. Po co i co to jest?
Jeżeli programista Hankiewicz chciałby napisać sobie polecenie "zrobmidobrze" i w tym samym momencie drugi programista zrobiłby takie samo, a oba wczytalibyśmy z bibliotek, program nie miałby pojęcia, o które polecenie nam chodzi. Dlatego powstały przestrzenie nazw. Od teraz możemy napisać:</p>

<p class="lowmar">hankiewicz::zrobmidobrze</p>
<p>programista2::zrobmidobrze</p>

<p>Dzięki temu program się nie pogubi. No dobrze, ale po co to using namespace? Jeżeli wiemy, że w namym programie nie będziemy używać dwóch jednakowych zestawów poleceń możemy ustawić jedną przestrzeń:</p>
<p>using namespace hankiewicz;</p>

<p>I od teraz nie musimy pisać za każdym razem:</p>

<pre>
hankiewicz::zrobmidobrze
hankiewicz::otak
hankiewicz::funkcja3
hankiewicz::siema
</pre>

tylko możemy zrobić tak:

<pre>
zrobmidobrze
otak
funkcja3
siema
</pre>

<p>i program sam będzie wiedział jakiej przestrzeni nazw używamy.
Pomyślcie ile właśnie zaoszczędziliście czasu.
Oczywiście w ogromnych projektach może to stanowić problem, dlatego możemy również ustawić przestrzeń nie dla wszystkich poleceń hankiewicza, ale tylko dla jednego:
</p>


<pre>
using std::cout;
using std::endl;
using std::cin;
</pre>

<p>Znamy już podstawy przestrzeni nazw. W takim razie jakie polecenia są w ::std? (standard library)
Te, których dzisiaj będziemy używać to cout, cin oraz endl.</p>

<h2 class="section-heading">Cout Cin Endl</h2>

<p>cout (c out), to polecenie, za pomocą którego program może wyświetlić dane na naszym ekranie.</p>
<pre>
cout << "Hello World!";                   -Hello World!
cout << "2+8";                            -2+8
cout << 2+8;                              -10
</pre>

<p>Tak! c++ potrafi liczyć. Wszystko zawarte w cudzysłowiach jest liczone jako tekst.
Teraz wprowadźmy zmienne.

<h3><i>Zmienna</i></h3> to nic innego jak pojemnik na dane. Każda zmienna ma swój rodzaj: może to być tekst, liczba całkowita, liczba zmiennoprzecinkowa, znak.
Jak możemy powiedzieć jakiego rodzaju jest zmienna? A oto mała tabelka do wkłucia:
</p>

<table class="FormatCSV" cellspacing="1" cellpadding="0"><tbody><tr><th>Nazwa typu</th><th>Ilość<br>Bajtów</th><th>Zakres wartości</th></tr><tr><td>bool</td><td>1</td><td><b>false</b> lub <b>true</b></td></tr><tr><td>char</td><td>1</td><td>od -128 do 127</td></tr><tr><td>unsigned char</td><td>1</td><td>od 0 do 255</td></tr><tr><td>wchar_t</td><td>2</td><td>od 0 do 65'535</td></tr><tr><td>short</td><td>2</td><td>od -32'768 do 32'767</td></tr><tr><td>unsigned short</td><td>2</td><td>od 0 do 65'535</td></tr><tr><td>int</td><td>4</td><td>od -2'147'483'648 do 2'147'483'647</td></tr><tr><td>unsigned int</td><td>4</td><td>od 0 do 4'294'967'295</td></tr><tr><td>long</td><td>4</td><td>od -2'147'483'648 do 2'147'483'647</td></tr><tr><td>unsigned long</td><td>4</td><td>od 0 do 4'294'967'295</td></tr><tr><td>long long</td><td>8</td><td>od -9'223'372'036'854'775'808</br>do 9'223'372'036'854'775'807</td></tr><tr><td>unsigned long long</td><td>8</td><td>od 0 do 18'446'744'073'709'551'615</td></tr><tr><td>float</td><td>4</td><td>3.4E +/- 38 (7 cyfr)</td></tr><tr><td>double</td><td>8</td><td>1.7E +/- 308 (15 cyfr)</td></tr><tr><td>long double</td><td>8</td><td>1.7E +/- 308 (15 cyfr)</td></tr></tbody></table>

<p>Jak widzicie mamy parę typów zmiennych. Najbardziej podstawowe to:<br>
int    - liczba całkowia<br>
float  - liczba zmiennoprzecinkowa<br>
char   - znak<br>
string - łańcuch znaków, czyli tekst</p>

<p>Teraz do dzieła. Zrobimy zmienną o nazwie liczba przechowującą liczbę całkowitą 230: <br>

<pre>
  int liczba = 230;
</pre>

A teraz wyświetlimy ją na ekranie za pomocą polecenia cout:</p>

<pre>
  cout << liczba;                   -230
</pre>

Zawartość zmiennej możemy w każdej chwili zmienić:

<pre>
   int liczba = 230;
  cout << liczba;                   -230
  liczba = 20;
  cout << liczba;                   -20
</pre>

<p>Zauważcie, że tylko na samym początku dopisujemy int, ten proces nazywa się deklaracją zmiennej.
Po zadeklarowaniu (stworzeniu i nadaniu wartości) zmiennej już nie będziemy mogli zmienić jej rodzaju.</p>

<p>cin (c in), to polecenie, za pomocą którego jesteśmy w stanie wprowadzić dane do środka programu.
<pre>
  int liczba = 0;
  cin >> liczba;                   -to podaje użytkownik
  cout << liczba;                  -to co wprowadził zostało zapisane i teraz jest wyświetlone
</pre>
</p>

<p>A teraz połączmy strumienie (tak, to co braliśmy na linuxie!) i dodajmy endl, czyli end of line:</p>

<pre class="lowmar">
  string imie = "";
  cin >> imie;                   -przyjmijmy, że wpisuje Grzybiarz
  cout << "Witaj " << imie << "." << endl << "Pierogi.";
</pre>

Rezultat:

<pre>
  Witaj Grzybiarz.
  Pierogi.
</pre>

<h2 class="section-heading">Funkcja Main()</h2>

<p>Funkcje to bardzo ważny i rozległy temat, dlatego dzisiaj dowiemy się tylko o co chodzi z tym main.

Każdy program rozpoczyna swoje działanie od funkcji main().
W jej środku znajdują się wszystkie instrukcje.
Return 0, czyli zwróć 0 mówi tej funkcji (czyli też programowi) żeby zakończya swoje działanie.</p>

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

<blockquote>Niejednokrotnie powtarzałem, że materiały uwcześniej przerobione oraz przyswojone z gimnazjum pozwolą wam na wykonanie poniższych zadań, a jeżeli nie: i tu już pomi... krótki koleś z ciebie!</blockquote>

<h2 class="section-heading">Zadania:</h2>

<p class="lowmar">1. Napisz program, który prosi użytkownika o wprowadzenie wieku, a następnie wyświetla wiek użytkownika podany w miesiącach.</p>

<p>2. Napisz program, który prosi użytkownika o podanie liczby godzin i minut, po czym wyświetla je w formie: "Czas: godzina:minuty", czyli np. "Czas: 23:56". </p>
