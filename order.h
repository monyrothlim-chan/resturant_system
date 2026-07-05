#ifndef ORDER_H
#define ORDER_H

#define MAX_ORDER_ITEMS 20

typedef struct {
    int item_number;
    int quantity;
} OrderItem;

typedef struct {
    int table_number;
    OrderItem items[MAX_ORDER_ITEMS];
    int order_count;
} TableOrder;

void assignTableNumber(TableOrder *order);
void takeOrder(TableOrder *order);

#endif