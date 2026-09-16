# Digital Wallet System — Bug Bounty Codebase

## What this is

This is a small, terminal-based **Digital Wallet System** written in C++,
built as a **bug bounty contest codebase**. It intentionally contains
**exactly 9 bugs** scattered across the files. Contestants must read,
compile, and/or run the code to find and fix each defect.

Bugs range from easy (syntax errors that block compilation) to
moderate (logic errors, wrong types, off-by-one mistakes) to hard
(memory management issues like buffer overflows, leaks, and a
Rule-of-Three violation). The answer key with locations and
explanations is in `BUGS.md` — try to find the bugs yourself first!

## What the program does

A simple terminal wallet app:

1. **Login** — user sets a username/password, then re-enters them to "log in" (simple, non-hashed demo auth).
2. **View Transaction History** — lists all recorded transactions.
3. **Add Transaction** — records a credit (money in) or debit (money out), updates balance.
4. **View Stats** — shows total transactions, net total, average amount, and current balance.
5. **Delete Transaction** — removes a transaction by its ID.
6. **Exit** — quits the program.

Note: because of the intentional bugs, **this codebase will not compile
or run correctly as-is**. That's the point of the contest — get it
building and behaving correctly by finding and fixing every bug.

## Project structure

```
digital-wallet-bug-bounty/
├── include/          # Class headers/declarations
│   ├── User.h
│   ├── Transaction.h
│   ├── Wallet.h
│   ├── Menu.h
│   └── Stats.h
├── src/              # Class implementations + entry point
│   ├── User.cpp
│   ├── Transaction.cpp
│   ├── Wallet.cpp
│   ├── Menu.cpp
│   ├── Stats.cpp
│   └── main.cpp
├── utils/            # Supporting utilities
│   ├── FileStorage.h
│   ├── FileStorage.cpp
│   ├── InputValidator.h
│   └── InputValidator.cpp
├── Makefile
├── README.md
└── BUGS.md           # Answer key — bug locations & descriptions
```

## File-by-file explanation

### `include/User.h`
Declares the `User` class: stores a username and password, and exposes
`checkPassword()` for login verification.

### `include/Transaction.h`
Declares the `TransactionType` enum (`CREDIT`/`DEBIT`) and the
`Transaction` class, which stores a single transaction's ID, type,
amount, description, and timestamp. Also declares a small inline
helper, `isCreditTransaction()`.

### `include/Wallet.h`
Declares the `Wallet` class, which owns the current balance and the
list of transactions. Also declares an inline helper,
`hasSufficientBalance()`, used to check if a debit can be covered.

### `include/Menu.h`
Declares the `Menu` class, which drives the terminal UI: showing the
main menu and dispatching to handlers for each option.

### `include/Stats.h`
Declares the `Stats` class with static helper functions for computing
totals, averages, and printing a summary of wallet activity.

### `src/User.cpp`
Implements `User`'s constructor (allocates and copies the password),
destructor (frees it), and `checkPassword()`.

### `src/Transaction.cpp`
Implements the `Transaction` class constructor and all getters.

### `src/Wallet.cpp`
Implements adding a transaction (with a balance check for debits),
deleting a transaction by ID, and simple getters for balance and
transaction history.

### `src/Menu.cpp`
Implements the main menu loop and the handlers for viewing history,
adding a transaction, viewing stats, and deleting a transaction.

### `src/Stats.cpp`
Implements the total/average calculations and the summary printout
used by the "View Stats" menu option.

### `src/main.cpp`
Program entry point. Handles the simple login flow (set credentials,
re-enter to confirm) and then starts the `Menu` loop.

### `utils/FileStorage.h`
Declares the `FileStorage` class, meant to save/load transactions to
and from a text file for basic persistence.

### `utils/FileStorage.cpp`
Implements writing each transaction as a line of text to a file, and
a stub for loading transactions back.

### `utils/InputValidator.h`
Declares the `InputValidator` class and a small inline helper,
`looksLikeNumber()`, for basic input sanity checks.

### `utils/InputValidator.cpp`
Implements `isNumeric()` (checks every character of a string is a
digit) and `isValidMenuChoice()` (checks a menu choice is in range).

## Building (once bugs are fixed)

### Linux / macOS / Windows (with Make)
```bash
make
./wallet
```

### Windows (without Make)
```cmd
.\build.bat
.\wallet.exe
```

## Contest rules of thumb

- There are **exactly 9 bugs** in total across the codebase (3 Easy, 3 Medium, 3 Hard).
- Bug types include: syntax errors, undeclared variables, infinite
  loops, assignment instead of equality, logic errors, memory management issues, and
  buffer overflows.
- Some bugs prevent compilation entirely; others compile fine but
  cause wrong behavior or crashes at runtime.
