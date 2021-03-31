#include <stdio.h>
#include <stdlib.h>

int absolute_value(int x)
{
	if (x < 0) {
		x = 0 - x;
	}
	return x;
}

int minimum(int values[], int size)
{
	int smallest = values[0];
	
	for (int i = 1; i < size; i++) {
		if (smallest > values[i]) {
			smallest = values[i];
		}
	}
	return smallest;
}

int distance(int x1, int y1, int x2, int y2)
{
	return absolute_value(x1 - x2) + absolute_value(y1 - y2);
}

int nearest(int rows[], int columns[], int row, int column, int size)
{
	int distances[size];
	for (int i = 0; i < size; i++) {
		distances[i] = distance(rows[i], columns[i], row, column);
	}
	return minimum(distances, size);
}

int main()
{
	int size, cars, parked_x, parked_y, parked_row, parked_column, x, y, row, column;
	printf("Size: ");
	scanf("%d", &size);
	
	while (size > 50 || size < 1) {
		printf("Size must be between 50 and 1\n");
		printf("Size: ");
		scanf("%d", &size);
	}
	
	printf("Cars: ");
	scanf("%d", &cars);

	int parking_area[size][size];
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			parking_area[i][j] = 0;
		}
	}
	
	int parked_rows[cars], parked_columns[cars];
	int capacity = 0;
	
	if (cars >= size * size) {
		x = 0;
		y = 0;
	} else if (cars == 0) {
		x = 1;
		y = 1;
	} else {
		for (int i = 0; i < cars; i++) {
			printf("Locations: ");
			scanf("%d %d", &parked_x, &parked_y);
			if (parked_x > size || parked_x < 1 || parked_y > size|| parked_y < 1);
			else {
				parked_row = size - parked_y;
				parked_column = parked_x - 1;
				parking_area[parked_row][parked_column] = 1;
				parked_rows[capacity] = parked_row;
				parked_columns[capacity] = parked_column;
				capacity++;
			}
		}
		int min_distance;
		int distance = -1; // any min_distance will be larger than -1
		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (parking_area[i][j] == 0) {
					min_distance = nearest(parked_rows, parked_columns, i, j, capacity);
					if (min_distance > distance) { // distance is the largest min_distance
						distance = min_distance;
						row = i;
						column = j;
					} else if (min_distance == distance) {
						if (column > j) {
							column = j;
							row = i;
						} else if (column == j) {
							if (row < i) {
								row = i;
							}
						}
					}
				}
			}
		}
		x = column + 1;
		y = size - row;
	}
	printf("Best Slot Found In: %d %d\n", x, y);
	return EXIT_SUCCESS;
}
