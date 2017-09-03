# Polymorphism in C++ __WITHOUT__ using virtual keyword

_I don't buy into the argument of letting compiler decide which function to call @ runtime._

`"I don't think compiler is intelligent enough to know what I want from my code. So its foolish to depend upon it to decide which function to call when the program executes. As a programmer I should be in control all the time and the code should not decide on its own which function to call at run-time"
`
______________________________________________________________________________________________________________________________
Polymorphism is one of the major backbone of any Object Oriented Programming Languages. However, of late this is being more misused than used.

For example, a class derivation should depict an __IS-A__ relationship. But how many times pure __IS-A__ relations is the reason for derivations. Most of the times it used for reusing the stuffs.

For a code as which spans through a hundreds of thousands of line, a run time polymorphic behavior essentially means that its the compiler and not the programmers, who will decide which function to be called.

As a __programmer__ , I guess, the idea also means that the programmer doesn't know about the code and dependent on compiler for expected behaviour.

The __virtual__ keyword is not only having a runtime cost, but also confuses programmers many a times with a guessing game on behaviors.

This page intends to show how the polymorphic behavior can be achieved in C++ without using runtime cost of __virtual__ which ultimately leads to maintenance related problems

## [ Module 1 : understanding __virtual__ keyword of C++](https://github.com/9lean/CPlusPlus_Polymorphism_Without_Virtual/tree/master/WhatVirtualDoes)


## [ Module 2 : Polymorphism without __virtual__ using C++ Templates](https://github.com/9lean/CPlusPlus_Polymorphism_Without_Virtual/tree/master/PolymorphismWithoutVirtual)
