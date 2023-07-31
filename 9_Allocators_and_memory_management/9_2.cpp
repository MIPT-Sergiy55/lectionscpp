//
// Created by sergiy on 18/06/22.
//
#include <iostream>


// REBIND
// problem: when using list, we have struct Node inside, so allocator have to work
// (allocate, deallocate, construct, destroy) with Nodes (not T),
// but container gets Alloc<T> as template argument.
// so Allocator has to have constructor from same allocator with other template.
// rebind:
// typename Alloc::rebind<Node>::other alloc;

// List(const List& other) : fakeNode(other.fakeNode), sz(other.sz),
// alloc(other.alloc.select_on_container_copy_construction())

// List operator= --//-- alloc(other.alloc.propagate_on_copy_assigment...)


// rebind, select_on_container_copy_construction(), propagate_on_copy_assigment.
