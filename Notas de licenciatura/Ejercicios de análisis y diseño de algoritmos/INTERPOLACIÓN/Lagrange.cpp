#include <iostream>
#include <cstring>

using namespace std;

main()
{
int n;
int j;
string s;
double x[100],  fx[100],  xint,  fxint,  k;
s.append(160,'_');
cout<<"\n\n\t\t\t       \4 Metodo de lagrange";
cout<<"\n"<<s;
cout<<"\n\n  \4 Ingresa el numero de parejas de puntos: ";
cin>>n;
cout<<"\n"<<s;
cout << "\n\n\nINGRESE VALORES DE x[i] y sus fx[i]\n\n";

for ( int i=0;  i<n;  i++ )
{

      cout << "\nx[ " << i << " ] : ";
      cin >> x[i];
      cout << "\nFx[ " << i << " ] : ";
      cin >> fx[i];
}
      cout << "\n\nINGRESE VALOR A INTERPOLAR : " ;
      cin >> xint;
fxint = 0;
for( int i=0; i<n; i++){
      k = 1;
      j = 0;
      while( j<n )
      {
             if( i != j){
                  k = k*( xint - x[j] )/( x[i] - x[j]);
                  }
                        j++;
            }
         fxint = fxint + k*fx[i];
    }
    cout<<"\n"<<s;
cout << "\n\nEL VALOR DE LA FUNCION EN LA INTERPOLACION DE f( " << xint << ") es : " << fxint;
cout << endl << endl << endl;



return 0;
}
