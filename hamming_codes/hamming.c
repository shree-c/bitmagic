#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ARR_SIZE 8
#define bit(a, n) ((a >> n) & 1)
void printarray(int *arr, int max) {
	printf("printing array: [ ");
	for (int i = 0; i < max; i++) {
		printf("%d ", arr[i]);
	}
	printf(" ]\n\n");
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void fill_random_bits(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 2);
	}
}

int bits_to_flip_in_int(int *arr, int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i]) {
			j ^= i;
		}
	}
	printf("parity bits: %d:\n", j);
	printBits(sizeof(int), &j);
	return j;
}

void set_parity_bits(int *arr, int size) {
	int parity = bits_to_flip_in_int(arr, size);
	for (int i = 0; i < 32; i++) {
		if (bit(parity, i)) {
			int pos = pow(2, i);
			arr[pos] = !arr[pos];
		}
	}
}

		
int main() {
	srand(time(0));
	int arr[ARR_SIZE];
	while (1) {
		printf("generating random array: \n");
		getchar();
		fill_random_bits(arr, ARR_SIZE);
		printarray(arr, ARR_SIZE);
		bits_to_flip_in_int(arr, ARR_SIZE);
		getchar();
		set_parity_bits(arr, ARR_SIZE);
		bits_to_flip_in_int(arr, ARR_SIZE);
		printarray(arr, ARR_SIZE);
		here:
		printf("induce random error between %d to %d pos: bit to flip: ", 0, ARR_SIZE - 1);
		int errpos = 0;
		scanf("%d", &errpos);
		if (errpos > 0 && errpos < ARR_SIZE) {
			arr[errpos] = !arr[errpos];
		} else {
			printf("enter correct pos\n");
			goto here;
		}
		printf("the error is at:>>>>>\n");
		bits_to_flip_in_int(arr, ARR_SIZE);
		printf(">>>>>>\n");
		getchar();
		printf("next random array: \n");
	}
}

