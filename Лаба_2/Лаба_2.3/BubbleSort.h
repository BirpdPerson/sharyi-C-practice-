#pragma once
class BubbleSort
{
public:
	template<class TItem, class Pred>
	static void bubbleSorting(TItem* arr,int size, Pred pred)
	{
		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < size - i; j++)
			{
				if (pred(arr[j], arr[j + 1]))
				{
					auto temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};
