## Objetives                                                   

To write a program named push_swap that takes as an argument the stack A formatted as a list of integers. 

The first argument should be at the top of the stack.
                
The goal is to sort in ascending order numbers into stack A, with the lowest possible number of operations. 

There are 2 stacks named A and B.
At the beginning:
- The stack A contains a random amount of negative and/or positive numbers
which cannot be duplicated.
- The stack B is empty.


To do so there are the following operations:
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1.
- rb (rotate b): Shift up all elements of stack b by 1.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
- rrr : rra and rrb at the same time.
Instructions must be separated by a ’\n’ and nothing else.

If no parameters are specified, the program must not display anything and give the
prompt back.

In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.

![Screenshot 2023-02-08 at 21-06-47 en subject pdf](https://user-images.githubusercontent.com/87911989/217651000-7d40f6e3-a298-4430-8769-09132b8ab140.png)


## Method and Guides

I followed this guide that used the QuickSort method: 
- https://www.youtube.com/watch?v=7KW59UO55TQ

I also used this visualizer to keep track of my mistakes while i was doing the project
- https://github.com/o-reo/push_swap_visualizer
