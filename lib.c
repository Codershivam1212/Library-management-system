#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued; // 0: available, 1: issued
};

void addBook(struct Book books[], int *count) {
    printf("Enter Book ID: ");
    scanf("%d", &books[*count].id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[*count].title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[*count].author);
    books[*count].isIssued = 0; // By default, book is not issued
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("\nID   Title                           Author                      Issued\n");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d%-30s%-25s%s\n",
               books[i].id, books[i].title, books[i].author, books[i].isIssued ? "Yes" : "No");
    }
}

void issueBook(struct Book books[], int count) {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued == 0) {
                books[i].isIssued = 1;
                printf("Book issued successfully!\n");
                return;
            } else {
                printf("Book is already issued.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

void returnBook(struct Book books[], int count) {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued == 1) {
                books[i].isIssued = 0;
                printf("Book returned successfully!\n");
                return;
            } else {
                printf("Book is not issued.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

void deleteBook(struct Book books[], int *count) {
    int id, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < (*count) - 1; j++) {
                books[j] = books[j + 1]; // Shift books left to remove the deleted book
            }
            (*count)--;
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    struct Book books[100];
    int count = 0, choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                issueBook(books, count);
                break;
            case 4:
                returnBook(books, count);
                break;
            case 5:
                deleteBook(books, &count);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
