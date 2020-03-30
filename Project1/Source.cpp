#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

using namespace std;

struct DannieUser {
	int year;
	int month;
	int day;
	int telephone;
};

struct DanniePoKnige {
	char nazvanie_knigi[20];
	char avtor[50];
	int Tom_knigi;
	int GodIzdaniya;
};

struct User {
	char nameUser[50];
	DannieUser dannie;
	DanniePoKnige dannie_k;
};


int Chelik;
int i(0), g(0), h(0);

User arrayOfUsers[100];
FILE* MoiFile_Rrr;



int reading() {
	if ((MoiFile_Rrr = fopen("text.dat", "rb")) == NULL)
	{
		cout << ("Ne rabotau (9(( ") << endl;
		return 0;
	}
	do
	{
		fread(&arrayOfUsers[Chelik], sizeof(User), 1, MoiFile_Rrr);
		Chelik++;
		if (feof(MoiFile_Rrr)) break;

	} while (1);

	Chelik--;

	cout << "Schitivanie zaversheno" << endl;
	fclose(MoiFile_Rrr);
	system("pause");
	return 0;
}

int outp_to_file() {
	FILE* MoiFile_Rrr;
	if ((MoiFile_Rrr = fopen("text.dat", "wb")) == NULL)
	{
		cout << ("Fail ne sozdan!\n");
		return 0;
	}
	for (int i = 0; i < Chelik; i++)
		fwrite(&arrayOfUsers[i], sizeof(User), 1, MoiFile_Rrr);
	cout << ("Fail zapisan");
	fclose(MoiFile_Rrr);
	system("pause");
	return 0;
}

int input_in_array() {
	int q = 1;
	while (q != 0)
	{
		cout << "\nVvedite svoe Imya: ";
		cin >> arrayOfUsers[i].nameUser;
		cout << "\nVvedite svoi den: ";
		cin >> arrayOfUsers[Chelik].dannie.day;
		cout << "\nVvedite svoi mesyac: ";
		cin >> arrayOfUsers[Chelik].dannie.month;
		cout << "\nVvedite svoi god: ";
		cin >> arrayOfUsers[Chelik].dannie.year;
		cout << "\nVvedite svoi telephone: ";
		cin >> arrayOfUsers[Chelik].dannie.telephone;
		cout << "\nVvedite knigu kotoruu vsiali: ";
		cin >> arrayOfUsers[Chelik].dannie_k.nazvanie_knigi;
		cout << "\nVvedite Avtora_knigi: ";
		cin >> arrayOfUsers[Chelik].dannie_k.avtor;
		cout << "\nVvedite Godizdaniya: ";
		cin >> arrayOfUsers[Chelik].dannie_k.GodIzdaniya;
		cout << "\nVvedite Tom_knigi : ";
		cin >> arrayOfUsers[Chelik].dannie_k.Tom_knigi;
		Chelik++;
		cout << "\nVvedite 0 dlya okonchaniya zapisi ili luboe chislo dlya prodolzheniya: ";
		cin >> q;
		cout << "\n";

	}
	return 0;
}

int VivEkran()
{
	system("cls");
	for (int i = 0; i < Chelik; i++) {
		cout << "***********************************" << endl;
		cout << "Zapis #" << i + 1 << "\n";
		cout << "\ User: " << arrayOfUsers[i].nameUser << "\n";
		cout << "\ den: " << arrayOfUsers[i].dannie.day << "\n";
		cout << "\ mesyac: " << arrayOfUsers[i].dannie.month << "\n";
		cout << "\ god: " << arrayOfUsers[i].dannie.year << "\n";
		cout << "\ telephone: " << arrayOfUsers[i].dannie.telephone << "\n";
		cout << "\ nazvanieKnigi: " << arrayOfUsers[i].dannie_k.nazvanie_knigi << "\n";
		cout << "\ Avtor: " << arrayOfUsers[i].dannie_k.avtor << "\n";
		cout << "\ Godizdaniya : " << arrayOfUsers[i].dannie_k.GodIzdaniya << "\n";
		cout << "\ TomKnigi  : " << arrayOfUsers[i].dannie_k.Tom_knigi << "\n";
		cout << "***********************************" << endl;
		system("pause");

	}
	return 0;
}
int Ydalenie() {
	cout << "\nNomer, kotorogo hotite ydalit': ";
	int u;
	cin >> u;
	for (int i = u; i < Chelik; i++) {
			memcpy((void*)(arrayOfUsers+i - 1), (void*)(arrayOfUsers+i), sizeof(User));               // копируем строку str1  и сохраняем в str2
		
	}
	if (u == 0 && u > Chelik) {
		return 1;
	}
	Chelik--;
	system("pause");
	return 0;
}

