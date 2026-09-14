#include <stdio.h>
#include <stdlib.h>

// reads a bunch of prime numbers from disk
void load_primes(unsigned int* count, unsigned int** buffer);

/*
    array: a pointer to a sorted array of integers
    value: an integer we're searching for in this array
    start: index to start searching at (0 to begin with)
    end: index to stop searching at (length of array - 1 to begin with)

    returns 1 if the number is in the array, 0 otherwise
*/
unsigned int search(
    unsigned int *array, 
    unsigned int value, 
    unsigned int start,
    unsigned int end) 
{
    // stop condition!
    if (start == end) {
        return value == array[start];
    }

    // split array in two, search in the correct half
    int middle = (end - start)/2 + start;
    if (value > array[middle]) {
        return search(array, value, middle + 1, end);
    } else {
        return search(array, value, start, middle);
    }
}

// used to read an array of primes
unsigned int Np;
unsigned int* primes;

int main() {
    
    // loads a primes.bin generated with the functions in generate_primes. 
    // the primes pointer will point to this,
    // Np says how many primes are in the array.
    // The array is ordered by increasing size.
    load_primes(&Np, &primes);

    // get a prime number from the array to test
    int number;

    // should return 1
    number = primes[999];
    printf("is %d prime? %d\n", number, search(primes, number, 0, Np-1));
    
    // should return 0
    number = 82;
    printf("is %d prime? %d\n", number, search(primes, number, 0, Np-1));

    return 0;
}



void load_primes(unsigned int* count, unsigned int** buffer) {
    FILE* fpt;
    fpt = fopen("primes.bin", "rb");

    // first read array size
    fread(count, sizeof(unsigned int), 1, fpt);

    // allocate space, read data into array
    *buffer = malloc((* count)*sizeof(unsigned int));
    fread(*buffer, sizeof(unsigned int), *count, fpt);

    printf("read %d primes from primes.bin\n", *count);

    fclose(fpt);
}

