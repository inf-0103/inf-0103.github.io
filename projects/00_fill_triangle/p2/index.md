# Project 1.2: triangle outlines
## Main task
Start with [fresh precode](../pre.zip). Implement the functions `scale_triangle`,
`translate_triangle`, and `calculate_bounding_box`. Draw the outline of the
triangle in `draw_triangle`. Think about how to check that `scale_triangle`
and `translate_triangle` work.

## Bonus tasks
1. implement a `rotate_triangle` that rotates the triangle by a user-specified
   angle
2. (more challenging) implement a `transform_triangle` that applies an
   arbitrary linear transformation of the triangle.

## Hints/resources
Think about how to check that `scale_triangle` and `translate_triangle` work.
What's the best order to approach the main task?

The triangles are passed as pointers to `struct`s. This is different from when
we had just defined a struct as a global object and accessed that directly in
[Project 1.1](../p1/). Have a look at these resources to get an idea of what is
going on

* [Beej's guide: pass by value](https://beej.us/guide/bgc/html/split/functions.html#passvalue)
* [Beej's guide: pointers](https://beej.us/guide/bgc/html/split/pointers.html)
* [Beej's guide: the arrow operator](https://beej.us/guide/bgc/html/split/structs.html#the-arrow-operator)
