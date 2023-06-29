# MarketSystem

MarketSystem is a program designed to help a small grocery store manage its inventory and perform sales transactions. It allows users to add products to the inventory, update stock quantities, modify product prices, make sales, and check the current cash balance.

## Getting Started

To use MarketSystem, follow the instructions below:

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Installation

1. Clone the repository

   ```bash
   git clone https://github.com/your-username/MarketSystem.git
    ```

2. Navigate to the project directory

   ```bash
   cd MarketSystem
   ```

### Usage

1. Compile and run the program using the provided Makefile

      ```bash
   make
    ```

2. Execute the program

      ```bash
   ./marketsystem
    ``` 
    
    or you can use:
   
      ```bash
   make run
    ```


3. To delete the generated files run
   ```bash
   make clean
   ```
#### Commands and outputs from the program
   System functionalities must be requested by means of commands followed by the required data. Commands are representedby two capital letters. The commands that system must recognize are specified below. The **_** symbol denotes blank space.

1. Insert product
   ```c
   IP_<name>_<quantity>_<price>
   ```
2. Increase stock
   ```c
   AE_<code>_<quantity>
    ```
3. Modify price
   ```c
   MP_<code>_<price>
   ```
4. Sale
   ```c
   VE_<code>_<code>_..._<code>_<-1>
   ```
5. Inventory consultation
   ```c
   CE
   ```
6. Balance inquiry
   ```c
   CS
   ```
7. Balance inquiry
   ```c
   FE
   ```

### Authors

Names   | USP Number
:--------- | ------
Luiz Felipe Diniz Costa | 13782032
nome | nusp
nome | nusp

Project for the course "Introduction to Computer Science 1" at the Institute of Mathematics and Computer Science, University of Sao Paulo

