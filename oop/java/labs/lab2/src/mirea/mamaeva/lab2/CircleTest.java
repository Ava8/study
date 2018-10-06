package mirea.mamaeva.lab2;

public class CircleTest {

    public static void main(String[] args) {
        Circle o1 = new Circle(0,0,6);
        Circle o2 = new Circle();

        o1.printCircle();
        o2.printCircle();

        System.out.println("o1 square: " +o1.squareCircle());
        System.out.println("o2 square: " +o2.squareCircle());

        System.out.println(o1.equalsCircle(o2));
        o2.zoomCircle(6);
        o1.moveCircle(2,-3);
        System.out.println(o1.equalsCircle(o2));
    }
}
