#pragma once
#include <iostream>
#include <vector>

void PrintCombination(int* arr, int size, int down);
void Combination(int* arr, int size, int down, int index, int count, bool choosed, std::vector<int> ans);