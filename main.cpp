#include <bits/stdc++.h>
using namespace std;

struct NODE 
{
    int key;
    NODE *left, *right;
};


NODE* creatNode(int data) 
{
    NODE* node = new NODE;
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//1 insert
void Insert(NODE* &pRoot, int x) 
{
    if (pRoot == NULL) 
	{
        pRoot = creatNode(x);
    } 
	else if (x < pRoot->key) 
	{
        Insert(pRoot->left, x);
    } 
	else 
	{
        Insert(pRoot->right, x);
    }
}

//2 travel node left right
void NLR(NODE* pRoot) 
{
    if (pRoot == NULL) return;
    cout << pRoot->key << " ";
    NLR(pRoot->left);
    NLR(pRoot->right);
}

//3 travel left node right
void LNR(NODE* pRoot) 
{
    if (pRoot == NULL) return;
    LNR(pRoot->left);
    cout << pRoot->key << " ";
    LNR(pRoot->right);
}

//4 travel left right node
void LRN(NODE* pRoot) 
{
    if (pRoot == NULL) return;
    LRN(pRoot->left);
    LRN(pRoot->right);
    cout << pRoot->key << " ";
}
//6 height of tree
int Height(NODE* pRoot)
{
	if(pRoot==NULL)
	{
		return 0;
	}
	else
	{
		int l=Height(pRoot->left);
		int r=Height(pRoot->right);
		return 1+max(l,r);
		
	}
}
//5 level order travel
void printlevel(NODE*pRoot,int lv)
{
	if(pRoot==NULL) return;
	if(lv==1) 
	{
		cout<<pRoot->key<<" ";
	}
	else if(lv>1)
	{
		printlevel(pRoot->left,lv-1);
		printlevel(pRoot->right,lv-1);
	}
	
	
}
void LevelOrder(NODE* pRoot)
{
	if(pRoot==NULL) return;
	int height=Height(pRoot);
	for(int i=1;i<=height;i++)
	{
		printlevel(pRoot,i);
	}
}


//7 count Node
int countNode(NODE* pRoot) 
{
    if (pRoot == NULL) 
	{
        return 0;
    } 
	else 
	{
        return 1 + countNode(pRoot->left) + countNode(pRoot->right);
    }
}

//8 sum Node
int sumNode(NODE* pRoot)
{
	if(pRoot == NULL)
	{
		0;
	}
	int l=sumNode(pRoot->left);
	int r=sumNode(pRoot->right);
	return l+r+pRoot->key;
}
//9 search Node by value
NODE* Search(NODE* pRoot, int x)
{
	if(pRoot == NULL||pRoot->key==x ) return pRoot;

	if(x<pRoot->key)
	{
		return Search(pRoot->left,x);
	}
	else 
	{
		return Search(pRoot->right,x);
	}
}
//10 remove by value
NODE* change(NODE* pRoot)
{
	while (pRoot->right != NULL) 
	{
        pRoot = pRoot->right;
    }
    return pRoot;
} 
void Remove(NODE* &pRoot, int x)
{
	if(pRoot == NULL) return;
	if(x>pRoot->key)
	{
		Remove(pRoot->right,x);
	}
	else if(x<pRoot->key)
	{
		Remove(pRoot->left,x);
	}
	else 
	{
		if(pRoot->left==NULL&pRoot->right==NULL)
		{
			delete pRoot;
			pRoot=NULL;	
		} 
		else if(pRoot->left==NULL)
		{
			NODE* temp = pRoot;
            pRoot = pRoot->right;
            delete temp;
		}
		else if(pRoot->right==NULL)
		{
			NODE*temp= pRoot;
			pRoot=pRoot->left;
			delete temp;
		}
		else
		{
			NODE*temp=change(pRoot);
			pRoot->key=temp->key;
			Remove(pRoot->right,temp->key);
		}
	}
	
}
//11 Create tree from array
NODE* createTree(int a[], int n)
{
	NODE*temp=NULL;
	for(int i=0;i<n;i++)
	{
		Insert(temp,a[i]);
	}
	return temp; 
}
//12 remove Tree 
void removeTree(NODE* &pRoot)
{
	if(pRoot==NULL) return;
	removeTree(pRoot->left);
	removeTree(pRoot->right);
	delete pRoot;
	pRoot=NULL;
}
//13 Calculate the height of a NODE with given value
int heightNode(NODE* pRoot, int value)
{
	NODE*temp=Search(pRoot,value);
	if(temp==NULL)
	{
		return -1;
	}
	return Height(temp);
}
//14 calculate a level of node
int Level(NODE* pRoot, NODE* p)
{
	int lv=1;
	if(pRoot==NULL)
	{
		return 0;
	}
	NODE*temp=pRoot;
	while(temp!=NULL)
	{
		if(temp->key==p->key)
		{
			return lv;
		}
		else if(p->key<temp->key)
		{
			temp=temp->left;
		}
		else 
		{
			temp=temp->right;
		}
		lv++;
	} 
	return -1;
}
// 15 Count the number leaves from a given Binary Tree:
int countLeaf(NODE* pRoot)
{
	if(pRoot==NULL)
	{
		return 0;
	}
	if (pRoot->left==NULL&&pRoot->right==NULL)
	{
		return 1;
	}
	return countLeaf(pRoot->left)+countLeaf(pRoot->right);
}
// 16 Count the number of NODE from a given Binary Search Tree which key value is less than a given
//value
int countLess(NODE* pRoot, int x)
{
	if(pRoot==NULL) return 0;
	int cnt=0;
	if(pRoot->key<x)
	{
		return 1+countLess(pRoot->left,x)+countLess(pRoot->right,x);
	}
	else 
	{
		return countLess(pRoot->left,x);
	}
	
}
// 17 count greater
int countGreater(NODE* pRoot, int x)
{
	if(pRoot==NULL) return 0;
	int cnt=0;
	if(pRoot->key>x)
	{
		return 1+countGreater(pRoot->left,x)+countGreater(pRoot->right,x);
	}
	else
	{
		return countGreater(pRoot->right,x);
	}
}
// 18 check binary search tree
//ham ho tro 1
bool checkLess(NODE*pRoot,int x)
{
	if(pRoot==NULL) return true;
	if(pRoot->key<=x&&checkLess(pRoot->left,x)&&checkLess(pRoot->right,x))
	{
		return true; 
	} 
	else 
	{
		return false;
	}
}
// ham ho tro 2
bool checkGreater(NODE*pRoot,int x)
{
	if(pRoot==NULL) return true;
	if(pRoot->key>x&&checkGreater(pRoot->left,x)&&checkGreater(pRoot->right,x))
	{
		return true; 
	} 
	else 
	{
		return false;
	}
}
bool isBST(NODE* pRoot)
{
	if(pRoot==NULL) return false;
	if(checkLess(pRoot->left,pRoot->key)&&checkGreater(pRoot->right,pRoot->key)&&isBST(pRoot->left)&&isBST(pRoot->right))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
// 20 check full binary tree
bool isFullBST(NODE* pRoot)
{
	if(pRoot==NULL) return false;
	int height=Height(pRoot);
	int node=countNode(pRoot);
	if(isBST(pRoot)&&node==pow(2,height+1)-1)
	{
		return true;
	}
	return false;
	
}
