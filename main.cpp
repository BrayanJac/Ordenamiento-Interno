#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMenu(int highlight, const string choices[], int n_choices) {
    system("cls");
    for (int i = 0; i < n_choices; ++i) {
        gotoxy(5, 5 + i);
        if (highlight == i) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        cout << choices[i];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

void printSubMenu(int highlight, const string choices[], int n_choices) {
    system("cls");
    for (int i = 0; i < n_choices; ++i) {
        gotoxy(30, 5 + i);
        if (highlight == i) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        cout << choices[i];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}

int main() {
    const string mainChoices[] = {
        "1. Lista Simple",
        "2. Lista Doble",
        "3. Lista Circular",
        "4. Lista Circular Doble",
        "5. Salir"
    };
    const string sortChoices[] = {
        "1. Ordenamiento por Intercambio",
        "2. Ordenamiento Burbuja",
        "3. Ordenamiento Quicksort",
        "4. Ordenamiento Shellsort",
        "5. Ordenamiento por Distribucion",
        "6. Ordenamiento Radix"
    };
    int n_mainChoices = sizeof(mainChoices) / sizeof(mainChoices[0]);
    int n_sortChoices = sizeof(sortChoices) / sizeof(sortChoices[0]);
    int highlight = 0;
    int subHighlight = 0;
    int choice = -1;
    char c;
    bool inSubMenu = false;
    bool listSelected = false;

    while (true) {
        if (!inSubMenu) {
            printMenu(highlight, mainChoices, n_mainChoices);
        } else {
            printSubMenu(subHighlight, sortChoices, n_sortChoices);
        }

        c = _getch();
        if (!inSubMenu) {
            switch (c) {
            case 72: // Flecha arriba
                if (highlight == 0) {
                    highlight = n_mainChoices - 1;
                } else {
                    --highlight;
                }
                break;
            case 80: // Flecha abajo
                if (highlight == n_mainChoices - 1) {
                    highlight = 0;
                } else {
                    ++highlight;
                }
                break;
            case 77: // Flecha derecha
                if (highlight < 4) {
                    inSubMenu = true;
                    subHighlight = 0;
                    listSelected = true;
                }
                break;
            case '\r': // Enter key
                if (highlight == 4) {
                    choice = highlight;
                }
                break;
            default:
                break;
            }
        } else {
            switch (c) {
            case 72: // Flecha arriba
                if (subHighlight == 0) {
                    subHighlight = n_sortChoices - 1;
                } else {
                    --subHighlight;
                }
                break;
            case 80: // Flecha abajo
                if (subHighlight == n_sortChoices - 1) {
                    subHighlight = 0;
                } else {
                    ++subHighlight;
                }
                break;
            case 75: // Flecha izquierda
                inSubMenu = false;
                break;
            case '\r': // Enter key
                system("cls");
                
                switch (highlight) {
                case 0: {
                    //LISTAS SIMPLES
                    cout << "Tipo de lista seleccionado: " << mainChoices[highlight] << endl;
                    switch (subHighlight) {
                        case 0:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Simple y el ordenamiento de Intercambio
                            break;
                        case 1:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Simple y el ordenamiento de Burbuja
                            break;
                        case 2:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Simple y el ordenamiento de Quicksort
                            break;
                        case 3:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Simple y el ordenamiento de Shellsort
                            break;
                        case 4:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Simple y el ordenamiento de Distribucion
                            break;
                        case 5:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Simple y el ordenamiento de Radix
                            break;
                        }

                    break;
                }
                case 1: {
                    //LISTAS DOBLES
                    cout << "Tipo de lista seleccionado: " << mainChoices[highlight] << endl;
                    switch (subHighlight) {
                        case 0:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Doble y el ordenamiento de Intercambio
                            break;
                        case 1:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Doble y el ordenamiento de Burbuja
                            break;
                        case 2:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Doble y el ordenamiento de Quicksort
                            break;
                        case 3:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Doble y el ordenamiento de Shellsort
                            break;
                        case 4:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Doble y el ordenamiento de Distribucion
                            break;
                        case 5:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Doble y el ordenamiento de Radix
                            break;
                        }

                    break;
                }
                case 2: {
                    //LISTAS CIRCULARESS
                    cout << "Tipo de lista seleccionado: " << mainChoices[highlight] << endl;
                    switch (subHighlight) {
                        case 0:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular y el ordenamiento de Intercambio
                            break;
                        case 1:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular y el ordenamiento de Burbuja
                            break;
                        case 2:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular y el ordenamiento de Quicksort
                            break;
                        case 3:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular y el ordenamiento de Shellsort
                            break;
                        case 4:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular y el ordenamiento de Distribucion
                            break;
                        case 5:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular y el ordenamiento de Radix
                            break;
                        }

                    break;
                }
                case 3: {
                    //LISTAS CIRCULARES DOBLES
                    cout << "Tipo de lista seleccionado: " << mainChoices[highlight] << endl;
                    switch (subHighlight) {
                        case 0:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular Doble y el ordenamiento de Intercambio
                            break;
                        case 1:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular Doble y el ordenamiento de Burbuja
                            break;
                        case 2:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular Doble y el ordenamiento de Quicksort
                            break;
                        case 3:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular Doble y el ordenamiento de Shellsort
                            break;
                        case 4:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular Doble y el ordenamiento de Distribucion
                            break;
                        case 5:
                            cout << "Ordenamiento seleccionado: " << sortChoices[subHighlight] << endl;
                            //Logica para trabajar con la Lista Circular Doble y el ordenamiento de Radix
                            break;
                        }
                    
                    break;
                }
                }

                system("pause");
                inSubMenu = false;
                listSelected = false;
                break;
            default:
                break;
            }
        }

        if (!inSubMenu && choice != -1) {
            break;
        }
    }

    system("cls");
    if (choice == 4) {
        cout << "Saliendo del programa..." << endl;
    }

    return 0;
}
