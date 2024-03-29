package by.bsu.storage.io;

import by.bsu.containers.Flower;

import java.util.Arrays;
import java.util.List;
import java.util.Objects;

import static java.util.stream.Collectors.toList;

public class FlowersLoader {
    private final String filename;

    public FlowersLoader(String filename) {
        this.filename = filename;
    }

    public List<Flower> load() {
        return load("#");
    }

    public List<Flower> load(String delimiter) {
        return new TextFileDataSource(filename).load().stream()
                .map(line -> line.split(delimiter))
                .map(this::toFlower)
                .filter(Objects::nonNull)
                .collect(toList());
    }

    private Flower toFlower(String ...params) {
        try {
            String name = params[0];
            Integer length = Integer.parseInt(params[1]);
            return new Flower(name, length);
        } catch (Exception e) {
            System.out.println("Incorrect line format: " + Arrays.toString(params));
            return null;
        }
    }
}
