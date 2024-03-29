When to use raw pointers and smart pointers?
As a general rule of thumb with modern C++, smart pointers should be used often. They will make your code safer as you no longer need to think (much) about the proper allocation and deallocation of memory. As a consequence, there will be much fewer memory leaks caused by dangling pointers or crashes from accessing invalidated memory blocks.

When using raw pointers on the other hand, your code might be susceptible to the following bugs:

Memory leaks
Freeing memory that shouldn’t be freed
Freeing memory incorrectly
Using memory that has not yet been allocated
Thinking that memory is still allocated after being freed
With all the advantages of smart pointers in modern C++, one could easily assume that it would be best to completely ban the use of new and delete from your code. However, while this is in many cases possible, it is not always advisable as well. Let us take a look at the C++ core guidelines, which has several rules for explicit memory allocation and deallocation. In the scope of this course, we will briefly discuss three of them:

R. 10: Avoid malloc and free While the calls (MyClass*)malloc( sizeof(MyClass) ) and new MyClass both allocate a block of memory on the heap in a perfectly valid manner, only new will also call the constructor of the class and free the destructor. To reduce the risk of undefined behavior, malloc and free should thus be avoided.

R. 11: Avoid calling new and delete explicitly Programmers have to make sure that every call of new is paired with the appropriate delete at the correct position so that no memory leak or invalid memory access occur. The emphasis here lies in the word "explicitly" as opposed to implicitly, such as with smart pointers or containers in the standard template library.

R. 12: Immediately give the result of an explicit resource allocation to a manager object It is recommended to make use of manager objects for controlling resources such as files, memory or network connections to mitigate the risk of memory leaks. This is the core idea of smart pointers as discussed at length in this section.

Summarizing, raw pointers created with new and delete allow for a high degree of flexibility and control over the managed memory as we have seen in earlier lessons of this course. To mitigate their proneness to errors, the following additional recommendations can be given:

A call to new should not be located too far away from the corresponding delete. It is bad style to stretch you new / delete pairs throughout your program with references criss-crossing your entire code.

Calls to new and delete should always be hidden from third parties so that they


## References:
- http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#main
- http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#r-resource-management
- http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rsmart-smart-pointers