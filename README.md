# VinylShop
Program symulujący działanie sklepu z płytami winylowymi.
# Uruchamianie programu
W celu uruchomienia programu należy wpisać kolejno następujące komendy:
cmake . -B ./build
make -C ./build
./build/vinylshop <T> <N>
Do linii poleceń trzeba podać dwa argumenty całkowitoliczbowe - czas trwania symulacji (T) oraz liczbę klientów (N)
W przypadku problemów z kompilacją pomocne może okazać się usunięcie folderu build / pliku CMakeCache.txt (zostanie on wtedy ponownie wygenerowany przy wykonaniu pierwszej komendy)
# Dzialanie programu
Realizowana przez nas symulacja ukazuje sposób działania sklepu z płytami winylowymi. W każdej
jednostce czasu pojawiają się w nim klienci, którzy mają przy sobie listę zakupów (poszukiwane przez
nich płyty, oraz potrzebna ilość). Kontaktują się oni ze sprzedawcami, po uprzednim odnalezieniu
osoby odpowiedzialnej za sekcję sklepu zajmującą się gatunkiem muzycznym, do którego należy
kupowana płyta. Gdy w magazynie jest wystarczający zapas, zamówienie klienta jest realizowane,
zaś w przeciwnym wypadku sprzedawca informuje klienta o braku, a towar jest zamawiany.

Program bedzie dla każdego T obsługiwał dostępnych klientów. Kolejni klienci przychądzą do sklepu co 1T aż do osiągnięcia N.
Uwaga! Klienci nie wychodzą ze sklepu (przekroczenie wymagań projektu), a każdy z nich zamawia od 1 do 3 pozycji. Dla czytelności wyników warto utrzymywać N na poziomie 1 - 3.
