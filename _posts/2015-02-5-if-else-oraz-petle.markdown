---
layout:     post
title:      "Zapętlona Logika"
subtitle:   "If...else, pętle i coś jeszcze."
date:       2015-02-06 18:25:00
author:     "Mrozo"
header-img: "img/post-bg-02.jpg"
---

<h2 class="section-heading toph">Wstęp</h2>
<p> Ta lekcja będzie zawierała o wiele więcej niezbędnych rzeczy, które mogą być na początku nie do ogarnięcia. Jednak już po przerobieniu dzisiejszego materiału wkońcu będziesz potrafił stworzyć coś normalnego i praktycznego, więc siedź cicho i uczyć się :P</p>

<h2 class="section-heading">Komentarze</h2>
<p class="lowmar">W każdym temacie mam zamiar wtrącać coś dodatkowego i dzisiaj będą to komentarze, czyli tekst, którego kompilator nie widzi. Dzięki temu możemy opisywać co dzieje się w naszym kodzie. Bardzo powszechną praktyką jest pisanie komentarzy opisujących co dokłanie ma robić dana funkcja. Jednak o funkcjach kiedy indziej.</p>

<p class="midmar">Mamy 2 rodzaje komentarzy: jednoliniowe oraz wieloliniowe</p>

<pre class="colorx">
<code class="c++">
&#35;include &#60;iostream&#62;

using namespace std;

int main()
{
   int liczba = 0;
   //zadeklarowanie liczby
   cin >> liczba
   //wprowadzenie liczby przez użytkownika // ups, nie zamknął się!
   cout << liczba;
   /* wypisanie zmiennej liczba
     to jest komentarz wieee-
     -eeelo liniowy */ tu już kod działa!
   return 0;
}
</code>
</pre>

<h2 class="section-heading">Warunek If...Else</h2>
<p class="lowmar"> Jest to warunek logiczny, który jeśli będzie spełniony to nasz program wykona podaną akcję (if), lub w przeciwnym wypadku podejmie się czegoś innego (else).</p>

<p class="lowmar">Budowa If:</p>

<pre>If(warunek)
{
  //jakiś kod
}
</pre>

<p class="lowmar">Budowa If...Else:</p>

<pre>If(warunek)
{
  //jakiś kod
}
else
{
  //jakiś kod
}
</pre>

<p class="lowmar">Rozbudujmy to nieco :D</p>

<pre class="colorx nullmar">
<code class="c++">if(warunek)
{
  //kod
  if(warunek)
  {
    //kod
    if(warunek)
    {
      //kod
      if(warunek)
      {
        //kod
      }
        else
        {
          //kod
        }
      }
  }
  else if(warunek)
  {
    if(warunek)
    {
      //kod
    }
  }
  else if(warunek)
  {
    //kod
  }
  else if(warunek)
  {
    //kod
  }
}</code></pre>

<table><tbody><tr><th><p class="null">Jeżeli nasz kod składa się tylko z jednej linijki możemy pominąć nawiasy</p></th></tr><th class="green"></th></tbody></table>

<p class="midmar">Takie klocki. Super, ale jak zdefiniować warunek?</p>

<h2 class="section-heading">Operacje Porównania</h2>

<p class="midmar">Na początku powinniśmy poznać operacje porównania:</p>

<table><tbody><tr><th>Operator</th><th>Krótki opis</th></tr><tr><td>&gt;</td><td>... jest większe od ...</td></tr><tr><td>&gt;=</td><td>... jest większe lub równe niż ...</td></tr><tr><td>&lt;</td><td>... jest mniejsze od ...</td></tr><tr><td>&lt;=</td><td>... jest mniejsze lub równe niż ...</td></tr><tr><td>==</td><td>... jest równe ...</td></tr><tr><td>!=</td><td>... jest różne od ...</td></tr></tbody></table>

<h2 class="section-heading">Operacje Logiczne</h2>

<p class="midmar">Dzięki nim możemy łączyć nasze warunki:</p>

<table class="FormatCSV" cellspacing="1" cellpadding="0"><tbody><tr><th>Nazwa</th><th>C++</th><th>Opis</th></tr><tr><td>i</td><td>&amp;&amp;</td><td>Iloczyn logiczny - wszystkie wartości muszą być prawdziwe, aby została zwrócona prawda.</td></tr><tr><td>lub</td><td>||</td><td>Suma logiczna - co najmniej jedna z wartości musi być prawdziwa, aby została zwrócona prawda.</td></tr><tr><td>negacja</td><td>!</td><td>Zanegowanie wartości - czyli zwrócenie wartości przeciwnej.</td></tr></tbody></table>

<h2 class="section-heading">Trochę praktyki</h2>

