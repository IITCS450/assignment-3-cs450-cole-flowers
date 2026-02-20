1. Setup
- Environment: MIT xv6-public running on QEMU
- CPU Configuration: 2 CPUs enabled
- Process Count: 3 child processes spawned from parent process
- Ticket Distribution:
    - Child 0: 10 tickets
    - Child 1: 20 tickets
    - Child 2: 30 tickets
2. Workload
- Each child process executed a CPU-bound loop of 50,000,000 iterations to compete for scheduler time slices
3. Observed Relative Shares
    Process     Tickets     Ticks Used      Relative Efficiency
    Child 0     10          53              1.00x (Baseline)
    Child 1     20          48              1.10x faster
    Child 2     30          33              1.60x faster
4. Discussion on Variance and Convergence
- Observed Performance: The results show the correlation between ticket count and CPU priority.
- Probabilistic Nature: In this specific run, Child 1 (20 tickets) and Child 0 (10 tickets) were relatively close in performance (48 vs 53 ticks). This illustrates the probabilistic nature of the lottery scheduler; over short durations, a lower-priority process can still "win" enough lottery draws to stay competitive.
- Convergence: As the workload increases and more lottery draws occur, the Law of Large Numbers dictates that the actual CPU shares will converge more closely to the 1:2:3 ratio assigned by the tickets.
- Scheduler Validation: The testlottery utility passed all validation checks, confirming that the settickets system call correctly handles input validation and ticket assignment.