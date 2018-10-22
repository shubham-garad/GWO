#include<iostream>
#include <cstdlib>
using namespace std;
int arraySum(int a[])  
{ 
	int n = len(a); 
    int initial_sum  = 0;  
    return accumulate(a, a+n, initial_sum); 
} 
int prod(int it[])
{
	int p=1,i;
	for (i=0;i<sizeof(it)/sizeof(it[0]);i++){
		p=p*it[i];
	}
	return (p);
}
int Ufun(int x,int a,int k,int m)
{
	int y=k*(pow((x-a),m)*(k>a)+k*(pow((-x-a),m)*(x<(-a))));
	return (y);
}
int slice(int x[], i, j)
{
	int z,p[300],m=0;
	for (z=i;z<j;z++)
	{
		p[m]=x[z];
		m=m+1;
	}
	return p;
}
int len(int x[])
{
	return (sizeof(x)/sizeof(x[0]));
}
int max(int x[])
{
	l=len(x);
	return ( std::max_element(x, x+l) );
}
int substract(a[],b[])
{
	int la=len(a);
	int lb=len(b);
	int mat3 [la][lb];
    for (int i = 0; i < la; i++)

    {

        for (int j = 0; j < lb; j++)

        {

            mat3[i][j] = mat2[i][j] - mat1[i][j];	

        }

    }
    return mat3;

}

int F1(int x[])
{
	int fit=arraySum(pow(x,2));
	return fit;
}
int F2(int x[])
{
	int fit=arraySum(x)+prod(x);
	return fit;
}
int F3(int x[])
{
	int dim=len(x)+1;
	int fit=0,i;
	for(i=1;i<dim;i++)
	{
		fit=fit+(pow(arraySum(slice(s,0,i))),2);
	}
	return fit;
}
int F4(int x[])
{
	int fit=abs(max(x));
	return fit;
}
int F5(int x[])
{
	int dim=len(x);
	int fit=pow(arraySum(100*slice(x,1,dim)-pow(slice(x,
		0,dim-1),2)),2)+pow((slice(x,0,dim-1)-1),2);
}
int F6(int x[])
{
	int fit=pow(arraySum(x+0.5),2);
	return fit;
}
int F7(int x[])
{
	int fit=0,i,dim=len(x);
	for(i=0;i<dim;i++)
	{
		fit=fit+((i+1)*pow(x[i],4)+rand()%2);
	}
	return fit;
}
int F8(int x[])
{
	int fit=arraySum(-x*sin(pow(abs(x),1/2)));
	return fit;
}
int F9(int x[])
{
	int dim=len(x);
	int fit=arraySum(pow(x,2)-10*cos(2*3.1415926*x))+10*dim;
	return fit;
}
int F10(int x[])
{
	int dim=len(x);
	int fit=-20*exp(-0.2*pow(arraySum(pow(x,2))/dim,
		1/2))-exp(arraySum(cos(2*3.1415926*x))/dim)+20+exp(1);
	return fit;
}
int F11(int x[])
{
	int i;
	int summation=0,production=0;
	for (i=0;i<len(x)-1;i++){
		int summation=summation+pow(x[i],2);
	}
	for (i=0;i<len(x)-1;i++)
	{
		production=production*(cos(x[i]/pow(summation,1/2)));
	}
	int fit=(summation)/4000-production+1;
	return fit;
}
int F12(int x[])
{
	int dim=len(x);
	int fit=(3.1415926/dim)*(10*pow((sin(3.1415926*(1+(x[0]+1/4)))),
		2)+arraySum(pow((slice(x,1,dim-1)+1)/4,2)*(1+10*pow(sin(3.1415926*
			(1+(slice(x,1,dim-1)+1)/4)),2)))+pow(((slice[dim-1]+1)/4),
		2))+arraySum(Ufun(x,10,100,4));
	return fit;
}
int F13(int x[])
{
	int dim=len(x);
	int fit=0.1*(pow(sin(3*3.1415926*x[1]),2)+arraySum((pow(slice(x,0,dim-2
		)-1),2)*(1+pow(sin(3*3.1415926*slice(x,1,dim-1)),2)))+(pow(x[dim-1]-1),2)
		*(1+pow(sin(2*3.1415926*x[dim-1]),2)))+arraySum(Ufun(x,5,100,4));
	return fit;
}
'''int F14(int x[])
{
	int i, aS[]={{-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,
		16,32,-32,-16,0,16,32,-32,-16,0,16,32},{-32,-32,-32,
		-32,-32,-16,-16,-16,-16,-16,0,0,0,0,0,16,16,16,16,16,
		32,32,32,32,32};
	bS [25]={ };
	for(i=0;i<25;i++)
	{
		H=x-aS[]
	}
}'''
int F15(int x[])
{
	int aK[]={0.1957,0.1947,0.1735,0.16,0.0844,0.0627,0.0456,
		0.0342,0.0323,0.0235,0.0246};
	int bK[]={0.25,0.5,1,2,4,8,10,12,14,16};
	bK=1/bK;
	int fit=arraySum(pow(aK-(L[0]*(pow(bK,2)+L[1]*bK))/(pow(bK,2)+L[2]*bK+L[3])),2)

}

