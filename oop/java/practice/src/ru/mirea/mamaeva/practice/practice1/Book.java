package ru.mirea.mamaeva.practice.practice1;

public class Book {
    private String name, author;
    private int release;

    public Book(String name, String author, int release) {
        this.name = name;
        this.author = author;
        this.release = release;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getRelease() {
        return release;
    }

    public void setRelease(int release) {
        this.release = release;
    }

    @Override
    public String toString() {
        return "Book{"
                + name + '\'' +
                ", author = '" + author + '\''
                + release +
                '}';
    }
}
