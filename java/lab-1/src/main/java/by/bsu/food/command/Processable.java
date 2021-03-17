package by.bsu.food.command;

import by.bsu.food.domain.Food;

public interface Processable {
   Food process(String ...args);
}
