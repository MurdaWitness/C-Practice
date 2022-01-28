#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{
    private:
    class Node
	{
	    public:
		T* data;
		int key;
		Node* next;
		Node(int key, T* data)
		{
			this-> key=key;
			this->data = data;
			next = nullptr;
		}
	};
	public:
	Node* Root;
	List()
	{
		this->Root = nullptr;
	}
	void Print()
	{
		Node* currentNode =Root;
		while (currentNode->next != nullptr) 
		{
			cout<< "key=" << currentNode->key<< ", data=" << *(currentNode->data)<<endl;
			currentNode = currentNode->next;
		}
		cout<< "key=" << currentNode->key<< ", data=" << *(currentNode->data)<<endl;
	}
	void addNode(int key, T* data)
	{
	    if (Root == nullptr) 
	    {
	        Root = new Node(key, data);
	    }
	    else
	    {
    		Node* currentNode = Root;
    		while (currentNode->next != nullptr) currentNode = currentNode->next;
    		currentNode->next = new Node(key, data);
	    }
	}
	void sort()
	{
		int size = 0;
		Node* currentNode = Root;
		while (currentNode->next != nullptr) 
		{
			currentNode = currentNode->next;
			size++;
		}
		size++;
		
		Node **array = new Node * [size];
		
		currentNode = Root;
		int i = 0;
		while (currentNode->next != nullptr) 
		{
			array[i] = currentNode;
			currentNode = currentNode->next;
			i++;
		}
		array[i] = currentNode;
		
		for(int i = 0; i<size-1; i++)
			for(int j = 0; j<size-i-1; j++)
    			if(array[j]->key > array[j+1]->key)
    			{
    				Node* temp = array[j];
    				array[j] = array[j+1];
    				array[j+1] = temp;
    			}
			
		Root = array[0];
		for(int i = 0; i<size-1; i++)
			array[i]->next = array[i+1];
		array[size-1]->next = nullptr;
	}
	T get(int key)
	{
		Node* currentNode =Root;
		while (currentNode->key !=key) currentNode = currentNode->next;
		return *(currentNode->data);
	}
};


int main()
{
    List<int> list = List<int>();
    int i1 = 1;
    int i2 = 2;
    int i3 = 3;
    int i4 = 4;
    list.addNode(9, &i1);
    list.addNode(2, &i2);
    list.addNode(1, &i3);
    list.addNode(3, &i4);
    list.addNode(2, &i4);
    list.addNode(7, &i4);
    list.addNode(7, &i4);
    list.Print();
    list.sort();
    cout << endl;
    list.Print();
	return 0;
}