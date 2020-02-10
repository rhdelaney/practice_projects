char shift(List *list, ) { 
	List *ptr = list;
	List *ptr1 = list;
	char *word;
	char *first;
	char *last;
	if (ptr == NULL) {
		return list;
	}

	if (ptr->next == NULL) {
			return list;
	}
	else {
		word = ptr->next;
		word->next = NULL;
		first = ptr->next;
		while (ptr1! == NULL) {
			last = ptr1->next;
			ptr1 = ptr1->next;
		}
		last->next = word;
		return first;
	}
}
