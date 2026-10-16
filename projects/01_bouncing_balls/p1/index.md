# Project 2.1: linked list

## Main task
We are building toward making an animation, but we first need a dynamic data
structure called a _linked list_.

Get [the precode](pre_ll.zip). In `list.c` you will find empty functions that
implement linked list functionality. Your task is to implement these.

For your convenience we have provided a program to test the list
implementation. You can build it by doing `make test` and run it by
`./testlist`. If all checks are OK here it's likely that the list works as
expected but note that you might get an OK on empty functions.

## Bonus tasks
If you finish early, try these extensions:

1. The important part of a linked list is its interface; the user (probably)
   doesn't care how the list is implemented underneath. Change the
   implementation to use an array as the underlying structure instead of
   dynamically allocated list nodes.
2. The list is general enough that you can put anything in it (it takes a void
   pointer). Use `rand()` to fill a list with random numbers and then implement
   a sorting algorithm to sort the list.

## Resources/hints
Look at `struct listnode` and `struct list` to get an idea of how the list
should be built. The linked list is a fundamental data structure and there are
many resources online to learn about it. The [wikipedia
article](https://en.wikipedia.org/wiki/Linked_list) is a good starting point.
Don't look at the C code example! (Or only look at it after you tried doing it
yourself).

The big new idea in this assignment is 
[memory allocation](https://beej.us/guide/bgc/html/split/manual-memory-allocation.html#manual-memory-allocation)
(see espeicially `malloc`/`free` on that page). 

There is also plenty of use of pointers, which technically we introduced in the
fill triangle assignment but we didn't have think too much about them. We do
now so 
[read up on pointers](https://beej.us/guide/bgc/html/split/pointers.html#pointers). 
Notice that the list node holds a 
[`void` pointer](https://beej.us/guide/bgc/html/split/pointers2.html#void-pointers).
Another useful idea is the 
[`NULL` pointer](https://beej.us/guide/bgc/html/split/pointers.html#the-null-pointer).

If you get comfortable with the ideas in this assignment you have mosly figured
out C, the rest is details.

### Testing
A useful idea that we gave you for free this time but that is worth remembering
is the idea that you can write a program that tests your implementation. The
basic approach is very simple:

0. I want to see that my function `f` does as it should
1. and for this input `X` I know that the output should be `Y`
2. so I do `f(X)`
3. and check if the result is `Y`.

You have probably used this approach informally already. The `testlist` program
just automates it.
