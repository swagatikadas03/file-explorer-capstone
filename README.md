# 🧭 File Explorer - Capstone Project

## 🧠 Project Overview
This project is a **console-based File Explorer** built in **C++**.  
It simulates common file system operations such as creating, listing, viewing info, navigating directories, and removing files/folders.

---

## ⚙️ Features
- `ls` — list files and directories  
- `mkdir <dirname>` — create a new directory  
- `cd <dirname>` — change directory  
- `touch <filename>` — create an empty file  
- `info <filename>` — display file information (path, size, type)  
- `rm <name>` — delete file or directory  
- `exit` — close the program  

---

## 🧩 Technologies Used
- C++17  
- Linux (Ubuntu WSL)  
- Filesystem library (`<filesystem>`)  
- GNU Make & GitHub  

---

## 🧱 Build Instructions
1. Clone the repository:
   ```bash
   git clone git@github.com:swagatikadas03/file-explorer-capstone.git
   cd file-explorer-capstone

2. Compile the code using:

   make

3. Run the program:

   ./file_explorer
