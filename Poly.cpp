#include "Poly.h"
#include <iostream>


Poly::Poly()
{
	// TODO	
	//set degree to -1
	this->deg = -1;
	//create the zero polynomial
	PolyNode* newNode = new PolyNode(-1, NULL, NULL);
	this->head = newNode;
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	// TODO	
	//creates a singly linked list (using the polynode class)
	PolyNode* newNode = new PolyNode(-1, NULL, NULL);
	this->head = newNode;
	this->deg = -1;

	//the degree elements are in increasing order so no checking required
	int counter = 1;

	//for loop that runs for the size of vector
	for (int i = 0; i < deg.size(); i++) {
		//create a new node in the SLL
		addMono(deg[i], coeff[i]);
		
	}

	deleteZeroMono();

}

Poly::~Poly()
{
	// TODO
	// reach out to a buddy and check again how to delete a SLL or delete a polyNode
	PolyNode* nodeHead = this->getHead();
	PolyNode* temp;



	while (nodeHead != NULL)
	{
		
		temp = nodeHead;
		nodeHead = nodeHead->next;
		//free(temp);
		
			 
		
	}

}

void Poly::addMono(int i, double c)
{

	//if coeff == 0, exit
	if (c == 0) { return; }

	//while loop to loop through the SLL
	PolyNode* current = this->getHead();


	//condition: next ptr != NULL, and the deg is still bigger than the current deg of the node
	while (current->next != NULL && current->next->deg > i) {
		//run through all of the nodes w/ a larger deg
		current = current->next;
	}
	

	//new node/mononomial
	if (current->next == NULL) {
		//create new mononomial
		PolyNode* newNode = new PolyNode(i, c, NULL);
		//add to list
		current->next = newNode;
	}
	else if (current->next->deg != i) {
		PolyNode* newNode = new PolyNode(i, c, current->next);
		current->next = newNode;
	}
	//add to existing term
	else if (current->next->deg == i) {
		current->next->coeff += c;
		
	}

	update();
}//theta(n)


void Poly::addPoly(const Poly& p)
{
	// TODO
	Poly passed = p;
	PolyNode* pHead = passed.getHead();
	
	//while loop to loop through poly p for each mononomial in this polynomial
	//1st condition: next ptr != NULL(to run through Poly p)
	while (pHead->next!=NULL) {
		pHead = pHead->next;
		double c = pHead->coeff;
		int d = pHead->deg;
		this->addMono(d,c);
	}

	update();
	
	return;
}//theta(n^2)

void Poly::multiplyMono(int i, double c)
{
	// TODO
	PolyNode* currentNode = this->getHead();
	//if the c is 0, delete all nodes in this poly and exit
	if (c == 0) {
		PolyNode* tmp;
		PolyNode* nodeHead = this->getHead();


		while (nodeHead->next != NULL)
		{
			tmp = nodeHead->next;
			nodeHead->next = nodeHead->next->next;
			//free(tmp);
		}
		
		update();

		return;
	}
	// while loop to loop through this poly 
	// condition: next ptr != NULL(to run through this Poly)
	while (currentNode->next != NULL) {
		//multiply each node's coeff by c, and add i to the degree
		currentNode->next->coeff = (currentNode->next->coeff) * c;
		currentNode->next->deg = (currentNode->next->deg) + i;
		currentNode = currentNode->next;
	}
	update();

}//theta(n)

void Poly::multiplyPoly(const Poly& p)
{
	Poly* thisCopy = new Poly();
	// copy this poly
	this->duplicate(*thisCopy);										
	//get negative version of this copy
	thisCopy->multiplyMono(0, -1);
	//add this copy to this to empty this poly
	this->addPoly(*thisCopy);
	//flip the sign of this copy again
	thisCopy->multiplyMono(0, -1);
	
	// While loop to run through each node in this polynomial
	Poly passed = p;
	PolyNode* pHead = passed.getHead();
	while (pHead->next != NULL) {
		int d = pHead->next->deg;
		double c = pHead->next->coeff;
		// we will multiply each monomomial in Poly p by this copy and store it in original this poly
		Poly* thisCopyCopy = new Poly();
		thisCopy->duplicate(*thisCopyCopy);							//n
		thisCopyCopy->multiplyMono(d, c);							//n
		//add the products of the mononomials and the polynomials
		this->addPoly(*thisCopyCopy);								//n^2*m
		//next node
		pHead = pHead->next;
	}


}

void Poly::duplicate(Poly& outputPoly)
{
	// TODO
	//add the entirety of this to outpoly
	outputPoly.addPoly(*this);

}

int Poly::getDegree()
{
	// TODO
	return this->deg;;//change this after completing this function
}

int Poly::getTermsNo()
{
	// TODO
	return this->numTerms;//change this after completing this function
}

double Poly::evaluate(double x)
{
	// TODO

	
	double total = 0;
	PolyNode* head = this->head->next;

	while (head != NULL) {
		total += head->coeff * pow(x, head->deg);
		head = head->next;

	}
	
	//Example: If this polynomial is P (X) = 4X3 + 5X + 2, then the invocation
	//evaluate(2.0) returns the value 4 * 2.03 + 5 * 2.0 + 2 = 44.0

	return -1;//change this after completing this function
}

std::string Poly::toString()
{
	// TODO
	// create starter string and set it to degree = get degree
	std::string answer = "degree = " + std::to_string(this->getDegree()) + "; ";
	
	// loop throgh LL to add the mononomial
	PolyNode currentNode = *this->getHead();

	//condition: next ptr != NULL
	while (currentNode.next != NULL) {
		answer = answer + "a(" + std::to_string(currentNode.next->deg)+ ") = "+ std::to_string(currentNode.next->coeff) + ";  ";
		currentNode = *(currentNode.next);
		//std::cout << std::to_string(currentNode->coeff) << std::endl;
	}

	//Example: If this polynomial is P(X) = 4X3 + 5X + 2, then the string representation could be :
	//“degree = 3; a(3) = 4.0; a(1) = 5.0; a(0) = 2.0"
	return answer;		//change this after completing this function
}

void Poly::deleteZeroMono() {
	//check to see if mononomial coeff is non-zero
	//while loop to loop through the SLL
	PolyNode* currentNode = this->getHead();

	//no header so exit
	if (currentNode->next == NULL) { return; }

	//condition: next ptr != NULL, and the deg is still bigger than the current deg of the node
	while (currentNode->next != NULL) {
		while (currentNode->next != NULL && currentNode->next->coeff == 0) {

			PolyNode* tmp = currentNode->next;
			currentNode->next = currentNode->next->next;
			//free(tmp);
			//decrement number of terms by 1
			this->numTerms--;


		}
		//std::cout << std::to_string(currentNode->coeff) << std::endl;
		if (currentNode == NULL || currentNode->next == NULL) { return; }
		currentNode = currentNode->next;


	}
}//theta(n)


void Poly::updateDegree() {
	//empty poly
	if (this->getHead()->next == NULL) { 
		this->deg = -1;
		return; 
	}
	//if this deg doesnt match with the first term, change it
	if (this->getDegree() != this->getHead()->next->deg) {
		this->deg = this->getHead()->next->deg;
	}
}//theta(1)

void Poly::updateTerms() {
	int counter = 0;
	PolyNode* temp = this->head;
	while (temp->next != NULL) {
		counter++;
		temp = temp->next;
	}
	this->numTerms = counter;
}//theta(n)

void Poly::update() {
	deleteZeroMono();
	updateDegree();
	updateTerms();
}//theta(n)

