#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "linkedQueue.h"


using namespace std;

template <class T>
struct AVLNode
{
	T * info;
	/*If the left side is higher(left high) bfactor = -1
	  if the right side is higher(right high) bfactor = 1
	  if hights are equal bfactor = 0
	*/
	int bfactor;
	AVLNode<T> * lTree;
	AVLNode<T> * rTree;
	~AVLNode(){delete info;};
};


template <class T>
class AVLTreeType
{
	public: 
		const AVLTreeType<T>& operator=(const AVLTreeType<T>&);
		bool isEmpty() const;
		void inorderTraversal() const;
		void preorderTraversal() const;
		void postorderTraversal() const;
		int treeHeight() const;
		int treeNodeCount() const;
		int treeLeavesCount() const;
		void destroyTree();
		bool search(const T& searchItem) const;
		void insert(const T& insertItem);
		void deleteNode(const T& deleteItem);
		template <class Type> friend ostream& operator<<(ostream& out, const AVLTreeType<Type>& tree);
		AVLTreeType(const AVLTreeType<T>& otherTree);
		AVLTreeType();
		~AVLTreeType();
	protected:
		AVLNode<T> *root;
	private:
		void copyTree(AVLNode<T>* &copiedTreeRoot, AVLNode<T>* otherTreeRoot);
		void destroy(AVLNode<T>* &p);
		void inorder(AVLNode<T> *p) const;
		void preorder(AVLNode<T> *p) const;
		void postorder(AVLNode<T> *p) const;
		int height(AVLNode<T> *p) const;
		int max(int x, int y)const;
		int nodeCount(AVLNode<T> *p) const;
		int leavesCount(AVLNode<T> *p) const;
		bool search(const T& searchItem, AVLNode<T>* p) const;
		string printTree() const;
		void rotateToLeft(AVLNode<T>* &root);
		void rotateToRight(AVLNode<T>* &root);
		void balanceFromLeft(AVLNode<T>* &root);
		void balanceFromRight(AVLNode<T>* &root);
		void insertIntoAVL(AVLNode<T>* &root, AVLNode<T>* newNode, bool& isTaller);
};

template <class T>
void AVLTreeType<T>::inorder(AVLNode<T> *p) const
{
	if(p != nullptr)
	{
		inorder(p->lTree);
		cout << *p->info << endl;
		inorder(p->rTree);
	}
}

template <class T>
void AVLTreeType<T>::preorderTraversal() const
{
	preorder(root);
}

template <class T>
void AVLTreeType<T>::preorder(AVLNode<T> *p) const
{
	if(p != nullptr)
	{
		cout << *p->info << " ";
		preorder(p->lTree);
		preorder(p->rTree);
	}
}
template <class T>
void AVLTreeType<T>::postorderTraversal() const
{
	postorder(root);
}

template <class T>
void AVLTreeType<T>::postorder(AVLNode<T> *p) const
{
	if(p != nullptr)
	{
		postrder(p->lTree);
		
		postorder(p->rTree);
		cout << *p->info << " ";
	}
}

template <class T>
int AVLTreeType<T>::height(AVLNode<T> *p) const
{
	if(p == nullptr)
	{
		return 0;
	}
	else 
		return 1 + max(height(p->lTree), height(p->rTree));
}

template <class T>
int AVLTreeType<T>::treeHeight() const 
{
	return height(root);
}
template <class T>
int AVLTreeType<T>::max(int x, int y) const
{
	if(x >= y)
		return x;
	else 
		return y;
}

template <class T>
void AVLTreeType<T>::copyTree(AVLNode<T> * &copiedTreeRoot, AVLNode<T> * otherTreeRoot)
{
	if(otherTreeRoot == nullptr)
		copiedTreeRoot = nullptr;
	else
	{
		copiedTreeRoot = new AVLNode<T>;
		copiedTreeRoot->info = new T(*otherTreeRoot->info);
		copyTree(copiedTreeRoot->lTree, otherTreeRoot->lTree);
		copyTree(copiedTreeRoot->rTree, otherTreeRoot->rTree);
	}
}

template <class T>
void AVLTreeType<T>::destroy(AVLNode<T> * &p)
{
	if(p!= nullptr)
	{
		destroy(p->lTree);
		destroy(p->rTree);
		delete p;
		p = nullptr;
	}
}

template <class T>
void AVLTreeType<T>::destroyTree()
{
	destroy(root);
}

template <class T>
AVLTreeType<T>::AVLTreeType()
{
	root = nullptr;
}

template <class T>
AVLTreeType<T>::~AVLTreeType()
{
	destroy(root);
}

template <class T>
AVLTreeType<T>::AVLTreeType(const AVLTreeType<T>& otherTree)
{
	if(otherTree.root == nullptr)
		root = nullptr;
	else
		copyTree(root, otherTree.root);
}

template <class T>
const AVLTreeType<T>& AVLTreeType<T>::operator=(const AVLTreeType<T>& otherTree)
{
	if(this != &otherTree)
	{
		if(root != nullptr)
			destroy(root);
		if(otherTree.root == nullptr)
			root = nullptr;
		else
		copyTree(root, otherTree.root);
	}
	
	return *this;
	
}

template <class T>
bool AVLTreeType<T>::search(const T& searchItem) const
{
	return search(searchItem, root);
}

template <class T>
bool AVLTreeType<T>::search(const T& searchItem, AVLNode<T> * p) const
{
	if(p == nullptr)
		return false;
	else
	{
		if(*p->info==searchItem)
			return true;
		else if (searchItem <*p->info)
			return search(searchItem, p->lTree);
		else 
			return search(searchItem, p->rTree);
		
	}
}

