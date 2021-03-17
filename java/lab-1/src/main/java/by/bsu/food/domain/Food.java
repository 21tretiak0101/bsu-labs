package by.bsu.food.domain;

import java.util.Objects;

public abstract class Food implements Consumable {
    private String name;

    public Food(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Food)) {
            return false;
        }
        if (Objects.isNull(name)) {
            return false;
        }
        Food food = (Food) obj;
        return name.equals(food.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}
