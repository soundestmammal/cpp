// (c) 2018 David Gerstl, all rights reserved

#include <iostream>
#include <set>
#include <random>
#include "bst.h"

bool test1();
bool test2();
int main() {
	int pause;
	farmingdale::bst theTestTree;
	theTestTree.insert("0000012");
	theTestTree.insert("0000027");
	theTestTree.insert("0000002");
	theTestTree.insert("0002498");
	theTestTree.insert("0000035");
	theTestTree.insert("0000115");
	theTestTree.insert("0000420");

	theTestTree.insert("0096357");
	theTestTree.insert("0005000");
	theTestTree.insert("0003000");
	theTestTree.insert("0006000");
	theTestTree.insert("0100000");
	theTestTree.insert("1000000");
	theTestTree.insert("0990000");
	// theTestTree.remove("0000012");
	std::cout << theTestTree << std::endl;

	bool passedSoFar = true;
	passedSoFar = test1();
	if (!passedSoFar) {
		std::cerr << "Failed test 1" << std::endl;
	}
	else {
		std::cerr << "Passed test 1" << std::endl;
	}
	passedSoFar = test2();
	if (!passedSoFar) {
		std::cerr << "Failed test 2" << std::endl;
	}
	else {
		std::cerr << "Passed test 2" << std::endl;
	}
	std::cin >> pause;

	return 0;
}


bool test2() {
	farmingdale::bst testBST;
	testBST.insert("Now is the winter of our discontent");
	testBST.insert("Made glorious summer by this sun of York");
	testBST.insert("And all the clouds that lour'd upon our house");
	testBST.insert("In the deep bosom of the ocean buried.");
	testBST.insert("Now are our brows bound with victorious wreaths;");
	testBST.insert("Our bruised arms hung up for monuments;");
	testBST.insert("Our stern alarums changed to merry meetings,");
	testBST.insert("Our dreadful marches to delightful measures.");
	testBST.insert("Grim - visaged war hath smooth'd his wrinkled front;");
	testBST.insert("And now, instead of mounting barbed steeds");
	testBST.insert("To fright the souls of fearful adversaries,");
	testBST.insert("He capers nimbly in a lady's chamber");
	testBST.insert("To the lascivious pleasing of a lute.");
	testBST.insert("But I, that am not shaped for sportive tricks,");
	testBST.insert("Nor made to court an amorous looking - glass;");
	testBST.insert("I, that am rudely stamp'd, and want love's majesty");
	testBST.insert("To strut before a wanton ambling nymph;");
	testBST.insert("I, that am curtail'd of this fair proportion,");
	testBST.insert("Cheated of feature by dissembling nature,");
	testBST.insert("Deformed, unfinish'd, sent before my time");
	testBST.insert("Into this breathing world, scarce half made up,");
	testBST.insert("And that so lamely and unfashionable");
	testBST.insert("That dogs bark at me as I halt by them;");
	testBST.insert("Why, I, in this weak piping time of peace,");
	testBST.insert("Have no delight to pass away the time,");
	testBST.insert("Unless to spy my shadow in the sun");
	testBST.insert("And descant on mine own deformity");
	testBST.insert("And therefore, since I cannot prove a lover,");
	testBST.insert("To entertain these fair well - spoken days,");
	testBST.insert("I am determined to prove a villain");
	testBST.insert("And hate the idle pleasures of these days.");
	testBST.insert("Plots have I laid, inductions dangerous,");
	testBST.insert("By drunken prophecies, libels and dreams,");
	testBST.insert("To set my brother Clarence and the king");
	testBST.insert("In deadly hate the one against the other :");
	testBST.insert("And if King Edward be as true and just");
	testBST.insert("As I am subtle, false and treacherous,");
	testBST.insert("This day should Clarence closely be mew'd up,");
	testBST.insert("About a prophecy, which says that 'G'");
	testBST.insert("Of Edward's heirs the murderer shall be.");
	testBST.insert("Dive, thoughts, down to my soul : here");
	testBST.insert("Clarence comes.");
	if (0 == testBST.search("That dogs bark at me as I halt by them;")) {
		std::cerr << "Error at line " << __LINE__ << std::endl;
		return false;
	}
	if (0 != testBST.search("Cry 'Havoc!,' and let slip the dogs of war.")) {
		std::cerr << "Error at line " << __LINE__ << std::endl;
		return false;
	}


	return true;
}


