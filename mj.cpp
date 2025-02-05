#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int maxissuedays;
int price = 100;
int returndate;
int issuedate;
int discount;

struct Book {
    string bookname;
    string authorname;
    int isbnumber;
};

struct Student {
    string studentname;
    string fathername;
    string membershipType;
    int studentid;
};

Book books[100];
Student students[100];
int bookCount = 0;
int studentCount = 0;

void readBookData() {
    ifstream fin("books1.txt");
    if (fin.is_open()) {
        bookCount = 0;
        while (fin >> books[bookCount].isbnumber) {
            fin.ignore();
            getline(fin, books[bookCount].bookname, ',');
            getline(fin, books[bookCount].authorname);
            bookCount++;
        }
        fin.close();

        // Display books data
        for (int i = 0; i < bookCount; i++) {
            cout << "Book " << i + 1 << ": " << endl;
            cout << "ISBN: " << books[i].isbnumber << endl;
            cout << "Book Name: " << books[i].bookname << endl;
            cout << "Author Name: " << books[i].authorname << endl;
            cout << "--------------------------" << endl;
        }
    }
}

void writeBookData() {
    ofstream fout("books1.txt", ios::app); // Open file in append mode
    fout << books[bookCount-1].isbnumber << "," << books[bookCount-1].bookname << "," << books[bookCount-1].authorname << endl;
    fout.close();
}

void readStudentData() {
    ifstream fin("students1.txt");
    if (fin.is_open()) {
        studentCount = 0;
        while (fin >> students[studentCount].studentid) {
            fin.ignore();
            getline(fin, students[studentCount].studentname, ',');
            getline(fin, students[studentCount].fathername, ',');
            getline(fin, students[studentCount].membershipType);
            studentCount++;
        }
        fin.close();

        // Display students data
        for (int i = 0; i < studentCount; i++) {
            cout << "Student " << i + 1 << ": " << endl;
            cout << "Student ID: " << students[i].studentid << endl;
            cout << "Student Name: " << students[i].studentname << endl;
            cout << "Father's Name: " << students[i].fathername << endl;
            cout << "Membership Type: " << students[i].membershipType << endl;
            cout << "--------------------------" << endl;
        }
    }
}

void writeStudentData() {
    ofstream fout("students1.txt", ios::app); // Open file in append mode
    fout << students[studentCount-1].studentid << "," << students[studentCount-1].studentname << "," << students[studentCount-1].fathername << "," << students[studentCount-1].membershipType << endl;
    fout.close();
}

int calculateDiscount(string membershipType) {
    if (membershipType == "Executive") {
        return price * 0.10;
    } else if (membershipType == "Premium") {
        return price * 0.20;
    } else if (membershipType == "Gold") {
        return price * 0.30;
    } else {
        return 0;
    }
}

void Executive() {
    maxissuedays = 3;
    discount = price - calculateDiscount("Executive");
    cout << "The final price after discount: " << discount << endl;
}

void Premium() {
    maxissuedays = 6;
    discount = price - calculateDiscount("Premium");
    cout << "Final price after discount is: " << discount << endl;
}

void Gold() {
    maxissuedays = 9;
    discount = price - calculateDiscount("Gold");
    cout << "Final price after discount is: " << discount << endl;
}
void writeIssuedBookData(Student s, Book b, int finalPrice);
void writeReturnedBookData(Student s, Book b);

void issueBook() {
    Student s;
    Book b;

    cout << "Enter student name: ";
    getline(cin, s.studentname);
    cout << "Enter father's name: ";
    getline(cin, s.fathername);
    cout << "Enter student ID: ";
    cin >> s.studentid;
    cin.ignore();
    cout << "Enter membership type: ";
    getline(cin, s.membershipType);

    cout << "Enter book name: ";
    getline(cin, b.bookname);
    cout << "Enter author name: ";
    getline(cin, b.authorname);
    cout << "Enter ISBN number: ";
    cin >> b.isbnumber;
    cin.ignore();

    int discount = calculateDiscount(s.membershipType);
    int finalPrice = price - discount;
    cout << "Book '" << b.bookname << "' issued to " << s.studentname 
         << " (ID: " << s.studentid << ") with membership " << s.membershipType 
         << ". Final price after discount: " << finalPrice << endl;

   
    writeIssuedBookData(s, b, finalPrice);
}

