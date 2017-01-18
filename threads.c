#include <pthread.h>
#include <stdio.h>

void* func1(void *ptr){
    int *shared_var_ptr = (int *)ptr;
	for (int i = 0; i < 1000000; i++)
		*shared_var_ptr = *shared_var_ptr + 1;
    return NULL;
}
void* func2(void *ptr){
    int *shared_var_ptr = (int *)ptr;
	for (int i = 0; i < 1000000; i++)
		*shared_var_ptr = *shared_var_ptr - 1;;
    return NULL;
}

int main(void) {
	
	int shared_var = 0;
	
	pthread_t thid1;
	pthread_t thid2;
	
	pthread_create(&thid1, NULL, &func1, &shared_var);
	pthread_create(&thid2, NULL, &func2, &shared_var);
	
	pthread_join(thid1, NULL);
	pthread_join(thid2, NULL);
	
	printf("shared_var = %i\n", shared_var);
	
	return 0;
}