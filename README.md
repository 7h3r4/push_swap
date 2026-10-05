*This project has been created as part of the 42 curriculum by abukh, denibyko.*

# push_swap

## Description

`push_swap` sorts a list of integers using two stacks (`a` and `b`) and a
limited set of eleven operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr`). The program reads the numbers as arguments,
computes the sequence of operations that sorts stack `a` in ascending order
and prints that sequence to stdout, one operation per line.

The program embeds four sorting strategies of different complexity classes
(measured in the number of push_swap operations produced, not CPU time):

| Selector     | Strategy                    | Class        |
|--------------|-----------------------------|--------------|
| `--simple`   | insertion sort              | O(n²)        |
| `--medium`   | chunk sort                  | O(n√n)       |
| `--complex`  | LSD radix sort              | O(n log n)   |
| `--adaptive` | chosen by disorder (default)| depends      |

Before any move is made the program measures the **disorder** of the input
(fraction of pairs that are in the wrong order, from 0 to 1). The adaptive
strategy uses that value to pick one of the three algorithms above.

The bonus program `checker` reads a list of operations from stdin, applies
them to the stack given as arguments and prints `OK` if the result is sorted
and `KO` otherwise.

## Instructions

### Build

```sh
make          # builds ./push_swap
make bonus    # builds ./checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # rebuilds everything
```

Compiled with `cc -Wall -Wextra -Werror`. Only `read`, `write`, `malloc`,
`free` and `exit` are used, plus our own libft.

### Run

```sh
./push_swap 2 1 3 6 5 8                 # default: --adaptive
./push_swap --simple 5 4 3 2 1          # force the O(n²) strategy
./push_swap --medium 5 4 3 2 1          # force the O(n√n) strategy
./push_swap --complex 5 4 3 2 1         # force the O(n log n) strategy
./push_swap "3 2 1"                     # numbers may be passed in one string
```

Selector flags and `--bench` must come before the numbers. If the stack is
already sorted nothing is printed. Without arguments the program prints
nothing. On invalid input (non integer, value outside `int`, duplicate,
empty argument) the program prints `Error` on stderr and exits with 1.

### Benchmark mode

`--bench` prints statistics to stderr after sorting; stdout still contains
only the operations, so it can be piped to a checker:

```sh
ARG=$(shuf -i 0-9999 -n 500); ./push_swap --bench $ARG 2> bench.txt | ./checker $ARG
OK
cat bench.txt
[bench] disorder: 50.82%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 6784
[bench] sa: 0 sb: 0 ss: 0 pa: 2284 pb: 2284
[bench] ra: 2216 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### Checker (bonus)

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
printf 'sa\nrra\npb\n' | ./checker 3 2 1 0
KO
printf 'sa\nfoo\n' | ./checker 3 2 1 0
Error
```

Every instruction must be terminated by `\n`; an unknown or malformed
instruction produces `Error`.

## Algorithms

Every number receives an **index** (its rank in the sorted order, from 0 to
n-1) when the stack is created. The medium and complex strategies work on
indexes, which makes them independent of the actual values.

### Simple: insertion sort, O(n²)

Stack `b` is kept sorted in descending order, cyclically (the maximum is not
necessarily on top). For every element on top of `a` we find the position in
`b` where it belongs, rotate `b` the shorter way (`rb` or `rrb`) so that
position comes to the top and push the element with `pb`. When `a` is empty,
`b` is rotated so that its maximum is on top and everything is pushed back
with `pa`.

Upper bound: each of the n insertions costs at most |b|/2 rotations plus one
`pb`, the final phase costs at most n/2 rotations plus n `pa`, so the total is
at most n·(n/2 + 1) + n/2 + n = O(n²) operations. Space: the two stacks only,
O(n).

The algorithm is adaptive by nature: on an almost sorted input every new
element is close to the current maximum of `b`, so it needs almost no
rotation and the real cost is close to 2n.

### Medium: chunk sort, O(n√n)

The index range is divided into k = √n / 2 chunks of s = n / k consecutive
indexes. Chunks are processed from the smallest indexes to the largest: `a`
is rotated with `ra` and every element belonging to the current chunk is
pushed to `b` with `pb`; elements of the lower half of the chunk are then
sent to the bottom of `b` with `rb`, so that the larger ones stay near the
top. When `a` is empty, the maximum of `b` is repeatedly brought to the top
(shorter direction) and pushed back with `pa`.

Upper bound: collecting one chunk needs at most one full rotation of `a`
(≤ n `ra`) plus s `pb` and at most s `rb`, so the first phase costs at most
k·(n + 2s) = O(n√n). In the second phase the maximum of `b` always belongs to
the highest chunk still in `b`, whose elements are either within the top s
positions or at the bottom (reachable with `rrb`), so each of the n `pa`
costs at most s/2 + 1 operations: O(n·√n). Total: O(n√n). Space: O(n).

k = √n / 2 was chosen after measuring: fewer chunks mean fewer rotations of
`a` while collecting, and the `rb` trick keeps the cost of the second phase
low. Measured: about 640 operations for 100 numbers and 5800 for 500.

### Complex: LSD radix sort, O(n log n)

Indexes are sorted bit by bit, least significant bit first. For every bit,
`a` is traversed once: elements whose current bit is 0 are pushed to `b`
(`pb`), elements whose bit is 1 are rotated to the bottom (`ra`); then all of
`b` is pushed back with `pa`. After the pass the stack is sorted by the bits
processed so far. The loop stops early if `a` becomes sorted.

Upper bound: the number of passes is ⌈log₂ n⌉ and each pass costs exactly
n operations for the traversal plus at most n `pa`, so the total is at most
2n·⌈log₂ n⌉ = O(n log n) operations. Space: O(n). The cost does not depend
on the input order at all: 1084 operations for 100 numbers and 6784 for 500.

### Adaptive (default)

The disorder is computed on the input array before any operation. The
thresholds follow the subject:

| Disorder        | Strategy       | Reason                                                    |
|-----------------|----------------|-----------------------------------------------------------|
| d < 0.2         | insertion sort | almost sorted: every element lands near the top of `b`, the real cost is close to linear |
| 0.2 ≤ d < 0.5   | chunk sort     | partial order helps the collection phase (elements of one chunk are close together), and it has the lowest measured cost on this range |
| d ≥ 0.5         | radix sort     | its cost is fixed by n only, so it gives a predictable O(n log n) bound for the worst inputs |

Stacks of 2 or 3 elements are sorted with at most one or two operations and
stacks of 4 or 5 with at most 10 operations (the two smallest elements go to
`b`, the remaining three are sorted, then pushed back). This is only done in
adaptive mode: a forced selector always runs the requested algorithm.

### Measured performance

| Input        | `--simple` | `--medium` | `--complex` | default            |
|--------------|-----------:|-----------:|------------:|--------------------|
| 100 random   | ~1400      | ~640       | 1084        | 640 – 1084         |
| 500 random   | ~32500     | ~5800      | 6784        | 5800 – 6784        |

Random inputs have a disorder close to 0.5, so the default mode selects the
medium or the complex strategy depending on the exact value.

## Contributions

- **denibyko**: project skeleton and header, argument parsing and validation
  (`parse.c`, `process_arr.c`), stack creation and freeing, disorder metric,
  swap operations.
- **abukh**: push, rotate and reverse rotate operations, libft, Makefile,
  sorting strategies, benchmark mode, checker bonus, README.

Both of us reviewed and tested every part of the code.

## Resources

- Push_swap subject, version 1.1 (42 intra)
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Kendall tau distance](https://en.wikipedia.org/wiki/Kendall_tau_distance)
  (the disorder metric is the normalized number of inversions)
- [Linked list](https://en.wikipedia.org/wiki/Linked_list)

### Use of AI

Claude Code (Anthropic) was used for the following tasks:

- implementing the sorting strategies (`issort.c`, `chunk_sort.c`,
  `radix_sort.c`, `small_sort.c`, `sort.c`) after we described the intended
  algorithms, and prototyping the chunk count with a small Python script;
- the `--bench` output (`bench.c`) and the `checker` bonus;
- adapting the operations to a shared context structure so that operations
  can be counted without global variables;
- test scripts (permutation tests, random tests against the checker,
  valgrind runs) and the first draft of this README.

Argument parsing, stack creation, the disorder metric and the stack
operations themselves were written by hand. Every generated part was read,
tested and, where needed, rewritten by us so that both of us can explain it.
