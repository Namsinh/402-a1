# CPSC 402 Compiler Construction
see [assignment](https://hackmd.io/s/HyaDeaXzN#)


# Assignment 1

This is a warm up exercise for compiler constructions. Source code is stored as a file. So we need to know how to process files. A file is a sequence of characters. The following questions ask you to search for certain sequences of characters in a given file. The following should be considered.

- For efficiency reasons, the search algorithm should have linear time complexity. In fact, the algorithm should process any character only once.

- Your solution should use as data structure only files with operations for open, close, read and write. Moreover, files should be read only one character at a time (and each character should be read only once during a search). Sam Balco (thanks!) provided a [primer](https://hackmd.io/s/H1N5cUkVN#).

- To make things easier, don't think of a file as a sequence of lines, just as a sequence of characters. The end of line symbol can be treated as just another character.

With this in mind write and test, for each of the questions, a program in Java or C/C++ or Python or Haskell which answers the following questions. Below, `*` is the usual wildcard that can stand for any number of any characters. If the answer to the question is yes the program should output a list of numbers containing the positions in the file where the last character of the sequence in question appears. 

- Does the file contain the character `a`? For example, if the file contains the characters `abaab` the output should be `[1,3,4]`. **(1 out of 10)**

- Does the file contain the word (sequence of characters) `ab`? For example, if the file is 'aababc' the out output should be [3,5]. **(1 out of 10)**

- Does the file contain the sequence `aa`? For example, if the file is `aaabaaa` the output should be `[2,3,6,7]`. **(2 out of 10)**

- Does the file contain the word `abc`? For example, if the file is 'aababcabc' the out output should be [6,9]. [Hint: Take [this picture](https://github.com/alexhkurz/compiler-construction/blob/master/abc.pdf) as the specification of your solution. This picture can be implemented either with labels and gotos, or by writing a function `transition(state,char)` that inputs a `state` and a `char` and outputs the state that is reached by reading `char` in `state`. ] **(2 out of 10)**

- Does the file contain the sequence `aa*aa`? Here, `*` is a wildcard that stands for zero or more occurrences of any character. For example, if the file is `abaaaacdbbaabcaa` the output should be `[6,12,16]`. **(2 out of 10)**

- Does the file contain the sequence `aa` or `aab`? For example, if the file is `aaabbaabb`, the output should be `[2,3,5,7,9]`. The challenge here is to not write a program that runs twice through the file, once to search for `aa` and once for `aab`, but to find a way of running through the file only once and to simultaneously search for both strings.  **(2 out of 10)** (There is a mistake: The output `[2,3,5,7,9]` works for `aa` or `abb` for `aa` or `aab` the correct output is `[2,3,4,7,8]`.)

If you want to try something extra ambitious, instead of writing separate programs for the first for items, write one single program that takes as input an arbitrary word and answers all four questions uniformly. Going even further, it is also possible to write programs that search for expressions containing wildcards `*` and or's (written as `+`) such as `aa*bb` and `aa+abb'.




[^footnote1]: Note that the requirement to process any character only once would also extend to any libraries you might want to use. In other words, if you want to reason about how efficient your algorithm is you need to take into account the efficiency of the libraries you use. This is one reason why we restrict the use of libraries for this exercise.
