package mirea.mamaeva.lab2;

public class Circle {
    private double x;
    private double y;
    private double radius;

    public Circle() {
        this.x = 0.0;
        this.y = 0.0;
        this.radius = 1;
    }
    public Circle( double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public void printCircle() {
        System.out.println("Circle with center [("+x+";"+y+")] and radius: " +radius);
    }

    public void moveCircle( double x, double y) {
        this.x += x;
        this.y += y;
    }

    public void zoomCircle(double radius) {
        this.radius = radius;
    }

    public double squareCircle() {
        double square = Math.PI * radius * radius;
        return  square;
    }

    public boolean equalsCircle (Circle circle) {
        if (this.squareCircle() ==  circle.squareCircle()) {
            return true;
        } else {
            return  false;
        }
    }

}
