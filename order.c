#include <stdio.h>
#include "order.h"

void assignTableNumber(TableOrder *order) {
    printf("\nEnter Table Number: ");
    scanf("%d", &order->table_number);
}

void takeOrder(TableOrder *order) {
    char add_more;
    
    do {
        if (order->order_count >= MAX_ORDER_ITEMS) {
            printf("Cart is full! Cannot add more items.\n");
            break;
        }

        int current_index = order->order_count;
        
        printf("\nEnter Item Number: ");
        scanf("%d", &order->items[current_index].item_number);
        
        printf("Enter Quantity: ");
        scanf("%d", &order->items[current_index].quantity);
        
        order->order_count++;

        printf("Add more items? (y/n): ");
        scanf(" %c", &add_more);

    } while (add_more == 'y' || add_more == 'Y');
}