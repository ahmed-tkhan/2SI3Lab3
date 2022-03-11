#include "Poly.h"
#include <iostream>


Poly::Poly()
{
	// TODO	
	//set degree to -1
	this->deg = -1;
	//create the zero polynomial
	head = new PolyNode(NULL, NULL, NULL);

}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	// TODO	
	//creates a singly linked list (using the polynode class)
	this->head = new PolyNode(NULL, NULL, NULL);
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
	PolyNode* tmp;
	PolyNode* nodeHead = this->head;


	while (nodeHead != NULL)
	{
		tmp = nodeHead;
		nodeHead = nodeHead->next;
		free(tmp);
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
		current = current->next;
	}

	//new node/mononomial
	if (current->next == NULL) {
		PolyNode* newNode = new PolyNode(i, c, current->next);
		current->next = newNode;
		if (this->getDegree() < i) { this->deg = i; }
		this->numTerms++;
		deleteZeroMono();
		return;
	}
	if (current->next->deg != i) {
		PolyNode* newNode = new PolyNode(i, c, current->next);
		current->next = newNode;
		if (this->getDegree() < i) { this->deg = i; }
		this->numTerms++;
		deleteZeroMono();
		return;
	}
	//add to existing term
	else if (current->next->deg == i) {
		current->next->coeff += c;
		deleteZeroMono();
		return;
	}




}

void Poly::deleteZeroMono() {
	//check to see if mononomial coeff is non-zero
	//while loop to loop through the SLL
	PolyNode* currentNode = this->getHead();

	//condition: next ptr != NULL, and the deg is still bigger than the current deg of the node
	while (currentNode->next != NULL) {
		if (currentNode->next->coeff == 0) {
			PolyNode* tmp = currentNode->next->next;
			delete(currentNode->next);
			currentNode->next = tmp;
		}
		currentNode = currentNode->next;
		//std::cout << std::to_string(currentNode->coeff) << std::endl;
		}

	

}

void Poly::addPoly(const Poly& p)
{
	// TODO
	Poly passed = p;
	PolyNode pHead = *passed.getHead();
	
	//while loop to loop through poly p for each mononomial in this polynomial
	//1st condition: next ptr != NULL(to run through Poly p)
	while (pHead.next!=NULL) {
		double c = pHead.coeff;
		int d = pHead.deg;
		passed.addMono(c,d);
		pHead = *pHead.next;
		
	}
		

}

void Poly::multiplyMono(int i, double c)
{
	// TODO
	PolyNode* currentNode = this->getHead();
	//if the c is 0, delete all nodes in this poly and exit
	if (c == 0) {
		PolyNode* tmp;
		PolyNode* nodeHead = this->head;


		while (nodeHead != NULL)
		{
			tmp = nodeHead;
			nodeHead = nodeHead->next;
			free(tmp);
		}
	}
	// while loop to loop through this poly 
	// condition: next ptr != NULL(to run through this Poly)
	//multiply each node's coeff by c, and add i to the degree
	while (currentNode->next != NULL) {
		currentNode->next->coeff = (currentNode->next->coeff) * c;
		currentNode->next->deg = (currentNode->next->deg) + i;
	}


	
	

}

void Poly::multiplyPoly(const Poly& p)
{
	// TODO
	// 
	// inefficient in both time and space:
	// ---------------------------------------------------------------
	// 
 	// While loop to create the vector/array of duplicate polynomials of poly P
	// 
	// While loop to run through each node in this polynomial
	// we will multiply each monomomial in this Poly by the whole poly P and store it in a vector/array of polynomials
	// note multiplying a polynomial by a mononomial means that the original poly is modified

	// While loop to empty this polynomial and then we will then add each of resulting polynomials

	//NOTE: need to create, duplicate, monoMultiply, addPoly
	//lol this is a really slow alghorithm and I get the feeling that this is wrong

}

void Poly::duplicate(Poly& outputPoly)
{
	// TODO

	// use a for loop using the get terms function to loop through each node    
	
	// create a vector of ints for the degrees
	// "                " doubles for the ceffs 
	// create a new polynomial using poly constructor


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

	// for loop to loop through each node
	// get the coeff and deg
	// multiply the coeff by the x to the power of the deg
	// add the answer 
	
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
	return answer;//change this after completing this function
}
