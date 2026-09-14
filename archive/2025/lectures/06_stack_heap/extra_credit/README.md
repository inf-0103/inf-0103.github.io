# Binary search by recursion

Download and unzip the file 

> https://www.dropbox.com/s/smyipjypgcf0b93/primes.bin.zip?dl=0

which holds a sorted list (smallest to largest) of all prime numbers smaller
than 1bn (50847534 numbers). The code in `primes.c` reads this file
(`primes.bin`) into memory so that you have an array called `primes` to work
with. The assignment is to check whether a number smaller than 1000000000 is
prime by searching this array.

One possibility is to check each number one after another. This takes at most
~50 million comparisons, one for each prime. A binary search is more efficient,
requiring at most log_2(~50 million), or about 25 comparisons. The algorithm is
roughly this:

1. check the middle number in the array
2. if what we're looking for is larger than this we must search in the top half of the array
3. if it is smaller than this we must search in the lower half.
4. define the half you're currently searchin in as a "new" array, go back to first step
5. once you have split the array so many times that you have only a single number left, you either have what you're looking for or the number is not here..

You can define this recursively: a binary search is a binary serach in the
correct half of the array. So: Fill in the `search` function to do a binary
search by recursion. As a bonus you might try to write the same code
sequentially (that is, without using recursion).

A solution is provided in `solution.c` If there is any problems with reading the
primes file I have included code to generate your own `primes.bin` in the `generate_primes.c` file.