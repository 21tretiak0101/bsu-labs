package by.bsu.containers;

public class Flower {
    private final String name;
    private final Integer length;

    public Flower(String name, Integer length) {
        this.name = name;
        this.length = length;
    }

    public String getName() {
        return name;
    }

    public Integer getLength() {
        return length;
    }

    @Override
    public String toString() {
        return "{" +
                "name='" + name + '\'' +
                ", length=" + length +
                '}';
    }
}
