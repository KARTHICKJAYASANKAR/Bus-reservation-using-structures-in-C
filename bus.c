#include <stdio.h>
#include <stdbool.h>

#define MAX_SEATS 10

// Structure to represent a bus seat
struct Seat {
    int seatNumber;
    bool isReserved;
    char passengerName[50];
};

// Function to display the available seats
void displaySeats(struct Seat seats[]) {
    printf("Available Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i].isReserved) {
            printf("Seat %d\n", seats[i].seatNumber);
        }
    }
    printf("\n");
}

// Function to reserve a seat
void reserveSeat(struct Seat seats[], int seatNumber, char passengerName[]) {
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].seatNumber == seatNumber && !seats[i].isReserved) {
            seats[i].isReserved = true;
            strcpy(seats[i].passengerName, passengerName);
            printf("Seat %d reserved for passenger %s.\n\n", seatNumber, passengerName);
            return;
        }
    }
    printf("Seat %d is either already reserved or invalid.\n\n", seatNumber);
}

int main() {
    // Create an array of seats
    struct Seat seats[MAX_SEATS];

    // Initialize the seats
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isReserved = false;
        strcpy(seats[i].passengerName, "");
    }

    int choice;
    do {
        printf("Bus Reservation System\n");
        printf("1. Display available seats\n");
        printf("2. Reserve a seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2: {
                int seatNumber;
                char passengerName[50];
                printf("Enter seat number: ");
                scanf("%d", &seatNumber);
                printf("Enter passenger name: ");
                scanf("%s", passengerName);
                reserveSeat(seats, seatNumber, passengerName);
                break;
            }
            case 3:
                printf("Thank you for using the Bus Reservation System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 3);

    return 0;
}
