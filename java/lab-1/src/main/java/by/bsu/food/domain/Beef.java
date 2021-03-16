package by.bsu.food.domain;

import java.util.Objects;

public class Beef extends Food {
    private String preparedness;

    public static final String FOOD_NAME = "Beef";

    public Beef(String preparedness) {
        super(FOOD_NAME);
        this.preparedness = preparedness;
    }

    public String getPreparedness() {
        return preparedness;
    }

    public void setPreparedness(String preparedness) {
        this.preparedness = preparedness;
    }

    @Override
    public void consume() {
        System.out.println("A " + this + " is eaten.");
    }

    @Override
    public String toString() {
        return String.format("%s with preparedness '%s'", super.toString(), preparedness);
    }

    @Override
    public boolean equals(Object obj) {
        if (!super.equals(obj)) {
            return false;
        }
        if (!(obj instanceof Beef)) {
            return false;
        }
        Beef beef = (Beef) obj;
        return Objects.equals(preparedness, beef.preparedness);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), preparedness);
    }
}
