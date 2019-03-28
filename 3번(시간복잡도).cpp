#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define swap(x, y) { int temp; temp = x; x=y;y=temp; }
#define N1 1000
#define N2 10000
#define N3 100000

int sorted[N3];
void Bubble(int list[], int n);
void Selection(int list[], int n);
void Insertion(int list[], int n);
void Merge_sort(int list[], int left, int mid, int right);
void Merge(int list[], int left, int right);
int partition1(int list[], int left, int right);
int partition2(int list[], int left, int right);
int partition3(int list[], int left, int right);
void Quick1(int list[], int left, int right);
void Quick2(int list[], int left, int right);
void Quick3(int list[], int left, int right);
int Bubble_time(int list[], int n);
int Selection_time(int list[], int n);
int Insertion_time(int list[], int n);
int Merge_time(int list[], int left, int right, int n);
int Quick1_time(int list[], int left, int right, int n);
int Quick2_time(int list[], int left, int right, int n);
int Quick3_time(int list[], int left, int right, int n);
void make_arrage();
void rand_temp(int tmp[],int random[], int n);
void random_time(int index, int Random[], int n ,int Random_temp[]);
void reverse_time(int index, int Reverse[], int n);


int Random1000[N1];
int Reverse1000[N1];
int Random10000[N2];
int Reverse10000[N2];
int Random100000[N3];
int Reverse100000[N3];
int table[7][6];

void rand_temp(int tmp[], int random[],int n) {
	
	for (int j = 0; j < n; j++)
	{
		tmp[j] = random[j];
	}
}


void SWAP(int list[], int x, int y) {
	int tmp;

	tmp = list[x];
	list[x] = list[y];
	list[y] = tmp;
}


int main() {

	
	printf("          Random1000    Reverse1000    Random1000    Reverse10000     Random100000    Reverse100000\n");
	

	srand((unsigned)time(NULL));

	make_arrage();

	printf("Bubble   ");

	for (int i = 0; i < 6; i++)
	{
		printf("            %d ", table[0][i]);

	}
	printf("\n");

	printf("Selection   ");

	for (int i = 0; i < 6; i++)
	{
		printf("         %d ", table[1][i]);

	}
	printf("\n");

	printf("Insertion   ");

	for (int i = 0; i < 6; i++)
	{
		printf("         %d ", table[2][i]);

	}
	printf("\n");

	printf("Merge    ");

	for (int i = 0; i < 6; i++)
	{
		printf("        %d ", table[3][i]);

	}
	printf("\n");

	printf("Quick1    ");

	for (int i = 0; i < 6; i++)
	{
		printf("        %d ", table[4][i]);

	}
	printf("\n");

	printf("Quick2   ");

	for (int i = 0; i < 6; i++)
	{
		printf("        %d ", table[5][i]);

	}
	printf("\n");


	printf("Quick3    ");

	for (int i = 0; i < 6; i++)
	{
		printf("        %d ", table[6][i]);

	}
	printf("\n");




	
}

void make_arrage() {

	int Random_temp1[N1];
	int Random_temp2[N2];
	int Random_temp3[N3];

	random_time(0, Random1000, N1, Random_temp1);
	random_time(2, Random10000, N2, Random_temp2);
	random_time(4, Random100000, N3, Random_temp3);

	reverse_time(1, Reverse1000, N1);
	reverse_time(3, Reverse10000, N2);
	reverse_time(5, Reverse100000, N3);

}
void reverse_time(int index, int Reverse[], int n) {

	int Time[7];

	for (int i = 0; i < 7; i++)
	{
		Time[i] = 0;
	}

	int k = n;

	for (int i = 0; i < n; i++)
	{
		Reverse[i] = k;
		k--;
	}
	
	Time[0]= Bubble_time(Reverse, n);

	for (int i = 0; i < n; i++)
	{
		Reverse[i] = k;
		k--;
	}

	Time[1] = Selection_time(Reverse, n);
	
	for (int i = 0; i < n; i++)
	{
		Reverse[i] = k;
		k--;
	}

	Time[2] = Insertion_time(Reverse, n);

	for (int i = 0; i < n; i++)
	{
		Reverse[i] = k;
		k--;
	}

	Time[3] = Merge_time(Reverse, 0, n - 1, n);



	for (int i = 0; i < n; i++)
	{
		Reverse[i] = k;
		k--;
	}

	Time[4] = Quick1_time(Reverse, 0, n - 1, n);
	


	for (int i = 0; i < n; i++)
	{
		Reverse[i] = k;
		k--;
	}


	Time[5] = Quick2_time(Reverse, 0, n - 1, n);


	for (int i = 0; i < n; i++)
	{
		Reverse[i] = k;
		k--;
	}

	Time[6] = Quick3_time(Reverse, 0, n - 1, n);

	
	for (int i = 0; i < 7; i++)
	{
		table[i][index] = Time[i];
	}


}


