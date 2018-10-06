package mirea.mamaeva.lab1;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Lab1 {
    int sum = 0;

    public  void initializeArray(int[] array) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите массив:");
        for (int i = 0; i < array.length; i ++) {
            array[i] = scanner.nextInt();
        }
        System.out.println("initialized array:");
        System.out.println(Arrays.toString(array));
    }

    public void task1(int[] array) {

        System.out.println("Sum of array's elems:");

        for (int i = 0; i < array.length; i ++) {
            sum += array[i];
        }
        System.out.println(sum);
        sum = 0;

        for (int elem: array) {
            sum += elem;
        }
        System.out.println(sum);
        sum = 0;

        int i = 0;
        while (i != array.length) {
            sum += array[i];
            i ++;
        }
        System.out.println(sum);
        i = 0;
        sum = 0;

        do {
            sum += array[i];
            i ++;
        } while (i < array.length);
        System.out.println(sum);
        sum = 0;
    }

    public void task3() {
        double value = 0;
        System.out.println("10 elems of harmonic series:");
        for (int n = 1; n < 11; n ++) {
            value = 1/(double)n;
            System.out.println(value);
        }
    }

    public void task4() {
        int[] a = new int[20];
        for (int i = 0; i < a.length; i ++) {
            // диапозон от -10 до 90
            a[i] = (int) Math.round(Math.random() * 100 - 10);
        }
        System.out.println("unsorted array:");
        System.out.println(Arrays.toString(a));
        System.out.println("sorted array:");
        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
    }

    public BigInteger factorial(int value) {
        BigInteger result = BigInteger.ONE;
        for (int i = 1; i <= value; i ++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }

}

