package by.bsu.food;

import by.bsu.food.command.FoodProcessor;
import by.bsu.food.domain.Food;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        FoodProcessor processor = new FoodProcessor();
        List<Food> breakfast = Arrays.stream(args)
                .map(arguments -> arguments.split("/"))
                .map(item -> {
                    String foodName = item[0];
                    String[] arguments = Arrays.copyOfRange(item, 1, item.length);
                    return processor.process(foodName, arguments);
                })
                .collect(Collectors.toList());

        breakfast.forEach(Food::consume);

        Map<String, Long> foodGroupingByName = breakfast.stream()
                .collect(Collectors.groupingBy(Food::getName, Collectors.counting()));

        foodGroupingByName.forEach((name, count) -> System.out.printf("\n%s: %d", name, count));
    }
}
