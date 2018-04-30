#include<iostream>
#include<bits/stdc++.h>
#include<complex.h>
using namespace std;
float yreal[20],yimag[20];
int dft(float a[],int n)
{
	float wnreal,wnimag,w,wreal,wimag,s,sreal,simag,treal,timag;
	wreal =1; 
	wimag = 0;
	//wn = cos(2*3.14/n) + I*sin(2*3.14/n);
	for(int i=0; i < n; i++)
	{
		//s = a[n-1];
		sreal=a[n-1];
		simag=0;
		for(int j=n-2; j>=0;j--)
		{
			//s= s*w + a[j];
			treal = sreal*wreal - simag*wimag + a[j];
			timag = sreal*wimag + simag*wreal;
			sreal=treal;
			simag=timag;
		}
		yreal[i]=sreal;
		yimag[i] = simag;
		treal = wreal*cos(2*3.14/n) - wimag*sin(2*3.14/n);
		timag = wimag*cos(2*3.14/n) + wreal*sin(2*3.14/n);
		wreal =treal;
		wimag =timag;
		//w=w*wn;
	}
	for(int i=0;i<n;i++)
	{
		cout<<yreal[i]<<" ";
		yimag[i]>0?cout<<"+":cout<<" ";
		cout<<yimag[i]<<"i"<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	float a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	dft(a,n);
}

