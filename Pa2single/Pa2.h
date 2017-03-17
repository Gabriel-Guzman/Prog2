#pragma once

class Node {
    public:
        Node(int start, int end, std::string n);
        void insert(int start, int end, std::string n);
        void setName(std::string);
        Node * getNext();
        bool isTaken();
        std::string getName();

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
    taken = false;
};

bool Node::isTaken(){
    return taken;
}

std::string Node::getName(){
    return name;
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
        bool addProgram(std::string name, int pages, bool bestFit);
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
                std::cout<<"Here";
	while(temp->getNext() != NULL && found == false){
		if(temp->getNext()->getName().compare(n) == 0){
			found = true;
		}
	}

	return found;
}

class Group {
public:
    Node* start;
    int length;
    Group(Node * s, int l);
    Group();
};

Group::Group(Node * s, int l){
    start = s;
    length = l;

}

Group::Group(){
    start = NULL;
    length = 0;
}

bool LinkedList::addProgram(std::string name, int pages, bool bestFit){
    Node * temp = head;

    Node * potBegin; //Stands for potential beginning of the program in memory
    bool succ = false;
    bool counting = false;
    int groupCounter = 0;

    int numGroups = 0;

    Group groups[17];

    while(temp!= NULL) {
        if (!temp->isTaken())
        {
            if (!counting)
            {
                potBegin = temp;
            }
            
            groupCounter++;
        } else {
            if (counting)
            {
                counting = !counting;
                groups[numGroups].start = potBegin;
                groups[numGroups].length = groupCounter - 1;
                numGroups++;

            }

            groupCounter = 0;
        }
        temp = temp->getNext();
    }
    return succ;
}

//Function declarations not related to classes are below here
bool addProgram(LinkedList * ll, std::string name, int pages);