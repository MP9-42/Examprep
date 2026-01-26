#include "list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *head = *begin_list;
	int len = 0;
	while(head->next)
		len++;
	while (len - 1 >= 0)
	{
		if (cmp(head->data, data_ref))
		{
			head
		}
	}
}

int main()
{

}