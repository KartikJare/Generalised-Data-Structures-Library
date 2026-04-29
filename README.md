# 📚 Generalised Data Structures Library (C++ Templates)

## 📌 Description

The **Generalised Data Structures Library** is a reusable C++ library that provides **generic implementations of fundamental data structures and algorithms** using templates.

This project allows developers to use the same data structure with **any data type**, making it flexible, scalable, and efficient.

---

## 🚀 Features

* 🔁 Generic (Template-based) implementations
* 📦 Multiple Data Structures included
* ⚡ Reusable and modular design
* 🧠 Covers core DSA concepts
* 🧩 Includes both data structures and algorithms

---

## 🛠️ Technologies Used

* Language: **C++**
* Concepts:

  * Templates (Generic Programming)
  * Object-Oriented Programming (OOP)
  * Dynamic Memory Allocation
  * Data Structures & Algorithms

---

## 📂 Data Structures Implemented

### 📌 Linear Data Structures

* Stack (LIFO)
* Queue (FIFO)
* Singly Linked List
* Doubly Linked List
* Singly Circular Linked List
* Doubly Circular Linked List

👉 All implemented using **templates for generic data types** 

---

### 🌳 Non-Linear Data Structures

* Binary Search Tree (BST)

  * Insert
  * Search
  * Traversals (Inorder, Preorder, Postorder)
  * Node counting

---

### 📊 Algorithms Included

#### 🔹 Sorting Algorithms

* Bubble Sort
* Efficient Bubble Sort
* Selection Sort
* Insertion Sort

#### 🔹 Searching Algorithms

* Linear Search
* Bidirectional Search
* Binary Search (Increasing / Decreasing)
* Optimized Binary Search

---

## ⚙️ Project Structure

```bash id="ds1"
Generalised-Data-Structures-Library/
│── DataStructures.cpp
│── README.md
```

---

## ⚙️ How It Works

### 🔹 Generic Programming

All data structures are implemented using **C++ templates**, allowing usage like:

```cpp id="ds2"
StackX<int> s1;
StackX<float> s2;
QueueX<char> q1;
```

---

### 🔹 Example Usage

```cpp id="ds3"
QueueX<int> q;
q.Enqueue(10);
q.Enqueue(20);
q.Display();

StackX<int> s;
s.Push(5);
s.Push(15);
s.Display();
```

---

## 🧑‍💻 Compilation & Execution

```bash id="ds4"
g++ DataStructures.cpp -o app
./app
```

---

## 📂 Sample Output

```id="ds5"
| 10 |- | 20 |-
| 15 |- | 5 |-
```

---

## 📈 Future Improvements

* Add Graph data structures
* Implement Heap / Priority Queue
* Add STL-like iterator support
* Add exception handling
* Split into header + implementation files
* Convert into installable library

---

## 💡 Learning Outcomes

* Mastery of Data Structures
* Understanding Generic Programming
* Memory management in C++
* Writing reusable library code
* Designing scalable systems

---

## 👤 Author

**Kartik Ganesh Jare**

---

## 📜 License

All Rights Reserved © 2026
This project is the intellectual property of the author. Unauthorized use is prohibited.

---

## ⭐ Why This Project Matters

This is a **library-level project**, not just practice.

It demonstrates:

* Advanced C++ skills
* Generic programming
* Strong DSA knowledge
* Ability to design reusable systems

👉 This is highly valuable for:

* Product-based companies
* System-level roles
* Software engineering interviews

---
