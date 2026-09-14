
# include <stdio.h>

/*
    Note: this file doesn't compile. It's just there in case anyone needs these
    functions
*/
// makes a file on disk of all primes smaller than limit
void generate_primes(unsigned int limit);
int is_prime(long num);




int is_prime(long num)
{

    if (num <= 3)
    {
        return num > 1;
    }
    else if (((num % 2) == 0) || ((num % 3) == 0))
    {
        return 0;
    }
    
    for (long i = 5; (i * i) <= num; i += 6)
    {
        if (((num % i) == 0) || ((num % (i + 2)) == 0))
        {
            return 0;
        }
    } 
    return 1;
}

void generate_primes(unsigned int limit) {
    // allocate space for our primes
    unsigned int num_primes = 1.4*limit/log(limit);  // approximate prime counting function 
    unsigned int* prime_array = malloc(num_primes * sizeof(unsigned int));    
    
    // checks all numbers from 2 to limit
    // work can be cut in half by a simple modification (exercise for the reader)
    unsigned int prime_count = 0;
    for (unsigned int i = 2; i <= limit; i++) {
        if (is_prime(i)) prime_array[prime_count++] = i;

        if (!(prime_count < num_primes)) { printf("Array too small\n"); exit(-1); }

        // progress counter updates every 10k 
        if ((i % 10000) == 0) printf("\r%d %%       ", (int)((100*(float) i)/(float)limit));
    }

    // write to file
    FILE* fpt;
    fpt = fopen("primes.bin", "wb");

    fwrite(&prime_count, sizeof(unsigned int), 1, fpt);  // writes array size
    fwrite(prime_array, sizeof(unsigned int), prime_count, fpt); // writes data

    fclose(fpt);

    printf("\r wrote %d primes to primes.bin\n", prime_count);
}