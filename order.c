#include <stdio.h>
#include "order.h"

// ---- Menu data: two arrays that line up with each other ----
// menuNames[0] goes with menuPrices[0], menuNames[1] with menuPrices[1], etc.
char menuNames[MENU_SIZE][30] = {
    "Fried Rice",
    "Grilled Chicken",
    "Spaghetti",
    "Iced Tea",
    "Chocolate Cake"
};

float menuPrices[MENU_SIZE] = {3.50, 5.00, 4.25, 1.50, 2.75};


// Prints the menu so the customer can see item numbers and prices
void displayMenu(void) {
    int i;
    printf("\n===== MENU =====\n");
    for (i = 0; i < MENU_SIZE; i++) {
        printf("%d. %-20s $%.2f\n", i + 1, menuNames[i], menuPrices[i]);
    }
    printf("================\n");
}


// Uses a pointer so the table number typed here is saved back in main()
void assignTableNumber(int *table_number) {
    printf("\nEnter Table Number: ");
    scanf("%d", table_number);
}


// Adds items to the cart (order_items / order_qty arrays).
// order_count is a pointer because this function needs to change
// the actual counter that main() keeps track of.
// Returns ORDER_SUCCESS if order is valid, ORDER_INVALID if invalid input was entered
int takeOrder(int order_items[], int order_qty[], int *order_count) {
    char add_more;
    int choice, qty;

    do {
        if (*order_count >= MAX_ORDER_ITEMS) {
            printf("Cart is full! Cannot add more items.\n");
            break;
        }

        displayMenu();

        printf("Enter Item Number (1-%d): ", MENU_SIZE);
        scanf("%d", &choice);

        // simple check so the program doesn't crash on a bad number
        if (choice < 1 || choice > MENU_SIZE) {
            printf("Invalid item number, please try again.\n");
            return ORDER_INVALID;  // Return invalid to restart order
        }

        printf("Enter Quantity: ");
        scanf("%d", &qty);

        // store the item as an index (0-4) so it matches the menu arrays
        order_items[*order_count] = choice - 1;
        order_qty[*order_count] = qty;
        (*order_count)++;

        printf("Add more items? (y/n): ");
        scanf(" %c", &add_more);

    } while (add_more == 'y' || add_more == 'Y');
    
    return ORDER_SUCCESS;  // Order completed successfully
}


// Adds up price * quantity for every item in the cart
float calculateSubtotal(int order_items[], int order_qty[], int order_count) {
    float subtotal = 0;
    int i;

    for (i = 0; i < order_count; i++) {
        subtotal = subtotal + (menuPrices[order_items[i]] * order_qty[i]);
    }

    return subtotal;
}


// Prints the final receipt, including the service charge and grand total
void printReceipt(int table_number, int order_items[], int order_qty[], int order_count) {
    float subtotal = calculateSubtotal(order_items, order_qty, order_count);
    float service_charge = subtotal * SERVICE_CHARGE_RATE;
    float total = subtotal + service_charge;
    int i;

    printf("\n========================================\n");
    printf("           RESTAURANT RECEIPT\n");
    printf("========================================\n");
    printf("Table Number: %d\n", table_number);
    printf("----------------------------------------\n");
    printf("%-20s %5s %8s\n", "Item", "Qty", "Price");
    printf("----------------------------------------\n");

    for (i = 0; i < order_count; i++) {
        float lineTotal = menuPrices[order_items[i]] * order_qty[i];
        printf("%-20s %5d %8.2f\n", menuNames[order_items[i]], order_qty[i], lineTotal);
    }

    printf("----------------------------------------\n");
    printf("Subtotal:              %14.2f\n", subtotal);
    printf("Service Charge (10%%):  %14.2f\n", service_charge);
    printf("TOTAL:                 %14.2f\n", total);
    printf("========================================\n");
    printf("        Thank you, come again!\n");
    printf("========================================\n");
}