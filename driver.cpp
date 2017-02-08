#include "Wrapper.h"
#include "createInstance.h"

//-------------------------------------------------------------------

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


/* practice quizes operation subtract

void subtract(IntegerSequence& s, Integer toSub)
//! updates s
//! restores x
//! ensures: s = s# with all values of s reduced by toSub
{
	Integer count, temp;
	Integer len = s.length();
	for (count = 0; count < len; count++)
	{
		s.remove(0, temp);  //remove first save as temp
		temp = (temp - toSub);		//subtract toSub from temp
		s.add((len-1), temp);	//add new temp to back
	}//end for
}//end suntract


void moveItemsFromS1ToS2(IntegerSequence& s1, IntegerSequence& s2)
//! updates s1
//! replaces s2
//! ensures: all items in #s1 located in odd numbered positions  
//!          have been removed and put into s2 in same order and
//!          the items remaining in s1 are in the same order as 
//!          they were in #s1
{
	Integer count, temp, posCount;
	IntegerSequence sTemp;
	Integer len = s1.length();
	
	s2 = sTemp;  //clear to replace s2 so it can up updates

	for (count = 0; count < len; count++)
	{
		s1.remove(0, temp);
		if (posCount % 2 == 1) //if pos is odd
		{
			s2.add(s2.length(), temp); //add back of s2
			posCount++;
		}
		else // pos is even
		{
			s1.add(s1.length(), temp);  //add to back of s1
			posCount++;
		}//end if
	}//end for
}//end moveItems...
*/




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

	
	IntegerSequence s1, s2, s3;
	
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

	
	/*practice 
	Integer y = 47;
	s2.add(s2.length(), y);
	y = 10;
	s2.add(s2.length(), y);
	y = 57;
	s2.add(s2.length(), y);
	y = 9;
	s2.add(s2.length(), y);
	y = 67;
	s2.add(s2.length(), y);
	y = 8;
	s2.add(s2.length(), y);
	y = 0;
	s2.add(s2.length(), y);
	y = 18;
	s3.add(0, y);
	

	wcout << "s2 = " << s2 << " before sub operation" << endl;
	subtract(s2, 10);
	wcout << "s2 = " << s2 << " after sub operation" << endl << endl;
	
	wcout << " before moveItemsfromS1toS2" << endl;
	wcout << s2 << endl;
	wcout <<  s3 << endl;
	moveItemsFromS1ToS2(s2, s3);
	wcout << " after moveItemsfromS1toS2" << endl;
	wcout << s2 << endl;
	wcout << s3 << endl;
	*/


	system("pause");
	return 0;
}	// end main