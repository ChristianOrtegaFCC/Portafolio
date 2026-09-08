#include <iostream>
#include <cstring>
#include <math.h>

main()
{
        string s1;
        int n, i, j;
        float x[100],  fx[100],  xint,  fxint,  s;
        s1.append(160,'_');
       cout << "\n\n\t\t METODO DE LAGRANGE ";
       cout<<"\n"<<s1;
       cout<<"\n\n  \4 Ingresa el numero de parejas de puntos: ";
       cin >> n;
       cout<<"\n"<<s;
       cout << "\n\n\nINGRESE VALORES DE x[i] y sus fx[i]\n\n";

for ( i=0;  i<n;  i++ ) {

      cout << "\nx[ " << i << " ] : ";
      cin >> x[i];
      cout << "\nFx[ " << i << " ] : ";
      cin >> fx[i];
  }
      cout << "\n\nINGRESE VALOR A INTERPOLAR : " ;
      cin >> xint;

      fxint = 0;
for( i=0; i<n; i++){
      s = 1;
      j = 0;
      while( j<n )
      {
             if( i != j){
                  s = s*( xint - x[j] )/( x[i] - x[j]);
                  }
                        j++;
            }
         fxint = fxint + s*fx[i];
    }
    cout<<"\n"<<s1;
cout << "\n\nEL VALOR DE LA FUNCION EN LA INTERPOLACION DE f( " << xint << ") es : " << fxint;
cout << endl << endl << endl;

 return 0;
}
