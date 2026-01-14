# 🏦 Bank Management System (C Project)

A **console-based Bank Management System** written in **C**, designed to manage bank accounts efficiently using a simple **menu-driven interface**.  
The system allows users to manage customer accounts, perform transactions, search records, generate reports, and sort data.

---

## 📌 Features

- 🔐 **User Authentication**
  - Login system using username and password
- 👤 **Account Management**
  - Add new bank accounts
  - Delete accounts *(only if balance = 0)*
  - Modify existing account information
  - Change account status
- 🔎 **Search Operations**
  - Search by account number
  - Advanced search using keywords
- 💰 **Transactions**
  - Deposit money
  - Withdraw money *(withdrawal amount cannot exceed balance)*
  - Transfer money between accounts *(sender balance validation)*
- 📊 **Reports**
  - Display all transactions performed by a specific account
- 🔃 **Sorting**
  - Sort customers by different criteria
- 🧾 **Menu-driven Interface**
  - Simple numbered menu for easy navigation

---

## 🧑‍💻 Team Members

- **Omar Ashour Ragheb** 
- **Yehia Nader Ali** 
- **Omar Mohamed Abdelfatah** 
- **Yassin Tarek Ahmed** 

---

## 🛠️ Technologies & Libraries

- **Language:** C  
- **Compiler:** GCC  
- **Standard Libraries Used:**
  - stdio.h
  - stdlib.h
  - string.h
  - ctype.h
  - time.h

---

## 📂 Project Structure

Bank-Management-System/
│
├── main.c # Program entry point & main menu
├── structs.h # Struct definitions
├── bankaccount.h # Account-related functions
├── transactions.h # Deposit, withdrawal, transfer logic
├── prints.h # Output & display helpers
├── *.c # Function implementations
└── README.md


---

## ▶️ How to Compile and Run

### Compile the project
bash
gcc *.c -o bank_system
./bank_system
📋 Menu Overview

After running the program:

Login

Quit

After successful login, choose from the following operations:
| Option | Operation                            |
| ------ | ------------------------------------ |
| 1      | Add Account                          |
| 2      | Delete Account *(balance must be 0)* |
| 3      | Modify Account                       |
| 4      | Search by Account Number             |
| 5      | Advanced Search                      |
| 6      | Change Account Status                |
| 7      | Withdraw Money                       |
| 8      | Deposit Money                        |
| 9      | Transfer Money                       |
| 10     | Transaction Report                   |
| 11     | Sort Customers                       |
| 12     | Quit Program                         |


⚠️ Rules & Validations

❌ Withdrawal amount must not exceed the account balance

❌ Transfer amount must not exceed sender balance

❌ Accounts with non-zero balance cannot be deleted

✅ Input validation is applied to all critical operations
