# Benchmarking notes

The original coursework included experimental timing code for Bubble Sort, Quick Sort, and Merge Sort. To make comparisons meaningful:

1. Generate or prepare one input array.
2. Copy the same original array before running each algorithm.
3. Test several input sizes and input orders (random, sorted, reverse-sorted).
4. Reset operation counters for every run.
5. Run each test multiple times and report an average.
6. Avoid drawing conclusions from very small timings; timer resolution and system load can distort results.

The current `src/` programs are interactive demonstrations. Keep benchmark code separate from these programs so each algorithm has a single, clear entry point.
