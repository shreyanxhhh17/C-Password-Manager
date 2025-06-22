# 🔒 Encrypted Password Manager (C Language)

A simple command-line **Password Manager written in C** that securely stores your credentials in an encrypted file using XOR encryption. This project uses basic C features like file I/O, structs, and string handling to build a fully functional local password storage system.

---

## 🚀 Features

- 🔐 Master password access
- 📝 Add new credentials (website, username, password)
- 📄 View all saved credentials (decrypted view)
- 🔍 Search credentials by website name
- 🗑️ Delete specific credentials
- 🔒 Data stored in encrypted binary file (`data.enc`)
- ❌ No plain-text storage — `data.csv` is intentionally not used

---

## 🛠️ Technologies Used

- **Language:** C
- **Concepts:** Structs, File I/O, XOR encryption, Dynamic Memory
- **Compiler:** `gcc`
- **Platform:** Linux / Windows (CLI)

---

## 📂 Project Structure

![image](https://github.com/user-attachments/assets/ead0eb4c-fc4f-4129-b6c3-0916471ada2b)



---

## 🔧 How to Compile & Run

```bash
# Compile
gcc main.c password_utils.c -o password-manager

# Run
./password-manager