int poisk()
{
	cout << "Vvedite god : ";
	int y;
	cin >> y;
	bool not_found = true;
	for (int i = 0; i < Chelik; i++) {
		if (arrayOfUsers[i].dannie.year == y) {
			cout << "Zapis #" << i + 1 << "\n";
			cout << "\ User: " << arrayOfUsers[i].nameUser << "\n";
			cout << "\ den : " << arrayOfUsers[i].dannie.day << "\n";
			cout << "\ mesyac: " << arrayOfUsers[i].dannie.month << "\n";
			cout << "\ god : " << arrayOfUsers[i].dannie.year << "\n";
			cout << "\ telephone : " << arrayOfUsers[i].dannie.telephone << "\n";
			cout << "\ Nazvanie_knigi: " << arrayOfUsers[i].dannie_k.nazvanie_knigi << "\n";
			cout << "\ Avtor: " << arrayOfUsers[i].dannie_k.avtor << "\n";
			cout << "\ Godizdaniya : " << arrayOfUsers[i].dannie_k.GodIzdaniya << "\n";
			cout << "\ Tom  : " << arrayOfUsers[i].dannie_k.Tom_knigi << "\n";
			not_found = false;
			system("pause");
		}
	}
	if (not_found) {
		cout << "Dannie za etot god ne naideni\n";
	}
	return 0;
}


int del_tex()
{
	FILE* MoiFile_Rrr;
	int nomer, i = 0;
	char  tip[80], mas[100];
	int day, god, cena;
	int str = 0;
	char ch;
	if ((MoiFile_Rrr = fopen("text.dat", "r")) == NULL) {
		printf("Невозможно открыть файл.");
		exit(1);
		while (fscanf(MoiFile_Rrr, "%d", &arrayOfUsers[i].dannie.day) != EOF)
			str++;
		printf("kol-vo strok: %d\n", str);

		printf("Введите нормер записи которую надо удалить: \n");
		scanf("%d", &nomer);
		if (nomer<1 || nomer>str) {
			printf("Неправильынй ввод!");

			exit(1);
		}
		else
		{
			//if fscanf(,"%s%s%d%d%d",&tender[i].naz, &tender[i].tip, &tender[i].kol_vo, &tender[i].god, &tender[i].cena)!=EOF{
			for (i = 0; i <= str; i++)
			{

				printf("Введите нормер записи которую надо удалить: \n");
				scanf("%d", &nomer);
				if (nomer < 1 || nomer>10) {
					printf("Неправильынй ввод!");
					exit(1);
				}
				printf("nomer stroki: %d\n", i);
				i++;
			}
		}
		fclose(MoiFile_Rrr);
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	system("color A");

	int chislo = 1;
	while (chislo != 0)
	{
		system("cls");
		cout << "Sdelal' Loskutov Dmitrii Andreevich group 8871" << endl;
		cout << "Menu" << endl;
		cout << "*********************************************" << endl;
		cout << "*1 - Dobavit dannie;                        *" << endl;
		cout << "*2 - Vvod dannih v fail;                    *" << endl;
		cout << "*3 - Shitat dannie        ;                 *" << endl;
		cout << "*4 - Vivisti na ekran vsi dannie;           *" << endl;
		cout << "*5 - Poisk zadolshenikov po gody;           *" << endl;
		cout << "*6 - Ydalenie Zapisi                        *" << endl;
		cout << "*0 - Vihod;                                 *" << endl;
		cout << "*********************************************" << endl;
		cin >> chislo;
		switch (chislo)
		{
		case 1:reading(); break;
		case 2:outp_to_file(); break;
		case 3:input_in_array(); break;
		case 4:VivEkran(); break;
		case 5:poisk(); break;
		case 6:Ydalenie(); break;
		case 0:exit(0); break;
		default:break;
		}
	}


	system("pause");
	return 0;
}