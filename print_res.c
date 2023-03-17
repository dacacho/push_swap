#include "push_swap.h"

void    print_list(t_s **a, t_s **b, void (*f)())
{
	t_s *t1, *t2;

	if (f)
		f(a, b);
	
	t1 = *a;
	t2 = *b;

	while (t1 || t2)
	{
		if (t1 != NULL && t2 != NULL && t1->val != '\0' && t2->val != '\0')
		{
			
			printf("(A) val: %i | idx: %i |\t(B) val: %i | idx: %i |\n", t1->val, t1->idx, t2->val, t2->idx);
			t1 = t1->next;
			t2 = t2->next;
		}
		else if ((t1 != NULL && t2 == NULL) || t2->val == '\0')
		{
			printf("(A) val: %i | idx: %i |\t(B)                             \n", t1->val, t1->idx);
			t1 = t1->next;
		}
		else if ((t1 == NULL && t2 != NULL) || t1->val == '\0')
		{	
			printf("(A)                            \t(B) val: %i | idx: %i |\n", t2->val, t2->idx);
			t2 = t2->next;
		}
	}
}