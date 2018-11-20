package ru.mirea.mamaeva.practice.practice2;

public class Author {
    private String name, adress;
    private char gender;

    public Author(String name, String email, char gender) {
        this.name = name;
        this.adress = email;
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public char getGender() {
        return gender;
    }

    public String getAdress() {
        return adress;
    }

    public void setAdress(String adre) {
        this.adress = adress;
    }

    @Override
    public String toString() {
        return name + " (" + gender + ") " + adress;
    }
}
