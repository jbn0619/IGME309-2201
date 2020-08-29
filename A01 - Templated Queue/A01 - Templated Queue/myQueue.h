// Preprocessor directives
#ifndef MYQUEUE_H
#define MYQUEUE_H

// All includes go here.
#include <iostream>

// Using statements
using namespace std;

template <class T>
class MyQueue {
public:

	#pragma region Fields

	T* items;
	int itemCount;
	int arraySize;

	#pragma endregion

	// Class constructor
	MyQueue()
	{
		items = new T[1];
		itemCount = 0;
		arraySize = 1;
	}

	#pragma region Rule of Three Functions

	// Copy constructor.
	MyQueue(const MyQueue &oldQueue)
	{
		// Make a new items array as the size of the old queue's items array.
		T* newArray = new T[oldQueue.arraySize];

		// Copy the contents of the old queue's array into the new one.
		for (int i = 0; i < oldQueue.itemCount; i++) 
		{
			newArray[i] = oldQueue.items[i];
		}

		// Swap the new array into items after deleting the old array.
		delete[] items;
		items = newArray;
		newArray = nullptr;

		// Finally update the item count and array size.
		itemCount = oldQueue.itemCount;
		arraySize = oldQueue.arraySize;
	}

	// Copy assignment operator.
	MyQueue& operator = (const MyQueue &oldQueue)
	{
		// First, check to see if the old queue is the same as this one. If so, just stop the function early.
		if (oldQueue == this) 
		{
			return *this;
		}

		// Make a new items array as the size of the old queue's items array.
		T* newArray = new T[oldQueue.arraySize];

		// Copy the contents of the old queue's array into the new one.
		for (int i = 0; i < oldQueue.itemCount; i++)
		{
			newArray[i] = oldQueue.items[i];
		}

		// Swap the new array into items after deleting the old array.
		delete[] items;
		items = newArray;
		newArray = nullptr;

		// Finally update the item count and array size.
		itemCount = oldQueue.itemCount;
		arraySize = oldQueue.arraySize;

		return *this;
	}
	
	// Class destructor
	~MyQueue()
	{
		// Delete the internal array of items.
		delete[] items;
		items = nullptr;
	}

	#pragma endregion

	// Adds a new item to the back of the Queue.
	void Push(T newItem) 
	{
		// First, increase the item count.
		itemCount += 1;

		// Next see if we need to resize the array.
		if (itemCount > arraySize) 
		{
			GrowArray();
		}

		// Add new item to the end of the queue.
		items[itemCount - 1] = newItem;

		// Finally, sort the queue.
		Sort();
	}

	// Removes the first element in the queue and returns it.
	T Pop()
	{
		// First pull the item that needs to be popped.
		T returnItem = items[0];

		// Move every item in the queue down one spot.
		for (int i = 1; i < itemCount; i++) 
		{
			items[i - 1] = items[i];
		}

		// Next, update the itemCount variable.
		itemCount -= 1;

		// Finally, return the item being popped.
		return returnItem;
	}

	// Prints the contents of this queue.
	void Print()
	{
		// Simply loop through items and print each item with cout.
		for (int i = 0; i < itemCount; i++) 
		{
			cout << items[i] << ", ";
		}

		// Start a new line in the console so things look nicer.
		cout << "\n";
	}

	// Returns if there are any items currently in the queue or not.
	bool IsEmpty()
	{
		if (itemCount == 0) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Returns the amount of items in this queue.
	int GetSize() 
	{
		return itemCount;
	}

	// Deletes every item in the queue.
	void Empty()
	{
		delete[] items;

		arraySize = 1;
		items = new T[arraySize];
		itemCount = 0;
		
	}

protected:

	// Sorts the internal array after Push is called.
	void Sort()
	{
		// Using insertion sort, sort the array from least to greatest.
		for (int i = 0; i < itemCount; i++)
		{
			// Go through the array and see if there are any lower numbers.
			int lowestNumIndex = i;
			for (int j = i + 1; j < itemCount; j++) 
			{
				// If a lower number has been found, grab their index.
				if (items[j] < items[lowestNumIndex]) {
					lowestNumIndex = j;
				}
			}

			// Swap the lowest number with the current number.
			T temp = items[lowestNumIndex];
			items[lowestNumIndex] = items[i];
			items[i] = temp;
		}
	}

	// Grows the internal array if necessary.
	void GrowArray() 
	{
		// Make a new array with twice the size of the old one.
		T* newArray = new T[arraySize * 2];
		
		// Copy over the contents of the old array into the new one.
		for (int i = 0; i < arraySize; i++) 
		{
			newArray[i] = items[i];
		}

		// Delete the old items array and move the new one in there.
		delete[] items;
		items = newArray;
		newArray = nullptr;

		// Finally, update arraySize;
		arraySize = arraySize * 2;
	}
};

#endif