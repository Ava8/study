package ru.mirea.mamaeva.lab4;

public class Student implements Nameable {
    private String FIO;
    private String Group;

    public Student() {}
    public Student(String name, String group) {
        FIO = name;
        Group = group;
    }
    public Student(String name) {
        FIO = name;
    }

    public void setFIO(String StudentName) {
        FIO = StudentName;
    }
    public void setGroup(String group) {
        Group = group;
    }

    @Override
    public String getName() {
        return FIO;
    }
}
