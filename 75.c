#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int price;
    int span;
} Pair;

typedef struct
{
    Pair *stack;
    int top;
    int size;
} StockSpanner;

StockSpanner *stockSpannerCreate()
{
    StockSpanner *obj = (StockSpanner *)malloc(sizeof(StockSpanner));

    obj->size = 10000;
    obj->top = -1;

    obj->stack = (Pair *)malloc(sizeof(Pair) * obj->size);

    return obj;
}

int stockSpannerNext(StockSpanner *obj, int price)
{
    int span = 1;

    while (obj->top != -1 &&
           obj->stack[obj->top].price <= price)
    {
        span += obj->stack[obj->top].span;
        obj->top--;
    }

    obj->top++;

    obj->stack[obj->top].price = price;
    obj->stack[obj->top].span = span;

    return span;
}

void stockSpannerFree(StockSpanner *obj)
{
    free(obj->stack);
    free(obj);
}

int main()
{
    StockSpanner *stockSpanner = stockSpannerCreate();

    int n;

    printf("Enter number of stock prices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int price;

        printf("Enter stock price: ");
        scanf("%d", &price);

        int span = stockSpannerNext(stockSpanner, price);

        printf("Span = %d\n", span);
    }

    stockSpannerFree(stockSpanner);

    return 0;
}
