package by.bsu.storage.io;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import static java.util.stream.Collectors.toList;

public class TextFileDataSource {
    private final String filename;

    public TextFileDataSource(String filename) {
        this.filename = filename;
    }

    public List<String> load() {
        try (BufferedReader reader = Files.newBufferedReader(Path.of(filename))) {
            return reader.lines().collect(toList());
        } catch (IOException e) {
            System.out.println(e.toString());
            return new ArrayList<>();
        }
    }
}
