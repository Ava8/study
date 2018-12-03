package ru.mirea.mamaeva.practice.practice8.Order;

import ru.mirea.mamaeva.practice.practice8.Item.Item;

public interface Order {
    public boolean add(Item item);
    public boolean delete(String name);
    public int deleteAll(String name);
    public int getCount();
    public Item[] getAll();
    public int getCost();
    public int getCountOf(String name);
    public String[] getAllNames();
    public Item[] sortingByCost();
}
