#include <iostream>

using namespace std;

class RELATION{
    int set1[100], relate[100][100];
    char set3[100];
    int set_l1;

    public:
    RELATION(){
        cout<<"\n\n\t\t\t!!!! YOU HAVE SELECTED ONLY ALPHABETS AS A OPTION FOR ELEMENTS OF YOUR SET !!!!\n\n";
        cout<<"     NUMBER OF ELEMENTS IN SET= ";
        cin>>set_l1;
        cout<<"     ENTER ELEMENTS OF SET:-\n";
        cout<<"     ";

        for(int i=0;i<set_l1;i++){
            cin>>set3[i];
        }

        cout<<"\t\t\t\t!!!!		 SET MAKING SUCCESSFUL		!!!!\n\n";
    }

    RELATION(int x){
		
		cout<<"\n\n\t\t\t!!!! YOU HAVE SELECTED ONLY NUMBERS AS A OPTION FOR ELEMENTS OF YOUR SET !!!!\n\n";
        cout<<"     NUMBER OF ELEMENTS IN SET= ";
        cin>>set_l1;
        cout<<"     ENTER ELEMENTS OF SET:-\n";
        cout<<"     ";

        for(int i=0;i<set_l1;i++){
            cin>>set1[i];
        }

        cout<<"\t\t\t\t!!!!		 SET MAKING SUCCESSFUL		!!!!\n\n";
        
    }
    
    void make_a_relation(){
    	for(int i=0;i<100;i++){
    		for(int j=0;j<100;j++){
    			relate[i][j]=0;
			}
		}
    	
    	cout<<"\n\n\t\t\t\t!!!!		 SETTING UP A RELATION		!!!!\n\n";
    	
    	cout<<"\t\t\tWRITE THE ELEMENTS OF THE RELATION AS SHOWN BELOW IN THE EXAMPLE\n\n";
    	
    	cout<<"\t\t\t     #### EXAMPLE { ENTER YOUR ELEMENT:- ( a , b ) }  ####\n\n\n";
    	cout<<"\t\t#### TO BREAK THE INPUT JUST WRITE 0 AS YOUR ELEMENT AS { ENTER YOUR ELEMENT:- 0  ####\n\n\n";
    	
    	char x, k1, k2;
    	while(1){
    		cout<<"\t\t	ENTER YOUR ELEMENT ( a , b ):- ";
    		
    		cin>>x;
			if(x=='0')break;
			
			cin>>k1>>x>>k2>>x;
			int i,j;
    		for(i=0;i<set_l1;i++){
    			if(set3[i]==k1){  break;}
			}
			
			for(j=0;j<set_l1;j++){
    			if(set3[j]==k2){  break;}
			}
			
			relate[i][j]=1;
		}
    	
    	cout<<"\n\n\n\t\t\t!!!!		 RELATION MAKING SUCCESSFUL		!!!!\n\n";
	}
	
	void make_a_relation(int x){
		for(int i=0;i<100;i++){
    		for(int j=0;j<100;j++){
    			relate[i][j]=0;
			}
		}
    	
    	cout<<"\n\n\t\t\t\t!!!!		 SETTING UP A RELATION		!!!!\n\n";
    	
    	cout<<"\t\t\tWRITE THE ELEMENTS OF THE RELATION AS SHOWN BELOW IN THE EXAMPLE\n\n";
    	
    	cout<<"\t\t\t     #### EXAMPLE { ENTER YOUR ELEMENT:- ( a , b ) }  ####\n\n\n";
    	cout<<"\t\t#### TO BREAK THE INPUT JUST WRITE 0 AS YOUR ELEMENT AS { ENTER YOUR ELEMENT:- 0  ####\n\n\n";
    	
    	char x1;
		int k1, k2;
    	while(1){
    		cout<<"\t\t	ENTER YOUR ELEMENT ( a , b ):- ";
    		
    		cin>>x1;
			if(x1=='0')break;
			
			cin>>k1>>x1>>k2>>x1;
			int i,j;
    		for(i=0;i<set_l1;i++){
    			if(set1[i]==k1){  break;}
			}
			
			for(j=0;j<set_l1;j++){
    			if(set1[j]==k2){  break;}
			}
			
			relate[i][j]=1;
		}
    	
    	cout<<"\n\n\n\t\t\t\t!!!!		 RELATION MAKING SUCCESSFUL		!!!!\n\n";
	}

