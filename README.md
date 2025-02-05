# Library Management System (Prototype)

## Overview
This project is a **Library Management System** developed as a final semester project. It serves as a **prototype** for a more comprehensive library system that will be further enhanced in the future. The system is designed **without using object-oriented programming (OOP)** and is instead built using **functions and structures** in C++.

## Features
The current version of the system includes the following functionalities:

### 1. **Book Management**
- Stores and manages book records, including:
  - Book Name
  - Author Name
  - ISBN Number
- Allows staff to add books to the system.
- Displays a list of all books stored in the system.

### 2. **Student Management**
- Maintains student records, including:
  - Student Name
  - Father's Name
  - Membership Type (Executive, Premium, Gold)
  - Student ID
- Allows staff to add new student records.
- Displays all registered students.

### 3. **Book Issuing System**
- Allows students to issue books based on their membership type.
- Applies discounts based on membership type:
  - **Executive**: 10% discount, maximum issue period of 3 days.
  - **Premium**: 20% discount, maximum issue period of 6 days.
  - **Gold**: 30% discount, maximum issue period of 9 days.
- Records issued book details in a file for tracking.

### 4. **Book Return System**
- Enables students to return books.
- Stores returned book details in a file for record-keeping.

### 5. **User Authentication**
- Supports two types of logins:
  - **Staff Login** (Password: `1234`)
  - **Student Login** (Password: `786`)
- Limits incorrect password attempts to prevent unauthorized access.

## File Management
- **Books Data** is stored in `books1.txt`.
- **Students Data** is stored in `students1.txt`.
- **Issued Books Records** are stored in `issued_books.txt`.
- **Returned Books Records** are stored in `returned_books.txt`.

## Future Enhancements
This prototype is a stepping stone toward a **fully developed library management system**. Future improvements will include:
- **Implementation of OOP principles** for better code structure and maintainability.
- **Database integration** instead of file storage.
- **Graphical User Interface (GUI)** for better user interaction.
- **Fine calculation** for late book returns.
- **Automated notifications** for book due dates.

## How to Use
1. **Run the program** in a C++ compiler.
2. **Log in** as a staff or student.
3. **Perform desired actions** such as adding books, issuing or returning books, or viewing records.

## Contributors
This project was developed as part of our **final semester project** by our team. We appreciate any feedback and suggestions for future improvements.

## License
This project is free to use and modify for educational purposes.

---
Thank you for checking out our Library Management System! 🚀

