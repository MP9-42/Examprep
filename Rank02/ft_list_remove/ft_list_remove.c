#include "list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *head = *begin_list;
	t_list *tmp;
	int len = 0;
	while (head->next)
	{
		if (cmp(begin_list->data, data_ref) == 0)
		{
			head
		}
	}
}

int main()
{

}