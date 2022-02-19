// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  3

// FILE: node1_New.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit and THREE added functions (see node1_New.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1_New.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>   // Provides Input and Output Stream

using namespace std;

// The value returned is the number of nodes in the linked list. Returns 0 if head_ptr is empty.
size_t list_length(const node* head_ptr)
// Library facilities used: cstdlib
{
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
		++answer;

	return answer;
}

// A new node containing the given entry has been added at the head of
// the linked list; head_ptr now points to the head of the new, longer linked list.
void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
	head_ptr = new node(entry, head_ptr);
}

// A new node containing the given entry has been added after the node
// that previous_ptr points to.
void list_insert(node* previous_ptr, const node::value_type& entry) 
{
	node *insert_ptr;
	insert_ptr = new node(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
}

// The pointer returned points to the first node containing the specified
// target in its data field. If there is no such node, the null pointer is returned.
node* list_search(node* head_ptr, const node::value_type& target) 
// Library facilities used: cstdlib
{
	node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
		if (target == cursor->data( ))
		return cursor;
	return NULL;
}

// The pointer returned points to the first node containing the specified
// target in its data field. If there is no such node, the null pointer is returned.
const node* list_search(const node* head_ptr, const node::value_type& target) 
// Library facilities used: cstdlib
{
	const node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
		if (target == cursor->data( ))
		return cursor;
	return NULL;
}

// The pointer returned points to the node at the specified position in the
// list. (The head node is position 1, the next node is position 2, and so on.) If there is no
// such position, then the null pointer is returned.
node* list_locate(node* head_ptr, size_t position) 
// Library facilities used: cassert, cstdlib
{
	node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->link( );
	return cursor;
}

// The pointer returned points to the node at the specified position in the
// list. (The head node is position 1, the next node is position 2, and so on.) If there is no
// such position, then the null pointer is returned.
const node* list_locate(const node* head_ptr, size_t position) 
// Library facilities used: cassert, cstdlib
{
	const node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->link( );
	return cursor;
}

// The head node has been removed and returned to the heap;
// head_ptr is now the head pointer of the new, shorter linked list.
void list_head_remove(node*& head_ptr)
{
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
}

// The node after previous_ptr has been removed from the linked list.
void list_remove(node* previous_ptr)
{
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
}

// All nodes of the list have been returned to the heap, and the head_ptr is
// now NULL.
void list_clear(node*& head_ptr)
// Library facilities used: cstdlib
{
	while (head_ptr != NULL)
		list_head_remove(head_ptr);
}

// head_ptr and tail_ptr are the head and tail pointers for a new list that
// contains the same items as the list pointed to by source_ptr.
void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) 
// Library facilities used: cstdlib
{
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
		return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( ); 
	while (source_ptr != NULL)
	{
		list_insert(tail_ptr, source_ptr->data( ));
		tail_ptr = tail_ptr->link( );
		source_ptr = source_ptr->link( );
	}
}

// Returns a new node list that contains the same items without any duplicates.
node* delete_reps(const node* head_ptr)
// Library facilities used: cstdlib
{
	// 100 90 80 100 70 80 -> 100 90 80 70
	
	// Handle the case of the empty list.
	if (head_ptr == NULL)
		return NULL;

	node* target_list = NULL;
	node* tail_ptr = NULL;		// Required for copying data values to target_list
	
	// Copy head_ptr list into target_list
	list_copy(head_ptr, target_list, tail_ptr);
	
	// Loop thorugh each node removing duplicates one at a time.
	node* cursor_1 = target_list;
	node* cursor_2 = NULL;
	while(cursor_1 != NULL && cursor_1->link() != NULL)
	{
		cursor_2 = cursor_1;
		while(cursor_2->link() != NULL)
		{
			if(cursor_1->data() == cursor_2->link()->data())
				list_remove(cursor_2);
			else
				cursor_2 = cursor_2->link();
		}
		cursor_1 = cursor_1->link();
	}
	
	// Returns the target_list with no duplicates.
	return target_list;
}

// All nodes of the list have been sorted from smallest to largest.
void sort_list(node*& head_ptr)
// Library facilities used: cstdlib
{
	// Declare and initiate target_list as NULL.
	node* target_list = NULL;
	
	// Loop through each node until only one node left which is the smallest data value.
	while(head_ptr != NULL && head_ptr->link() != NULL)
	{
		node* cursor_ptr= head_ptr;
		node* max_grade_ptr = NULL;
		double max_grade = head_ptr->data();
		
		// Loop through each node after cursor_ptr and find largest data value.
		while(cursor_ptr != NULL && cursor_ptr->link() != NULL)
		{
			if(max_grade < cursor_ptr->link()->data())
			{
				max_grade = cursor_ptr->link()->data();
				max_grade_ptr = cursor_ptr;
			}
				
			cursor_ptr = cursor_ptr->link();
		}
		
		// If the largest value is head_ptr than remove that node else, remove that node.
		if (max_grade == head_ptr->data())
			list_head_remove(head_ptr);
		else
			list_remove(max_grade_ptr);
		
		// Insert the max value to the target_ptr using list_head_insert function.
		list_head_insert(target_list, max_grade);
	}
	
	// Insert the smallest data value node left in the head_ptr to the target_list
	list_head_insert(target_list, head_ptr->data());
	
	head_ptr = NULL; // Remove head_ptr from pointing to anything. Points to NULL.
	head_ptr = target_list; // head_ptr points to the target_list.
}

// List1 contains nodes up to but not including the first split_value. List2 contains 
// all nodes after the split_value including split_value node.
void split_list(node*& List1, node*& List2, double split_value)
// Library facilities used: cstdlib, iostream
{
	List2 = NULL;
	node* List2_tail_ptr = NULL;
	
	// Searches the List1 for provided split_value.
	node* split_node = list_search(List1, split_value);

	// Handles the NULL node if no such data value in List1.
	if(split_node == NULL)
	{
		cout << "The value " << split_value << " is not in the grade list." << endl;
		return;
	}
	
	// Copy value beginning from split_node_pos into the List2.
	list_copy(split_node, List2, List2_tail_ptr);
	
	// Find the previous node of split_value node
	node* prv_node = List1;
	if(split_node == List1)
		List1 = NULL;
	else {
		while(prv_node != split_node)
		{
			prv_node = prv_node->link();
		}
		// Remove any remaining nodes. 
		while(prv_node->link() != NULL)
		{
			list_remove(prv_node);
		}
	}
}
