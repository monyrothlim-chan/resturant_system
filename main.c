#include <stdio.h>
#include "order.h"

int main() {
    int table_number;

    // The "cart": two arrays that store what was ordered,
    // plus a counter for how many items are in it so far
    int order_items[MAX_ORDER_ITEMS];
    int order_qty[MAX_ORDER_ITEMS];
    int order_count = 0;

    printf("=== RESTAURANT ORDER SYSTEM ===\n");

    assignTableNumber(&table_number);
    
    // Keep asking for order until valid input is received
    while (takeOrder(order_items, order_qty, &order_count) == ORDER_INVALID) {
        printf("\nLet's try that again. Please re-enter your order.\n");
        order_count = 0;  // Reset the order count to start fresh
    }
    
    printReceipt(table_number, order_items, order_qty, order_count);

    return 0;
}