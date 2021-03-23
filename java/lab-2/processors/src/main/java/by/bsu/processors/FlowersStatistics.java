package by.bsu.processors;

import by.bsu.containers.Flower;

import java.util.List;
import java.util.Map;
import java.util.TreeMap;

import static java.util.stream.Collectors.*;

public class FlowersStatistics {
    public static final Integer DEFAULT_RANGE_STEP = 20;

    public List<String> groupByAmount(List<Flower> flowers) {
        return flowers.stream()
                .collect(groupingBy(Flower::getName, TreeMap::new, counting()))
                .entrySet().stream()
                .map((entry) -> String.format("%s: %d", entry.getKey(), entry.getValue()))
                .collect(toList());
    }

    public Map<String, List<Flower>> groupByRange(List<Flower> flowers) {
        return flowers.stream().collect(groupingBy(this::range, TreeMap::new, toList()));
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
