package ru.mirea.mamaeva.practice.practice8.Item;

public final class Dish implements Item {
    private int cost;
    private String name;
    private String description;

    Dish(String name, String description){
        this.name=name;
        this.description=description;
    }

    Dish(int cost, String name, String description) throws IllegalArgumentException{
        if (cost < 0) throw new IllegalArgumentException();
        this.cost=cost;
        this.name=name;
        this.description=description;
    }

    public int getCost() {
        return cost;
    }

    public String getDescription() {
        return description;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return Integer.toString(cost) + "\n" + name + "\n" + description;
    }
}
