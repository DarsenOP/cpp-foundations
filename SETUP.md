# 🚀 C++ Foundations – Setup Guide

This document outlines the complete setup process for using this repository with GitHub, SSH authentication, and CLion.

---

## 1️⃣ Setting Up the GitHub Repository

**📌 Step 1: Create & Clone the Repository**

1. Created a new public GitHub repository: `cpp-foundations`.
2. Cloned the repository into the development folder.
   
   ```bash
   cd ~/Documents/dev
   git clone https://github.com/DarsenOP/cpp-foundations.git
4. Verified Git setup inside the repo.

   ```bash
   git status

---

## 2️⃣ Setting Up CLion for C++ Development

**📌 Step 2: Open in CLion & Configure CMake**

1. Opened CLion and selected `cpp-foundations/` as the project folder.
2. Created `CMakeLists.txt`.
3. Created `main.cpp`.
4. Reloaded CMake.

---

## 3️⃣ Configuring `.gitignore`

**📌 Step 3: Add `.gitignore` to Ignore Unnecessary Files**

1. Created `.gitignore` in `cpp-foundations/`.
2. Added necessary files to ignore.
3. Committed and pushed `.gitignore` to GitHub.

---

## 4️⃣ Setting Up SSH Authentication for GitHub

**📌 Step 4: Generate & Add SSH Key to GitHub**

1. Checked if an SSH key existed.

   ```bash
   ls -al ~/.ssh
3. Generated a new SSH key (if needed).

   ```bash
   ssh-keygen -t rsa -b 4096 -C "my-email@example.com"
5. Copied the public key and added it to GitHub under **Settings → SSH and GPG Keys**.

   ```bash
   cat ~/.ssh/id_rsa.pub
7. Tested SSH connection.

   ```bash
   ssh -T git@github.com
9. Updated Git remote to use SSH instead of HTTPS.

    ```bash
    git remote set-url origin git@github.com:DarsenOP/cpp-foundations.git
11. Verified new remote settings.

    ```bash
    git remote -v
13. Pushed using SSH (no password required anymore!).

    ```bash
    git push origin main

---

## 5️⃣ Organizing Project Structure

**📌 Step 5: Organize Repository for Learning Path**

1. Created day-wise folders.
2. Moved `main.cpp` to `Day_1/`.
3. Updated `CMakeLists.txt` to point to the new location.
4. Committed and pushed the new project structure.

---

## 🎯 Final Setup Summary

✅ GitHub repo (`cpp-foundations`) is fully set up.  
✅ CLion is properly configured with CMake.  
✅ SSH authentication is working (no more password prompts!).  
✅ Project is well-organized with day-wise folders.  
✅ Pushed all changes to GitHub successfully.  
✅ The first C++ program (`main.cpp`) runs successfully.
