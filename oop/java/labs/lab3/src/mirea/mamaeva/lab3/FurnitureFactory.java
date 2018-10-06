package mirea.mamaeva.lab3;

import mirea.mamaeva.lab3.Model.Furniture;
import mirea.mamaeva.lab3.Model.Sofa;
import mirea.mamaeva.lab3.Model.Table;

import java.util.*;
import java.util.stream.Collectors;

public class FurnitureFactory {
//    private ArrayList<Furniture> allFurniture;
    private List<Furniture> allFurniture;
    private List<Sofa> allSofas;
    private List<Table> allTables;

    public FurnitureFactory() {

    }

    public FurnitureFactory(List<Sofa> sofas, List<Table> tables) {
        allFurniture = sofas.stream().collect(Collectors.toList());
        allFurniture.addAll(tables);

        allSofas = sofas;
        allTables = tables;
    }

    public void setAllFurniture(List<Furniture> allFurniture) {
        this.allFurniture = allFurniture;
    }

    public void setAllSofas(List<Sofa> allSofas) {
        this.allSofas = allSofas;
    }

    public void setAllTables(List<Table> allTables) {
        this.allTables = allTables;
    }

    public void getSofaType(int sofaID) {
        Sofa sofa = allSofas.get(sofaID);
        Sofa.SofaType type = sofa.getType();
        System.out.println("Sofa type is " +type);
    }

    public void getSofaHumanCapacity(int sofaID) {
        Sofa sofa = allSofas.get(sofaID);
        int capacity = sofa.getHumanCapacity();
        System.out.println("Sofa human capacity is " +capacity);
    }

    public void getSofaManufacture(int sofaID) {
        Sofa sofa = allSofas.get(sofaID);
        String manufacture = sofa.getManufacturer();
        System.out.println("Sofa manufacture is " +manufacture);
    }

    public void getSofaMaterial(int sofaID) {
        Sofa sofa = allSofas.get(sofaID);
        String material = sofa.getMaterial();
        System.out.println("Sofa material is " +material);
    }

    public void getSofaColor(int sofaID) {
        Sofa sofa = allSofas.get(sofaID);
        String color = sofa.getColor();
        System.out.println("Sofa color is " +color);
    }

    public void getSofaPrice(int sofaID) {
        Sofa sofa = allSofas.get(sofaID);
        int price = sofa.getPrice();
        System.out.println("Sofa price is " +price);
    }

    public void getSofaFullInformation(int sofaID) {
        Sofa sofa = allSofas.get(sofaID);
        Sofa.SofaType type = sofa.getType();
        System.out.println("Sofa type is " +type);
        int capacity = sofa.getHumanCapacity();
        System.out.println("Sofa human capacity is " +capacity);
        String manufacture = sofa.getManufacturer();
        System.out.println("Sofa manufacture is " +manufacture);
        String material = sofa.getMaterial();
        System.out.println("Sofa material is " +material);
        String color = sofa.getColor();
        System.out.println("Sofa color is " +color);
        int price = sofa.getPrice();
        System.out.println("Sofa price is " +price);
    }

    public void getTableSquare(int tableID) {
        Table table = allTables.get(tableID);
        int square = table.getSquare();
        System.out.println("Table square is " +square);
    }

    public void getTableForm(int tableID) {
        Table table = allTables.get(tableID);
        Table.TableForm form = table.getForm();
        System.out.println("Table form is " +form);
    }

    public void getTableManufacture(int tableID) {
        Table table = allTables.get(tableID);
        String manufacture = table.getManufacturer();
        System.out.println("Table manufacture is " +manufacture);
    }

    public void getTableMaterial(int tableID) {
        Table table = allTables.get(tableID);
        String material = table.getMaterial();
        System.out.println("Table material is " +material);
    }

    public void getTableColor(int tableID) {
        Table table = allTables.get(tableID);
        String color = table.getColor();
        System.out.println("Table color is " +color);
    }

    public void getTablePrice(int tableID) {
        Table table = allTables.get(tableID);
        int price = table.getPrice();
        System.out.println("Table price is " +price);
    }

    public void getTableFullInformation(int tableID) {
        Table table = allTables.get(tableID);
        int square = table.getSquare();
        System.out.println("Table square is " +square);
        Table.TableForm form = table.getForm();
        System.out.println("Table form is " +form);
        String manufacture = table.getManufacturer();
        System.out.println("Table manufacture is " +manufacture);
        String material = table.getMaterial();
        System.out.println("Table material is " +material);
        String color = table.getColor();
        System.out.println("Table color is " +color);
        int price = table.getPrice();
        System.out.println("Table price is " +price);
    }

    public void FurnitureCount() {
        System.out.println("Items count in factory is " +allFurniture.size());
    }

    public void addSofa(Sofa sofa) {
        allSofas.add(sofa);
        allFurniture.add(sofa);
    }

    public void addTable(Table table) {
        allTables.add(table);
        allFurniture.add(table);
    }

}