int F16(int x[])
{
	int fit=4*pow(x[0],2)-2.1*pow(x[0],4)+pow(x[0],6)/3+
		x[0]*x[1]-4*pow(x[1],2)+4*pow(x[1],4);
	return fit;
}
int F17(int L[])
{
	int fit=pow((L[1]-pow(L[0],2)*5.1/4*pow(3.1415926,2)+5/3.1415926*L[0]-6),2)+
		10*(1-1/(8*3.1415926))*cos(x[0])+10;
	return fit;
}
int F18(int L[])
{
	int fit=(1+pow((L[0]+L[1]+1),2)*(19-14*L[0]+3*pow(L[0],2)-
		14*L[1]+6*L[0]*L[1]+3*pow(L[1],2)))*(30+pow((2*L[0]-
		3*L[1]),2)*(18-32*L[0]+12*pow(L[0],2)+48*L[1]-
		36*L[0]*L[1]+27*pow(L[1],2)));
	return fit;
}
int F19(int L[])
{
	int aH[]={{3,10,30},{0.1,10,35},{3,10,30},{0.1,10,35}};
	int cH[]={1,1.2,3,3.2};
	int pH[]={{0.3689,0.117,0.2673},{0.4699,0.4387,0.747},
		{0.1091,0.8732,0.5547},{0.03815,0.5743,0.8828}};
	int fit=0,i=0;
	for(i=0;i<4;i++)
	{
		fit=fit-cH[i]*exp(-(arraySum(aH[i] *pow((L-pH[i]),2))));
	}
	return fit;
}
int F20(int L[])
{
	int aH[]={{10,3,17,3.5,1.7,8},{0.05,10,17,0.1,8,14},{3,3.5,1.7,10,17,8},{17,8,0.5,10,0.1,14}};
	int cH[]={1,1.2,3,3.2};
	int pH[]={{0.1312,0.1696,0.5569,0.0124,0.8283,0.5886},{0.2329,0.4135,0.8307,0.3736,0.1004,0.9991},{0.2348,0.1415,0.3522,
		0.2883,0.3047,0.6650},{0.4047,0.8828,0.8732,0.5743,0.1091,0.0381}};
	int fit=0,i=0;
	for(i=0;i<4;i++)
	{
		fit=fit-cH[i]*exp(-(arraySum(aH[i] *pow((L-pH[i]),2))));
	}
	return fit;	
}
int F21(int L[])
{
	int aSH []={{4,4,4,4},{1,1,1,1},{8,8,8,8},{6,6,6,6},{3,7,3,7},{2,9,2,9},{5,5,3,3},{8,1,8,1},{6,2,6,2}};
	int cSH []={0.1,0.2,0.2,0.4,0.4,0.6,0.3,0.7,0.5,0.5};
	int fit=0,i=0;
	for(i=0;i<4;i++)
	{
		int v[]
		fit=fit-cH[i]*exp(-(arraySum(aH[i] *pow((L-pH[i]),2))));
	}
	return fit;
}

'''
int getFunctionDetails(a)
{
	int param=[[]]
}'''