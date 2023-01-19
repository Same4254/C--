#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int *keys;
    int *values;
} AIP_tag;

void initPair(AIP_tag *pairs, int32_t length) {
    srand(3160);

	for (int i = 0; i < length; i++) {
		pairs->keys[i] = rand() % 100;
        pairs->values[i] = i;
    }
}

void printPair(AIP_tag *pairs, int32_t length) {
	for (int i = 0; i < length; i++) {
		printf("<%d, %d>\n", pairs->keys[i], pairs->values[i]);
    }
}
