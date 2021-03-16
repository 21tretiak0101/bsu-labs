package by.bsu.food.command;

import by.bsu.food.domain.Apple;
import by.bsu.food.domain.Beef;
import by.bsu.food.domain.Cheese;
import by.bsu.food.domain.Food;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

public class FoodProcessor {
    private final Map<String, Processable> food = new HashMap<>();

    {
        food.put(Apple.FOOD_NAME, (args) -> new Apple(args[0]));
        food.put(Cheese.FOOD_NAME, (args) -> new Cheese());
        food.put(Beef.FOOD_NAME, (args) -> new Beef(args[0]));
    }

    public Food process(String foodName, String ...args) {
        return Optional.ofNullable(food.get(foodName))
                .orElseThrow(UnsupportedOperationException::new)
                .process(args);
    }
}
