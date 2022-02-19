// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  3

// FILE: node1_New.h
// CLASS PROVIDED: 
//   class node
//     A class for a node in a linked list and a collection of functions for manipulating linked lists.
//     A node has two variables: data value and link to the next node.
//     
//   CONSTRUCTOR:
//     node(const value_type& init_data = value_type(), node* init_link = NULL)
//       POST-CONDITION: This node has been created with data value and link to next node specified.
//       If no link is specified, it will use default value of NULL.
//   
//   MEMBER FUNCTIONS TO SET THE DATA AND LINK FIELDS:
//     void set_data(const value_type& new_data)
//       POST_CONDITION: Sets the data value to called node pointer.
//
//     void set_link(node* new_link)
//		 POST_CONDITION: Sets the link for the next node to the called node pointer.
//
//   CONSTANT MEMBER FUNCTION TO RETRIEVE THE CURRENT DATA:
//	   value_type data( ) const
//		 POST_CONDITION: Returns the data value of the called node pointer.
//
//   Two slightly different member functions to retreive the current link:
//     const node* link( ) const
//		 POST_CONDITION: Returns the constant version of link of this node.
//
//     node* link( )
//		 POST_CONDITION: Returns the non-constant version of link of this node.
//
//   FUNCTIONS for the linked list toolkit
//     std::size_t list_length(const node* head_ptr);
//		 PRE_CONDITION: head_ptr is the head pointer of a linked list.
//		 POST_CONDITION: The value returned is the number of nodes in the linked list.
//
//     void list_head_insert(node*& head_ptr, const node::value_type& entry);
//		 PRE_CONDITION: head_ptr is the head pointer of a linked list.
//		 POST_CONDITION: A new node containing the given entry has been added at the head of
//       the linked list; head_ptr now points to the head of the new, longer linked list.
//
//     void list_insert(node* previous_ptr, const node::value_type& entry);
//		 PRE_CONDITION: previous_ptr points to a node in a linked list.
//		 POST_CONDITION: A new node containing the given entry has been added after the node
//       that previous_ptr points to.
//
//     node* list_search(node* head_ptr, const node::value_type& target);
//     const node* list_search (const node* head_ptr, const node::value_type& target);
//       Returns the constant and non-constant version node.
//		 PRE_CONDITION: head_ptr is the head pointer of a linked list.
//		 POST_CONDITION: The pointer returned points to the first node containing the specified
//       target in its data field. If there is no such node, the null pointer is returned.
//
//     node* list_locate(node* head_ptr, std::size_t position);
//     const node* list_locate(const node* head_ptr, std::size_t position);
//		 Returns the constant and non-constant version of node.
//		 PRE_CONDITION: head_ptr is the head pointer of a linked list, and position > 0.
//		 POST_CONDITION: The pointer returned points to the node at the specified position in the
//       list. (The head node is position 1, the next node is position 2, and so on.) If there is no
//       such position, then the null pointer is returned.
//
//     void list_head_remove(node*& head_ptr);
//		 PRE_CONDITION: head_ptr is the head pointer of a linked list, with at least one node.
//		 POST_CONDITION: The head node has been removed and returned to the heap;
//       head_ptr is now the head pointer of the new, shorter linked list.
//
//     void list_remove(node* previous_ptr);
//		 PRE_CONDITION: ptr points to a node in a linked list, and this is not the tail node of
//       the list.
//		 POST_CONDITION: The node after previous_ptr has been removed from the linked list.
//
//     void list_clear(node*& head_ptr);
//		 PRE_CONDITION: head_ptr is the head pointer of a linked list.
//		 POST_CONDITION: All nodes of the list have been returned to the heap, and the head_ptr is
//       now NULL.
//
//     void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
//		 PRE_CONDITION: source_ptr is the head pointer of a linked list.
//		 POST_CONDITION: head_ptr and tail_ptr are the head and tail pointers for a new list that
//       contains the same items as the list pointed to by source_ptr.
//
//     node* delete_reps(const node* head_ptr);
//       PRE_CONDITION: head_ptr is the head pointer of a linked list.
//		 POST_CONDITION: Returns a new node list that contains the same items without any duplicates
//
//     void sort_list(node*& head_ptr);
//       PRE_CONDITION: head_ptr is the head pointer of a linked list.
//		 POST_CONDITION: All nodes of the list have been sorted from smallest to largest.
//
//     void split_list(node*& List1, node*& List2, double split_value); 
//       PRE_CONDITION: List1 is the head pointer of a linked list. Split_value must be in the List1 list.
//		 POST_CONDITION: List1 contains nodes up to but not including the first split_value. List2 contains 
//       all nodes after the split_value including split_value node.
//

#ifndef NODE1_NEW_H
#define NODE1_NEW_H

#include <cstdlib> // Provides size_t and NULL

class node
{
public:
	// TYPEDEF
	typedef double value_type;
	
	// CONSTRUCTOR
	node(
		const value_type& init_data = value_type(),
		node* init_link = NULL
	)
	{ data_field = init_data; link_field = init_link; }

	// Member functions to set the data and link fields:
	void set_data(const value_type& new_data) { data_field = new_data; }
	void set_link(node* new_link)             { link_field = new_link; }

	// Constant member function to retrieve the current data:
	value_type data( ) const { return data_field; }

	// Two slightly different member functions to retreive
	// the current link:
	const node* link( ) const { return link_field; }
	node* link( ) { return link_field; }

private:
	value_type data_field;
	node* link_field;
};

// FUNCTIONS for the linked list toolkit
std::size_t list_length(const node* head_ptr);
void list_head_insert(node*& head_ptr, const node::value_type& entry);
void list_insert(node* previous_ptr, const node::value_type& entry);
node* list_search(node* head_ptr, const node::value_type& target);
const node* list_search (const node* head_ptr, const node::value_type& target);
node* list_locate(node* head_ptr, std::size_t position);
const node* list_locate(const node* head_ptr, std::size_t position);
void list_head_remove(node*& head_ptr);
void list_remove(node* previous_ptr);
void list_clear(node*& head_ptr);
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
node* delete_reps(const node* head_ptr);
void sort_list(node*& head_ptr);
void split_list(node*& List1, node*& List2, double split_value);

#endif // NODE1_H
