#include <iostream>
#include <string>
#include <new>
#include <limits.h>
using namespace std;

class BinaryNode
{
  int         key;
  BinaryNode* left;
  BinaryNode* right;
	
public:
  BinaryNode( int x ): key(x), left(NULL), right(NULL) { };
  friend class BinarySearchTree;
};


class BinarySearchTree
{
	
  BinaryNode* root;

public:
  BinarySearchTree( );
  ~BinarySearchTree( );
  bool Insert( int x );
  bool Find( int x ) const;
  void Show( ) const;
  void RemoveMin();
  void RemoveMax();
	
	
private:
  bool insert( int x, BinaryNode* & p );
  bool find( int x, BinaryNode* p ) const;
  void show( BinaryNode* p ) const;
  void makeEmpty( BinaryNode* p );
  BinaryNode* removemin(BinaryNode* p);
  BinaryNode* removemax(BinaryNode* p); 
};

BinarySearchTree::BinarySearchTree( )
{
  root = NULL;
}

BinarySearchTree::~BinarySearchTree( )
{
  makeEmpty( root );
}

void BinarySearchTree::makeEmpty( BinaryNode* p )
{
  if ( p != NULL ) {
    makeEmpty( p -> left );
    makeEmpty( p -> right );
    delete p;
  }
}

bool BinarySearchTree::Insert( int x )
{
  return insert( x, root );
}

bool BinarySearchTree::insert( int x, BinaryNode* & p )
{
  if ( p == NULL ) {
    p =  new BinaryNode( x );
    return true;
  }
  else if ( p->key == x )
    return false ;
  else if ( p->key > x )
    return insert( x, p->left );
  else
    return insert( x, p->right );
}

void BinarySearchTree::Show( ) const
{
  show( root );
  cout << endl;
}

void BinarySearchTree::show( BinaryNode* p ) const
{
  if ( p != NULL ) {
    show( p->left );
    cout << p->key<<". ";
    show( p->right );
  }
}

bool BinarySearchTree::Find( int x ) const
{
  return find( x, root );
}

bool BinarySearchTree::find( int x, BinaryNode* p ) const
{
  if(p == NULL) return false;
  else if(p -> key == x) return true;
  else if(p -> key > x) return find(x,p->left);
  else {return find(x,p->right);}
}


void BinarySearchTree::RemoveMin()
{
  root = removemin(root); 
}


void BinarySearchTree::RemoveMax()
{
  root = removemax(root);
}

BinaryNode* BinarySearchTree::removemin(BinaryNode *p){
  if(p == NULL) return p;

  if(p -> left == NULL){
    BinaryNode* np = p -> right;
    delete p;
    return np;
  }

  p -> left = removemin(p -> left);
  return p;
}

BinaryNode* BinarySearchTree::removemax(BinaryNode *p){
  if(p == NULL) return p;

  if(p -> right == NULL){
    BinaryNode* np = p -> left;
    delete p;
    return np;
  }

  p -> right = removemax(p -> right);
  return p;
}

int main( )
{ 
	
  BinarySearchTree bst;
	
  int data;
  while( !cin.eof() ){
    cin >> data;
    bst.Insert(data);
  }

  bst.Show();
	
  bst.RemoveMax();
  bst.RemoveMin();

  int target = 0;
  cout <<"Input Search Number"<< endl;
  cin.clear();
  cin.ignore(INT_MAX,'\n');
  cin >> target;

  if(bst.Find(target)){
    cout << "There is the element " << target << " ." << endl;
  }
  else{
    cout << "There is not the element" << target << " ." << endl;
  }
	
  return 0;
} 
