# Push Swap

## Description
The Push Swap project is an algorithmic challenge designed to sort a stack of integers using a limited set of operations. The goal is to sort the stack with the minimum number of moves.

## Features
- **Sorting Algorithms**: Implements efficient sorting algorithms for stacks of different sizes.
- **Stack Operations**: Utilizes a variety of stack operations to manipulate and sort the stack.
- **Error Handling**: Includes robust error handling for invalid inputs and duplicate values.

## Operations
The following operations are used to sort the stack:
- `sa`, `sb`, `ss`: Swap the first two elements of the stack.
- `pa`, `pb`: Push the top element from one stack to another.
- `ra`, `rb`, `rr`: Rotate the stack upwards.
- `rra`, `rrb`, `rrr`: Rotate the stack downwards.

## Algorithms
1. **Three-Element Sort**: A specific algorithm to sort stacks with three elements.
2. **General Sort**: For stacks with more than three elements, a combination of stack operations is used to move elements between two stacks (`stack_a` and `stack_b`) and sort them. This includes:
   - Finding the node with the maximum value and assigning it an index.
   - Calculating movement costs to optimize operations.
   - Moving elements between stacks until they are sorted.

## Usage
1. Compile the project using `make`.
2. Run the executable with a list of integers as arguments:
   ```sh
   ./push_swap 3 2 5 1 4
   ```
