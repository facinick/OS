# OS Algorithms in C++

Welcome to the OS Algorithms repository! This repository contains various operating system algorithms implemented in C++. Each algorithm aims to solve different problems and enhance the efficiency of various processes in an operating system. Below, you'll find a list of the algorithms included in this repository, along with a brief description, usage information, and pseudocode.

## 1. First Come First Serve Non-preemptive Scheduling Algorithm
Description: This algorithm schedules processes based on their arrival time. It follows a non-preemptive approach, meaning that once a process starts executing, it runs until completion.

Usage: This algorithm is useful in scenarios where processes have equal priority and should be executed in the order they arrive.

Pseudocode:
```
initialize waiting time as 0
for each process in the queue:
    calculate the waiting time as the sum of the burst times of previous processes
    update the waiting time for the next process
```

## 2. Best Fit Algorithm
Description: The Best Fit algorithm is a memory allocation technique that assigns the smallest available partition to a process that best fits its size.

Usage: This algorithm is useful for optimizing memory allocation and reducing memory fragmentation.

Pseudocode:
```
initialize the list of free memory partitions
for each process:
    find the smallest available partition that can accommodate the process
    allocate the process to that partition
    update the list of free memory partitions
```

## 3. C-Scan Algorithm
Description: The C-Scan algorithm is a disk scheduling algorithm that provides a more uniform access time to disk requests.

Usage: This algorithm is beneficial in scenarios where the disk arm moves in one direction only and needs to traverse the entire disk to service requests.

Pseudocode:
```
initialize the current head position and direction
while there are pending requests:
    find the next request in the current direction
    move the disk arm to that request and service it
    if there are no more requests in the current direction:
        move the disk arm to the opposite end and continue
```

## 4. Deadlock Detection Algorithm (Banker's)
Description: This algorithm checks for the existence of a deadlock in a resource allocation system by analyzing resource allocation graphs.

Usage: This algorithm helps in identifying whether a system is in a deadlock state, allowing for timely recovery and avoidance of system crashes.

Pseudocode:
```
initialize the resource allocation and request matrices
while there are unprocessed processes:
    find a process that can be executed (with resources available)
    update the available resources and mark the process as processed
if all processes are processed:
    no deadlock exists
else:
    deadlock detected
```

## 5. First Fit Algorithm
Description: The First Fit algorithm is a memory allocation technique that assigns the first available memory partition that can accommodate a process.

Usage: This algorithm is suitable for allocating memory in scenarios where processes have varying sizes and need to be allocated quickly.

Pseudocode:
```
initialize the list of free memory partitions
for each process:
    find the first available partition that can accommodate the process
    allocate the process to that partition
    update the list of free memory partitions
```

## 6. Priority Non-preemptive Scheduling Algorithm
Description: The Priority Non-preemptive Scheduling algorithm assigns priorities to processes and executes them based on their priority. Once a process starts execution, it runs until completion.

Usage: This algorithm is useful when processes have different priorities, and higher-priority processes should be executed first.

Pseudocode:
```
initialize waiting time as 0
for each process in the queue:
    find the process with the highest priority
    calculate the waiting time as the sum of the burst times of previous processes
    update the waiting time for the next process
```

## 7. Round Robin Scheduling Algorithm
Description: The Round Robin scheduling algorithm allocates a fixed time quantum to each process in a cyclic manner. It provides fair CPU time to all processes.

Usage: This algorithm is commonly used in time-sharing systems, where multiple processes are competing for CPU time.

Pseudocode:
```
initialize the time quantum
initialize the queue of processes
while there are processes in the queue:
    select the first process in the queue
    execute the process for the time quantum
    if the process is not completed:
        move the process to the end of the queue
```

## 8. Shortest Job First Non-preemptive Algorithm
Description: The Shortest Job First (SJF) Non-preemptive algorithm selects the process with the shortest burst time and executes it until completion.

Usage: This algorithm is beneficial when the burst times of processes are known in advance and the goal is to minimize the average waiting time.

Pseudocode:
```
initialize waiting time as 0
for each process in the queue:
    find the process with the shortest burst time
    calculate the waiting time as the sum of the burst times of previous processes
    update the waiting time for the next process
```

## 9. Shortest Job First Preemptive Algorithm
Description: The Shortest Job First (SJF) Preemptive algorithm selects the process with the shortest remaining burst time and allows preemption if a shorter job arrives.

Usage: This algorithm is useful when the burst times of processes are dynamic and can change during execution.

Pseudocode:
```
initialize the remaining burst time for each process
while there are processes remaining:
    find the process with the shortest remaining burst time
    execute the process for a fixed time unit
    if the process still has remaining burst time:
        move the process to the end of the queue
```

## 10. Worst Fit Algorithm
Description: The Worst Fit algorithm is a memory allocation technique that assigns the largest available partition to a process.

Usage: This algorithm is suitable for reducing external fragmentation in memory allocation scenarios.

Pseudocode:
```
initialize the list of free memory partitions
for each process:
    find the largest available partition that can accommodate the process
    allocate the process to that partition
    update the list of free memory partitions
```

Please refer to the respective algorithm's source code in this repository for detailed implementation.

## Contributions
Contributions to this repository are welcome! If you'd like to contribute an algorithm implementation or suggest improvements, please feel free to submit a pull request.

## License
This repository is licensed under the [MIT License](LICENSE).
