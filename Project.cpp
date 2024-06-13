#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <cstdio>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include "ArrayTemplate.h"
#include "games.h"
using namespace std;

void showTitle() {
    cout << "+---+------------------------------+------------------------------+-------+------+\n";
    cout << "|" << setw(3) << "№ " << "|" << setw(30) << "Name" << "|" << setw(30) << "Studio"
        << "|" << setw(7) << "Raiting" << "|" << setw(6) << "Price"
        << "|" << endl;
    cout << "+---+------------------------------+------------------------------+-------+------+\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE* Library = nullptr;
    Games* game = nullptr;
    fopen_s(&Library, "Library.txt", "r");
    char now[100] = "";
    char akk[100] = "";
    char pass[4] = "";
    int i = 0;
    fseek(Library, SEEK_SET, 0);
    int NG = 0;

    fscanf_s(Library, "%d", &NG);
    game = new Games[NG];
    for (int i = 0; i < NG; i++)
    {
        game[i].loadFromtextFile(Library);
    }

    if (Library != NULL)
    {
        cout << "Enter mode(Admin, User): ";
        cin >> akk;
        if (string(akk) == "Admin")
        {
            cout << "Enter password: ";
            cin >> pass;
            if (string(pass) == "1a2b")
            {
                char pass[4] = "";
                while (true)
                {
                    i++;
                    cout << endl << "Enter command(Search by, See all, Add element, Editing element, Del element, Sort, Exit): ";
                    if (i == 1)
                    {
                        cin.ignore();
                    }
                    char com[100] = "";
                    cin.getline(com, 100);

                    if (string(com) == "Search by")
                    {
                        cout << endl << "Enter command (Name, Studio, Raiting, Price): ";
                        char sb[100] = "";
                        cin.getline(sb, 100);
                        cout << endl;
                        if (string(sb) == "Name")
                        {

                            cout << "Name: ";
                            char Name[100] = "";
                            cin.getline(Name, 100);
                            cout << endl;
                            for (int i = 0; i < NG; i++)
                            {
                                if (string(Name)==game[i].name)
                                {
                                    game[i].showInfo();
                                }
                            }
                        }
                        else if (string(sb) == "Studio")
                        {

                            cout << "Studio: ";
                            char Studio[100] = "";
                            cin.getline(Studio, 100);
                            cout << endl;
                            for (int i = 0; i < NG; i++)
                            {
                                if (string(Studio) == game[i].studio)
                                {
                                    game[i].showInfo();
                                    cout << endl;
                                }
                            }
                        }
                        else if (string(sb) == "Raiting")
                        {

                            cout << "Raiting < ";
                            int x;
                            cin>>x;
                            cout << endl;
                            for (int i = 0; i < NG; i++)
                            {
                                if (x>game[i].rating)
                                {
                                    game[i].showInfo();
                                    cout << endl;
                                }
                            }
                            cin.ignore();
                        }
                        else if (string(sb) == "Price")
                        {

                            cout << "Price > ";
                            int x;
                            cin >> x;
                            cout << endl;
                            for (int i = 0; i < NG; i++)
                            {
                                if (x > game[i].price)
                                {
                                    game[i].showInfo();
                                    cout << endl;
                                }
                            }
                            cin.ignore();
                        }
                        else {
                            cout << "Not found!\n";
                        }
                    }
                    else if (string(com) == "See all")
                    {
                        cout << endl<< endl;
                        showTitle();
                        for (int i = 0; i < NG; i++)
                        {
                            cout << "| " << i + 1 << " ";
                            game[i].showTable();
                        }
                        cout << endl << endl;
                    }
                    else if (string(com) == "Add element")
                    {
                        cout << endl;
                        Games add;
                        cout << "Enter name: ";
                        cin.getline(add.name, 100);
                        cout << "Enter studio: ";
                        cin.getline(add.studio, 100);
                        cout << "Enter rating: ";
                        cin >> add.rating;
                        cout << "Enter price: ";
                        cin >> add.price;

                        fclose(Library);

                        fopen_s(&Library, "Library.txt", "w");

                        addItemBack(game, NG, add);

                        fprintf(Library, "%d", NG);
                        for (int i = 0; i < NG; i++)
                        {
                            game[i].seveToTextFile(Library);
                        }
                        fclose(Library);

                        cout << endl;
                        cin.ignore();
                    }
                    else if (string(com) == "Editing element")
                    {
                        cout << endl;
                        int k;

                        cout << "Enter num element: ";
                        cin >> k;
                        k--;
                        game[k].showInfo();

                        cout << endl << "Enter command (Name, Studio, Rating, Price): ";
                        cin.ignore();
                        cin.getline(com, 100);
                        if (string(com) == "Name")
                        {
                            cout << "New Name: ";
                            cin.getline(game[k].name, 100);
                        }
                        else if (string(com) == "Studio")
                        {
                            cout << "New Studio: ";
                            cin.getline(game[k].studio, 100);
                        }
                        else if (string(com) == "Rating")
                        {
                            cout << "New Rating: ";
                            cin >> game[k].rating;
                            cin.ignore();
                        }
                        else if (string(com) == "Price")
                        {
                            cout << "New Price: ";
                            cin >> game[k].price;
                            cin.ignore();
                        }

                        fclose(Library);

                        fopen_s(&Library, "Library.txt", "w");

                        fprintf(Library, "%d", NG);
                        for (int i = 0; i < NG; i++)
                        {
                            game[i].seveToTextFile(Library);
                        }
                        fclose(Library);

                    }
                    else if (string(com) == "Del element")
                    {
                        cout << endl;
                        int k;

                        cout << "Enter num element: ";
                        cin >> k;

                        fclose(Library);

                        fopen_s(&Library, "Library.txt", "w");

                        delItem(game, NG, k - 1);

                        fprintf(Library, "%d", NG);
                        for (int i = 0; i < NG; i++)
                        {
                            game[i].seveToTextFile(Library);
                        }
                        fclose(Library);

                        cout << endl;
                        cin.ignore();
                    }
                    else if (string(com) == "Sort")
                    {
                        cout << "Enter command (Name, Raiting, Price): ";
                        cin.getline(com, 100);
                        if (string(com) == "Name")
                        {
                            my_sort<Games>(game, NG, [](Games a, Games b) {return strcmp(a.name, b.name) > 0; });
                        }
                        else if (string(com) == "Raiting")
                        {
                            my_sort<Games>(game, NG, [](Games a, Games b) {return b.rating > a.rating > 0; });
                        }
                        else if (string(com) == "Price")
                        {
                            my_sort<Games>(game, NG, [](Games a, Games b) {return b.price > a.price > 0; });
                        }

                        fclose(Library);

                        fopen_s(&Library, "Library.txt", "w");

                        fprintf(Library, "%d", NG);
                        for (int i = 0; i < NG; i++)
                        {
                            game[i].seveToTextFile(Library);
                        }
                        fclose(Library);
                    }
                    else if (string(com) == "Exit")
                    {
                        fclose(Library);
                        cout << "File save";
                        return 0;
                    }
                    else
                    {
                        fclose(Library);
                        cout << endl<<"Command incorrect"<<endl;
                    }
                }
            }
            else
            {
                fclose(Library);
                cout << "Password incorrect";
            }
        }
        else if (string(akk) == "User")
        {
            while (true)
            {
                i++;
                cout << endl << "Enter command(Search by, See all, Sort, Exit): ";
                if (i == 1)
                {
                    cin.ignore();
                }
                char com[100] = "";
                cin.getline(com, 100);

                if (string(com) == "Search by")
                {
                    cout << endl << "Enter command (Name, Studio, Raiting, Price): ";
                    char sb[100] = "";
                    cin.getline(sb, 100);
                    cout << endl;
                    if (string(sb) == "Name")
                    {

                        cout << "Name: ";
                        char Name[100] = "";
                        cin.getline(Name, 100);
                        cout << endl;
                        for (int i = 0; i < NG; i++)
                        {
                            if (string(Name) == game[i].name)
                            {
                                game[i].showInfo();
                            }
                        }
                    }
                    else if (string(sb) == "Studio")
                    {

                        cout << "Studio: ";
                        char Studio[100] = "";
                        cin.getline(Studio, 100);
                        cout << endl;
                        for (int i = 0; i < NG; i++)
                        {
                            if (string(Studio) == game[i].studio)
                            {
                                game[i].showInfo();
                                cout << endl;
                            }
                        }
                    }
                    else if (string(sb) == "Raiting")
                    {

                        cout << "Raiting < ";
                        int x;
                        cin >> x;
                        cout << endl;
                        for (int i = 0; i < NG; i++)
                        {
                            if (x > game[i].rating)
                            {
                                game[i].showInfo();
                                cout << endl;
                            }
                        }
                        cin.ignore();
                    }
                    else if (string(sb) == "Price")
                    {

                        cout << "Price > ";
                        int x;
                        cin >> x;
                        cout << endl;
                        for (int i = 0; i < NG; i++)
                        {
                            if (x > game[i].price)
                            {
                                game[i].showInfo();
                                cout << endl;
                            }
                        }
                        cin.ignore();
                    }
                    else {
                        cout << "Not found!\n";
                    }
                }
                else if (string(com) == "See all")
                {
                    cout << endl << endl;
                    showTitle();
                    for (int i = 0; i < NG; i++)
                    {
                        cout << "| " << i + 1 << " ";
                        game[i].showTable();
                    }
                    cout << endl << endl;
                }
                else if (string(com) == "Sort")
                {
                    cout << "Enter command (Name, Raiting, Price): ";
                    cin.getline(com, 100);
                    if (string(com) == "Name")
                    {
                        my_sort<Games>(game, NG, [](Games a, Games b) {return strcmp(a.name, b.name) > 0; });
                    }
                    else if (string(com) == "Raiting")
                    {
                        my_sort<Games>(game, NG, [](Games a, Games b) {return b.rating > a.rating > 0; });
                    }
                    else if (string(com) == "Price")
                    {
                        my_sort<Games>(game, NG, [](Games a, Games b) {return b.price > a.price > 0; });
                    }

                    fclose(Library);

                    fopen_s(&Library, "Library.txt", "w");

                    fprintf(Library, "%d", NG);
                    for (int i = 0; i < NG; i++)
                    {
                        game[i].seveToTextFile(Library);
                    }
                    fclose(Library);
                }
                else if (string(com) == "Exit")
                {
                    fclose(Library);
                    cout << "File save";
                    return 0;
                }
                else
                {
                    fclose(Library);
                    cout << endl << "Command incorrect" << endl;
                }
            }
        }
        else
        {
            cout << "Not mode";
            fclose(Library);
        }
    }
    else
    {
        cout << "ERROR!!!";
        fclose(Library);
    }

    return 0;
}