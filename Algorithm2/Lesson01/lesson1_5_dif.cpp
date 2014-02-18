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
  friend class BinarySearchTree; // BinarySearchTree クラスから
  // このクラスのプライベートメンバへの
  // アクセスを許可する。
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
  void removemax(BinaryNode* p); 
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
  removemax(root);
}

BinaryNode* BinarySearchTree::removemin(BinaryNode *p){
  cout <<"test1"<< endl;
  if(p == NULL) return p;

  if(p -> left != NULL){
    cout <<"test2"<< endl;
    p -> left = removemin(p -> left);
  }
  else{
    cout <<"test3"<< endl;
    BinaryNode* np = p -> right;
    cout <<"test4"<< endl;
    delete p;
    cout <<"test5"<< endl;
    if(np == NULL || np -> left == NULL ) return np;
    else{
      cout <<"test6"<< endl;
      return removemin(np -> left);
    }
  }
  cout <<"FFFFFFFFF"<< endl;
  return p;
}

void BinarySearchTree::removemax(BinaryNode *p){
  return;
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
	
  bst.RemoveMax(); //最大の値を削除する
  bst.RemoveMin(); //最小の値を削除する

  int target = 0;
  cout <<"Input Search Number"<< endl;
  cin.clear();
  cin.ignore(INT_MAX,'\n');
  cin >> target;

  cout <<"data = "<< data << endl;
  cout <<"test = "<< target << endl;

  if(bst.Find(target)){
    cout << "There is the element " << target << " ." << endl;
  }
  else{
    cout << "There is not the element" << target << " ." << endl;
  }
	
  return 0;
} 
