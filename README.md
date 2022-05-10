# Philosophers
In this project, we'll be practicing the basics of threading a process. We'll see how to create threads and we'll discover mutexes.

# Notes:
- Add a `-pthread` flag to the compilation command.
- `pthread_t` is the data type which holds the thread ID
- a _Thread_ is the smallest unit of processing that can be performed in an OS
- An Atomic action is one that effectively happens all at once, meaning that it is not splitted into several sub-actions, it either happens or doesn't , and it is 
- Each **Thread** has a its own _Stack_ and set of _Registers_

https://www.section.io/engineering-education/fork-in-c-programming-language/

- A thread shares the same Data Segment _(Uninitialized Data or BSS, and Initialized Data)_, Text Segment _(The actual code instructions of a program)_, and the Heap Segment, though they have independent call Stacks _(i.e. different Stack Segments)_, which are still reachable to each other through pointers _(though messing whith them can lead to undefined behaviour)_.

!!! note Accessing Variables outside our defined Scope
- You can access out-of-scope variables _(belonging to other functions)_ through pointers as long as they still exist, once their calling functions return, the behaviour becomes undefined