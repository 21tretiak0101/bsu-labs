package by.bsu.food.domain;

import java.util.Objects;

public class Apple extends Food {
    private String size;

    public static final String FOOD_NAME = "Apple";

    public Apple(String size) {
        super(FOOD_NAME);
        this.size = size;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    @Override
    public void consume() {
        System.out.println("An " + this + " is eaten.");
    }

    @Override
    public String toString() {
        return String.format("%s with size '%s'", super.toString(), size.toUpperCase());
    }

    @Override
    public boolean equals(Object obj) {
        if (!super.equals(obj)) {
            return false;
        }
        if (!(obj instanceof Apple)) {
            return false;
        }
        Apple apple = (Apple) obj;
        return Objects.equals(size, apple.size);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), size);
    }
}