void returnBook() {
    Student s;
    Book b;

    cout << "Enter student name: ";
    getline(cin, s.studentname);
    cout << "Enter father's name: ";
    getline(cin, s.fathername);
    cout << "Enter student ID: ";
    cin >> s.studentid;
    cin.ignore();
    cout << "Enter membership type: ";
    getline(cin, s.membershipType);

    cout << "Enter book name: ";
    getline(cin, b.bookname);
    cout << "Enter author name: ";
    getline(cin, b.authorname);
    cout << "Enter ISBN number: ";
    cin >> b.isbnumber;
    cin.ignore();

    cout << "Book '" << b.bookname << "' returned by " << s.studentname 
         << " (ID: " << s.studentid << ") with membership " << s.membershipType << "." << endl;

    writeReturnedBookData(s, b);
}

void writeIssuedBookData(Student s, Book b, int finalPrice) {
    ofstream fout("issued_books.txt", ios::app);
    fout << s.studentid << "," << s.studentname << "," << s.fathername << "," 
         << s.membershipType << "," << b.bookname << "," << b.authorname << "," 
         << b.isbnumber << "," << finalPrice << endl;
    fout.close();
}

void writeReturnedBookData(Student s, Book b) {
    ofstream fout("returned_books.txt", ios::app);
    fout << s.studentid << "," << s.studentname << "," << s.fathername << "," 
         << s.membershipType << "," << b.bookname << "," << b.authorname << "," 
         << b.isbnumber << endl;
    fout.close();
}




int main() {
	cout<<"                                  ----------------------------------------------"<<endl;
	cout<<"                                      Welcome to Our library Managment Sytem"<<endl;
    cout<<"                                  ----------------------------------------------"<<endl;
    cout<<"\n \n ";
    

    char login;
    cout << "Enter S IF YOU ARE LOGGING IN AS A STAFF ELSE PRESS A FOR STUDENT: ";
    cin >> login;
    int passwordSta;
    int passwordStu;
    string membershipType;
    int choice;
    int attempts = 0;
    int soft;

    if (login == 'S' || login == 's') {
        while (attempts < 5) {
            cout << "Enter password: ";
            cin >> passwordSta;
            if (passwordSta == 1234) {
                cout << "How many times do you want to run the software? " << endl;
                cin >> soft;
                for (int i = 0; i < soft; i++) {
                    cout << "1. Add books to the shelf\n2. Add student data\n3. View all students\n4. View all books\nEnter your choice: ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1) {
                        cout << "Enter book name: ";
                        getline(cin, books[bookCount].bookname);
                        cout << "Enter author name: ";
                        getline(cin, books[bookCount].authorname);
                        cout << "Enter ISB number: ";
                        cin >> books[bookCount].isbnumber;
                        bookCount++;
                        writeBookData();
                    } else if (choice == 2) {
                        cout << "Enter student name: ";
                        getline(cin, students[studentCount].studentname);
                        cout << "Enter father's name: ";
                        getline(cin, students[studentCount].fathername);
                        cout << "Enter student ID: ";
                        cin >> students[studentCount].studentid;
                        cin.ignore();
                        cout << "Enter membership type: ";
                        getline(cin, students[studentCount].membershipType);
                        studentCount++;
                        writeStudentData();
                    } else if (choice == 3) {
                        readStudentData();
                    } else if (choice == 4) {
                        readBookData();
                    }
                }
                return 0;
            } else {
                cout << "Wrong Password. Try again." << endl;
                attempts++;
            }
        }
    } else if (login == 'A' || login == 'a') {
        while (attempts < 5) {
            cout << "Enter password: ";
            cin >> passwordStu;
            if (passwordStu == 786) {
                cout << "How many times do you want to run the software? " << endl;
                cin >> soft;
                cin.ignore();
                for (int i = 0; i < soft; i++) {
                    cout << "1. Issue a book\n2. Return a book\nEnter your choice: ";
                    cin >> choice;
                    cin.ignore();
                    if (choice == 1) {
                        string membershipType;
                        cout << "Enter membership type: ";
                        getline(cin, membershipType);

                        // Set max issue days based on membership type
                        if (membershipType == "Executive") {
                            Executive();
                        } else if (membershipType == "Premium") {
                            Premium();
                        } else if (membershipType == "Gold") {
                            Gold();
                        } else {
                            cout << "Invalid membership type! Defaulting to Executive.\n";
                            Executive();
                        }

                        cout << "Maximum days this book can be issued: " << maxissuedays << " days" << endl;
                        issueBook();
                    } else if (choice == 2) {
                        returnBook();
                    }
                }
                return 0;
            } else {
                cout << "Wrong Password. Try again." << endl;
                attempts++;
            }
        }
    }
    cout << "Too many attempts." << endl;
    
    return 0;
}

