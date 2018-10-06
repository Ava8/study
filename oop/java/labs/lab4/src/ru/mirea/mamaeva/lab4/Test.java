package ru.mirea.mamaeva.lab4;

public class Test {

    public static void main(String[] args) {
        Nameable name = new Student("Arina");
        System.out.println(name.getName());
        name = new Planet("Earth");
        System.out.println(name.getName());
    }
}
