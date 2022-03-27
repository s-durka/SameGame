# SameGame
https://en.wikipedia.org/wiki/SameGame
Prostokątna plansza do gry SameGame dzieli się na pola, uporządkowane w wiersze i kolumny.

Każde pole albo jest puste albo jest na nim klocek określonego rodzaju.

Gracz usuwa z planszy grupy sąsiadujących klocków tego samego rodzaju.

Klocki opadają na puste pola w wierszach poniżej.

Kolumny, w których są jakieś klocki, są przesuwane w lewo, na miejsce kolumn pustych.
Polecenie

Napisz program przekształcający tekst w sposób wzorowany na grze SameGame.

Dane programu określają rozmiar planszy i jej początkowy stan.

Liczba wierszy planszy jest równa liczbie wierszy danych a liczba kolumn planszy jest równa maksymalnej długości wiersza danych.

Znaki różne od spacji, dalej nazywane znakami widocznymi, odpowiadają klockom w SameGame a spacje i miejsca za końcem wiersza to pola puste.

Zbiór widocznych znaków G w tekście nazywamy grupą, jeśli spełnione są trzy warunki:

    wszystkie znaki w zbiorze G są takie same,

    od każdego znaku w zbiorze G można przejść do każdego z pozostałych znaków w tym zbiorze, wykonując tylko kroki do bezpośrednich sąsiadów w wierszu lub w kolumnie i poruszając się przy tym wyłącznie po znakach ze zbioru G,

    zbioru G nie można rozszerzyć, nie łamiąc zasad 1 i 2.

Inaczej, niż w grze SameGame, nie wymagamy, by grupa była co najmniej dwuelementowa.

Można zauważyć, że każdy widoczny znak w tekście jednoznacznie określa grupę, do której należy.

Program wykonuje następujący algorytm:

    czyta i porządkuje dane,

    wymazuje jedną grupę znaków widocznych, o ile taka grupa istnieje,

    porządkuje i pisze wynik.

Porządkując tekst, program:

    dopóki jest choć jeden widoczny znak, bezpośrednio poniżej którego, w tej samej kolumnie, jest pole puste, przesuwa ten znak o jeden wiersz w dół,

    usuwa wszystkie kolumny, w których nie ma widocznego znaku.

Wymazanie grupy widocznych znaków polega na zastąpieniu ich w tekście spacjami.

Do wymazania wybierana jest grupa widocznych znaków, do której należy znak w pierwszej kolumnie ostatniego wiersza tekstu.
Postać danych

Dane programu to dowolny tekst.

Wolno założyć, że każdy wiersz danych, także ostatni, będzie zakończony reprezentacją końca wiersza \n.

Wolno założyć, że dane zmieszczą się w pamięci a liczba wierszy i liczba kolumn będzie w zakresie typu int.

Jeśli rozwiązanie nałoży dodatkowe ograniczenia na rozmiar danych, to jego ocena jakości zostanie obniżona o 1 punkt.

Podczas walidacji i testów dane będą miały nie więcej niż 20 wierszy i nie więcej niż 80 kolumn.

Za program, który ogranicza liczbę wierszy do 20 i liczbę kolumn do 80, można więc zdobyć maksymalnie 19 punktów na 20 możliwych.
Postać wyniku

Wynikiem programu są niepuste wiersze przekształconych danych.

Na końcach wierszy nie są wypisywane spacje.

Każdy wiersz, także ostatni, jest zakończony końcem wiersza \n.
