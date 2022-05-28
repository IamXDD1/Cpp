#include "Store.h"

int main()
{
    Product p1("Juice", 30), p2("Cookies", 20);
    Combo c1 = p1 + p2;
    Store store;
    store.Add(p1);
    store.Add(p2);
    store.Add(c1);
    c1.SetPrice(40);
    store.Add(c1);
    store.Buy("Cookies");
    store.Buy("Juice+Cookies");
    store.Buy("Juice");
    store.PrintReceipt();
    store.PrintReceipt();
    store.Buy("Cookies");
    store.Buy("Cookies");
    store.Buy("Juice+Cookies");
    store.Buy("Juice");
    store.PrintReceipt();
}
