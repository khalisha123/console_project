#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bus information
struct Bus {
    int busNumber;
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
    float fare;
};

// Define a structure to store user login information
struct User {
    char username[50];
    char password[50];
};

// Dynamic array initialization
struct User* users = NULL;
struct Bus* buses = NULL;

// Initialize with a specified size
int numUsers = 0, numBuses = 0;

// Function to initialize buses
void initializeBuses() {
    numBuses = 3; // Example size
    buses = malloc(numBuses * sizeof(struct Bus));
    if (buses == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Initialize bus data
    buses[0] = (struct Bus){101, "City A", "City B", 50, 50, 500.0};
    buses[1] = (struct Bus){102, "City C", "City D", 40, 40, 400.0};
    buses[2] = (struct Bus){103, "City E", "City F", 30, 30, 300.0};
}

// Function to register a new user
void registerUser() {
    numUsers++;
    users = realloc(users, numUsers * sizeof(struct User));
    if (users == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter new username: ");
    scanf("%s", users[numUsers - 1].username);
    printf("Enter new password: ");
    scanf("%s", users[numUsers - 1].password);
    printf("Registration successful!\n");
}

// Function to display the main menu
void displayMainMenu() {
    printf("\n=== Main Menu ===\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to perform user login
int loginUser(char username[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return the index of the logged-in user
        }
    }
    return -1; // Return -1 if login fails
}

// Main function
int main() {
    // Initialize users (initially empty)
    users = malloc(sizeof(struct User) * 1); // Initial allocation for one user

    initializeBuses(); // Populate buses

    int loggedInUserId = -1; // Index of the logged-in user

    while (1) {
        if (loggedInUserId == -1) {
            displayMainMenu();
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1: { // Login
                    char username[50], password[50];
                    printf("Enter Username: ");
                    scanf("%s", username);
                    printf("Enter Password: ");
                    scanf("%s", password);
                    loggedInUserId = loginUser(username, password);
                    if (loggedInUserId == -1) {
                        printf("Login failed. Please check your username and password.\n");
                    } else {
                        printf("Login successful. Welcome, %s!\n", username);
                    }
                    break;
                }
                case 2: // Register
                    registerUser();
                    break;
                case 3: // Exit
                    printf("Exiting the program.\n");
                    free(users);
                    free(buses);
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    }

    // Cleanup (although we never reach here due to infinite loop)
    free(users);
    free(buses);
    return 0;
}