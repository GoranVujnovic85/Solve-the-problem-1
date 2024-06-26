/*
 ============================================================================
 Name        : RT_RK_day1_2.c
 Author      : Goran Vujnovic
 Version     :
 Copyright   : Your copyright notice
 Description :  У датотеци дат је програм који задати низ најпре уређује у нерастућем
                редоследу, а онда исписује на екран елементе уређеног низа докле год су већи од
		вредности задате симболом TRESHOLD. Програм уз елементе низа исписује и
		индексе које су елементи имали у почетном низу.
		Разумети програм. Проверити да ли ради исправно. Која функција не ради
		исправно? Ставити тачку прекида на почетак те функције. Корак по корак
		извршавати функцију и пратити вредности. Уочити где се грешка дешава и
		отклонити је. Поново проверити програм.
 ============================================================================
 */

#include <stdio.h>

#define TRESHOLD 2000000000u

// Sortira niz values i niz indexes, koji sadrzi prvobitne indekse vrednosti
// Niz se uredjuje u neopadajucem poretku, koricenjem "bubble sort" algoritma
void sort(int* values, int* indexes, int n)
{
	int i;
	int j;
	for (i = 0; i < (n - 1); i++)
		{
			for (j = 0; j < n-i-1; j++)
			{
				if (values[j] > values[j+1])
				{
					int tmp;
					tmp = values[j];
					values[j] = values[j+1];
					values[j+1] = tmp;

					tmp = indexes[j];
					indexes[j] = indexes[j+1];
					indexes[j+1] = tmp;
				}
			}
		}
}


// stampa na ekran vrednosti i njihove prvobitne indekse
// dokle god su vece od vrednosti definisane simbolom TRESHOLD
void print(int* values, int* indexes, int n)
{
	int i = 0;
	printf("Up to the first treshold: ");
	while (values[i] > TRESHOLD)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
}


void main()
{
	int values[10] = {2123874386, -2047433648, 2147287536, 2147000000, -2000021030, 2107487649, 2137433633, 2113426428, 2012345678, 2147182248};
	int indexes[10];
	int n = 10;
	int i;

	sort(values, indexes, n);

	for (i = 0; i < n; i++)
	{
		printf("%d. element: %d", i, values[i]);
		indexes[i] = i;
		printf("\n");
	}

	print(values, indexes, n);
}


