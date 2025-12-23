#include <iostream>
#include <string>


class Item 
{
public:
	Item()
	{
		itemName = "";
		itemPrice = 0; 
		
	}

	Item(std::string name, int price)
	{
		itemName = name;
		itemPrice = price;
	}
	~Item()
	{
		
		
	}

	std::string GetItemName()
	{
		return itemName;
	}

	int GetItemPrice()
	{
		return itemPrice;
	}


private:
	std::string itemName; 
	int itemPrice; 
}; 

template <typename T>
class Inventory
{
public:
	Inventory(int capacity = 10) 
	{
		this->capacity = capacity;
		size = 0;
		pItems = new Item[capacity];
	}

	~Inventory()
	{
		delete[] pItems;
	}

	void AddItem(Item item)
	{
		if (size >= capacity) 
			return;
		pItems[size++] = item;
	}

	void RemoveLastItem()
	{
		size = size - 1;
	}

	void PrintAllItems()
	{
		for (int i = 0; i < size; ++i)
		{
			std::cout << "Name : " << pItems[i].GetItemName() << ", Price: " << pItems[i].GetItemPrice() << std::endl;
		}
	}

	int GetSize() const;           // size_
	int GetCapacity() const;       // capacity_

private:
	T* pItems;
	int capacity;
	int size;

};




int main()
{
	Item item("Hello Item", 1000);
	Inventory<Item> inventory;
	inventory.AddItem(item);
	inventory.AddItem(Item("Hello Item2", 1100));

	for (int i = 0; i < 10; ++i)
	{
		inventory.AddItem(Item("Hello Item" + std::to_string(i), 100));
	}

	inventory.RemoveLastItem();
	inventory.PrintAllItems();

	Item* itemPtr = new Item();
	delete itemPtr;
	return 0;
}