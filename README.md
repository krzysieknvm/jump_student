# Jump Student
Jump Student to gra polegająca skakaniu po platformach w celu dotarcia na samą górę.

W tym opisie znajdziesz:
* [Zasady i opis sterowania](#zasady)
* [Wymagania sprzętowe](#wymagania)
* [Proces instalacji](#instalacja)

### Zasady
Żeby wykonać skok należy wcisnąć spację. Można zmienić kierunek lotu, wciskając A lub D podczas 
"ładowania" skoku (czyli trzymania spacji).

### Wymagania
Aby móc skompilować program u siebie na komputerze trzeba mieć zainstalowane:
* CMake 4.0.0 (minimum 3.19)
* Qt Creator
* Qt 6.8.2 MinGW 64-bit

### Instalacja
Aby zainstalować i zbuildować tę grę u siebie należy:
1. Pobrać cały kod
2. Stworzyć projekt w Qt Creator oparty na *Cmake z wykorzystaniem qt 6.5 lub nowszego*
3. Zaznaczyć w dodatkowych opcjach wykorzystanie *Qt 6.8.2 MinGW 64-bit*
4. Odpalić ten projekt za pomocą dowolnego innego środowiska programistycznego
5. Wpisać w konsolę `cmake build` (tu pewnie wystąpi problem, ale trzeba go olać)
6. Dodać do pliku `CMakeLists.txt` następujący kod:
```
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "twoja ścieżka do qt 6.8.2")

qt_add_executable(jump_student
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
        src/class/StartWindow.cpp
        src/module/StartWindow.h
        src/scenes/class/FirstScene.cpp
        src/scenes/module/FirstScene.h
        src/class/MainCharacter.cpp
        src/module/MainCharacter.h
)
```
7. Przejść w cmd do katalogu `cmake-build-default-mingw` (cmake automatycznie tworzy ten folder po komendzie z punktu 5 (może się inaczej nazywać ale zawsze zaczyna się od `cmake-build`))
8. Uruchomić komendę `C:\Qt\6.8.2\mingw_64\bin\windeployqt.exe jump_student.exe`
9. Powtórzyć punkt 5

Teraz można uruchomić grę poprzez środowisko i cieszyć się doświadczeniami.