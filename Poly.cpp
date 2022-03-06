#include "Poly.h"

Poly::Poly()
{
	// TODO	
	//set degree to -1
	this->deg = -1;
	//create the zero polynomial

}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{//
	// TODO	
	//creates a singly linked list (using the polynode class)
	//the degree elements are in increasing order so no checking required
	
	//step 1 create a for loop that runs for the size of deg vector

	//step 2 in each iteration in the loop: create a new node in the LL

	//in each node set the d to the ith degree element, and the c to the ith coefficient
	//set the "next PolyNode ptr" to a new polyNode
	//in the new PNode, point it to null
	//by the end each PNode will point to the next node except the tail will point to null
}

Poly::~Poly()
{
	// TODO
	// reach out to a buddy and check again how to delete a SLL or delete a polyNode
}

void Poly::addMono(int i, double c)
{
	// TODO
	// 
	// 
	//if coeff == 0, exit

	//while loop to loop through the SLL
	//condition: next ptr != NULL, and the deg is still bigger than the current deg of the node

}

void Poly::addPoly(const Poly& p)
{
	// TODO


	//Double while loop to loop through poly p for each mononomial in this polynomial
	//1st condition: next ptr != NULL(to run through Poly p)
		//2nd condition: next ptr != NULL, and the deg of the ith node in poly P is still bigger than the jth node in this
			//if the degree is equal, add the coeff
			// if the degree is smaller, insert the polynomial after the jth node


}

void Poly::multiplyMono(int i, double c)
{
	// TODO

	//if the c is 0, delete all nodes in this poly and exit
	
	// while loop to loop through this poly 
	// condition: next ptr != NULL(to run through this Poly)
	//multiply each node's coeff by c, and add i to the degree

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
	// loop throgh LL to add the mononomial
	// 

	//Example: If this polynomial is P(X) = 4X3 + 5X + 2, then the string representation could be :
	//“degree = 3; a(3) = 4.0; a(1) = 5.0; a(0) = 2.0"
	return "";//change this after completing this function
}
