#include <iostream>
#include <math.h>



using namespace std;

int main(){
    bool choice;
    cout<<"Enter coice: [0 for exponential; 1 for power]:   ";
    cin>>choice;

    int size;
    cout<<"enter size of arrays";
    cin>>size;
     double arr_x_init[size], arr_y_init[size];
    cout<<"Enter the elements for x!\n\n";
    double arr_x[size];
    for (int i=0;i<size;i++){
        cout<<"enter element"<<i<<":    ";
        cin>>arr_x[i];
         arr_x_init[i]=arr_x[i];
    }
    cout<<endl;

    cout<<"Enter the elements for y!\n\n";
    double arr_y[size];
    for (int j=0;j<size;j++){
        cout<<"enter element"<<j<<":    ";
        cin>>arr_y[j];
        arr_y_init[j]=arr_y[j];

    }
    cout<<endl;

   
    // for (int i=0; i<size; i++)
    //     {
           
            
    //     }

    if (!choice){
        //for exponential function
        for (int i=0;i<size;i++){
        arr_y[i]=log(arr_y[i]);
        }


    }else{
        //for power function
        for (int e=0;e<size;e++){
        arr_x[e]=log(arr_x[e]);
        arr_y[e]=log(arr_y[e]);
        }
        
    }

    double sum_x=0, sum_y=0, sum_x2=0, sum_xy=0;

   
    for (int r=0;r<size;r++){
        sum_x+=arr_x[r];
        sum_y+=arr_y[r];
        sum_x2+=(pow(arr_x[r],2));
        sum_xy+=(arr_x[r]*arr_y[r]);
    }
   

    double slope, intercept;

    slope= ((size*sum_xy) - (sum_x*sum_y))/((size*sum_x2) - (pow(sum_x,2)));

    intercept=exp(((sum_y/size) - (slope*(sum_x/size))));

    cout<<"slope is "<<slope<<endl;
    cout<<"intercept is "<<intercept<<endl;

    cout<<"x\t"<<"y\t"<<"y_calc\t\t"<<"error"<<endl;

    double y_calc=0;
    float tempy,tempx,tempz;

    if (!choice){
        for (int w=0; w<size; w++)
        {
             tempx=(double) (intercept * (exp(arr_x_init[w]*slope)));
             tempy=(double) ((arr_y_init[w])-((intercept) * (exp(arr_x_init[w]*slope))));
            cout<<arr_x_init[w]<<"\t"<<arr_y_init[w]<<"\t"<<tempx<<"\t\t"<<tempy<<endl;
        }
    }else{
        for (int q=0; q<size; q++){
            y_calc=(float) ((intercept) * (pow(arr_x_init[q],slope)));
             tempz=(float) (y_calc-(arr_y_init[q]));
            cout<<arr_x_init[q]<<"\t"<<arr_y_init[q]<<"\t"<<y_calc<<"\t\t"<<tempz<<endl;
        }
    }
    
}