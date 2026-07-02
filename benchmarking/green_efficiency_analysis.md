# Green Efficiency Analysis

## Measurement Methodology

To measure the time, we ran the program 3 times to get an average and avoid any weird glitches. We used the standard `clock()` function from `<time.h>` which counts processor ticks. We split the code tracking into three main parts:
* **BUILD_DATA**: where the array gets filled up with numbers.
* **PROCESS**: the math part with all the multiplications, divisions, and modulos.
* **REDUCE**: the final check to see if the data is corrupted.

To get seconds, we do (end_time - start_time) / `CLOCKS_PER_SEC`. We also printed the REDUCE output at the very end so the compiler doesn't skip the calculations.

Here are the 3 runs we got:
* Run 1: TOTAL: 0.001026s | BUILD_DATA: 0.000418s | PROCESS: 0.000413s | REDUCE: 0.000182s
* Run 2: TOTAL: 0.001031s | BUILD_DATA: 0.000420s | PROCESS: 0.000415s | REDUCE: 0.000181s
* Run 3: TOTAL: 0.001021s | BUILD_DATA: 0.000416s | PROCESS: 0.000411s | REDUCE: 0.000183s

Average values:
* TOTAL: 0.001026 seconds
* BUILD_DATA: 0.000418 seconds
* PROCESS: 0.000413 seconds
* REDUCE: 0.000182 seconds

## Observed Performance Differences

Looking at the averages, BUILD_DATA (0.000418 s) and PROCESS (0.000413 s) take almost the exact same time. They consume like 80% of the whole program time. REDUCE is super fast next to them (0.000182 s).

If we compare this code to another implementation that is less optimized, the times change a lot. The slower version uses nested loops and repeats the same operations inside the main loop, which makes the CPU do way too much useless work. That's why the code structure makes a huge difference in the final execution times.

## Relation Between Runtime and Energy Consumption

We are using the runtime as an indirect proxy to estimate energy consumption, we are not measuring real Watts directly from the wall. The logic is simple: a longer runtime means the CPU is active for a longer time. 

When the processor works longer, the transistors switch more, so it uses more power over time. Since BUILD_DATA and PROCESS take the most time (0.000418s and 0.000413s), they keep the CPU busy way longer than REDUCE. Also, PROCESS does hard math like divisions and modulos, which forces the processor components to work at full power, so these two phases are definitely the ones consuming the most energy.

## Limitations of the Experiment

This experiment has two big limitations:
1. **OS scheduling noise**: `clock()` is a software measurement, so it suffers from timing resolution issues and OS background noise or context switching.
2. **No real hardware tools**: We are just guessing energy based on time. We don't have a physical wattmeter or internal hardware sensors like Intel RAPL to see the actual power draw.

## Practical Engineering Takeaway

The takeaway is that if you want to make a program eco-friendly, you must focus on the real bottlenecks. 

Optimizing REDUCE (0.000182 s) is completely useless because it's already too fast to matter. If we want to save energy, we need to fix the nested loops or simplify the math inside the PROCESS phase, or optimize how we generate data in BUILD_DATA.
