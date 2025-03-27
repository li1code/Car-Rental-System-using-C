#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100

typedef struct {
    char model[50];
    char license_plate[20];
    float daily_rate;
    int is_rented;
} Car;

Car car_list[MAX_CARS];
int car_count = 0;

void add_car() {
    if (car_count >= MAX_CARS) {
        printf("Car list is full!\n");
        return;
    }
    
    Car new_car;
    printf("Enter car model: ");
    scanf("%s", new_car.model);
    printf("Enter license plate: ");
    scanf("%s", new_car.license_plate);
    printf("Enter daily rental rate: ");
    scanf("%f", &new_car.daily_rate);
    new_car.is_rented = 0; // Not rented initially

    car_list[car_count++] = new_car;
    printf("Car added successfully!\n");
}

void rent_car() {
    char license_plate[20];
    printf("Enter license plate of the car to rent: ");
    scanf("%s", license_plate);

    for (int i = 0; i < car_count; i++) {
        if (strcmp(car_list[i].license_plate, license_plate) == 0) {
            if (car_list[i].is_rented) {
                printf("Car is already rented!\n");
            } else {
                car_list[i].is_rented = 1;
                printf("Car rented successfully!\n");
            }
            return;
        }
    }
    printf("Car not found!\n");
}

void return_car() {
    char license_plate[20];
    printf("Enter license plate of the car to return: ");
    scanf("%s", license_plate);

    for (int i = 0; i < car_count; i++) {
        if (strcmp(car_list[i].license_plate, license_plate) == 0) {
            if (!car_list[i].is_rented) {
                printf("Car was not rented!\n");
            } else {
                car_list[i].is_rented = 0;
                printf("Car returned successfully!\n");
            }
            return;
        }
    }
    printf("Car not found!\n");
}

void display_cars() {
    printf("\nAvailable Cars:\n");
    for (int i = 0; i < car_count; i++) {
        if (!car_list[i].is_rented) {
            printf("Model: %s, License Plate: %s, Daily Rate: %.2f\n",
                   car_list[i].model, car_list[i].license_plate, car_list[i].daily_rate);
        }
    }
}

void display_menu() {
    printf("\nCar Rental System Menu:\n");
    printf("1. Add Car\n");
    printf("2. Rent Car\n");
    printf("3. Return Car\n");
    printf("4. Display Available Cars\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_car();
                break;
            case 2:
                rent_car();
                break;
            case 3:
                return_car();
                break;
            case 4:
                display_cars();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}