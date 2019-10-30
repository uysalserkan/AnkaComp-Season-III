# Stack

## Insert a Element in Stack

`IF TOP == MAX -1`
`-->RETURN STACK IS FULL`
`SET TOP = TOP + 1`
`SET STACK[TOP] = VALUE`
`EXIT`


## Delete an Element

`IF TOP == NULL`
`-->RETURN STACK IS EMPTY`
`SET VAL = STACK[TOP]`
`SET TOP = TOP - 1`
`RETURN VAL`
`EXIT`


## Peek

`IF TOP == NULL`
`--> RETURN STACK IS EMPTY`
`RETURN STACK[TOP]`
`EXIT`


## Insert an Element in a Linked Stack

`SET NEWNODE->DATA = VAL`
`IF TOP == NULL`
`--> SET NEWNODE->NEXT = NULL`
`--> SET TOP = NEWNODE`
`ELSE`
`--> SET NEWNODE->NEXT = TOP`
`SET TOP = NEWNODE`
`END`


## Delete an Element From a Linked Stack

`IF TOP == NULL`
`-->END`
`SET PTR = TOP`
`SET TOP = TOP ->NEXT`
`FREE PTR`
`END`


## 