std::ostream & operator<<(std::ostream & theStream, std::set<std::string> & theSet) {
	std::set<std::string>::iterator currentIt = theSet.begin();
	while (currentIt != theSet.end()) {
		theStream << *currentIt << " ";
		++currentIt;
	}
	return theStream;
}
// This test code is untested...
bool test1() {
	farmingdale::bst myBST;
	std::set<int> mySet;

	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	const int NUM_ITEMS = 10000;
	std::uniform_int_distribution<> dis(1, NUM_ITEMS);
	std::pair<std::set<int>::iterator, bool> ret;
	farmingdale::status status1;
	std::string string1;

	for (int i = 0; i < NUM_ITEMS; ++i) {
		// get a random number (between 1 and NUM_ITEMS)
		int num = dis(gen);
		// insert string representation into bst
		string1 = std::to_string(num);
		status1 = myBST.insert(string1);
		// insert into set
		ret = mySet.insert(num);
		// if bst returned FAILURE, it better be that set returned pair::second  == false
		// if bst returned SUCCESS, it better be that set returned pair::second  == true
		if (farmingdale::FAILURE == status1 && false != ret.second) {
			std::cerr << "Error at line " << __LINE__ << " iteration " << i << std::endl;
			return false;
		}
		else if (farmingdale::SUCCESS == status1 && true != ret.second) {
			std::cerr << "Error at line " << __LINE__ << " iteration " << i << std::endl;
			return false;
		}
	}
	// cheap way of doing this; not very good;
	std::set<int>::iterator myIter = mySet.begin();
	while (mySet.end() != myIter) {
		// look for string rep of -(*myIter) in BST. it should fail
		string1 = std::to_string(-(*myIter));
		if (0 != myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		// look for string rep of (*myIter+2*NUM_ITEMS) in BST. it should fail
		string1 = std::to_string((*myIter) + (2 * NUM_ITEMS));
		if (0 != myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		// look for string per of *myIter in BST. This should succeed.
		string1 = std::to_string(*myIter);
		if (0 == myBST.search(string1)) {
			std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
			return false;
		}
		myIter++;
	}
	// remove about NUM_ITEMS/5 from the BST and set. Store somewhere
	std::set<std::string> removedSet;
	std::pair<std::set<std::string>::iterator, bool> retS;
	farmingdale::bstNode *aNode;
	std::uniform_int_distribution<> smallDis(1, 5);
	myIter = mySet.begin();
	while (mySet.end() != myIter) {
		int num = smallDis(gen);
		if (2 == num) {
			// store this item in removedSet, and remove from myBST
			string1 = std::to_string(*myIter);
			retS = removedSet.insert(string1);
			// This can't be a duplicate, so  it better be that set returned pair::second  == true
			if (false == retS.second) {
				std::cerr << "Error at line " << __LINE__ << " inserting " << string1 << " into removedSet" << std::endl;
				// std::cerr << "RemovedSet is " << removedSet << std::endl;
				return false;
			}
			if (0 == (aNode = myBST.search(string1)) || farmingdale::FAILURE == myBST.remove(aNode)) {
				std::cerr << "Error at line " << __LINE__ << " removing " << string1 << std::endl;
				return false;
			}
			// std::cerr << "Removed " << string1 << std::endl;
		}
		myIter++;
	}
	// check the item are not in BST
	myIter = mySet.begin();
	while (mySet.end() != myIter) {
		string1 = std::to_string(*myIter);
		if (removedSet.end() == removedSet.find(string1)) {
			// should be there
			if (0 == myBST.search(string1)) {
				std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
				return false;
			}
		} else {
			// was removed
			if (0 != myBST.search(string1)) {
				std::cerr << "Error at line " << __LINE__ << " looking for " << string1 << std::endl;
				return false;
			}
		}
		++myIter;
	}
	// didn't fail
	return true;
}