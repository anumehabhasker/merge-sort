#include<iostream>
#include<algorithm>

using namespace std;

// MERGE SORT: sort each pair of elements. Then sort every four elements by merging them as two pairs. Then sort every 8 elements etc. O(nlogn)

int a[50];

void merge(int low, int mid, int high)
{
	int h,i,j; int b[50];
	h=low;
	i=low;
	j=mid+1;

	while((h<=mid)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>mid)
	{
		for(int k=j;k<=high;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(int k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	for(int k=low;k<=high;k++) 
		a[k]=b[k];

}

void merge_sort(int low, int high)
{
	int mid;
	cout<<"low: "<<low<<"\t"<<"high: "<<high;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}

int main()
{
	a[0]=3;
	a[1]=2;
	a[2]=5;
	a[3]=1;
	a[4]=7;
	a[5]=6;
	a[6]=4;
	
	cout<<"\n original array \n";
	for(int i=0;i<7;i++)	cout<<" "<<a[i]<<"\t";
	merge_sort(0,6);

	cout<<"\n merge sorted array \n";
	for(int i=0;i<7;i++)	cout<<" "<<a[i]<<"\t";
	return 0;
}
