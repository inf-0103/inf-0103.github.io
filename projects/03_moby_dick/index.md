# Project 3: Moby-Dick (or The Whale)

## Main task
On [wikipedia](https://en.wikipedia.org/wiki/Whale) we can read that the
creatures we informally call whales

> correspond to large members of the infraorder Cetacea, i.e. all cetaceans
> apart from dolphins and porpoises. 

Download [the file `moby_dick.txt`](misc/moby_dick.txt), which is just the book
Moby-Dick in plain text. Melville was no scientist, but we are. Your task is to
write a program that 

1. reads `moby_dick.txt`,
2. replaces every occurrence of `"whale"` with `"cetacean (but neither dolphin nor
   porpoise)"`, and
3. writes the new text to a file called `moby_dick_fixed.txt`.

## Bonus tasks
If you finish early, try these extensions:

1. This doesn't really make sense with the plural `"whales"`. Can you fix it?
   Are there other cases we're not covering?
2. Write a program that encrypts the file `moby_dick_fixed.txt`. I suggest you
   do the [Vigenére cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
   with key `"whale"`. Make sure you're able to decrypt the encrypted file
   afterward! 

## Resources/hints
Beej's guide has a 
[page on file operations](https://beej.us/guide/bgc/html/split/file-inputoutput.html#file-inputoutput)
and 
[one on strings](https://beej.us/guide/bgc/html/split/strings.html#strings). 

Consider: do you need ALL of Moby Dick to test your code during development?

I provide no precode or makefile so part of the task is to start the project
and compile it on your own. 

Here is [a suggested solution](misc/whale_fixer.c) but don't look at it.

