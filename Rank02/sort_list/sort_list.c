#include "list.h"

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	tmp;
	if (cmp(lst->data, lst->next->data) == 0)
	{
		tmp = *lst;
		lst = lst->next;
		lst->next = tmp;
	}
}