void random_time(int index, int Random[], int n, int Random_temp[]) {


	int Sum[7];

	for (int i = 0; i < 7; i++)
	{
		Sum[i] = 0;
	}

	int k = 0;
	while (k<10)
	{
		for (int i = 0; i < n; i++)
		{
			Random[i] = 1 + rand() % n;
		}

		rand_temp(Random_temp, Random, n);

		Sum[0] += Bubble_time(Random_temp, n);
		rand_temp(Random_temp, Random, n);
		Sum[1] += Selection_time(Random_temp, n);
		rand_temp(Random_temp, Random, n);
		Sum[2] += Insertion_time(Random_temp, n);
		rand_temp(Random_temp, Random, n);
		Sum[3] += Merge_time(Random_temp, 0, n - 1, n);
		rand_temp(Random_temp, Random, n);
		Sum[4] += Quick1_time(Random_temp, 0, n - 1, n);
		rand_temp(Random_temp, Random, n);
		Sum[5] += Quick2_time(Random_temp, 0, n - 1, n);
		rand_temp(Random_temp, Random, n);
		Sum[6] += Quick3_time(Random_temp, 0, n - 1, n);
		rand_temp(Random_temp, Random, n);


		k++;
	}

	for (int i = 0; i < 7; i++)
	{
		table[i][index] = Sum[i] / 10;
	}



}


void Bubble(int list[], int n) {
	int i, j, temp;

	for (i = n - 1; i>=0; i--) {
		for (j = 0; j<i; j++) {
			if (list[j]>list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}


int Bubble_time(int list[], int n) {

	int start = clock();

	Bubble(list, n);

	int end = clock();

	return end - start;

}


void Selection(int list[], int n) {
	int i, j, k,last;

	for (i = n - 1; i > 0; i--) {
		last = i;
		int k = 0;
		for (j = 0; j < last + 1; j++) {
			if (list[j] > list[k])
				k = j;
		}

		swap(list[k], list[last]);
	}
}

int Selection_time(int list[], int n) {

	int start = clock();

	Selection(list, n);

	int end = clock();

	return end - start;

}


void Insertion(int list[], int n) {
	int i, j, key;

	for (i = 1; i<n; i++) {
		key = list[i]; 
		for (j = i - 1; j >= 0 && list[j]>key; j--) {
			list[j + 1] = list[j]; 
		}

		list[j + 1] = key;
	}
}

int Insertion_time(int list[], int n) {

	int start = clock();

	Insertion(list, n);

	int end = clock();

	return end - start;

}

void Merge_sort(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i>mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

void Merge(int list[], int left, int right) {
	int mid;

	if (left<right) {
		mid = (left + right) / 2; 
		Merge(list, left, mid); 
		Merge(list, mid + 1, right); 
		Merge_sort(list, left, mid, right); 
	}
}


int Merge_time(int list[], int left,  int right, int n) {

	int start = clock();

	Merge(list, left, right);

	int end = clock();

	return end - start;

}

int partition1(int list[], int left, int right) {
	
	int x = list[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {

		if (list[j] <= x)
		{
			i++;
			swap(list[i], list[j]);
		}
	}

	swap(list[i + 1], list[right]);
	return i + 1;

}


void Quick1(int list[], int left, int right) {

	
	if (left<right) {
		
		int q = partition1(list, left, right); // q: 피벗의 위치									
		Quick1(list, left, q - 1);
		Quick1(list, q + 1, right); 
	
	}

}

int Quick1_time(int list[], int left, int right, int n) {

	int start = clock();

	Quick1(list, left, right);

	int end = clock();

	return end - start;

}


int partition2(int list[], int left, int right) {


	int	mid = (left + right) / 2;

	if (list[left] > list[mid]) SWAP(list, left, mid);

	if (list[left] > list[right]) SWAP(list, left, right);

	if (list[mid] > list[right]) SWAP(list, mid, right);

	SWAP(list, mid, right - 1);//중간값을 list[right-1]에 넣음
	
	int x = list[right - 1]; int i = left;

		for (int j = left + 1; j < right-1; j++) {

		if (list[j] <= x)
		{
			i++;
			swap(list[i], list[j]);
		}
	}

	swap(list[i+1], list[right-1]);
	return i + 1;


}

void Quick2(int list[], int left, int right) {

	if (left + 1  < right) {

		int q = partition2(list, left, right); // q: 피벗의 위치									
		Quick2(list, left, q - 1);
		Quick2(list, q + 1, right);

	}
}

int Quick2_time(int list[], int left, int right, int n) {

	int start = clock();

	Quick2(list, left, right);

	int end = clock();

	return end - start;

}
int partition3(int list[], int left, int right) {


	int p = rand() % (right - left ) + left;

	SWAP(list, p, right);

	int x = list[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {

		if (list[j] <= x)
		{
			i++;
			swap(list[i], list[j]);
		}
	}

	swap(list[i + 1], list[right]);
	return i + 1;


}


void Quick3(int list[], int left, int right) {

	if (left  < right) {

		int q = partition3(list, left, right); // q: 피벗의 위치									
		Quick3(list, left, q - 1);
		Quick3(list, q + 1, right);

	}
}

int Quick3_time(int list[], int left, int right, int n) {

	int start = clock();

	Quick3(list, left, right);

	int end = clock();

	return end - start;

}







