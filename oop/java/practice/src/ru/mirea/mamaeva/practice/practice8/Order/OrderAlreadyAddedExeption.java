package ru.mirea.mamaeva.practice.practice8.Order;

public class OrderAlreadyAddedExeption extends Exception {
    String message = "Order already added!";

    OrderAlreadyAddedExeption(){}

    @Override
    public String toString() {
        return super.toString() + message;
    }
}

