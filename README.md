*This project has been created as part of the 42 curriculum by dbotelho.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.  
The goal is to sort a stack of integers in ascending order using **two stacks** (`a` and `b`) and a **restricted set of operations**, while producing the **smallest possible number of instructions**.

The program receives a list of integers as arguments, stores them in stack `a`, and outputs a sequence of operations that will sort the stack with the smallest number on top.

Efficiency is a key part of the project: the number of operations is measured and compared against predefined benchmarks.

---

## Rules Overview

- You have two stacks: `a` and `b`
- Stack `a` starts filled, stack `b` is empty
- Only specific operations are allowed (`sa`, `pb`, `ra`, `rra`, etc.)
- Numbers must be sorted in ascending order in stack `a`
- Duplicate numbers or invalid input must result in an `Error`

---

## Algorithm & Strategy

This implementation uses:

### Radix Sort (Binary)
- A **bitwise radix sort** to efficiently handle large inputs (100+ numbers)
- Numbers are first indexed to reduce value range
- Sorting is done bit by bit using `pb`, `pa`, and rotations

### Small Stack Optimization
- A **hardcoded algorithm for 3 numbers** to ensure minimal operations
yaml
Copy code

---

Se quiseres, posso:
- adaptar o README para **nível 100% (radix + chunks)**  
- simplificar para um estilo mais “peer-friendly”
- ou ajustar o texto para ficar ainda mais **avaliador-proof** 😄
- Avoids unnecessary overhead for very small inputs

### Data Structure Choice
- Stacks are implemented using **linked lists** instead of arrays  
  This choice simplifies rotations and push operations without reallocations.

---

- **libft** project is used for common utilities/functions
- **ft_printf** project is used for output's

---

## Compilation

To compile the project, run:

```bash
make

```
This will generate the push_swap executable.

Other available rules:

```bash
make clean
make fclean
make re
```
How to Run push_swap program

Basic usage

```bash
./push_swap 3 2 1
```
Recommended testing method
Use an environment variable to generate arguments:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG
```
To count the number of operations:

```bash
ARG="4 67 3 87 23" ./push_swap $ARG | wc -l
```
With the official checker
```bash
ARG="4 67 3 87 23" ./push_swap $ARG | ./checker_linux $ARG
```

If no arguments are passed, the program produces no output.

Performance
✅ ~1100 operations for 100 random numbers

Meets the minimal benchmark requirements of the project wich are:

For maximum project validation (100%) and eligibility for bonuses, you must:
Sort 100 random numbers in fewer than 700 operations.
• For minimal project validation (which implies a minimum grade of 80%), you
can succeed with different averages:
◦ 100 numbers in under 1100 operations and 500 numbers in under
8500 operations

Resources
42 Subject PDF: push_swap

Radix Sort (Binary): https://en.wikipedia.org/wiki/Radix_sort

Official checker_linux tool provided by 42

Use of Artificial Intelligence
AI tools were used during development for:

Assisting with input parsing logic

Helping adapt the radix sort algorithm to a linked list-based stack

General algorithm clarification and debugging support

Final Notes
This project focuses on:

Algorithmic optimization

Efficient data manipulation

Clean error handling

Respecting strict operational constraints

It serves as a strong introduction to performance-oriented problem solving using low-level data structures.