// Includes
#include "myQueue.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void TestWrapper();

int main() 
{
	TestWrapper();

	_CrtDumpMemoryLeaks();

	return 0;
}

// A wrapper function to help detect memory leaks and also makes the main.cpp code look cleaner.
void TestWrapper()
{
	// Instantiate new queue on heap because I said so.
	MyQueue<int>* testQueue = new MyQueue<int>();

	// Begin testing by just pushing a bunch of ints into the queue.
	testQueue->Push(4);
	testQueue->Push(3);
	testQueue->Push(7);
	testQueue->Push(15);
	testQueue->Push(1);
	testQueue->Push(2);

	testQueue->Print();

	// Use various rule of three functions.
	MyQueue<int> copyAssignmentQueue = *testQueue;
	MyQueue<int>* copyConstructorQueue = new MyQueue<int>(*testQueue);

	// Edit the rule of three queues.
	cout << "Pushing 420 into Copy Assignment operator queue.\n";
	copyAssignmentQueue.Push(420);

	cout << "Popping from copy constructor queue: " << copyConstructorQueue->Pop();
	cout << "\n";

	// Print the contents of the three queues.
	cout << "Base queue: ";
	testQueue->Print();

	cout << "Copy Assignment operator queue: ";
	copyAssignmentQueue.Print();

	cout << "Copy constructor queue: ";
	copyConstructorQueue->Print();

	cout << "\n";

	// Print out queue sizes.
	cout << "Printing queue sizes...\n";

	cout << "Base queue size: " << testQueue->GetSize() << "\n";
	cout << "Copy constructor queue size: " << copyConstructorQueue->GetSize() << "\n";
	cout << "Copy assignment operator queue size: " << copyAssignmentQueue.GetSize() << "\n";

	cout << "\n";

	// Test the IsEmpty and Empty functions.
	cout << "Is base queue empty? " << testQueue->IsEmpty() << "\n";

	cout << "Emptying base queue...\n";
	testQueue->Empty();

	cout << "Is base queue empty? " << testQueue->IsEmpty() << "\n";


	// Clean up memory stuffs
	
	delete copyConstructorQueue;
	copyConstructorQueue = nullptr;
	delete testQueue;
	testQueue = nullptr;
}