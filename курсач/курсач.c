#include <math.h>
#include <stdio.h>
#include <locale.h>
void menю();
void max();
int main()
{
	float consts[5][2] = {
		{157.0, 50.0}, {73.0, 100.0}, {30.0, 50.0}, {80.0, 100.0}, {63.0, 100.0}
	};
	setlocale(LC_ALL, "RUS");
	printf("Одиночное Плавание");
	double arr[5][5] = { {50.0, 166.0, 1.0, 1.0},
					  {100.0, 57.0, 2.0, 1.0},
					  {100.0, 75.0, 3.0, 1.0 },
					  {50.0, 35.0, 4.0, 1.0},
					  {100.0, 93.0, 1.0, 1.0}
	};
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
		case 2: max(consts, arr, names);
			break;
		default:printf("неизвестная команда\n");
			break;
		}
	}
}
void menю(float consts [5][2], double arr[5][5], char names[][30]) {
	setlocale(LC_ALL, "RUS");
	printf("|Спортсмен | Дистанция, м | Время, с | Стиль | Кол-во заплывов|  Очки |");
	double k;
	for (int i = 0; i < 5; i++) {
		k = arr[i][2];
		if (k == 1.0) {
			if (arr[i][0] == 50) {
				arr[i][4] = 1000 * pow((consts [0][0] / arr[i][1]), 3.0);


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
void max(float consts[5][2], double arr[5][5], char names[][30])
{
	double k;
	for (int i = 0; i < 5; i++) {
		k = arr[i][2];
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
	int index = 0;
	double max = 0.0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i][4] > max)
		{
			index = i;
			max = arr[i][4];
		}
	}
	printf("Максимальное количесво очков, среди спортсменов: %s = %5.2f", names [index], max );
}
