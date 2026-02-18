*This project has been created as part of the 42 curriculum by paapahid*

🔢 push_swap

📖 Description
This project is part of the 42 curriculum. The main goal is to sort a list of numbers using **two stacks (A and B)** and a limited set of operations, generating the smallest possible number of moves.

Includes:

🎯 Operation count optimization
🧠 Manipulation of dynamic structures (linked lists / stacks)
🧩 Sorting algorithms adapted to constraints

This README is designed so that any external reader can quickly understand the project.

---

⚙️ Instructions

🔧 Compilation

```bash
git clone https://github.com/tuusuario/push_swap.git
cd push_swap
make
```

Cleaning compiled files:

```bash
make clean
make fclean
make re
```

▶️ Execution

```bash
./push_swap [numbers]
```

Examples:

```bash
./push_swap 4 3 2 1
./push_swap "3 5 1 8 2"
```

---

📚 Allowed Operations

Available stack operations:

```
sa  → (swap a) Swap the first 2 elements at the top of stack a.
sb  → (swap b) Swap the first 2 elements at the top of stack b.
ss  → (sa + sb)
pa  → (push a) Take the first element at the top of b and put it at the top of a.
pb  → (push b) Take the first element at the top of a and put it at the top of b.
ra  → (rotate a) Shift up all elements of stack a by 1. The first element becomes the last one.
rb  → (rotate b) Shift up all elements of stack a by 1. The first element becomes the last one.
rr  → (ra + rb)
rra → (reverse rotate a) Shift down all elements of stack a by 1. The last element becomes the first one.
rrb → (reverse rotate b) Shift down all elements of stack a by 1. The last element becomes the first one.
rrr → (rra + rrb)
```

---

🧠 Algorithm Strategy

📌 Small sort (3 numbers)

* Simple algorithm that:
	* Moves the biggest number at the bottom of the stack using ra or rra
	* Swaps the first two elements if they are not in order

📌 Big sort (large inputs)

* In this case the project uses a complex algorithm (turk algorithm):
	* Pushes the first two numbers to B
	* Pushes to B in descending order until three remain in A
	* Sort A (small sort)
	* Pushes numbers back on ascending order

📌 Big sort (4 numbers)

* This is a variation of the Big sort case:
	* Pushes first two numbers to B
	* Sort A in ascending order
	* Sort B in descending order
	* Return to A

📌 Big sort (5 numbers)

* This is a variation of the Big sort case:
	* Pushes the first two numbers to B
	* Sort A (small sort)
	* Sort B in descending order
	* Return to A

---

🛠️ Main Design Choices

📦 Linked lists used to represent stacks
🔢 Pre-indexing to simplify comparisons
♻️ Clear separation between parsing, logic and operations
🧪 Strict argument validation (duplicates, overflow, errors)

---

📂 Project Structure

```
.
├── src/
├── Makefile
└── README.md
```

---

⚠️ Error Handling

The program must:

❌ Detect invalid numbers
❌ Detect duplicates
❌ Detect overflow
❌ Print "Error" followed by a newline

---

📊 Performance

Average number of operations after 100 different tests:

* 3 numbers → ≤ 3 operations
* 5 numbers → ≤ 12 operations
* 100 numbers → < 650 operations
* 500 numbers → < 5550 operations

---

📖 Resources

* [Oceano's push swap tutorial](https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s) --> Understanding push_swap general functionality
* [A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) --> Mechanical Turk (algorithm explanation)
* [Linked lists for absolute beginners](https://www.youtube.com/watch?v=uBZHMkpsTfg&list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl) --> Understanding linked lists
* [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawsonpush-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) --> More reserch for push_swap

---

🤖 Use of AI

Artificial intelligence has been used responsibly and transparently to:

* Review documentation
* Improve the README writing
* Understanding the theory behind popular algorithms

AI was not used to generate evaluable project code.

---

👤 Author

Pavel Apahidean
42 Student – 42 Madrid

[GitHub Profile](https://github.com/papahide)

---

💡 A good algorithm doesn’t just sort, it optimizes.
