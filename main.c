#include <stdio.h>
#include "order.h"

int main() {
    TableOrder currentOrder;
    currentOrder.order_count = 0;

    printf("=== RESTAURANT ORDER SYSTEM (GROUP 2) ===\n");

    // Execute Group 2 Logic
    assignTableNumber(&currentOrder);
    takeOrder(&currentOrder);

    // Print summary to verify everything works perfectly
    printf("\n--- Order Captured Successfully ---\n");
    printf("Table Number: %d\n", currentOrder.table_number);
    printf("Total Distinct Items Ordered: %d\n", currentOrder.order_count);
    
    return 0;
}