<p class="lowmar">A teraz złóżmy to wszyskto w jedną całość. <br>
Przykład 1:</p>

<pre class="colorx nullmar">
<code class="c++">if(wiek >= 18)
{
  cout << "Jesteś pełnoletni. Możesz wejść.";
  forsa = forsa - 50;
}
else if(wiek < 18)
  cout << <span class="orange">"Spadaj dzieciaku!"</span>;
else
  cout << "Ale jesteś stary!";</code></pre>

<table><tbody><tr><th><p class="null">Pamiętajce, że w c++ nie używamy znaków polskich! Przynajmniej do czasu :)</p></th></tr><th class="red"></th></tbody></table>

<p class="lowmar">Przykład 2:</p>

<pre class="colorx">
<code class="c++">if((x>=0||y>=0)&&z==10)
  cout << "Jeśli warunek if jest spełniony to pokaże się na ekranie";
else
  cout << "Warunek nie został spełniony, więc wyświetliło się to";</code></pre>

<h2 class="section-heading">Pętla while</h2>
<p class="lowmar">Pętla to tak naprawdę takie if z jedną różnicą: dopóki dany warunek będzie spełniany dla pętli, dopóty kod w środku niej będzie się wykonywał (powtarzał)</p>

<p class="lowmar">Budowa Pętli While:</p>

<pre>while(warunek)
{
  //jakiś kod
}
</pre>

<p class="lowmar">Pora na przykłady:</p>
<pre class="colorx">
<code class="c++">while(forsa>=0)
{
  cout << "Mam " << forsa << " pieniędzy." << endl;
  forsa = forsa - 20;
  cout << "Wydałem 20 pieniędzy." << endl;
}
cout << "Już ni mam pieniędzy :(";</code></pre>

<p class="lowmar">Po nadaniu forsie wartości 100 ukaże nam się taki widok:</p>


<pre class="colorx">
<code class="c++">Mam 100 pieniędzy.
Wydałem 20 pieniędzy.
Mam 80 pieniędzy.
Wydałem 20 pieniędzy.
Mam 60 pieniędzy.
Wydałem 20 pieniędzy.
Mam 40 pieniędzy.
Wydałem 20 pieniędzy.
Mam 20 pieniędzy.
Wydałem 20 pieniędzy.
Mam 0 pieniędzy.
Wydałem 20 pieniędzy.
Już nie mam pieniędzy :(</code></pre>


<h2 class="section-heading">Pętla do...while</h2>

<p class="lowmar">Ta pętla różni się tylko jednym małym szczegółem od poprzedniej: za pierwszym razem kod wykonuje się nawet jeżeli warunek nie jest spełniony.</p>

<p class="lowmar">Budowa Pętli While:</p>

<pre>do
{
  //jakiś kod
}while(warunek)
</pre>

<p class="lowmar">I znów mały przykład:</p>
<pre class="colorx">
<code class="c++">do
{
  //tutaj mamy naszą grę
  cout << "Czy chcesz powtórzyć grę?" << endl;
  cin >> wybor;
}while(wybor==1)</code></pre>

<p>Jak widać pętla ta przydaje się podczas robienia np. menu. Zanim wprowadzimy dane pętla wykonuje się przynajmniej jeden raz. Jeżeli wybor będzie równał się 0, wyjdziemy z pętli i nasza gra zakończy się, w przeciwnym wypadku zostanie powtórzona.</p>

<h2 class="section-heading">Zadania</h2>

<p class="lowmar">1. W moim przykładzie z pętlą while znajduje się błąd. Po pokazaniu informacji "mam 0 pieniędzy" pokazuje się kolejna: "Wydałem 20 pieniędzy". Odtwórz ten program i popraw go używając if-a.</p>

<p class="lowmar">2. Stwórz program, który będzie wyświetlał wszystkie liczby parzyste w zakresie od 0 do 1000 włącznie. (I nawet nie próbuj zrobić to samymi cout-ami :D) </p>

<p>3. Napisz kalkulator (nie przesłyszałeś się), który będzie potrafił dodawać, odejmować, mnożyć i dzielić. Wskazówka: stwórz menu, w którym będzie można wybrać jedną z 5 opcji: np 1 to dodawanie, 2 to odejmowanie itd. (0 to wyjście z programu, bez zera menu po wystawieniu poprzedniego wyniku ma się znowu pojawić!) Następnie wprowadzamy a, enter, b, enter i program podaje wynik. (uff ale ci podpowiedziałem :D. Teraz pewnie zrobisz to w 20 sekund)
<blockquote>Oczywiśnie nic nie stai na przeszkodzie aby zrobić pętlę w pętli w pętli. Dodajmy jeszcze if elsa i tadaa! Wasze zadanie domowe gotowe ;)</blockquote>
