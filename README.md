# Contact Management System

This project is a simple console-based Contact Management System implemented in C. It allows users to create, view, search, edit, and delete contacts. Contacts are stored in a CSV file, making it easy to manage and access.

## Features

- **Create New Contact**: Add a new contact with details such as name, phone number, email, and address.
- **List Contacts**: View all saved contacts.
- **Search Contact**: Find a contact by name.
- **Edit Contact**: Modify existing contact details.
- **Delete Contact**: Remove a contact from the list.

## Structure

The project consists of the following functions:

- `create_contact()`: Prompts the user to enter details for a new contact and saves it to a CSV file.
- `list_contact()`: Reads and displays all contacts from the CSV file.
- `search_contact()`: Searches for a contact by name and displays their details.
- `edit_contact()`: Allows modification of an existing contact's details.
- `delete_contact()`: Deletes a specified contact from the CSV file.

## Requirements

- C compiler (e.g., GCC)
- Standard C libraries

## How to Compile and Run

1. Save the code in a file named `contact_management.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the code using:
   ```bash
   gcc contact_management.c -o contact_management
   ```
4. Run the program:
   ```bash
   ./contact_management
   ```

## Usage

1. Select an option from the main menu.
2. Follow the prompts to manage your contacts.
3. To exit the program, choose the exit option from the menu.

## License

This project is licensed under the MIT License. Feel free to modify and use it for your own purposes.

## Acknowledgments

- Inspired by the need for a simple contact management solution.
- Thanks to documentation and resources available on C programming.

```
