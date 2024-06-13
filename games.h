#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;

struct Games
{
	char name[100];		//name
	char studio[100];		//Номер карти
	double rating;			//Рейтинг
	double price;			//Кошти

	void seveToTextFile(FILE* fp) {
		fprintf(fp, "\n%s\n%s\n%0.1lf\n%0.1lf", name, studio, rating, price);
	}

	void loadFromtextFile(FILE* fp) {
		fscanf_s(fp, "\n");
		fgets(name, 100, fp);
		name[strlen(name) - 1] = '\0';

		fgets(studio, 100, fp);
		studio[strlen(studio) - 1] = '\0';
		fscanf_s(fp, "%lf", &rating);
		fscanf_s(fp, "\n%lf", &price);
	}
	//Меноди - Функції структури
	void showInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Studio: " << studio << endl;
		cout << "Rating: " << rating << endl;
		cout << "Price: " << price << endl;
	}
	void showTable()
	{
		cout << "|" << setw(30) << name << "|" << setw(30) << studio
			<< "|" << setw(7) << rating
			<< "|" << setw(6) << price << "|" << endl;
		cout << "+---+------------------------------+------------------------------+-------+------+\n";
	}
};