package by.bsu.food.domain;

public class Cheese extends Food {
    public static final String FOOD_NAME = "Cheese";

    public Cheese() {
        super(FOOD_NAME);
    }

    @Override
    public void consume() {
        System.out.println("A " + this + " is eaten.");
    }
}
