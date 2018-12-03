package ru.mirea.mamaeva.practice.practice8.Order;

public class IllegalTableNumber extends Exception {
    int number;
    IllegalTableNumber(String message, int number){
        this.number = number;
    }

    @Override
    public String toString() {
        return "Illegal Table Number exception!" + " " + number + "not available";
    }
}