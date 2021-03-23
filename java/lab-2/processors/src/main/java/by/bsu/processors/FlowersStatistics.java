package by.bsu.processors;

import by.bsu.containers.Flower;

import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

public class FlowersStatistics {
    public static final Integer DEFAULT_RANGE_STEP = 20;

    public List<String> getFlowersAmount(List<Flower> flowers) {
        return flowers.stream()
                .collect(Collectors.groupingBy(Flower::getName, Collectors.counting()))
                .entrySet().stream()
                .sorted(Map.Entry.comparingByKey())
                .map((entry) -> String.format("%s: %d", entry.getKey(), entry.getValue()))
                .collect(Collectors.toList());
    }

    public Map<String, List<Flower>> groupingByRange(List<Flower> flowers) {
        return flowers.stream()
                .collect(Collectors.groupingBy(this::range, TreeMap::new, Collectors.toList()));
    }

    private String range(Flower flower) {
        return generateRange(flower.getLength());
    }

    private String generateRange(Integer number) {
        Integer rangeStart = (number / DEFAULT_RANGE_STEP) * DEFAULT_RANGE_STEP;
        Integer rangeEnd = rangeStart + DEFAULT_RANGE_STEP;
        return String.format("%s-%s", rangeStart, rangeEnd);
    }
}
