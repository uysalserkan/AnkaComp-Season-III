# QUEUE

## Array Representation Queue

### Insert an Element in a Queue

`IF Rear == Max - 1`
`-->Exıt`
`IF Front == -1 and Rear == -1`
`--> SET Front = Rear = 0`
`ELSE`
`--> SET Rear = Rear + 1`
`SET QUEUE[Rear] = NUM`
`EXIT`


### Delete an Element From a Queue 

`IF FRONT == -1 OR FRONT > REAR`
`-->WRITE UNDERFLOW AND EXIT`
`ELSE`
`--> SET VALUE = QUEUE[FRONT]`
`-->SET FRONT = FRONT + 1`
`[END OF IF]`
`EXIT`

## Linked_List Representation Queue

### Insert an Element in a Linked_List Queue

`ALLACATE MEMORY AREA FOR NODE PTR`
`SET PTR->DATA = VAL`
`IF FRONT == NULL`
`-->SET FRONT = REAR = PTR`
`-->SET FRONT->NEXT = REAR->NEXT = NULL`
`ELSE`
`-->SET REAR->NEXT = PTR`
`-->SET REAR = PTR`
`-->SET REAR->NEXT = NULL`
`EXIT`

### Delete an Element from a Linked List Queue

`IF FRONT == NULL`
`-->EXIT`
`SET PTR = FRONT`
`SET FRONT = FRONT->NEXT`
`FREE PTR`
`EXIT`


## Circular Queue

## Insert an Element in a Circular Queue

`IF FRONT == 0 AND REAR == MAX -1`
`-->EXIT`
`IF FRONT == -1 AND REAR == -1`
`-->SET FRONT = REAR = 0`
`ELSE IF REAR == MAX AND FRONT != 0`
`-->SET REAR = 0`
`ELSE`
`-->SET REAR = REAR + 1`
`SET QUEUE[REAR] = VAL`
`EXIT`

