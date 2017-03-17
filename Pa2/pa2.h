#pragma once

class Node {
    public:
        Node(int start, int end, std::string n);
        void insert(int start, int end, std::string n);
        void setName(std::string n);
        Node * getNext();
        void setNext(Node * n);

    private:
        int start;
        int end;
        bool taken;
        std::string name;
        Node * next; 
};

Node::Node(int s, int e, std::string n){
    start = s;
    end = e;
    name = n;
    next = NULL;
};

Node::setNext(Node * n){
	next = n;
}

Node * Node::getNext(){
	return next;
}

void Node::insert(int s, int e, std::string n){
    if(next == NULL || next == 0){
        next = new Node(s, e, n);
    } else {
        next->insert(s, e, n);
    }
};

//Change the name of the node. The name is the name of the program taking up it's memory
void Node::setName(std::string n) {
    name = n;
};  

class LinkedList {
    private:
        Node * head;
    public:
        LinkedList();
        void insert(int s, int e, std::string n);
        bool isRunning(std::string n);
};

LinkedList::LinkedList(){
    head = NULL;
}

void LinkedList::insert(int s, int e, std::string n) {
    
    if(head == NULL || head == 0){
        head = new Node(s, e, n);
    } else {
        head->insert(s, e, n);
    }
};

bool LinkedList::isRunning(std::string n){
	Node * temp = head;
	bool found = false;
	while(temp->getNext() != NULL && found == false){
		if(temp->getNext().getName().compare(n) == 0){
			found = true;
		}
	}

	return found;
}

void LinkedList::sortList(){
	Node * temp;
	Node * tempForChanging;
	bool done = false;

	while (!done){
		while(temp->getNext() != NULL){
			if(temp.getNext.getStart() < temp.getStart()){
				tempForChanging = temp.getNext();

				
			}
		}
	}
}