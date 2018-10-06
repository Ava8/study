package ru.mirea.mamaeva.lab4;

public class Planet implements Nameable {
    private String PlanetName;

    public Planet() { }
    public Planet(String planet) {
        PlanetName = planet;
    }

    public void setPlanetName(String name) {
        PlanetName = name;
    }
    public void changeName(String newName) {
        PlanetName = newName;
    }

    @Override
    public String getName() {
        return PlanetName;
    }
}
