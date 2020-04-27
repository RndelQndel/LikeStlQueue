#include <iostream>
#include <cstdlib>

template<typename T>
class Queue_Stl{
	private:
		struct node{
			node* pNext;
			T value;
		};
		node* m_pHead;
		node* m_pTail;
		int capacity;
		int n_count;
	public:
		Queue_Stl(){
			m_pHead = NULL;
			m_pTail = NULL;
			capacity = 9999;
			n_count = 0;
		}
		~Queue_Stl(){
			while( !Empty() ){
				int Temp = 0;
				Pop(Temp);
			}
			m_pHead = NULL;
			m_pTail = NULL;
			capacity = 0;
			n_count = 0;
		}
		bool Push( T input ){
			if ( Full() )
				return false;
			node* NewNode = new node;
			node* Temp = m_pTail;
			NewNode->value = input;
			if( Empty() ){
				m_pHead = NewNode;
				m_pTail = m_pHead;
			}
			else{
				Temp->pNext = NewNode;
				m_pTail = NewNode;
			}
			n_count++;
			return true;
		}
		bool Pop( T& retValue ){
			if ( Empty() )
				return false;
			retValue = m_pHead->value;
			node* Temp = m_pHead;
			m_pHead = m_pHead->pNext;
			delete Temp;
			n_count--;
			return true;
		}
		bool Empty(){
			return ((n_count == 0) ? true : false);
		}
		bool Full(){
			return ((capacity == n_count) ? true : false);
		}
		void SetCapacity(int count){
			capacity = count;
		}
};
