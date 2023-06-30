# MarketSystem

MarketSystem is a program designed to help a small grocery store manage its inventory and perform sales transactions. It
allows users to add products to the inventory, update stock quantities, modify product prices, make sales, and check the
current cash balance.

## Getting Started

To use MarketSystem, follow the instructions below:

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Installation

1. Clone the repository

```bash
git clone https://github.com/lfelipediniz/MarketSystem.git
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

2. Execute the program (with either of the two commands)

```bash
make run
```

3. To delete the generated files run

```bash
make clean
```

#### Commands and outputs from the program

System functionalities must be requested by means of commands followed by the required data. Commands are representedby
two capital letters. The commands that system must recognize are specified below. The **\_** symbol denotes blank space.

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

#### Test case

<table>
    <thead>
        <tr>
            <th>Input</th>
            <th>Output</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>4 </br>
IP chocolate 10 2.50</br>
IP macarrão 20 3.00</br>
IP pao 25 3.00</br>
IP arroz 20 3.00</br>
VE 0 2 1 1 -1</br>
CS</br>
CE</br>
AE 1 10</br>
MP 1 3.50</br>
VE 3 1 -1</br>
FE</td>
            <td>chocolate 2.50</br>
pao 3.00</br>
macarrao 3.00</br>
macarrao 3.00</br>
Total: 11.50</br>
--------------------------------------------------</br>
Saldo: 111.50</br>
--------------------------------------------------</br>
0 chocolate 9</br>
1 macarrao 18</br>
2 pao 24</br>
3 arroz 20</br>
--------------------------------------------------</br>
arroz 3.00</br>
macarrao 3.50</br>
Total: 6.50</br>
--------------------------------------------------</td>
        </tr>
    </tbody>
</table>

### Authors

| Names                       | USP Number |
| :---------------------------| ---------- |
| Luiz Felipe Diniz Costa     | 13782032   |
| Hélio Márcio Cabral Santos  | 14577862   |
| nome                        | nusp       |

Project for the course "Introduction to Computer Science 1" at the Institute of Mathematics and Computer Science, University of Sao Paulo
