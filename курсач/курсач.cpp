#include <iostream>
#include <locale.h>
void menю();
int main()
{
	setlocale(LC_ALL, "RUS");
	printf("Одиночное Плавание");
	while (1>0)
	{
		int k;
		printf("\n\nНажмите 1 чтобы показать таблицу, или 2 чтобы вывести список победителей\n");
		scanf_s("%d", &k);
		switch (k) {
		case 1: menю();
		break;
		case 2: printf("это\n");
			break;
		default:printf("неизвестная команда\n");
			break;
		}
	}
}
void menю() {
	setlocale(LC_ALL, "RUS");
	printf("|Спортсмен | Дистанция, м | Время, с | Стиль | Кол-во заплывов|  Очки |");
	int arr[5][5] = { {50, 166, 1, 1},
					  {100, 57, 2, 1},
					  {100, 75, 3, 1 },
					  {50, 35, 4, 1},
					  {100, 93, 1, 1}
	};
	char names[][30] = {
	"Иванов", "Рыбов", "Акулов", "Жуков", "Синичкин" };
	for (int i = 0; i < 5; i++) {
		printf("\n\n");
		for (int j = 0; j < 5; j++) {
			if (j == 0) {
				printf("%9s      %4d       ", names[i], arr[i][j]);
			}
			else { printf("  %4d      ", arr[i][j]); }
		}

	}
}