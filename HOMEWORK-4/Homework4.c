/*
*  ____________________________________
* |         Comiler: GCC 7.4.0        |
* |     Enviroment: Ubuntu 18.04.1    |
* |                                   |
* |    SERKAN                UYSAL    |
* |      uysalserkan08@gmail.com      |
* |___________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct EmployeeNode
{
	int employeeId;
	int customerTakenTime;
	int totalTakenTime;
	bool aviable;
	struct EmployeeNode *next;
};

struct CustomerNode
{
	int customerId;
	int comingTime;
	int takenTime;
	struct CustomerNode *next;
};

struct StackEmployees
{
	struct EmployeeNode *front;
};

struct QueueCustomers
{
	struct CustomerNode *front;
	struct CustomerNode *rear;
};

typedef struct EmployeeNode EmployeeNode;
typedef struct CustomerNode CustomerNode;
typedef struct StackEmployees StackEmployees;
typedef struct QueueCustomers QueueCustomers;

// ! Pops Pushs and prints functions will be coming..
void InitializeEmployeeInfos(StackEmployees **front);
void TakeCustomerInformation(QueueCustomers **head);
void PrintEmployeeInfos(StackEmployees *head);
void printCustomerInfos(QueueCustomers *head);
EmployeeNode *PopEmployee(StackEmployees **head);
CustomerNode *PopCustomer(QueueCustomers **head);
void PushEmployee(StackEmployees **head, EmployeeNode **node);
void PushCustomer(QueueCustomers **head, CustomerNode **node);
void TransactionCustomers(QueueCustomers **customerHead, StackEmployees **employeeHead);
int totalTimeSum(QueueCustomers *head);

// Main Function Start
int main()
{
	StackEmployees *employeeHead = (StackEmployees *)malloc(sizeof(StackEmployees));
	QueueCustomers *customerHead = (QueueCustomers *)malloc(sizeof(QueueCustomers));
	InitializeEmployeeInfos(&employeeHead);
	TakeCustomerInformation(&customerHead);
	// printf("Total Time: %d\n", totalTimeSum(customerHead));
	TransactionCustomers(&customerHead, &employeeHead);

	// PrintEmployeeInfos(employeeHead);
	// printf("\n____________\n");
	// InitializeEmployeeInfos(&employeeHead);
	// EmployeeNode *ptr = (EmployeeNode *)malloc(sizeof(EmployeeNode));
	// ptr->employeeId = 25;
	// ptr->totalTakenTime = 1998;
	// PushEmployee(&employeeHead, &ptr);
	printf("\n");
	PrintEmployeeInfos(employeeHead);
	// printCustomerInfos(customerHead);
	// PopCustomer(&customerHead);
	// PopCustomer(&customerHead);
	// printf("\nAfter 2 pop customer is\n\n");
	// printCustomerInfos(customerHead);
}
// Main Function End.

// Functions are initialized here.

void InitializeEmployeeInfos(StackEmployees **front)
{
	for (size_t i = 0; i < 6; i++)
	{
		// StackEmployees *ptr = front;
		EmployeeNode *body = (EmployeeNode *)malloc(sizeof(EmployeeNode));
		body->customerTakenTime = 0;
		body->employeeId = i + 1;
		body->totalTakenTime = 0;
		body->aviable = true;
		body->next = (*front)->front;
		(*front)->front = body;
	}
}

void TakeCustomerInformation(QueueCustomers **head)
{
	/*
    ? ID -1 olana kadar infoları alarak queue'yi kaydırarak yazdır bilgiler.
    */
	int id;
	int comingTime;
	int takenTime;
	CustomerNode *first = (CustomerNode *)malloc(sizeof(CustomerNode));

	scanf("%d %d %d", &id, &comingTime, &takenTime);
	first->customerId = id;
	first->comingTime = comingTime;
	first->takenTime = takenTime;
	(*head)->front = first;
	(*head)->rear = first;
	scanf("%d", &id);
	while (id != -1)
	{
		scanf("%d %d", &comingTime, &takenTime);
		CustomerNode *ptr = (CustomerNode *)malloc(sizeof(CustomerNode));
		ptr->customerId = id;
		ptr->takenTime = takenTime;
		ptr->comingTime = comingTime;
		(*head)->front->next = ptr;
		(*head)->front = ptr;

		scanf("%d", &id);
	}
}

void PrintEmployeeInfos(StackEmployees *head)
{
	EmployeeNode *tmep = head->front;

	while (head->front != NULL)
	{
		printf("%d\t%d\n", head->front->employeeId, head->front->totalTakenTime);
		head->front = head->front->next;
	}
	head->front = tmep;
}

void printCustomerInfos(QueueCustomers *head)
{
	QueueCustomers ptr = *head;
	while (head->rear != NULL)
	{
		printf("ID: %d \t ComingTime: %d \t TakenTime: %d\n", head->rear->customerId, head->rear->comingTime, head->rear->takenTime);
		head->rear = head->rear->next;
	}
	*head = ptr;
}

EmployeeNode *PopEmployee(StackEmployees **head)
{
	/*
    ? Will be coming..
    */
	EmployeeNode *ptr = (EmployeeNode *)malloc(sizeof(EmployeeNode));
	EmployeeNode *willBeFree = (*head)->front;
	ptr->employeeId = (*head)->front->employeeId;
	ptr->customerTakenTime = (*head)->front->customerTakenTime;
	ptr->totalTakenTime = (*head)->front->totalTakenTime;
	(*head)->front = (*head)->front->next;
	free(willBeFree);
	return ptr;
}

