#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#pragma warning(disable:4996)
#include <math.h>
double rot();
void menю();
void poisk();
int main()
{
	float consts[5][2] = {
		{157.0, 50.0}, {73.0, 100.0}, {30.0, 50.0}, {80.0, 100.0}, {63.0, 100.0}
	};
	setlocale(LC_ALL, "RUS");
	double arr[5][5];
	char  extension[6] = { ".txt\0" };
	char file_name[40];
	puts("Введите название файла в пределах 30 символов (без указания расширения файла)");

	gets(file_name);
	strcat(file_name, extension);
	printf("Имя файла: %s\n", file_name);
	int size = 0;
	FILE* Dokyment;
	Dokyment = fopen(file_name, "rt");
	if (Dokyment == NULL) {
		puts("Не удалось открыть файл");
		fclose(Dokyment);
		exit(0);
	}
	
	
	fseek(Dokyment, 0, SEEK_SET);
	printf("Одиночное Плавание");
	for (int i = 0; i < 5 ; i++) {
		fscanf(Dokyment, "%lf ", &arr[i][0]);
		fscanf(Dokyment, "%lf ", &arr[i][1]);
		fscanf(Dokyment, "%lf ", &arr[i][2]);
		fscanf(Dokyment, "%lf\n", &arr[i][3]);

	}
	
	char names[][30] = {
	"Иванов", "Рыбов", "Акулов", "Жуков", "Синичкин" };
	while (1>0)
	{
		int k;
		printf("\n\nНажмите 1 чтобы показать таблицу, или 2 чтобы вывести список победителей\n");
		scanf_s("%d", &k);
		switch (k) {
		case 1: menю(consts, arr, names);
		break;
		case 2: printf("Введите (через пробел) метраж заплыва и стиль:\n");
			double metr, style;
			scanf_s("%lf %lf", &metr, &style);
			poisk(consts, arr, names, metr, style);
			break;
		default:printf("неизвестная команда\n");
			break;
		}
	}
}
double rot(int k, float consts[5][2], double arr[5][5], int i) {
	if (k == 1.0) {
		if (arr[i][0] == 50) {
			arr[i][4] = 1000 * pow((consts[0][0] / arr[i][1]), 3.0);


		}
		else arr[i][4] = 1000 * pow((consts[1][0] / arr[i][1]), 3.0);
	}
	if (k == 2.0) {
		arr[i][4] = 1000 * pow((consts[2][0] / arr[i][1]), 3.0);
	}
	if (k == 3.0) {
		arr[i][4] = 1000 * pow((consts[3][0] / arr[i][1]), 3.0);
	}
	if (k == 4.0) {
		arr[i][4] = 1000 * pow((consts[4][0] / arr[i][1]), 3.0);
	}


}

void menю(float consts [5][2], double arr[5][5], char names[][30]) {
	setlocale(LC_ALL, "RUS");
	printf("|Спортсмен | Дистанция, м | Время, с | Стиль | Кол-во заплывов|  Очки |");
	double k;
	for (int i = 0; i < 5; i++) {
		k = arr[i][2];
		rot(k, consts, arr, i);

	}
	for (int i = 0; i < 5; i++) {
		printf("\n\n");
		for (int j = 0; j < 5; j++) {
			if (j == 0) {
				printf("%9s      %4.1f       ", names[i], arr[i][j]);
			}
			else { printf("  %4.1f      ", arr[i][j]); }
		}
		
	}

}
void poisk(float consts[5][2], double arr[5][5], char names[][30], double metr, double style)
{
	int k = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i][0] == metr && arr[i][2]==style) {
			printf("%s\n", names[i]);
			k += 1;
		}
	}
	if (k == 0) {
		printf("Ничего не найдено\n");
	}
}
