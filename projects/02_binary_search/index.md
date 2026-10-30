# Project 3: Recusion/binary search

## Main task
We're going to implement binary search as a recursive function. We first need
some data.

Download [the precode](pre.zip) (don't look at `solution.c`!!!!!!). The file
`generate_primes.c` is a program that finds all the primes less than some
number and writes those primes to a file. Compile and run this program like

```bash
gcc generate_primes.c -o generate_primes
./generate_primes 500000000
```

This takes a couple of minutes and generates a 100MB file `primes.bin` holding an
array of 26355867 prime numbers. The numbers are sorted from smallest to
largest. 

The code in `primes.c` reads `primes.bin` into memory so that you have an array
called `primes` to work with. The assignment is to fill in the `search`
function to do a binary search of the primes array by recursion (see hints). In
`main()` there is a prime and a nonprime defined to help you test your code.

There is no makefile this time so you have to figure out how to compile
`primes.c` for yourself. I recommend you do it by command line and stay away
from any VSCode automatic build thing.

## Bonus tasks
If you finish early, try these extensions:

1. A) Do the binary search as a loop instead of recursively. 
   B) Measure which of the two approaches is faster (by generating lots of
   random searches). Can you explain the results?
2. (Challenging) Assume you have a big array that isn't sorted. You can
   generate one by using `rand()`. The idea that "a binary search is a binary
   search in the right half of the array" can be used in sorting: a quicksort
   is a quicksort on two partitions of the array. Implement quicksort. 

## Resources/hints
Note: most likely neither of the below descriptions are enough for you to
understand recursion, so some web searching is probably needed.

A recursive function is a function that calls itself. For example the following 
function returns `n` factorial, $n! = n\cdot(n-1)\cdot...\cdot2\cdot1=n\cdot(n-1)!$:

```C
int fact(int n) {
    if (n == 1) return 1;
    return n*fact(n-1);
}
```

A recursive binary search goes something like this:

1. check the middle number in the array
2. if what we're looking for is larger than this we must search in the top half of the array
3. otherwise we must search in the lower half.
4. so do a binary search in the correct half
5. once you have split the array so many times that you have only a single
   number left, you either have what you're looking for or the number is not
   here.

In other words a binary search is a binary search in the correct half of the
array. You know which half is correct because the array is sorted. 

