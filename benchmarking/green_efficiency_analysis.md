# Green Efficiency Analysis

## Measurement Methodology
To measure the execution time of our C program, we added timing markers using the standard `clock()` function from the `<time.h>` library. This function counts the clock cycles (or "ticks") used by the processor while the program is running. We isolated the three main stages of the code to analyze them separately:
* **BUILD_DATA**: The moment where the array is filled with numbers generated one by one.
* **PROCESS**: The mathematical computation phase where each number undergoes multiplications, divisions, and modulos.
* **REDUCE**: The final step that calculates a unique signature (checksum) to verify that the data has not been corrupted.

To get a readable result, we subtract the start time from the end time, then we divide the total by `CLOCKS_PER_SEC` to convert the cycles into precise seconds. Finally, we display the result of REDUCE at the end to force the compiler to perform all calculations.

## Observed Performance Differences
By running the program, we obtained the following exact time measurements:
* **TOTAL seconds**: 0.001026
* **BUILD_DATA seconds**: 0.000418
* **PROCESS seconds**: 0.000413
* **REDUCE seconds**: 0.000182

When analyzing these numbers, we notice that the `BUILD_DATA` and `PROCESS` phases are almost identical and take up the vast majority of the execution time. The `REDUCE` phase is much faster, representing the minority of the total time.

## Relation Between Runtime and Energy Consumption
Execution time and computer energy consumption are linked: the longer and harder a processor works, the more electricity it will consume. Total energy is calculated in watts multiplied by the execution time.

In our case, the `BUILD_DATA` and `PROCESS` phases last the longest. Additionally, `PROCESS` uses operations like division and modulo. These calculations force the processor components to remain active at their maximum performance, which increases the electrical power consumed. Since these two phases last longer and require much more effort, they are the most energy-consuming ones in this code.

## Limitations of the Experiment
This experiment has two important limitations:
1. **The measurement function**: `clock()` only measures the time that the processor spends on our program.
2. **The lack of a physical sensor**: We deduce energy consumption solely from the time written on the screen. We do not have a wattmeter or an external hardware tool to measure the real electrical consumption of the machine.

## Practical Engineering Takeaway
The practical lesson from this analysis is that **to make a program more eco-friendly, optimization efforts must focus on the longest parts**.

Here, trying to speed up the `REDUCE` phase would change almost nothing about the overall consumption, because it is already very fast. If we want to reduce the energy footprint of this code, we must simplify the calculations of the `PROCESS` phase or optimize the data generation in `BUILD_DATA`, because these two blocks consume a large part of the energy.
