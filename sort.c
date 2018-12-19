#include "sysprg_study_montis.h"


int partition(float * lst, int begin, int end){
	float median = lst[begin]; /* rand() % end + begin */
	int pos = begin+1;
	for(int i = begin+1; i <= end; i++){
		if(lst[i] < median){
			float tmp = lst[pos];
			lst[pos] = lst[i];
			lst[i] = tmp;
			pos++;
		}
	}
	float tmp = lst[pos-1];
	lst[pos-1] = median;
	lst[begin] = tmp;
	return pos;
}

void quick_sort(float * lst, int begin, int end){
	if(begin < end){
		int median = partition(lst, begin, end);
		quick_sort(lst, begin, median-1);
		quick_sort(lst, median, end);
	}
}

void insertion_sort(float * lst, int len){
	for(int i = 0; i < len-1; i++){
		int min = lst[i];
		int check = 0;
		int pos;
		for(int j = i +1; j < len; j++){
			if(lst[j] < min){
				check = 1;
				min = lst[j];
				pos = j;
			}
		}
		if(check == 1){
			float tmp = lst[pos];
			lst[pos] = lst[i]; 
			lst[i] = tmp;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	lstn * lst = create_lstn();
	int len = 101;
	for(int i = len; i > 0; i--){
		add_lstn(lst, i);
	}
	// printf("%d\n", partition(lst, 0, 4));
	print_lstn(lst);
	// insertion_sort(lst->nums, len);
	quick_sort(lst->nums,0, len-1);
	print_lstn(lst);
	for(int i = 1; i < len; i++){
		if(lst->nums[i-1] > lst->nums[i])
			printf("BAD SORTING\n");
	}
	return 0;
}