#ifndef ORDER_H
#define ORDER_H

#define MAX_ORDER_ITEMS 20     // max number of different items a table can order
#define MENU_SIZE 5            // how many items are on the menu
#define SERVICE_CHARGE_RATE 0.10  // 10% service charge

// ---- Menu data (the actual values live in order.c) ----
extern char menuNames[MENU_SIZE][30];
extern float menuPrices[MENU_SIZE];

// ---- Function prototypes ----
void displayMenu(void);
void assignTableNumber(int *table_number);
void takeOrder(int order_items[], int order_qty[], int *order_count);
float calculateSubtotal(int order_items[], int order_qty[], int order_count);
void printReceipt(int table_number, int order_items[], int order_qty[], int order_count);

#endif