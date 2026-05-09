# Packet Filtering / Sorting

## Overview
This C program simulates a basic firewall or network packet processing system. It reads a list of incoming network packets from a text file, sorts them based on priority and order of arrival, and then outputs the order in which they should be processed.

## How it Works
The program defines a `Packet` structure with two main attributes:
- `serialNo`: The serial number (arrival ID) of the packet.
- `priority`: The priority level of the packet.

### Execution Flow:
1. **File Reading**: The program reads packet data from a local file named `packets.txt`. The file should contain comma-separated values for `serialNo` and `priority` (up to a maximum of 10 packets).
2. **Sorting Logic (Bubble Sort)**: It applies a Bubble Sort algorithm to order the packets:
   - **Primary sorting**: Packets are sorted by their `priority` in ascending order (where a lower priority number is processed first).
   - **Secondary sorting**: If two packets share the same `priority`, they are sorted by their `serialNo` in ascending order (first to arrive is processed first).
3. **Output**: Finally, the sorted list of packets is printed to the console, demonstrating the precise order in which the firewall should handle them.

## Usage
1. Ensure a file named `packets.txt` exists in the same directory as the executable. The file should have lines containing integer pairs for serial number and priority, separated by a comma (e.g., `101, 2`).
2. Compile and run the program. The processed order will be displayed in the console.
