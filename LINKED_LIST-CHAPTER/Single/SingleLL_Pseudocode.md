# Single Linked List

## Traversing a Linked List

`Set[ptr=Head]`
`[LOOP] when ptr->next!=NULL`
`ptr->data=data`
`ptr=ptr->next`
`[END LOOP]`


## Count Linked List Size

`SET [ptr=Head]`
`[LOOP] when ptr->next != NULL`
`counter += 1`
`ptr = ptr->next`
`[END LOOP]`


## Search Value in Linked List

`SET [ptr=Head]`
`[LOOP] when ptr->next != NULL`
`if val == ptr->data`
`RETURN POSITION OF THE DATA`
`else ptr = ptr->next`
`[END IF]`
`[END LOOP]`
`POS = -1 AND RETURN POS`


## Insert New Node at the Beginning

`IF avail = NULL`
`RETURN -1`
`SET NEW NODE = AVAIL`
`SET AVAIL = AVAIL->NEXT`
`SET NEWNODE->DATA = VAL`
`NEWNODE->NEXT = START`
`START = NEWNODE`
`EXIT`


## Insert New Node at the End

`IF avail = NULL`
`RETURN -1`
`SET NEW NODE = AVAIL`
`SET AVAIL = AVAIL->NEXT`
`SET NEWNODE->DATA = VAL`
`SET NEWNODE->NEXT = NULL`
`SET PTR = START`
`WHILE PTR->NEXT != NULL`
`-->PTR = PTR->NEXT`
`[END OF LOOP]`
`SET PTR->NEXT = NEWNODE`
`EXIT`


## Insert a New Node After a Node that Has Value NUM

`IF avail = NULL`
`RETURN -1`
`SET NEW NODE = AVAIL`
`SET AVAIL = AVAIL->NEXT`
`SET NEWNODE->DATA = VAL`
`SET PTR = START`
`SET PREPTR=PTR`
`WHILE PREPTR->DATA != NUM`
`-->SET PREPTR=PTR`
`-->SET PTR=PTR->NEXT`
`[END OF LOOP]`
`PREPTR->NEXT = NEWNODE`
`SET NEWNODE->NEXT = PTR`
`EIXT`


## Delete First Node

`IF START == NULL`
`-->EXIT`
`SET PTR = START`
`SET START = START->NEXT`
`FREE PTR`
`EXIT`


## Delete Last Node

`IF START == NULL`
`-->EXIT`
`SET PTR = START`
`WHILE PTR->NEXT != NULL`
`-->PREPTR = PTR`
`-->PTR=PTR->NEXT`
`[END OF LOOP]`
`SET PREPTR->NEXT NULL`
`FREE PTR`
`EXIT`


## Delete Given Node

`IF START == NULL`
`-->EXIT`
`SET PTR = START`
`SET PREPTR = PTR`
`WHILE PREPTR->DATA != NULL`
`--> SET PREPTR = PTR`
`--> SET PTR = PTR->NEXT`
`[END OF LOOP]`
`SET TEMP = PTR`
`SET PREPTR->NEXT = PTR->NEXT`
`FREE TEMP`
`EXIT`
