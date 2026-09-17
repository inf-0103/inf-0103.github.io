# Project 1.1: triangle data structure

## Main task
Get [the precode](../pre.zip). In the `main()` function of the program, use
`draw_line` to draw the object `exampletriangle1`.

## Bonus tasks
If you finish early, try these extensions:

1. implement a `quadrilateral_t` data structure that defines a shape with four
   sides. Bonus points (imaginary) if you define it in its own header. Now
   define and draw a quadrilateral.
2. (more challengeing) Same as 1) but instead of a quadrilateral implement a
   `polygon_t` where you can have an arbitrary number of sides.

## Resources/hints
You might be a little hazy on the structure of a C program. See the 
[very detailed dissection of `Hello, world!` in Beej's guide](https://beej.us/guide/bgc/html/split/hello-world.html#hello-world-1).

The triangles are `structs` 
    ([Beej's guide: structs](https://beej.us/guide/bgc/html/split/structs.html#structs)). 
These are often defined in
    [included](https://beej.us/guide/bgc/html/split/the-c-preprocessor.html#include)
header files. See if you can find the definition of `triangle_t` to start with. And where is the definition of `draw_line`?