void PushEmployee(StackEmployees **head, EmployeeNode **node)
{
	/* 
    ? Stack'in next'i ni EmployeeNode'ye işaret edip Stack'in front'u oraya kaydırılır.
    */
	// printf("front is: %d\n", (*head)->front->employeeId);
	(*node)->next = (*head)->front;
	(*head)->front = *node;
}

CustomerNode *PopCustomer(QueueCustomers **head)
{
	/* 
    ? Queue'nin rear'i yeni bi CustomerNode oluşturularak oraya tanımlanır datası.
    ? Queue'nin rear'i bir sonraki gelen CustomerNode'sine işaret edilir ve free bırakılır.
    */
	CustomerNode *ptr = (CustomerNode *)malloc(sizeof(CustomerNode));
	CustomerNode *willBeFree = (*head)->rear;
	ptr->comingTime = (*head)->rear->comingTime;
	ptr->customerId = (*head)->rear->customerId;
	ptr->takenTime = (*head)->rear->takenTime;
	(*head)->rear = (*head)->rear->next;
	free(willBeFree);
	return ptr;
}

/* 
    ! NOT Working
void PushCustomer(QueueCustomers **head, CustomerNode **node)
{
     
    ? Queue'nin next'i ni CustomerNode'ye işaret edip Queue'nin front'u oraya kaydırılır.
    
(*head)->front->next = (*node);
(*head)->front = (*node);
}
*/

int totalTimeSum(QueueCustomers *head)
{
	CustomerNode *firstNode = head->rear;
	int totalTime = 0;
	CustomerNode *ptr = head->rear;
	while (ptr != NULL)
	{

		totalTime += ptr->takenTime;
		ptr = ptr->next;
	}
	head->rear = firstNode;
	return totalTime;
}

void TransactionCustomers(QueueCustomers **customerHead, StackEmployees **employeeHead)
{
	//? Total time'yi tutup, coming time ye göre isbusy değeri değişecek..
	// int maximumTime = totalTimeSum(*customerHead);
	EmployeeNode *arrEmployee[6];
	EmployeeNode *firstNode = (*employeeHead)->front;
	StackEmployees *ptrEmployee = *employeeHead;
	for (size_t i = 0; i < 6; i++)
	{
		//?0'ıncı index 6. kasayı tutuyor..
		arrEmployee[i] = ptrEmployee->front;
		ptrEmployee->front = ptrEmployee->front->next;
	}
	//! Tüm çalışanlar array'e atandı ve kontrol edildi.

	int timer = 0;
	while ((*customerHead)->rear != NULL)
	{
		// printf("not bomb\n");
		int cur_time;
		for (size_t i = 0; i < 6; i++)
		{
			if (arrEmployee[i]->aviable == false)
			{
				arrEmployee[i]->customerTakenTime = arrEmployee[i]->customerTakenTime - 1;
				if (arrEmployee[i]->customerTakenTime == 0)
				{
					arrEmployee[i]->aviable = true;
				}
			}
		}

		//? çalışan varsa ilk azalt sonra kontrol et
		cur_time = (*customerHead)->rear->comingTime;
		// printf("\nCURRENT TIME: %d\n", cur_time);
		int index = 0;
		while ((*customerHead)->rear->comingTime == cur_time)
		{
			if (arrEmployee[index]->aviable == true)
			{
				arrEmployee[index]->aviable = false;
				arrEmployee[index]->customerTakenTime = (*customerHead)->rear->takenTime;
				arrEmployee[index]->totalTakenTime += (*customerHead)->rear->takenTime;
				printf("%d\t%d\t%d\t%d\t%d\n",
					   (*customerHead)->rear->customerId,
					   arrEmployee[index]->employeeId,
					   cur_time + timer,
					   cur_time + timer + (*customerHead)->rear->takenTime,
					   timer);
				if ((*customerHead)->rear != (*customerHead)->front)
					(*customerHead)->rear = (*customerHead)->rear->next;
				else
				{
					// printf("we are here\n");
					(*employeeHead)->front = firstNode;
					return;
				}

				// index++;
			}
			else
			{
				if (index < 6)
					index++;
				else
				{
					timer += 1;
					// printf("we are here timer is: %d\n", timer);
					break;
				}
			}
		}

		//afterrr
	}
	int cur_time;
	for (size_t i = 0; i < 6; i++)
	{
		if (arrEmployee[i]->aviable == false)
		{
			arrEmployee[i]->customerTakenTime = arrEmployee[i]->customerTakenTime - 1;
			if (arrEmployee[i]->customerTakenTime == 0)
			{
				arrEmployee[i]->aviable = true;
			}
		}
	}

	//? çalışan varsa ilk azalt sonra kontrol et
	cur_time = (*customerHead)->rear->comingTime;
	// printf("\nCURRENT TIME: %d\n", cur_time);
	int index = 0;
	while ((*customerHead)->rear->comingTime == cur_time)
	{
		if (arrEmployee[index]->aviable == true)
		{
			arrEmployee[index]->aviable = false;
			arrEmployee[index]->customerTakenTime = (*customerHead)->rear->takenTime;
			arrEmployee[index]->totalTakenTime += (*customerHead)->rear->takenTime;
			printf("%d\t%d\t%d\t%d\t%d\n",
				   (*customerHead)->rear->customerId,
				   arrEmployee[index]->employeeId,
				   cur_time + timer,
				   cur_time + timer + (*customerHead)->rear->takenTime,
				   timer);

			(*customerHead)->rear = (*customerHead)->rear->next;
			// index++;
		}
		else
		{
			if (index < 6)
				index++;
			else
			{
				timer += 1;
				// printf("we are here timer is: %d\n", timer);
				break;
			}
		}
	}
}