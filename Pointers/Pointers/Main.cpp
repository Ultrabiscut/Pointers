#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//
//
//
//

//define the sorting object
struct candidate
{
	//member variables
	string name;
	int numVotes;
	double percent;


};

//function prototypes
void voters(candidate *vArray, int iAmount);
void percent(candidate *vArray, int iAmount);
int winner(candidate *vArray, int iAmount);
void print(candidate *vArray, int iAmount, int iLoc);

int main()
{
	//declare variables
	int iNum; //store size of array
	int iLocation; //hold what is returned from winner function
	candidate *voteArray; //pointer for array

	//get input
	cout << "How many candidates are there: ";
	cin >> iNum;

	voteArray = new candidate[iNum]; //create the dynamic array

	//call on name function
	voters(voteArray, iNum);
	cout << "\n";

	//call on percent function
	percent(voteArray, iNum);
	
	//call on winner function
	iLocation = winner(voteArray, iNum); 
	cout << fixed << setprecision(2);
	//call on print function
	print(voteArray, iNum, iLocation);
	cout << "\n";

	//deallocate memory
	delete[] voteArray;
	voteArray = NULL;
	
	return 0;
}

//candidate's name function
void voters(candidate *vArray, int iAmount)
{
	//loop for names and votes
	for (int x = 0; x < iAmount; x++)
	{
		//voters name
		cout << "Enter voter " << x + 1 << " : ";
		cin >> vArray[x].name;
		
		//amount of votes 
		cout << "Enter votes for candidate " << x + 1 << " : ";
		cin >> vArray[x].numVotes;
	}


}

//percent function
void percent(candidate *vArray, int iAmount)
{
	//declare variables
	double iTotal = 0.0;

	for (int x = 0; x < iAmount; x++)
	{

		iTotal = iTotal + vArray[x].numVotes;

	}



	for (int x = 0; x < iAmount; x++)
	{

	vArray[x].percent = (vArray[x].numVotes / iTotal) * 100;

	}

}

//winner function
int winner(candidate *vArray, int iAmount)
{
	//delcare variables
	double dLargest = 0; //hold the largest of the percents
	int iLocation = 0; //will hold the location where it is found

	for (int x = 0; x < iAmount; x++)
	{
		if (vArray[x].percent > dLargest)
		{
			dLargest = vArray[x].percent;
			iLocation = x;
		}
	}

	return iLocation; //return location
}



//print function
void print(candidate *vArray, int iAmount, int iLoc)
{
	cout << "Candidate \t"
		<< "Votes \t"
		<< "% Of Total Votes \n";
	cout << "-----------------------------------------\n";

	//loop through array display EVERYTHING!!!!
	for (int x = 0; x < iAmount; x++)
	{
		cout << vArray[x].name << "\t"
			<< right << setw(12) << vArray[x].numVotes << "\t"
			<< setw(9) << vArray[x].percent << "\n";
	}
	cout << endl;

	cout << "The winner is " << vArray[iLoc].name << " !!!" << endl;
}