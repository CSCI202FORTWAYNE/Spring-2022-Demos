#include <iostream>
#include "AVLTree.h"


using namespace std;



int main()
{
	
	AVLTreeType<int> tree;
	for(int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		tree.insert(x);
		cout << tree << endl << endl;
	}
	
	//cout << tree;
	
	
	return 0;
}

