package by.bsu.main;

import by.bsu.containers.Flower;
import by.bsu.processors.FlowersStatistics;
import by.bsu.storage.export.FlowerDataExporter;
import by.bsu.storage.io.FlowersLoader;

import java.util.List;

public class Main {
    public static void main(String ...args) {
        List<Flower> flowers = new FlowersLoader(args[0]).load();
        FlowersStatistics statistics = new FlowersStatistics();
        new FlowerDataExporter(args[0]).uploadAmount(statistics.groupByAmount(flowers));
    }
}
