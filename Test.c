#include "bstADT.c"
#include "stackADT.c"

#include <stdlib.h>

int main(){
	
	Node* root = createNode(5);	//root node
	insert(root,4);
	insert(root,3);
	insert(root,2);
	insert(root,1);
	insert(root,6);
	insert(root,7);
	insert(root,8);
	insert(root,9);
	insert(root,10);
	printf("Initial tree: \n");
	inorder(root);
	printf("\n\n");

	Stack* stack = createStack(10); //stack
	int r,i=0;
	for(i=1; i<=10;i++){
		r = ( rand() % 4 ) + 1; //random integer between 1 and 4
		
		//int willDelete=111;
		
		switch(r){
			case 1:	
				printf("Task-> insert %d\n",i*3);
				printf("The value %d inserted.\n",i*3);
				insert(root,i*3);
				push(stack,1,i*3);
				//printf("Tree after insert operation: \n");
				inorder(root);
				printf("\n\n");
				break;
			case 2:
				/*if(willDelete != root->data && search(root,willDelete)==-1)
					printf("Value does not exists in tree..\n"); */  //When the desired value to delete is not in tree

				printf("Task-> delete %d\n",minValueNode(root)->data);
				printf("The value %d deleted.\n",minValueNode(root)->data);
				push(stack,2,minValueNode(root)->data);				
				deleteNode(root,minValueNode(root)->data);
				//printf("Tree after delete operation: \n");
				inorder(root);
				printf("\n\n");
				break;
			case 3:

				printf("Task-> min\nMinimum value of tree is: %d\n\n",minValueNode(root)->data);
				break;
			case 4:
				printf("Task-> search %d\n",minValueNode(root)->data);
				printf("Value %d found in %d steps.\n\n",minValueNode(root)->data,search(root,minValueNode(root)->data));
				break;
			default:
				break;
		}	
	}
		printf("_______________________________________________________________________________\n");
		printf("Actual status of tree:\n");
		inorder(root);
		int num,flag=1;
		
			printf("\n");
			printf("How many steps back: ");
			scanf("%d",&num);
			if(num>stack->top){
				flag=0;
			}
		printf("_______________________________________________________________________________\n");
		int index;
		while(num>0){
			index = pop(stack);
			if(stack->task[index] == 1){
				printf("Inserted value %d is deleted.: \n",stack->values[index]);
				deleteNode(root,stack->values[index]);
				inorder(root);
				printf("\n");
			}
				
			else if(stack->task[index] == 2){
				printf("Deleted value %d is inserted.: \n",stack->values[index]);
				insert(root,stack->values[index]);
				inorder(root);
				printf("\n");
			}
			num--;
		}

	if(flag == 0)
		printf("There is no task left to be undone..\n");
	printf("_______________________________________________________________________________\n");

	return 0;
}
