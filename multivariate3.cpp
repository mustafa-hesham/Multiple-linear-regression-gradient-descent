#include <iostream>
#include <cmath>

using namespace std;

int main()

{
	repeat:
	int m = 0;
	cout<<"Please enter number of points: ";
	cin>>m;
	double compar = 0.0;
	double cost = 0.0;
	double total = 0.0;
	int num;
	cout<<"\nPlease enter number of features including the bias: ";
	cin>>num;
	double xs[m][num];
	double ys[m];
	for (int i = 0; i < m; i++)
	{
		for (int z = 0; z<(num); z++)
		{
			if (z == 0)
			{
				xs[i][z] = 1.0;
				continue; 
			}
			cout<<"Please enter X["<<i+1<<"]"<<"["<<z+1<<"]: ";
		cin>>xs[i][z];
		}
		
		cout<<"Please enter Y["<<i+1<<"]: ";
		cin>>ys[i];
	}
	double feat[num];
	double finalfeat[num];
	for (int i = 0; i < num; i++)
	{
		finalfeat[i] = 0;
		feat[i] = 0;
	}
	
	double step;
	int ite;
	cout<<"\n\n\nPlease enter number of iterations: ";
	cin>>ite;
	cout<<"\nPlease enter learning rate: ";
	cin>>step;
	
	for (int r = 0; r < m; r++)
	{
		total = 0;
		for (int c = 0; c < num; c++)
		{
			total = feat[c]*xs[r][c];
			
		}
		compar += pow((total-ys[r]), 2.0)*(1.0/(2.0*m));
	}
	
	cout <<"\n\n\nThe initial cost function is: "<<compar<<endl;
	
		for (int it = 0; it < ite; it++)
		{
			cost = 0.0;
			
				for (int x = 0; x<m; x++)
			{ 
					
					
					for (int f = 0; f < num; f++)
						{
							
						if (f == 0)
						{
				
								for (int r = 0; r < m; r++)
							{
								
								total = 0.0;
								for (int c = 0; c < num; c++)
								{
									total += feat[c]*xs[r][c];
								
								}
								feat[f] -= step*(1.0/m)*(total-ys[r]);
								
							}
									
							continue;
						}
							
						 else if (f > 0)
						{
							
								for (int r = 0; r < m; r++)
							{
								
								total = 0.0;
								for (int c = 0; c < num; c++)
								{
									total += feat[c]*xs[r][c];
								
												
								}
								feat[f] -= step*(total-ys[r])*xs[r][f]*(1.0/(m));		
								
							}
							
							continue;
						}
						
						
				    	}
		
			}
			
			for (int r = 0; r < m; r++)
									{
										total = 0.0;
										for (int c = 0; c < num; c++)
										{
											total += feat[c]*xs[r][c];
										}
										cost += pow((total-ys[r]), 2.0)*(1.0/(2.0*m));
									}
					
						
						if (cost<compar) 
						{
							compar = cost;
							for (int fin = 0; fin < num; fin++)
							{
								finalfeat[fin] = feat[fin];
							
							}
						}

			if (compar == 0) it += ite;
		}

	cout<<"\n\n\nThe equation is: "<<finalfeat[0]<<" + ";
	for (int r = 1; r < num; r++)
		{
			cout<<finalfeat[r]<<" X"<<r<<" + ";
		
		}
		cout<<"0"<<endl;
		cout<<"\n\n\n";
		cout<<"Enter 1 to repeat: ";
	int rp = 0;
	cin>>rp;
	if (rp == 1)
	goto repeat;
}