	void check_the_relation(){
		int reflexivity=1;
		
		for(int i=0;i<set_l1;i++){
			if(relate[i][i]==0) { reflexivity=0; break; }
		}
		
		if(reflexivity==1){	cout<<"\t\t\t((((    RELATION IS REFLEXIVE    ))))\n\n";}
		else cout<<"\t\t\t((((    RELATION IS NOT REFLEXIVE    ))))n\n";
		
		
		int symmetricity=1;
		
		for(int i=0;i<set_l1;i++){
			for(int j=0;j<set_l1;j++){
				if(i!=j && relate[i][j]!=relate[j][i]){	symmetricity=0; break; }
			}
		}
		
		if(symmetricity==1){	cout<<"\t\t\t((((    RELATION IS SYMMETRIC    ))))\n\n";}
		else cout<<"\t\t\t((((    RELATION IS NOT SYMMETRIC    ))))\n\n";
		
		
		int transitivity=1;
		
		for(int i=0;i<set_l1;i++){
			for(int j=0;j<set_l1;j++){
				for(int k=0;k<set_l1;k++){
					if(relate[i][j]==1 && relate[j][k]==1){
						if(relate[i][k]!=1){	transitivity=0; break;}
					}
				}
			}
		}
		
		if(transitivity==1){	cout<<"\t\t\t((((    RELATION IS TRANSITIVE    ))))\n\n";}
		else cout<<"\t\t\t((((    RELATION IS NOT TRANSITIVE    !!!!\n\n";
		
		
		int antisymmetricity=1;
		for(int i=0;i<set_l1;i++){
			for(int j=0;j<set_l1;j++){
				if(i!=j){
						if(relate[i][j]==1 && relate[j][i]==1){ antisymmetricity=0; break;}
				}
			}
		}
		
		if(antisymmetricity==1){	cout<<"\t\t\t((((    RELATION IS ANTISYMMETRIC    ))))\n\n";}
		else cout<<"\t\t\t((((    RELATION IS NOT ANTISYMMETRIC    ))))\n\n";
	}

};

int main(){
    start:{
    cout<<"\n\n\n";
    cout<<"!!!! FOLLOWING IS THE PROGRAM TO CHECK WHETHER A RELATION ON A SET IS REFLEXIVE, SYMMETRIC, ANTI-SYMMETRIC AND TRANSITIVE OR NOT FOR TWO SETS !!!!\n";
    cout<<"\n-->      ENTER THE TYPE OF ELEMENTS YOU ARE ENTERING IN THE SETS:-\n";
    cout<<"-->      1.    NUMBERS\n";
    cout<<"-->      2.    ALPHABETS\n";
    cout<<"-->      ENTER YOUR SELECTION:- ";
    int x;  cin>>x;

    switch (x)
    {
        case 1:
            {
                RELATION r1(1);
                r1.make_a_relation(1);
                r1.check_the_relation();
                break;
            }

        case 2:
            {
                RELATION r1;
                r1.make_a_relation();
                r1.check_the_relation();
                break;
            }

        default:
            {
                cout<<"\n\n\n!!!!     WRONG INPUT ENTERED     !!!!!\n\n\n";
            }
    }

	cout<<"\n\n\t\t!!!!     WANT TO GO AT THE STARTING OF THE PROGRAM(Y-->YES / N-->NO)       !!!!\n\n";
	cout<<"			ENTER YOU SELECTION:- ";
	char c; cin>>c;
	if(c=='y' || c=='Y'){
		cout<<"!!!!     YOU ARE BEING RETURNED TO STARTING OF THE PROGRAM       !!!!\n\n";
		goto start;
	}
	
	}
    

    return 0;
}
