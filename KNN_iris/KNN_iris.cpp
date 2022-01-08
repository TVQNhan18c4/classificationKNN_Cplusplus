#include <bits/stdc++.h>

using namespace std;

struct Point{
    int val,val1,val2,val3; 
    double x1;
    double x2;
    double x3;
    double x4;
    double distance;
};

//xao mang
void Swap(Point* number_1, Point* number_2)
{
	Point temp = *number_1;
	*number_1 = *number_2;
	*number_2 = temp;
}

void ShuffleArray(Point* arr, int n)
{

	int minPosition;
	int maxPosition = n - 1;
	int swapPosition;

	int i = 0;
	while (i < n - 1)
	{
		minPosition = i + 1;
		swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;

		Swap(&arr[i], &arr[swapPosition]);
		i++;
	}
}


//KNN
void phanLopKnn(Point arr[], int b, Point p)
{
    for(int i =0 ;i <b ;i++)
    {
        arr[i].distance = sqrt( ((arr[i].x1 - p.x1)*(arr[i].x1 - p.x1))
							   +((arr[i].x2 - p.x2)*(arr[i].x2 - p.x2))
							   +((arr[i].x3 - p.x3)*(arr[i].x3 - p.x3))
							   +((arr[i].x4 - p.x4)*(arr[i].x4 - p.x4)) );
    }
    for(int i=0;i<b-1;i++)
    {
        for(int j = i+1; j<b;j++)
        {
            if(arr[i].distance  > arr[j].distance)
            {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}

int ketqua(Point arr[], int k){
    int dem1 = 0;
    int dem2 = 0;
    int dem3 = 0;

    for(int i=0;i<k;i++)
    {
        if(arr[i].val == 1)
        {
            dem1++;
        }
        else if(arr[i].val == 2)
        {
            dem2++;
        }
        else
        {
        	dem3++;
		}
    }
    if(dem1 > dem2 && dem1 > dem3)
    {
        return 1;
    }	
    else if(dem2 > dem1 && dem2 > dem3)
	{
        return 2;
    }
    else{
    	return 3;
	}
}

//danh gia
void ti_le(int n, int m, Point p[], Point arr[]){
	int kiemtra;
	for(int i=0; i<n-m; i++){
    	if(p[i].val==arr[n-1-i].val){
    		kiemtra++;
		}
		else{
			cout<<"\nmau "<<i+1<<" sai"<<endl;
		}
    }
    cout<<"\nti le chinh xac : "<<kiemtra<<"/"<<n-m<<" = "<<(double)100*(kiemtra)/(n-m)<<"%";
}


int main(){
	ifstream file; 
	//open file;
	file.open("iris.dat");
	int n;
	while (!file.eof())
	{
		n++;
	}
	
//	int n=150*7; 
	double a[n];
	for(int i=0; i<n; i++){
		file>>a[i];
	}
	file.close();
	//doc du lieu
	cout<<"\tDU LIEU DOC :\n";
	int b = 150;
    Point arr[b];
	for(int i=0; i<b; i++){
		arr[i].x1=a[i*7];
		arr[i].x2=a[i*7+1];
		arr[i].x3=a[i*7+2];
		arr[i].x4=a[i*7+3];
		arr[i].val1=a[i*7+4];
		arr[i].val2=a[i*7+5];
		arr[i].val3=a[i*7+6];
		cout<<arr[i].x1<<"\t"<<arr[i].x2<<"\t"<<arr[i].x3<<"\t"<<arr[i].x4<<"\t"<<arr[i].val1<<"\t"<<arr[i].val2<<"\t"<<arr[i].val3<<"\t"<<endl;
		if(arr[i].val1==1 && arr[i].val2==0 && arr[i].val3==0){
			arr[i].val=1;
		}
		if(arr[i].val1==0 && arr[i].val2==1 && arr[i].val3==0){
			arr[i].val=2;
		}
		if(arr[i].val1==0 && arr[i].val2==0 && arr[i].val3==1){
			arr[i].val=3;
		}
	}
	
	//xao du lieu
	cout<<"\n\n\n\tXAO DU LIEU :\n";
	ShuffleArray(arr,b);
	for(int i=0; i<b; i++){
		cout<<arr[i].x1<<"\t"<<arr[i].x2<<"\t"<<arr[i].x3<<"\t"<<arr[i].x4<<"\t"<<arr[i].val1<<"\t"<<arr[i].val2<<"\t"<<arr[i].val3<<endl;
	}
	
	//80%
	cout<<"\n\n\n\t80% FOR TRAINNING:\n";
	int m;
	m=b*8/10;	//80%
	for(int i=0; i<m; i++){
		cout<<"mau "<<i+1<<"\t\t"<<arr[i].x1<<"\t"<<arr[i].x2<<"\t"<<arr[i].x3<<"\t"<<arr[i].x4<<"\t"<<arr[i].val1<<"\t"<<arr[i].val2<<"\t"<<arr[i].val3<<endl;
	}
	
	//20%
	cout<<"\n\n\n\t20% FOR TESTING:\n";
	for(int i=b-1; i>m-1; i--){//chay lui 149 -> 119
		cout<<"mau "<<150-i<<"\t\t"<<arr[i].x1<<"\t"<<arr[i].x2<<"\t"<<arr[i].x3<<"\t"<<arr[i].x4<<"\t"<<arr[i].val1<<"\t"<<arr[i].val2<<"\t"<<arr[i].val3<<endl;
	}
	
	//TESTING
	cout<<"\n\n\n\tTESTING:\n";
    Point p[b-m];
    for(int i=0; i<b-m; i++){
    	p[i].x1=arr[b-1-i].x1;
    	p[i].x2=arr[b-1-i].x2;
    	p[i].x3=arr[b-1-i].x3;
    	p[i].x4=arr[b-1-i].x4;
    	cout<<"mau "<<i+1<<"\t\t"<<p[i].x1<<"\t"<<p[i].x2<<"\t"<<p[i].x3<<"\t"<<p[i].x4<<"\t?"<<"\t?"<<"\t?"<<endl;
	}
	
	//KNN -> ket qua
	int k;
	cout<<"\n\n\tnhap k : ";
	cin>>k;
    for(int i=0; i<b-m; i++){
   		phanLopKnn(arr, m, p[i]);
   		int nhom = ketqua(arr, k);
   		p[i].val=nhom;
   		if(p[i].val== 1){
   			p[i].val1=1;
   			p[i].val2=0;
   			p[i].val3=0;
		}
		if(p[i].val== 2){
   			p[i].val1=0;
   			p[i].val2=1;
   			p[i].val3=0;
		}
		if(p[i].val== 3){
   			p[i].val1=0;
   			p[i].val2=0;
   			p[i].val3=1;
		}
   		cout<<"mau "<<i+1<<"\t\t"<<p[i].x1<<"\t"<<p[i].x2<<"\t"<<p[i].x3<<"\t"<<p[i].x4<<"\t"<<p[i].val1<<"\t"<<p[i].val2<<"\t"<<p[i].val3<<endl;
	}
	
	ti_le(b,m,p,arr);
}

