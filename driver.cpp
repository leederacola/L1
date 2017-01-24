#include "Wrapper.h"
#include "createInstance.h"

//-------------------------------------------------------------------

void loadRandomIntoQueue(IntegerQueue& q, Integer numberToLoad)
//! replaces q
//! restores numberToLoad
//! requires: numberToLoad >= 0
//! ensures: |q| = numberToLoad and q contains integers generated from rand() function
{
	for (int k = 0; k < numberToLoad; k++) {
		Integer y = rand() % 1000;
		q.enqueue(y);
	} // end for
} // loadRandomIntoQueue




void loadRandomIntoSequence(IntegerSequence& s, Integer numberToLoad)
//! replaces s
//! restores numberToLoad
//! requires: numberToLoad >= 0
//! ensures: |s| = numberToLoad and s contains integers generated from rand() function
{
	for (int k = 0; k < numberToLoad; k++) 
	{

		Integer y = rand() % 1000;
		s.add(0, y);
	} // end for
} // loadRandomIntoSequence
//-------------------------------------------------------------------

void displayQueue(IntegerQueue& q)
//! restores q
//! ensures: contents of q are displayed, separated by commas
{
	IntegerQueue qTemp;

	wcout << "<";
	for (int k = 0, z = q.length(); k < z; k++) {
		Integer y;

		q.dequeue(y);
		wcout << y;
		if (q.length() > 0) {
			wcout << ",";
		} // end if
		qTemp.enqueue(y);
	} // end for
	wcout << ">";
	q.transferFrom(qTemp);
} // displayQueue


void displaySequence(IntegerSequence& s)
//! restores s
//! ensures: contents of s are displayed, separated by commas
{
	IntegerSequence sTemp;

	wcout << "<";
	for (int k = 0, z = s.length(); k < z; k++) 
	{
		Integer y;
		s.remove(0, y); //remove items from s at pos 0
		
		wcout << y;
		if (s.length() > 0) 
		{
			wcout << ",";
		} // end if
		sTemp.add(k, y);  //add removed item y to pos k in sTemp
	} // end for
	
	wcout << ">";
	s.transferFrom(sTemp);
} // displayQueue

//-------------------------------------------------------------------



void moveLargestToFront(IntegerSequence& s)
//! updates s
//! requires: |s| > 0
//! ensures: the largest value found in s is moved to position zero and
//!          perms(#s, s)
{
	Integer largest, count, temp;	//stores current largest, counts up to s.length, hold value for teting
	{
		s.remove(0, largest);
		while (count < s.length())
		{
			s.remove(0,temp);
			if (temp > largest)
			{					
				//!!!!!!!!does not add item when there is a new large!!!!!!!!!!!all attempts to fix have failed!!!!!!!!
				s.add(s.length() - 1, largest);
				largest = temp;   //temp > largest, assign new largest										
			}
			else  //temp < largest...
			{
				s.add((s.length() - 1), temp); // put temp in back of the sequence........
			}
			//wcout << "temp " << temp << "\n";
			//wcout << "large " << largest << "\n";
			count++;
		}
		
		s.add(0, largest);  //add largest to front of sequence
	}//end while loop
} // moveLargestToFront



  //-------------------------------------------------------------------

void reverse(IntegerSequence& s)
//! updates s
//! ensures: s = rev(#s)
{
	IntegerSequence sTemp;
	Integer count, temp;
	Integer len = s.length();
	for (count = 0; count < len; count++)
	{
		s.remove(0, temp);
		sTemp.add(0, temp);
		
	}
	s = sTemp;
} // reverse



//-------------------------------------------------------------------
// main executable body
//-------------------------------------------------------------------

int main(int argc, char* argv[])
{
	// Do not change the next 5 lines
	Integer numToLoad = 7;
	if (argc > 1) {
		// obtain from the command line the number of integers to load
		numToLoad = atoi(argv[1]);
	} // end if

	
	IntegerSequence s1, s2;
	
	wcout << "s1 = " << s1 << endl;
	loadRandomIntoSequence(s1, numToLoad);
	wcout << "s1 = " << s1 << " after loading " << numToLoad << " items into s1" << endl << endl;
	
	wcout << "Display s1 using displaySequence: ";
	displaySequence(s1);
	wcout << endl << endl;

	wcout << "s1 = " << s1 << " before moving largest to the front" << endl;
	moveLargestToFront(s1);
	wcout << "s1 = " << s1 << " with largest at the front" << endl << endl;
	
	wcout << "s1 = " << s1 << " before reverse operation" << endl;
	reverse(s1);
	wcout << "s1 = " << s1 << " after reverse operation" << endl << endl;

	system("pause");
	return 0;
}	// end main


	/*
	TODO #11:
		1) Eliminate from this file all "TODO" comments
		2) Rebuild and run - there should be no compiler errors
		3) Eliminate from this file all lines that have to do with Queue
		4) Rebuild and run - there should be no compiler errors
		5) Your output should now look similar to the output from L1Sol.exe except
		   that the random integers might be different
		6) Go back to the file createInstance.h and do TODO #12
	*/