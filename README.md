# Universal Turing Machine Simulator

## Introduction

A Universal Turing Machine Simulator written in C++

Inspired by [Challenge 208 The Universal Machine"](https://www.reddit.com/r/dailyprogrammer/comments/31aja8/20150403_challenge_208_hard_the_universal_machine/)
from [/r/dailyprogrammer](www.reddit.com/r/dailyprogrammer)

Used the formal definition of a (Single Tape) Turing Machine from *Introduction to the Theory of Computation 3rd Ed p. 168* by Michael J. Sipser.

## Dependencies

* gcc 5.0 and up (need support for c++14)
* GNU Make 4.2.1 and up

## Compiling

### On Linux

Open a terminal and cd into project root directory then type:
```bash
$ make
```

### On Windows

Will put instructions once tested

## Format of sample files

```
Line 1: Alphabet
Line 2: Blank Symbol
Line 3: States (space separated)
Line 4: Start State
Line 5: Accept State
Line 6: Reject State
Line 7: Initial Tape
Line 8 and up: Transition Funciton
    Format of transitions: <StateBefore SymbolBefore = StateAfter SymbolAfter DirectionToMove>
    DirectoToMove is either '<' or '>', Left and Right respectively
```

Check the sample files in src/samples for more information
