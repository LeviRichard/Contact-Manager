# Contact Management System

## Objective
The Contact Management System is a console-based application written in C that allows users to manage personal and professional contacts efficiently. Users can create, view, search, edit, and delete contacts stored in a CSV file. This project emphasizes file handling, structured programming, and interactive console design.

### Skills Learned
- File handling in C for storing and retrieving contact information in CSV format.  
- Implementing a modular program structure using functions.  
- User input validation and buffer management.  
- String manipulation for processing names, emails, phone numbers, and addresses.  
- Building interactive console menus for CRUD operations.  
- Working with loops, conditionals, and structures (`struct`) to manage data efficiently.

### Tools Used
- C Programming Language  
- Standard C Library (`stdio.h`, `stdlib.h`, `string.h`)  
- Console manipulation functions (`system("cls")`)  
- `conio.h` for keypress handling with `getch()`  

## Features
The system provides the following features:

- **New Contact** – Add a new contact with first name, last name, phone number, email, and address.  
- **List Contacts** – Display all saved contacts in a structured format.  
- **Search Contact** – Search for a contact by first or full name.  
- **Edit Contact** – Update existing contact details selectively.  
- **Delete Contact** – Remove a contact from the CSV file.  
- **Exit** – Close the application gracefully.  

## How to Run
1. Compile the program using a C compiler:  

```bash
gcc main.c -o main
````

2. Run the compiled executable:

```bash
./main
```

3. Follow the on-screen menu to manage your contacts.

## Steps / Screenshots

Drag & drop screenshots here or use Imgur and reference them using `imgsrc`.

*Ref 1: Main Menu*
Shows the primary options: New Contact, List Contacts, Search, Edit, Delete, Exit.

*Ref 2: Creating a Contact*
Input first name, last name, phone number, email, and address.

*Ref 3: Listing Contacts*
Displays all contacts with full details and count.

*Ref 4: Searching a Contact*
Demonstrates searching by name and displaying results.

*Ref 5: Editing a Contact*
Update specific fields (name, phone, email, address) selectively.

*Ref 6: Deleting a Contact*
Confirm deletion and remove the contact from the CSV file.

## Further Improvements

* Add input validation for email and phone number formats.
* Implement sorting of contacts alphabetically.
* Enable multi-user support with login authentication.
* Add GUI interface for improved usability.
* Integrate secure storage mechanisms for sensitive data.

## License

This project is licensed under the MIT License.

## Contributing

Contributions are welcome. Feel free to fork the project and submit pull requests.


