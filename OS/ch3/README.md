# Process Investigation Guide

This guide outlines various commands to view and manage process information on Linux systems. It is aimed at system administrators and developers who need to diagnose and monitor system and application behaviors.

## Viewing Process Details

### CPU, Memory Usage, and State

- **Dynamic Overview:**
  - `top`: Shows a dynamic overview of running processes.
  - `htop`: Provides a more interactive and visually appealing overview (if installed).

### Snapshot of Current Processes

- **List Processes:**
  - `ps aux`: Displays all running processes with detailed information.
  - `ps -ef`: Another format for listing all running processes.

## Inspecting Low-level Process Details

### Program Counter, CPU Registers

- **GNU Debugger (GDB):**
  - `gdb -p <PID>`: Attach GDB to a running process using its PID to inspect lower-level details like program counter and CPU registers.

## Memory Management

### Viewing Memory Allocation

- **Memory Map:**
  - `pmap <PID>`: Displays the memory map of a specific process.

## Performance Measurement

### Execution Time and Resources

- **Time Command:**
  - `time <command>`: Measures the execution time and resources used by a command.
  - Real: The total elapsed time (wall clock time) it took to execute the command from start to finish, as if you'd timed it with a stopwatch 
    This includes all sorts of delays, like waiting for I/O operations or time slices spent running other processes.
  - User: The amount of CPU time spent in user-mode code (outside the kernel) within the process. This is only the time spent doing   
    computations or executing code in the context of the command you ran.
  - Sys: The amount of CPU time spent in the kernel within the process. This includes time spent for system calls made by the program, like 
    file I/O operations, allocating memory, etc.

## Process Accounting

### Enabling and Viewing Accounting Information

- **Setup:**
  - `sudo apt-get install acct`: Installs the accounting utilities.
  - `sudo /etc/init.d/acct start`: Starts the accounting service.
- **Viewing Summaries:**
  - `sa`: Summarizes accounting information.

## Monitoring File and I/O Usage

### Open Files and I/O Status

- **List Open Files:**
  - `lsof`: Lists open files by all processes.
  - `lsof -p <PID>`: Lists files opened by a specific process.

### I/O Usage

- **Monitoring Tools:**
  - `iotop`: Monitors I/O usage (requires installation and root privileges).
  - `atop`: Provides an overview of various metrics, including I/O (also requires installation).

Please replace `<PID>`, `<nice_value>`, `<new_nice_value>`, and `<command>` with appropriate values for your specific use case.
