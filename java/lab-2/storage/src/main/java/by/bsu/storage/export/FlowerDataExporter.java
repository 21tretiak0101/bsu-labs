package by.bsu.storage.export;

import by.bsu.containers.Flower;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class FlowerDataExporter {
    public final String filename;

    public FlowerDataExporter(String filename) {
        this.filename = filename;
    }

    public void uploadRangeOfLength(Map<String, List<Flower>> statistics) {
        String data = statistics.entrySet().stream()
                .map((entry) -> {
                    String flowers = entry.getValue().stream()
                            .map(Flower::toString)
                            .collect(Collectors.joining(", "));
                    return String.format("%s, %s", entry.getKey(), flowers);
                })
                .collect(Collectors.joining("\n"));
        upload(data);
    }

    public void uploadAmount(List<String> statistics) {
        String data = String.join("\n", statistics);
        upload(data);
    }

    private void upload(String data) {
        try (BufferedWriter writer = Files.newBufferedWriter(Path.of(filename))) {
            writer.write(data);
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }
}
