#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#pragma warning(disable:4996)
#include <math.h>
double rot(int consts[5][2], double arr_elem, int j);
void menu(float consts[5][2], double arr[5][5], char names[][30]);
void poisk(float consts[5][2], double arr[5][5], char names[][30], char name[30]);
void file(char file_name[40], char names[5][30], double arr[5][5]);
void orig_menu(float consts[5][2], double arr[5][5], char names[][30]);
void bubbleSort(double arr[5][5], char names[][30]);
int red_ochki(char name[40], double arr[5][5], char names[][30]);
int main()
{

	char names[5][30];
	char orig_names[5][30];
	int consts[2] = {
		43, 30
	};
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double arr[5][5];
	double orig[5][5];
	char  extension[6] = { ".txt\0" };
	char file_name[40];
	puts("Введите название файла в пределах 30 символов (без указания расширения файла)");

	gets(file_name);
	strcat(file_name, extension);
	printf("Имя файла: %s\n", file_name);
	int size = 0;
	file(file_name, names, arr);
	file(file_name, orig_names, orig);

	while (1 > 0)
	{
		int k;
		printf("\n\nНажмите:\n 1 - чтобы показать таблицу с итоговыми значениями и сортировкой по стилю\n 2 - вывести базовую таблицу\n 3 - чтобы вывести спортсмена по имени\n 4 - изменение результатов спортсмена\n 5 - чтобы очистить консоль\n 6 - чтобы выйти из консоли\n");
		scanf_s("%d", &k);
		switch (k) {
		case 1: menu(consts, arr, names);
			break;
		case 2: orig_menu(consts, orig, orig_names);
			break;
		case 3: printf("Введите имя искомого спортсмена (с большой буквы):\n");
			double metr, style;
			char name[40];
			scanf("%s", &name);

			poisk(consts, arr, names, name);
			break;
		case 4: {
			puts("Введите имя искомого спортсмена (с большой буквы):");
			char name[40];
			int flag;
			scanf("%s", &name);
			flag = red_ochki(name, arr, names);
			if (flag == 0) {
				printf("По запросу '%s' ничего не найдено", name);

			}
			else {
				puts("Результаты успешно изменены!!");

			}

		}break;
		case 5:
			system("cls");
			break;
		case 6:
			exit(0);
			break;
		default:printf("неизвестная команда\n");
			break;

		}
	}
}
double rot(int consts[2], double arr_elem, int j) {
	double sum = 0;
	if (j == 0 || j == 1) {
		return 1000 * pow((consts[0] / arr_elem), 3.0);
	}
	else {
		return 1000 * pow((consts[1] / arr_elem), 3.0);
	}
}

void menu(float consts[5][2], double arr[5][5], char names[][30]) {

	setlocale(LC_ALL, "RUS");
	printf("|Спортсмен | Брас 50 м, с | Брас 100 м, с | Кроль 50 м, с | Кроль 100 м, с |   Очки   |");

	double summ = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			summ += rot(consts, arr[i][j], j);
		}
		arr[i][4] = summ;
		summ = 0;
	}
	bubbleSort(arr, names);
	for (int i = 0; i < 5; i++) {
		printf("\n\n");
		for (int j = 0; j < 5; j++) {
			if (j == 0) {
				printf("%9s        %5.1lf ", names[i], arr[i][j]);
			}
			else { printf("     %5.1lf       ", arr[i][j]); }
		}

	}

}
void poisk(float consts[5][2], double arr[5][5], char names[][30], char name[30])
{
	int k = 0;


	for (int i = 0; i < 5; i++) {
		if (strcmp(names[i], name) == 0) {
			printf("Спортсмен %s найден под индексом %d\n", names[i], i);
			k++;
		}
	}
	if (k == 0) {
		printf("Ничего не найдено\n");
	}
}
void file(char file_name[40], char names[5][30], double arr[5][5]) {
	FILE* Dokyment;
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Dokyment = fopen(file_name, "rt");
	if (Dokyment == NULL) {
		puts("Не удалось открыть файл");
		fclose(Dokyment);
		exit(0);
	}

	fseek(Dokyment, 0, SEEK_SET);
	printf("Одиночное Плавание");
	for (int i = 0; i < 5; i++) {
		fscanf(Dokyment, "%s", &names[i]);
		fscanf(Dokyment, "%lf ", &arr[i][0]);
		fscanf(Dokyment, "%lf ", &arr[i][1]);
		fscanf(Dokyment, "%lf ", &arr[i][2]);
		fscanf(Dokyment, "%lf", &arr[i][3]);
	}

}
void orig_menu(float consts[5][2], double arr[5][5], char names[][30]) {
	setlocale(LC_ALL, "RUS");
	printf("|Спортсмен | Брас 50 м, с | Брас 100 м, с | Кроль 50 м, с | Кроль 100 м, с |   Очки   |");
	for (int i = 0; i < 5; i++) {
		printf("\n\n");
		for (int j = 0; j < 5; j++) {
			if (j == 0) {
				printf("%9s        %5.1lf ", names[i], arr[i][j]);
			}
			if (j == 1) {
				continue;
			}
			if (j == 4) {
				printf("        0");
			}
			else { printf("     %5.1lf       ", arr[i][j]); }
		}

	}
}
void bubbleSort(double arr[5][5], char names[][30])
{
	setlocale(LC_ALL, "RUS");


	int max_index;
	for (int i = 0; i < 5; i++) {
		max_index = i;
		for (int j = i + 1; j < 5; j++) {
			if (arr[max_index][4] < arr[j][4]) {
				max_index = j;
			}
		}
		double buffer[5];
		for (int buff = 0; buff < 5; buff++) {
			buffer[buff] = arr[max_index][buff];
			arr[max_index][buff] = arr[i][buff];
			arr[i][buff] = buffer[buff];
		}
		char name_buff[40];
		strcpy(name_buff, names[max_index]);
		strcpy(names[max_index], names[i]);
		strcpy(names[i], name_buff);

	}
}

int red_ochki(char name[40], double arr[5][5], char names[][30]) {
	setlocale(LC_ALL, "RUS");

	int flag = 0;
	int index = 0;
	for (int i = 0; i < 5; i++) {
		if (strcmp(names[i], name) == 0) {

			printf("%s найден\n", name);
			flag++;
			index = i;
			break;
		}
		printf("%s\n", names[i]);
	}
	if (flag == 0) {
		return 0;
	}
	double new_ochki[4];
	puts("Введите дистанции через пробел:");
	scanf("%lf %lf %lf %lf", &new_ochki[0], &new_ochki[1], &new_ochki[2], &new_ochki[3]);
	for (int j = 0; j < 4; j++) {
		arr[index][j] = new_ochki[j];
	}
	return 1;
}
