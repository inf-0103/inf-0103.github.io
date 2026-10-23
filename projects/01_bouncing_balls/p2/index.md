# Project 2.2: bouncing `object_t`

## Main task
Now that we have a linked list we are going to use it to store a bunch of balls
to make a bouncy ball animation. Specifically we want several balls to bounce
on the screen such that:

* Each ball starts off at the top of the screen with a random speed in the x
  direction. 
* Whenever a ball hits a screen boundary it bounces off at an angle equal to
  the impact angle and loses some speed.
* Eventually each ball comes to a rest at the bottom of the screen.
* Five seconds after coming to a rest a ball is removed from the screen. 

[This video](https://youtu.be/x04-uMLQHQA) demonstrates what we're aiming for. 

To ensure that the balls come to a rest at the bottom of the screen you need a
constant gravitational pull toward the bottom.

Get [the precode](pre_bb.zip) or start with your own from last project. The new
precode provides a linked list and so provides a suggested solution for last
week's project. 

## Bonus tasks
If you finish early, try these extensions:

1. Make it possible for the user to specify how many balls they want in the
   animation. This could be through `argc` and `argv` or by using `scanf`.
2. (More challenging:) Implement collision between the balls also.

## Resources/hints
In `main.c` there is an function `bouncing_balls` that should hold your
animation loop.

Each ball should be represented as a separate `object_t` data structure (see
`object.h`/`object.c`). This data structure contains all variables you need to render the
ball on the screen (translation, scale, model coordinates, etc.). The
object data structure uses floats to represent translation coordinates. This is
to make it easier to handle very small movements (at points, a ball might be
moving at a speed less than a pixel). Cast the translation coordinates into
integers before drawing the triangles on the screen.

The file `sphere_data.h` holds an array of `triangle_t` that make up a ball.

Don't make the bouncing algorithm too complex (unless you want to). Bouncing a
ball off a vertical or horizontal surface can be done without calculating
impact angles.

We suggest you break the task up: see if you can get a single ball to
work first. Then do a list of several balls. It might be a good idea to look at
`list.c` again. What does the iterator do?

Developing a skill for breaking a problem into more manageable parts is very
important: can you break up the animation task itself into smaller parts?
