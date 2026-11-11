#include <assert.h>
#include <stdio.h>
#include <stdlib.h>  

#define SZ 256

void print_array(int *arr, size_t size) {
  for (int i = 0; i < size; i++) printf("%d, ", arr[i]);
  printf("\n");
}

void swp(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// takes pointers to first and last item in a contiguous arr of ints
void quicksort(int *first, int *last) {
  // some times the pivot ends up first or last in the array so that first >
  // last when we either increase or decrease the pivot pointer in the
  // recursion. otherwise this would just be a check for == (ie we have an
  // array of one item)
  if (first >= last) return;

  /*
     the starts as last item in the array. the idea is to move items that are
     larger than the pivot to the right of the pivot. to do so we must make
     room

     c is current pointer, p is pivot pointer. 8 > 7 so we must move current
         c     p
     1 4 8 9 2 7

     first swap pivot and the item next to pivot. this makes room for 8 to go
     to the right of the pivot value
         c     p
     1 4 8 9 7 2

     then swap current and what p points to (which is no longer the pivot)
         c     p
     1 4 2 9 7 8

     then update pivot pointer so that it again points to pivot
         c   p  
     1 4 2 9 7 8

     next iteration would move c to the next item that's larger than p, ie. 9

  */
  int *pivot = last;
  int *current = first;

  while (current < pivot) {
    // moves current to first item that is on the wrong side of pivot
    while (*current <= *pivot && current < pivot) {
      current++;
    }

    if (current < pivot) {
      // if current and pivot are right next to one another (happens at the
      // last iteration) there is no need to "make room"
      if (current != pivot - 1) swp(pivot, pivot-1);
      swp(current, pivot);
      pivot--;
    } 
  }

  // the pivot is in place so now we just sort the rest of the array
  quicksort(pivot+1, last);
  quicksort(first, pivot-1);

}

int main() {
  int some_array[SZ];

  for (int i = 0; i < SZ; i++) some_array[i] = rand() % (SZ*13);

  printf("before:\n");
  print_array(some_array, SZ);

  quicksort(some_array, some_array+SZ-1);
  
  printf("after:\n");
  print_array(some_array, SZ);

  // this loop checks that the array is indeed sorted
  for (int i=1; i < SZ; i++) assert(some_array[i] >= some_array[i-1]);
}
