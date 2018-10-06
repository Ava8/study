package mirea.mamaeva.lab1;

import java.lang.System;
import java.util.Arrays;

public class Main {

    // psvm
    public static void main(String[] args) {
        // за ввод/вывод отвечает класс System
        System.out.println("Hello World!");

        // LAB WORK 1

        // task 1
        Lab1 lab1 = new Lab1();
        int[] array = {4,7,9,0,3,7};
        int[] arr = new int[10];
        lab1.task1(array);
//        lab1.initializeArray(arr);

        // task 2
        System.out.println("Args:");
        System.out.println(Arrays.toString(args));

        // task 3
        lab1.task3();

        // task 4
        lab1.task4();

        // task 5
        System.out.println("factorial:");
        System.out.println(lab1.factorial(15));


    }

}