template <class T>
void AVLTreeType<T>::rotateToLeft(AVLNode<T>* &root)
{
	AVLNode<T> *p;
	if(root == nullptr)
		cout << "Error" << endl;
	else if (root->rTree == nullptr)
		cout << "Error" << endl;
	else
	{
		p = root->rTree;
		root->rTree = p->lTree;
		p->lTree = root;
		root = p;
	}
	
}

template <class T>
void AVLTreeType<T>::rotateToRight(AVLNode<T>* &root)
{
	AVLNode<T> *p;
	if(root == nullptr)
		cout << "Error" << endl;
	else if (root->lTree == nullptr)
		cout << "Error" << endl;
	else
	{
		p = root->lTree;
		root->lTree = p->rTree;
		p->rTree = root;
		root = p;
	}
}

template <class T>
void AVLTreeType<T>::balanceFromLeft(AVLNode<T>* &root)
{
	AVLNode<T> *p;
	AVLNode<T> *w;
	p = root->lTree;
	switch(p->bfactor)
	{
		case -1:
			root->bfactor = 1;
			p->bfactor = 0;
			rotateToRight(root);
			break;
		case 0:
			cout << "Error" << endl;
		case 1:
			w = p->rTree;
			switch(w->bfactor)
			{
				case -1:
					root->bfactor = 1;
					p->bfactor = 0;
					break;
				case 0:
					root->bfactor = 0;
					p->bfactor = 0;
					break;
				case 1:
					root->bfactor = 0;
					p->bfactor = -1;
			}
			w->bfactor = 0;
			rotateToLeft(p);
			root->lTree = p;
			rotateToRight(root);
			
	}
}

template <class T>
void AVLTreeType<T>::balanceFromRight(AVLNode<T>* &root)
{
	AVLNode<T> *p;
	AVLNode<T> *w;
	p = root->rTree;
	switch(p->bfactor)
	{
		case -1:
			w = p->lTree;
			switch(w->bfactor)
			{
				case -1:
					root->bfactor = 0;
					p->bfactor = 1;
					break;
				case 0:
					root->bfactor = 0;
					p->bfactor = 0;
					break;
				case 1:
					root->bfactor = -1;
					p->bfactor = 0;
			}
			w->bfactor = 0;
			rotateToRight(p);
			root->rTree = p;
			rotateToLeft(root);
			break;
		case 0:
			cout << "Error" << endl;
		case 1:
			root->bfactor = 0;
			p->bfactor = 0;
			rotateToLeft(root);
			
			
	}
}

template <class T>
void AVLTreeType<T>::insertIntoAVL(AVLNode<T>* &root, AVLNode<T>* newNode, bool& isTaller)
{
	if(root == nullptr)
	{
		root = newNode;
		isTaller = true;
	}
	else if (*root->info == *newNode->info)
		cout << "No dupes" << endl;
	else if (*root->info > *newNode->info)
	{
		insertIntoAVL(root->lTree, newNode, isTaller);
		if(isTaller)
		{
			switch(root->bfactor)
			{
				case -1:
					balanceFromLeft(root);
					isTaller = false;
				case 0:
					root->bfactor = -1;
					isTaller = true;
					break;
				case 1:
					root->bfactor = 0;
					isTaller = false;
			}
		}
	}
	else
	{
		insertIntoAVL(root->rTree, newNode, isTaller);
		if(isTaller)
		{
			switch(root->bfactor)
			{
				case -1:
					root->bfactor = 0;
					isTaller = false;
					break;
				case 0:
					root->bfactor = 1;
					isTaller = true;
					break;
				case 1:
					balanceFromRight(root);
					isTaller = false;
			}
		}
	}
}

template <class T>
void AVLTreeType<T>::insert(const T& newItem)
{
	bool isTaller = false;
	AVLNode<T> * newNode;
	newNode = new AVLNode<T>;
	newNode->info = new T(newItem);
	newNode->bfactor = 0;
	newNode->lTree = nullptr;
	newNode->rTree = nullptr;
	
	insertIntoAVL(root, newNode, isTaller);
}



template<class T>
string AVLTreeType<T>::printTree() const
{
	ostringstream out;
	struct nodeDepth
	{
		AVLNode<T>* n;
    	int lvl;
    	//node_depth(node<T>* n_, int lvl_) : n(n_), lvl(lvl_) {}
	};
	int depth = height(root);
	int last_lvl = 0;
	int offset = (1 << depth) - 1;
	linkedQueueType<nodeDepth> nodes;
	nodeDepth rootDepth;
	rootDepth.n = root;
	rootDepth.lvl = last_lvl;
	nodes.enqueue(rootDepth);
	while(!nodes.isEmptyQueue())
	{
		nodeDepth current = nodes.front();
		if(last_lvl != current.lvl)
		{
			out << endl;
			last_lvl = current.lvl;
    		offset = (1 << (depth - current.lvl)) - 1;
			
		}
		if(current.n != nullptr)
		{
			out << setw(offset) << " ";
			out << setw(3) << *current.n->info;
			out << setw(offset) << " ";
			nodeDepth left;
			nodeDepth right;
			left.n = current.n->lTree;
			right.n = current.n->rTree;
			left.lvl = last_lvl + 1;
			right.lvl = last_lvl + 1;
			nodes.enqueue(left);
			nodes.enqueue(right);
		} 
		else
		{
			out << setw(offset) << " " << "   ";
			out << setw(offset) << " ";
		}
		nodes.dequeue();
	}
	out << endl;
	
	return out.str();
}

template <class elemType>
ostream& operator<<(ostream& out, const AVLTreeType<elemType>& tree)
{
	out << tree.printTree();
	return out;
}
#endif